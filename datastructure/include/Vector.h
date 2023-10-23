#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef>
#include <memory>


namespace slib{

class Vector {
public:
    Vector() = default;
    explicit Vector(size_t size);
    Vector(Vector &from);
    void push_back(int val);
    size_t size() const;
    size_t capacity() const;
    ~Vector();
    void clear();
    Vector& operator=(const Vector& from);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    bool empty() const;

private:
    static constexpr auto DEFAULT_CAPACITY = 5;
    void expand_capacity();
    size_t                  size_ = 0;
    size_t                  capacity_ = 0;
    std::unique_ptr<int[]>    data_ = nullptr;
};

}  // namespace slib


#endif  //VECTOR_H_
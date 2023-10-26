#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstddef>
#include <memory>

// TODO:
// 1. 改造成模板类
// 2. 支持列表初始化
// 3. 支持随机访问迭代器

namespace slib{

template <typename T>
class Vector {
public:
    class Iterator {
            friend class Vector;
            friend bool operator!=(const Iterator &l, const Iterator &r);
            friend bool operator==(const Iterator &l, const Iterator &r);
        public:
            // 前置
            int& operator++();
            // 后置
            int operator++(int);
            int& operator*();
            Iterator();
            ~Iterator();
        private:
            T *element_;
    };
public:
    Vector() = default;
    explicit Vector(size_t size);
    Vector(size_t size, T value);
    Vector(const Vector &from);
    Vector(Iterator begin, Iterator end);
    Vector(int *begin, int *end);
    void push_back(const T :val);
    size_t size() const;
    size_t capacity() const;
    ~Vector();
    void clear();
    Vector& operator=(const Vector& from);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    bool empty() const;
    Iterator begin();
    Iterator end();

private:
    static constexpr auto DEFAULT_CAPACITY = 5;
    static constexpr auto DEFAULT_MULTIPLE = 2;
    void copy(const Vector &from);
    void expand_capacity();
    void expand_capacity(size_t index);
    size_t                      size_ = 0;
    size_t                      capacity_ = 0;
    std::unique_ptr<T[]>      data_ = nullptr;
};

}  // namespace slib

#endif  //VECTOR_H_
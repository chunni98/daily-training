#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <cstddef>
#include <iostream>

namespace slib {
template <typename T>
class Vector{
public:
    Vector(size_t num, const T &val);
    template <typename Y>
    friend std::ostream & operator<<(std::ostream &out, const Vector<Y> &vec);

private:
    void expand(size_t size);
    static constexpr auto DEFAULT_CAPACITY = 5;
    std::unique_ptr<T[]> data_;
    size_t size_;
    size_t capacity_;
};
}

#include "Vector.tpp"

#endif  // VECTOR_HPP_
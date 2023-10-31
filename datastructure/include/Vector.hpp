#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <cstddef>

namespace slib {
template <typename T>
class Vector{
public:

private:
    std::unique_ptr<T> data_;
    size_t size_;
    size_t capacity_;
};
}

#include "Vector.cc"
#endif  // VECTOR_HPP_
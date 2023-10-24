#include "Vector.h"
#include <cmath>

using namespace std;

namespace slib {

Vector::Vector(size_t size)
{
    expand_capacity(size);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = 0;
    }
}

// Vector(size) 用
void Vector::expand_capacity(size_t size)
{
    capacity_ = DEFAULT_CAPACITY;
    while (capacity_ < size) {
        capacity_ *= DEFAULT_MULTIPLE;
    }
    data_ = make_unique<int[]>(capacity_);
    size_ = size;
}

// push_back() 用
void Vector::expand_capacity()
{
    if (capacity_ == 0) {
        data_ = make_unique<int[]>(DEFAULT_CAPACITY);
        capacity_ = DEFAULT_CAPACITY;
        return ;
    }
    auto ptr = make_unique<int[]>(capacity_ * DEFAULT_MULTIPLE);
    for (size_t i = 0; i < size_; ++i) {
        ptr[i] = data_[i];
    }
    data_.reset(ptr.release());
    capacity_ = capacity_ * DEFAULT_MULTIPLE;
}

void Vector::push_back(int val)
{
    if (capacity_ < size_+1) {
        expand_capacity();
    }
    data_[size_] = val;
    size_++;
}

void Vector::copy(const Vector &from)
{
    clear();
    capacity_ = from.capacity_;
    size_ = from.size_;
    data_ = make_unique<int[]>(capacity_);

    for (size_t i = 0; i < size_; ++i) {
        data_[i] = from.data_[i];
    }
}

Vector::Vector(const Vector &from)
{
    copy(from);
}

size_t Vector::size() const
{
    return size_;
}

size_t Vector::capacity() const
{
    return capacity_;
}

Vector::~Vector()
{

}

void Vector::clear()
{
    size_ = 0;
    capacity_ = 0;
    if (data_) {
        data_.reset();
    }
}

Vector& Vector::operator=(const Vector &from)
{
    copy(from);
    return *this;
}

int& Vector::operator[](size_t index)
{
    return data_[index];
}

const int& Vector::operator[](size_t index) const
{
    return data_[index];
}

bool Vector::empty() const
{
    return size_ == 0;
}

}   // namespace slib

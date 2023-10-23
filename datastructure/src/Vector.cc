#include "Vector.h"

using namespace std;

namespace slib {

Vector::Vector(size_t size)
{
    int multipe;
    if (size % DEFAULT_CAPACITY == 0) {
        multipe = size / DEFAULT_CAPACITY;
    } else {
        multipe = size / DEFAULT_CAPACITY + 1;
    }
    capacity_ = DEFAULT_CAPACITY * multipe;
    data_ = make_unique<int[]>(DEFAULT_CAPACITY * multipe);
    size_ = size;
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = 0;
    }
}

void Vector::expand_capacity()
{

}

void Vector::push_back(int val)
{

}

Vector::Vector(Vector &from)
{
    clear();
    capacity_ = from.capacity_;
    size_ = from.size_;
    data_ = make_unique<int[]>(capacity_);

    for (size_t i = 0; i < size_; ++i) {
        data_[i] = from.data_[i];
    }
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

#include "Vector.h"
#include <cassert>
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

Vector::Vector(size_t size, int value)
{
    expand_capacity(size);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}


Vector::Vector(int *begin, int *end)
{
    assert(begin != nullptr && end != nullptr);
    auto size = ((size_t)end - (size_t)begin ) / sizeof (int);
    expand_capacity(size);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = begin[i];
    }
}

// Vector(size) 用
void Vector::expand_capacity(size_t size)
{
    capacity_ = DEFAULT_CAPACITY;
    while (capacity_ <= size) {
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
    //auto ptr = make_unique<int[]>(capacity_ * DEFAULT_MULTIPLE);
    int *ptr = new int[capacity_ * DEFAULT_MULTIPLE];
    for (size_t i = 0; i < size_; ++i) {
        ptr[i] = data_[i];
    }
    data_.reset(ptr);
    capacity_ = capacity_ * DEFAULT_MULTIPLE;
}

void Vector::push_back(int val)
{
    if (capacity_ <= size_ + 1) {
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
        data_.reset(nullptr);
    }
}

Vector& Vector::operator=(const Vector &from)
{
    if (&from == this) {
        return *this;
    }
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

Vector::Iterator Vector::begin()
{
    Iterator iter;
    if (empty()) {
        iter.element_ = nullptr;
    }
    iter.element_ = &(data_[0]);
    return iter;
}

Vector::Iterator Vector::end()
{
    Iterator iter;
    if (empty()) iter.element_ = nullptr;
    iter.element_ = &(data_[size_]);
    return iter;
}

Vector::Iterator::Iterator()
{
}
Vector::Iterator::~Iterator()
{

}

int& Vector::Iterator::operator++()
{
    return *(++element_);
}
int Vector::Iterator::operator++(int)
{
    return *(element_++);
}

bool operator!=(const Vector::Iterator &l, const Vector::Iterator &r)
{
    return l.element_ != r.element_;
}

bool operator==(const Vector::Iterator &l, const Vector::Iterator &r)
{
    return l.element_ == r.element_;
}

int& Vector::Iterator::operator*()
{
    // TODO: end() 解引用
    // TODO: nullptr 解引用
    return *element_;
}



}   // namespace slib

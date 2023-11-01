#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory>
#include <cstddef>
#include <iostream>
#include <initializer_list>

namespace slib {
template <typename T>
class Vector{
public:
    Vector(size_t num, const T &val);
    Vector();
    ~Vector() {
        if (data_) {
            data_.reset();
        }
    }
    // 支持列表初始化
    Vector(std::initializer_list<T> list);
    Vector(const Vector &from);
    Vector& operator=(const Vector &from);
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    template <typename Y>
    friend std::ostream & operator<<(std::ostream &out, const Vector<Y> &vec);
    size_t size() const;
    size_t capacity() const;
    void push_back(const T &val);
    bool empty() const {return size_ == 0;}
    void clear();
    // TODO: 待实现
    Vector(T *begin, T *end);
    // 嵌套依赖
    class iterator{
    public:
        friend class Vector<T>;
        // 前置型
        iterator& operator ++();
        // 后置型
        iterator operator ++(int);
        T& operator *();
        bool operator ==(const iterator &from) const;
        bool operator !=(const iterator &from) const;
        // TODO: 待实现
        // 双向迭代
        // 随机迭代

    private:
        T *elem_;
    };

    iterator begin();
    iterator end();

    class const_iterator{
    public:
        friend class Vector<T>;
        // 前置型
        const_iterator& operator ++();
        // 后置型
        const_iterator operator ++(int);
        T operator *() const;
        bool operator ==(const const_iterator &from) const;
        bool operator !=(const const_iterator &from) const;
    private:
        const T *elem_;
    };
    const_iterator cbegin();
    const_iterator cend();

private:
    void expand();
    static constexpr auto DEFAULT_CAPACITY = 5;
    std::unique_ptr<T[]> data_;
    size_t size_;
    size_t capacity_;
};
}

#include "Vector.tpp"
#endif  // VECTOR_HPP_
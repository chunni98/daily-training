#ifndef VECTOR_TPP_
#define VECTOR_TPP_
namespace slib {
    template <typename T>
    Vector<T>::Vector(): capacity_(0),size_(0)
    {
        data_ = nullptr;
    }
    template <typename T>
    Vector<T>::Vector(size_t size, const T &val):capacity_(0),size_(0)
    {
        for (size_t i = 0; i < size; ++i) {
            push_back(val);
        }
        size_ = size;
    }

    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> list):size_(0), capacity_(0), data_(nullptr)
    {
        for (const auto &val : list) {
            push_back(val);
        }
        size_ = list.size();
    }

    template <typename T>
    size_t Vector<T>::size() const
    {
        return size_;
    }

    template <typename T>
    size_t Vector<T>::capacity() const
    {
        return capacity_;
    }

    template <typename T>
    void Vector<T>::expand()
    {
        if (capacity_ == 0) {
            capacity_ = DEFAULT_CAPACITY;
            data_.reset(new T[capacity_]);
        } else {
            capacity_ *= 2;
            auto pnew = std::make_unique<T[]>(capacity_);
            for (size_t i = 0; i < size_; ++i) {
                pnew[i] = data_[i];
            }
            data_ = std::move(pnew);
        }
    }
    template <typename T>
    std::ostream & operator<<(std::ostream &out, const Vector<T> &vec)
    {
        for (size_t i = 0; i < vec.size_; ++i) {
            out << vec.data_[i] << ' ';
        }
        return out;
    }

    template <typename T>
    void Vector<T>::push_back(const T &val)
    {
        if (size_ + 1 >= capacity_) {
            expand();
        }
        data_[size_] = val;
        size_++;
    }

    template <typename T>
    Vector<T>::Vector(const Vector<T> &from)
    {
        clear();
        capacity_ = from.capacity_;
        data_ = std::make_unique<T[]>(capacity_);
        for (size_t i = 0; i < from.size_; ++i) {
            data_[i] = from.data_[i];
        }
        size_ = from.size_;
    }

    template <typename T>
    const T& Vector<T>::operator[](size_t index) const
    {
        return data_[index];
    }

    template <typename T>
    T& Vector<T>::operator[](size_t index)
    {
        return data_[index];
    }

    template <typename T>
    void Vector<T>::clear()
    {
        if (data_)
            data_.reset();
        size_ = 0;
        capacity_ = 0;
    }

    template <typename T>
    Vector<T>& Vector<T>::operator=(const Vector<T> &from)
    {
        if (this == &from) {
            return *this;
        }
        clear();
        capacity_ = from.capacity_;
        data_ = std::make_unique<T[]>(capacity_);
        for (size_t i = 0; i < from.size_; ++i) {
            data_[i] = from.data_[i];
        }
        size_ = from.size_;
        return *this;
    }

    template <typename T>
    typename Vector<T>::iterator Vector<T>::begin()
    {
        typename Vector<T>::iterator iterator;
        iterator.elem_ = &data_[0];
        return iterator;
    }
    template <typename T>
    typename Vector<T>::iterator Vector<T>::end()
    {
        typename Vector<T>::iterator iterator;
        iterator.elem_ = &data_[size_];
        return iterator;
    }
    template <typename T>
    typename Vector<T>::const_iterator Vector<T>::cbegin()
    {
        typename Vector<T>::const_iterator iterator;
        iterator.elem_ = &data_[0];
        return iterator;
    }
    template <typename T>
    typename Vector<T>::const_iterator Vector<T>::cend()
    {
        typename Vector<T>::const_iterator iterator;
        iterator.elem_ = &data_[size_];
        return iterator;
    }

    template <typename T>
    typename Vector<T>::iterator& Vector<T>::iterator::operator ++()
    {
        elem_++;
        return *this;
    }
    template <typename T>
    typename Vector<T>::iterator Vector<T>::iterator::operator ++(int)
    {
        typename Vector<T>::iterator thiz = *this;
        elem_++;
        return thiz;
    }
    template <typename T>
    typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator ++()
    {
        elem_++;
        return *this;
    }
    template <typename T>
    typename Vector<T>::const_iterator Vector<T>::const_iterator::operator ++(int)
    {
        typename Vector<T>::const_iterator thiz = *this;
        elem_++;
        return thiz;
    }

    template <typename T>
    T& Vector<T>::iterator::operator *()
    {
        return *elem_;
    }
    template <typename T>
    T Vector<T>::const_iterator::operator *() const
    {
        return *elem_;
    }

    template <typename T>
    bool Vector<T>::iterator::operator!=(const typename Vector<T>::iterator &iter) const
    {
        return elem_ != iter.elem_;
    }
    template <typename T>
    bool Vector<T>::iterator::operator==(const typename Vector<T>::iterator &iter) const
    {
        return elem_ == iter.elem_;
    }
    template <typename T>
    bool Vector<T>::const_iterator::operator!=(const typename Vector<T>::const_iterator &iter) const
    {
        return elem_ != iter.elem_;
    }
    template <typename T>
    bool Vector<T>::const_iterator::operator==(const typename Vector<T>::const_iterator &iter) const
    {
        return elem_ == iter.elem_;
    }
}

#endif  // VECTOR_TPP_
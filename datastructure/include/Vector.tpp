namespace slib {
    template <typename T>
    Vector<T>::Vector(size_t size, const T &val)
    {
        expand(size);
        size_ = size;
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = val;
        }
    }

    template <typename T>
    void Vector<T>::expand(size_t size)
    {
        capacity_ = DEFAULT_CAPACITY;
        while (capacity_ <= size) {
            capacity_ *= 2;
        }
        data_ = std::make_unique<T[]>(capacity_);
    }

    template <typename T>
    std::ostream & operator<<(std::ostream &out, const Vector<T> &vec)
    {
        for (size_t i = 0; i < vec.size_; ++i) {
            out << vec.data_[i] << ' ';
        }
        out << std::endl;
        return out;
    }
}
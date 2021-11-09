#ifndef CPPWORKSHOPS_ARRAY2D_H
#define CPPWORKSHOPS_ARRAY2D_H

#include <iostream>
#include <vector>

template<class T, size_t ROW, size_t COLUMN>
class Array2D
{
    using value_type = T;
    using iterator = value_type*;
    using const_iterator = const value_type*;

public:
    Array2D() : array_(ROW*COLUMN) {}
    explicit Array2D(std::initializer_list<T> l) : array_(l) {}

    constexpr T* data() noexcept { return array_.data(); }
    //constexpr const T* data() noexcept const { return array_.data(); }

    constexpr T& at(const size_t r, const size_t c)
    {
        return array_.at(r*COLUMN + c);
    }

    constexpr const T& at(const size_t r, const size_t c) const
    {
        return array_.at(r*COLUMN + c);
    }

    constexpr T& operator()(const size_t r, const size_t c)
    {
        return at(r, c);
    }

    constexpr const T& operator()(const size_t r, const size_t c) const
    {
        return at(r, c);
    }

    constexpr bool empty() const noexcept { return ROW == 0 || COLUMN == 0; }

    constexpr size_t size(const int rank) const
    {
        if      (rank == 1) return ROW;
        else if (rank == 2) return COLUMN;

        throw std::out_of_range("Rank is out of range!");
    }

    void fill(const T& value)
    {
        std::fill(std::begin(array_), std::end(array_), value);
    }

    void swap(Array2D& other) noexcept
    {
        array_.swap(other.array_);
    }

    const_iterator  begin() const   { return array_.data(); }
    const_iterator  end() const     { return array_.data() + array_.size(); }
    iterator        begin()         { return array_.data(); }
    iterator        end()           { return array_.data() + array_.size(); }

private:
    std::vector<T> array_;
};

#endif //CPPWORKSHOPS_ARRAY2D_H

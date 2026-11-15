#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <ostream>

// Problem 3 (Dynamic Array 2.0) builds on your Problem 2 Dynarray.
// Start from your finished p2.cc, then add everything required by the
// handout:
//   - public type alias members (size_type, value_type, pointer, reference,
//     const_pointer, const_reference)
//   - subscript operator a[i] (like at(i), but no bounds checking)
//   - the six relational operators (lexicographical comparison,
//     no loops/recursions allowed)
//   - operator<< printing "[e1, e2, ...]"
class Dynarray
{
public:
  // Type alias members
  using size_type = std::size_t;
  using value_type = int;
  using pointer = value_type *;
  using reference = value_type &;
  using const_pointer = const value_type *;
  using const_reference = const value_type &;

private:
  size_type size_;
  int *data_;

public:
  // Initialization
  // Dynarray a;
  Dynarray() : size_(0), data_(nullptr) {}
  // Dynarray a(n);
  explicit Dynarray(size_type n)
      : size_(n), data_(n == 0 ? nullptr : new value_type[n]{}) {}
  // Dynarray a(n, x);
  Dynarray(size_type n, value_type x)
      : size_(n), data_(n == 0 ? nullptr : new value_type[n]{})
  {
    for (size_type i = 0; i < size_; i++)
    {
      data_[i] = x;
    }
  }
  // Dynarray a(begin, end);
  Dynarray(const int *begin, const int *end)
      : size_(begin == end ? 0 : static_cast<size_type>(end - begin)),
        data_(size_ == 0 ? nullptr : new value_type[size_])
  {
    for (size_type i = 0; i < size_; i++)
    {
      data_[i] = begin[i];
    }
  }
  // Copy-Initialization
  // Dynarray b = a;
  Dynarray(const Dynarray &other)
      : size_(other.size_),
        data_(size_ == 0 ? nullptr : new value_type[size_])
  {
    for (size_type i = 0; i < size_; i++)
    {
      data_[i] = other.data_[i];
    }
  }
  // Dynarray b = std::move(a);
  Dynarray(Dynarray &&other) noexcept
      : size_(other.size_), data_(other.data_)
  {
    other.size_ = 0;
    other.data_ = nullptr;
  }
  // Assignment
  // Copy-Assignment
  // b = a;
  Dynarray &operator=(const Dynarray &other)
  {
    if (this == &other)
    {
      return *this;
    }

    pointer new_data = other.size_ == 0 ? nullptr : new value_type[other.size_];
    // prepare the new data
    for (size_type i = 0; i < other.size_; i++)
    {
      new_data[i] = other.data_[i];
    }
    // release the old data first
    delete[] data_;
    data_ = new_data;
    size_ = other.size_;

    return *this;
  }
  // Move-Assignment
  // b = std::move(a);
  Dynarray &operator=(Dynarray &&other) noexcept
  {
    if (this == &other)
    {
      return *this;
    }

    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    // leaving a an empty dynamic array
    other.data_ = nullptr;
    other.size_ = 0;

    return *this;
  }
  // destructor
  ~Dynarray()
  {
    delete[] data_;
  }
  // returns the length of the "array"
  size_type size() const
  {
    return size_;
  }
  // returns a bool indicating whether the Dynarray is empty
  bool empty() const
  {
    return size_ == 0;
  }
  // returns a reference to the element indexed n, both readable and modifiable
  int &at(size_type i)
  {
    if (i >= size_)
    {
      throw std::out_of_range{"Dynarray index out of range!"};
    }

    return data_[i];
  }
  // returns a reference-to-const to the element indexed n, read-only
  const_reference at(size_type i) const
  {
    if (i >= size_)
    {
      throw std::out_of_range{"Dynarray index out of range!"};
    }

    return data_[i];
  }

  // a[i]
  reference operator[](size_type i)
  {
    return data_[i];
  }
  const_reference operator[](size_type i) const
  {
    return data_[i];
  }
  // <, <=, >, >=, == and !=
  bool operator==(const Dynarray &other) const
  {
    return std::equal(data_, data_ + size_, other.data_, other.data_ + other.size_);
  }
  bool operator<(const Dynarray &other) const
  {
    return std::lexicographical_compare(
        data_, data_ + size_,
        other.data_, other.data_ + other.size_);
  }
  bool operator!=(const Dynarray &other) const
  {
    return !(*this == other);
  }
  bool operator>(const Dynarray &other) const
  {
    return other < *this;
  }
  bool operator<=(const Dynarray &other) const
  {
    return !(other < *this);
  }
  bool operator>=(const Dynarray &other) const
  {
    return !(*this < other);
  }
};

inline std::ostream &operator<<(std::ostream &os, const Dynarray &a)
{
  os << '[';
  for (Dynarray::size_type i = 0; i < a.size(); i++)
  {
    if (i != 0)
    {
      os << ", ";
    }
    os << a[i];
  }
  os << ']';
  return os;
}

#endif // DYNARRAY_HPP

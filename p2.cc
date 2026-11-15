#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>

class Dynarray
{
private:
  std::size_t size_;
  int *data_;

public:
  // Initialization
  // Dynarray a;
  Dynarray() : size_(0), data_(nullptr) {}
  // Dynarray a(n);
  explicit Dynarray(std::size_t n)
      : size_(n), data_(n == 0 ? nullptr : new int[n]{}) {}
  // Dynarray a(n, x);
  Dynarray(std::size_t n, int x)
      : size_(n), data_(n == 0 ? nullptr : new int[n]{})
  {
    for (std::size_t i = 0; i < size_; i++)
    {
      data_[i] = x;
    }
  }
  // Dynarray a(begin, end);
  Dynarray(const int *begin, const int *end)
      : size_(begin == end ? 0 : static_cast<std::size_t>(end - begin)),
        data_(size_ == 0 ? nullptr : new int[size_])
  {
    for (std::size_t i = 0; i < size_; i++)
    {
      data_[i] = begin[i];
    }
  }
  // Copy-Initialization
  // Dynarray b = a;
  Dynarray(const Dynarray &other)
      : size_(other.size_),
        data_(size_ == 0 ? nullptr : new int[size_])
  {
    for (std::size_t i = 0; i < size_; i++)
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

    int *new_data = other.size_ == 0 ? nullptr : new int[other.size_];
    // prepare the new data
    for (std::size_t i = 0; i < other.size_; i++)
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
  std::size_t size() const
  {
    return size_;
  }
  // returns a bool indicating whether the Dynarray is empty
  bool empty() const
  {
    return size_ == 0;
  }
  // returns a reference to the element indexed n, both readable and modifiable
  int &at(std::size_t i)
  {
    if (i >= size_)
    {
      throw std::out_of_range{"Dynarray index out of range!"};
    }

    return data_[i];
  }
  // returns a reference-to-const to the element indexed n, read-only
  const int &at(std::size_t i) const
  {
    if (i >= size_)
    {
      throw std::out_of_range{"Dynarray index out of range!"};
    }

    return data_[i];
  }
};

#endif // DYNARRAY_HPP

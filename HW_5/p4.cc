#ifndef SMART_POINTERS_HPP
#define SMART_POINTERS_HPP 1

#include <cstddef>
#include <utility>

template <typename T>
class UniquePtr
{
private:
  T *ptr_;

public:
  // Construction
  //  UniquePtr<T> p;
  UniquePtr() : ptr_(nullptr) {}
  // UniquePtr<T> p(new T(...));
  explicit UniquePtr(T *ptr) : ptr_(ptr) {}
  // Copy Control
  UniquePtr(const UniquePtr &) = delete;
  UniquePtr &operator=(const UniquePtr &) = delete;
  // Move-Construction
  // UniquePtr<T> q = std::move(p);
  UniquePtr(UniquePtr &&other) noexcept : ptr_(other.ptr_)
  {
    other.ptr_ = nullptr;
  }
  // Move-Assignment
  // q = std::move(p);
  UniquePtr &operator=(UniquePtr &&other) noexcept
  {
    if (this == &other)
    {
      return *this;
    }

    delete ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
    return *this;
  }
  // destructor
  ~UniquePtr()
  {
    delete ptr_;
  }
  // Observation
  // *p
  T &operator*()
  {
    return *ptr_;
  }
  // *cp
  const T &operator*() const
  {
    return *ptr_;
  }
  // p->member
  T *operator->()
  {
    return ptr_;
  }
  const T *operator->() const
  {
    return ptr_;
  }
  // static_cast<bool>(p)
  explicit operator bool() const
  {
    return ptr_ != nullptr;
  }
  // p.get()
  T *get() const
  {
    return ptr_;
  }
  // Ownership manipulation
  // p.reset(q)
  void reset(T *ptr = nullptr)
  {
    if (ptr_ == ptr)
    {
      return;
    }

    delete ptr_;
    ptr_ = ptr;
  }
  // T *raw = p.release();
  T *release()
  {
    T *res = ptr_;
    ptr_ = nullptr;
    return res;
  }
};

template <typename T>
class SharedPtr
{
private:
  struct ControlBlock
  {
    T *ptr;
    std::size_t count;
  };
  ControlBlock *ctrl_;

  void release_current()
  {
    if (ctrl_ == nullptr)
    {
      return;
    }
    --ctrl_->count;
    if (ctrl_->count == 0)
    {
      delete ctrl_->ptr;
      delete ctrl_;
    }
    ctrl_ = nullptr;
  }

public:
  // SharedPtr<T> p;
  SharedPtr() : ctrl_(nullptr) {}
  // SharedPtr<T> p(new T(...));
  explicit SharedPtr(T *ptr) : ctrl_(nullptr)
  {
    if (ptr == nullptr)
    {
      return;
    }
    try
    {
      ctrl_ = new ControlBlock{ptr, 1};
    }
    catch (...)
    {
      delete ptr;
      throw;
    }
  }
  // SharedPtr<T> q = p;
  SharedPtr(const SharedPtr &other) : ctrl_(other.ctrl_)
  {
    if (ctrl_ != nullptr)
    {
      ++ctrl_->count;
    }
  }
  // SharedPtr<T> r = std::move(p);
  SharedPtr(SharedPtr &&other) noexcept : ctrl_(other.ctrl_)
  {
    other.ctrl_ = nullptr;
  }
  // Destruction
  ~SharedPtr()
  {
    release_current();
  }
  // q = p;
  SharedPtr &operator=(const SharedPtr &other)
  {
    ControlBlock *tmp = other.ctrl_;

    if (tmp != nullptr)
    {
      ++tmp->count;
    }

    release_current();
    ctrl_ = tmp;
    return *this;
  }
  // q = std::move(p);
  SharedPtr &operator=(SharedPtr &&other) noexcept
  {
    if (this == &other)
    {
      return *this;
    }

    release_current();
    ctrl_ = other.ctrl_;
    other.ctrl_ = nullptr;
    return *this;
  }
  T &operator*()
  {
    return *get();
  }
  const T &operator*() const
  {
    return *get();
  }
  T *operator->()
  {
    return get();
  }
  const T *operator->() const
  {
    return get();
  }
  explicit operator bool() const
  {
    return ctrl_ != nullptr;
  }
  T *get() const
  {
    return ctrl_ == nullptr ? nullptr : ctrl_->ptr;
  }
  std::size_t use_count() const
  {
    return ctrl_ == nullptr ? 0 : ctrl_->count;
  }
};

#endif // SMART_POINTERS_HPP

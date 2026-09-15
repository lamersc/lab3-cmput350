#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <utility>

// Your implementation here

template <typename T>
class UniquePtr {

public:
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) {
        raw_ptr = other.release();
    }

    UniquePtr& operator=(UniquePtr&& other) {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    UniquePtr() {};

    UniquePtr(T* ptr): raw_ptr(ptr) {};

    ~UniquePtr() {
        delete raw_ptr;
    }

    template <typename U>
    UniquePtr(UniquePtr<U>&& other) {
        raw_ptr = other.release();
    }

    T& operator*() const {
        return *raw_ptr;
    }

    T* operator->() const {
        return raw_ptr;
    }

    T* get() const {
        return raw_ptr;
    }

    bool operator==(const UniquePtr<T>& other) const {
        return raw_ptr == other.raw_ptr;
    }

    T* release() {
        T* rel_ptr = raw_ptr;
        raw_ptr = nullptr;
        return rel_ptr;
    }

    void reset(T* newPtr = nullptr) {
        if (raw_ptr != newPtr) {
            delete raw_ptr;
            raw_ptr = newPtr;
        }
    }

    void swap(UniquePtr<T>& other) {
        std::swap(raw_ptr, other.raw_ptr);
    }

    operator bool() const {
        return raw_ptr != nullptr;
    }

private:
    T* raw_ptr = nullptr;
};

template <typename T, typename... Args>
UniquePtr<T> makeUnique(Args&&... args)
{
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

#endif

#ifndef DOUBLYITERATOR_H
#define DOUBLYITERATOR_H

template<class doublyL>
class doublyIterator {
  public:
    using ItemType = typename doublyL::ItemType;
    using PtrType = ItemType*;
    using RefType = ItemType&;

  public:
    doublyIterator(PtrType pointer) : ptr(pointer) {}

    doublyIterator& operator++() {
      ptr++;
      return *this;
    }

    doublyIterator& operator++() {
      doublyIterator iterator = *this;
      ++(*this);
      return iterator;
    }
    doublyIterator& operator--() {
      ptr--;
      return *this;
    }

    doublyIterator& operator--() {
      doublyIterator iterator = *this;
      --(*this);
      return iterator;
    }
  private:
    PtrType ptr;
};
#endif // !DOUBLYITERATOR_H
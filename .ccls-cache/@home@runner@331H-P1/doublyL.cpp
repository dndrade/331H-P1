/*
    Program: Unordered doubly linked list
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  doubly linked list with insertion, deletion,
            search, and iterators.
*/

#include "doublyL.h"

template <class T> doublyL<T>::doublyL() { init(); }

template <class T> void doublyL<T>::init() {
  head = NULL;
  tail = NULL;
  length = 0;
}

template <class T> doublyL<T>::~doublyL() { destroy(); }

template <class T> doublyL<T>::doublyL(const doublyL<T> &other) {
  init();
  copy(other);
}

template <class T> doublyL<T> &doublyL<T>::operator=(const doublyL<T> &other) {
  if (this == &other) {
    return *this;
  }
  copy(other);

  return *this;
} // end of operator=

template <class T> void doublyL<T>::copy(const doublyL<T> &other) {
  length = other.length;

  if (other.head == NULL) {
    head = nullptr;
    tail = nullptr;
  } else {
    node *temp = other.head;
    while (temp != NULL) {
      insertBack(temp->data);
      temp = temp->next;
    }
  }
} // end of copy()

template <class T> void doublyL<T>::destroy() {
  node *p = head;
  while (p != nullptr) {
    node *delptr = p;
    p = p->next;
    delete delptr;
  }
  head = tail = nullptr;
} // end of destroy()

// inserting back
template <class T> void doublyL<T>::insertBack(T item) {
  length++;
  node *n = new node;
  n->data = item;
  n->next = nullptr;

  if (isEmpty()) {
    n->previous = nullptr;
    head = n;
    tail = n;
  } else {
    tail->next = n;
    n->previous = tail;
    tail = n;
  } // end of else
} // end of insertBack()

// inserting front
template <class T> void doublyL<T>::insertFront(T item) {
  node *n = new node;
  length++;
  n->data = item;
  n->previous = nullptr;
  if (isEmpty()) {
    // If list is empty, add the node  and update first and last
    n->next = nullptr;

    head = n;
    tail = n;
  } else {
    // If at least one node in the list, link new node
    // to old first and update first
    n->next = head;
    head->previous = n;
    head = n;
  }
} // end of insertFront()

template <class T> bool doublyL<T>::isEmpty() { return head == NULL; }

template <class T> int doublyL<T>::getLength() { return length; }

template <class T> void doublyL<T>::print() {
  if (head == NULL) {
    std::cout << "\nThe list is empty\n";
  } else {
    node *p = head;
    while (p != NULL) {
      std::cout << p->data << " ";
      p = p->next;
    }
  }
} // end of print()

template <class T> void doublyL<T>::deleteItem(T item) {
  node *itemSearch = search(item);
  length--;
  if (itemSearch == head) {
    // Do something it's the first node
    head = itemSearch->next;
    delete (itemSearch);
  } else if (itemSearch->next == nullptr) {
    // It's the last node
    itemSearch->previous->next = nullptr;
    delete (itemSearch);
  } else {
    // It's in the middle
    itemSearch->previous->next = itemSearch->next;
    itemSearch->next->previous = itemSearch->previous;
    delete (itemSearch);
  }
} // end of deleteItem();

template <class T> 
typename doublyL<T>::node *doublyL<T>::search(T item) {
  node *n = head;
  while (n != nullptr) {
    if (n->data == item) {
      found = true;
      return n;
    }
    n = n->next;
  }
  std::cerr << "Item is not in the list. \n";
  return nullptr;
} // end of search()

// Iterator nested class definition
template <class T> class doublyL<T>::iterator {
private:
  node *curr;

  iterator(node *p) { curr = p; }

public:
  friend class doublyL<T>;

  iterator() : curr(nullptr) {}

  iterator &operator++() {
    curr = curr->next;
    return *this;
  }
  iterator &operator++(int) {
    curr = curr->next;
    return *this;
  }

  iterator &operator--() {
    curr = curr->previous;
    return *this;
  }
  iterator &operator--(int) {
    curr = curr->previous;
    return *this;
  }
  bool operator!=(const iterator &other) const {
    return this->curr != other.curr;
  }
  const T &operator*() const { return curr->data; }
};
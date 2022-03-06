#include "doublyL.h"

template <class T> doublyL<T>::doublyL() {
  head = NULL;
  tail = NULL;
  length = 0;
  std::cout << "List's default constructor\n";
}

template <class T> doublyL<T>::~doublyL() {
  destroy();
  std::cout << "\nDestructor called\n";
}

template <class T> doublyL<T>::doublyL(const doublyL<T> &other) { copy(other); }

template <class T>
const doublyL<T> &doublyL<T>::operator=(const doublyL<T> &other) {
  if (this != &other) {
    destroy();
    copy(other);
  }
  return *this;
}

template <class T> void doublyL<T>::copy(const doublyL<T> &other) {
  length = other.length;

  if (other.head == NULL) {
    head = NULL;
    tail = NULL;
  } else {
    head = new node(other.head);
    node *otherTemp = other.head->next;
    node *tmp = head;

    while (otherTemp != NULL) {
      tmp->next = new node(otherTemp, NULL, tmp);
      tmp = tmp->next;
      otherTemp = otherTemp->next;
    }
    tail = tmp;
  }
}


template <class T> void doublyL<T>::destroy() {
  node *p = head;
  while (p != nullptr) {
    node *delptr = p;
    p = p->next;
    delete delptr;
  }
  head = tail = nullptr;
}

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
  }
  else {
    tail->next = n;
    n->previous = tail;
    tail = n;
  }// end of else
} // end of insertBack()

//  dl list -> F ____ B

// inserting front
template <class T> 
void doublyL<T>::insertFront(T item) {
  node *n = new node;
  length++;
  n->data = item;
  n->previous = nullptr;
  if(isEmpty()){
    // If our list is empty, we only need to add the node
    // and update first and last
    n->next = nullptr;

    head = n;
    tail = n;
  }
  else {
    // If we have atleast one node in our list, link our new node
    // to our old first and update first
    n->next = head;
    head->previous = n;
    head = n;
  }
}

template <class T> bool doublyL<T>::isEmpty() { return head == NULL; }

template <class T> int doublyL<T>::getLenght() { return length; }

template <class T> 
void doublyL<T>::print() {
  if (head == NULL) {
    std::cout << "\nThe list is empty\n";
  } else {
    std::cout << "\n\nList: ";
    node *p = head;

    while (p != NULL) {
      std::cout << p->data << " ";
      p = p->next;
    }
  }
} // end of print()

template <class T> 
void doublyL<T>::deleteItem(T item) {

  node *itemSearch = search(item);

  if (itemSearch == head){
    // Do something it's the first node
    head = itemSearch->next;
    delete(itemSearch);
  }
  else if (itemSearch->next == nullptr) {
    // It's the last node
    itemSearch->previous->next = nullptr;
    delete(itemSearch);
  }
  else {
    // It's in the middle
    itemSearch->previous->next = itemSearch->next;
    itemSearch->next->previous = itemSearch->previous;
    delete(itemSearch);
  }
}

template <class T> 
class doublyL<T>::node *doublyL<T>::search(T item) {
  node *n = head;
  while (n != nullptr) {
    if (n->data == item)
      return n;
    n = n->next;
  }
  std::cerr << "Item is not in the list. \n";
  return nullptr;
}
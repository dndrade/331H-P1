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

// review destroy later
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
  node *current; // pointer to walk the list
  // node* beforeCurrent; // previou to current
  node *newN = new node; // new node

  newN->data = item; // store the new item in the node
  newN->next = NULL;
  newN->previous = NULL;

  // if list is empty, newNode is the only node
  if (head == NULL) {
    head = newN;
    tail = newN;
    length++;
    std::cout << "Node has been inserted. (first node) \n";
  } else {
    current = head;

    head->previous = newN;
    newN->next = head;
    head = newN;
    length++;
    std::cout << "Node has been inserted at the back.\n";
  } // end of else
} // end of insertBack()

// inserting front
template <class T> 
void doublyL<T>::insertFront(T item) {
  node *newN = new node; // new node
  newN->data = item; // store the new item in the node
  newN->next = NULL;
  newN->previous = NULL;
  length++;
  
  if (head == NULL) {
    head = newN;
    std::cout << "\nNode has been inserted at the front.(First node)\n";
  }
  else {
    head->previous = newN;
    newN->next = head;
    head = newN;
    std::cout << "\nNode has been inserted at the front.\n";
  } // end of else
} // end of insertFront()

template <class T> bool doublyL<T>::isEmpty() { return head == NULL; }

template <class T> int doublyL<T>::getLenght() { return length; }

template <class T> void doublyL<T>::print() {
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
}

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
#include "doublyL.h"

template <class T> doublyL<T>::doublyL() {
  head = NULL;
  tail = NULL;
  length = 0;
  std::cout << "List's default constructor\n";
}

template <class T> doublyL<T>::~doublyL() {
  std::cout << "\nDestructor called\n";
  destroy();
  std::cout << "\nDestructor ended\n";
}

template <class T> 
doublyL<T>::doublyL(const doublyL<T> &other) { 
    std::cout << "Im in the copy constructor before if statement.\n";
  if (this != &other) {
    std::cout << "List is not equal to other\n";
    destroy();
    std::cout << "List has been distroyed\n";
    std::cout << "Im in the constructor and copy(other) will be called.\n";
    copy(other);
    std::cout << "List has been copied\n";
  }
  
}

template <class T>
doublyL<T> &doublyL<T>::operator=( doublyL<T> &other) {
  std::cout << "Im at operator= before if statement.\n";
  if (this != &other) {
    std::cout << "List is not equal to other\n";
    destroy();
    std::cout << "List has been distroyed\n";
    std::cout << "Im at operator= and copy(other) will be called.\n";
    copy(&other);
    std::cout << "List has been copied\n";
  }
  return *this;
} // end of operator=

template <class T> void doublyL<T>::copy(const doublyL<T> &other) {
  std::cout << "\nCopy, start\n";
  length = other.length;

  if (other.head == NULL) {
    std::cout << "\nCopy, Null";
    head = nullptr;
    tail = nullptr;
  }
  else {
    std::cout << "\nIm at copy's else statement";
    node* temp = other.head;
    std::cout << "\nGoing to while";
    while (temp != NULL) {
      std::cout << "\nabout to copy a node";
      insertBack(temp->data);
      std::cout << "\ncopied the node";
      temp = temp->next;
    }
  }
  std::cout << "\nabout to leave copy()";
} // end of copy()


template <class T> void doublyL<T>::destroy() {
  std::cout << "\nI'm at destroy";
  node *p = head; // this line is the problem
  std::cout << "\nI'm about to walk the thru the nodes";
  while (p != nullptr) {
    std::cout << "\nIm inside while loop";
    node *delptr = p;
    std::cout << "\nnode *delptr = p;";
    p = p->next;
    std::cout << "\np = p->next;";
    delete delptr;
    std::cout << "\ndelete delptr;";
  }
  std::cout << "\nhead = tail = nullptr";
  head = tail = nullptr;
  std::cout << "\nI'm about to leave destroy()";
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
  }
  else {
    tail->next = n;
    n->previous = tail;
    tail = n;
  }// end of else
} // end of insertBack()

//  dl list -> Front ____ Back

// inserting front
template <class T> 
void doublyL<T>::insertFront(T item) {
  node *n = new node;
  length++;
  n->data = item;
  n->previous = nullptr;
  if(isEmpty()){
    // If list is empty, add the node  and update first and last
    n->next = nullptr;

    head = n;
    tail = n;
  }
  else {
    // If at least one node in the list, link new node
    // to old first and update first
    n->next = head;
    head->previous = n;
    head = n;
  }
} // end of insertFront()

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
} // end of deleteItem();

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
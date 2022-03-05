#ifndef DOUBLYL_H
#define DOUBLYL_H

#include <iostream>

template<class T>
class doublyL {
  private:
    // node struct declaration
    /*template<class T>*/
    struct node {
        T data; // variable
        node* next; // next node pointer
        node* previous; // previous node pointer
        node() : data(NULL), next(NULL), previous(NULL) {}
        node(T item) : data( item ), next( nullptr ), previous( nullptr ) {}
    };

    node* head; // first node pointer
    node* tail; // last node pointer
    int length; // node counter


  public:
    doublyL(); // constructor
    ~doublyL(); // destructor

    doublyL(const doublyL<T>& other); // copy constructor
    const doublyL<T>& operator=(const doublyL<T>& other);
    void copy(const doublyL<T>& other);
    void destroy();
    bool isEmpty();
    int getLenght();

    void insertBack(T item);
    void insertFront(T item);
    void deleteItem(T item);
    node* search(T item);
    void print();

    // iterators
};
#endif // !DOUBLYL_H



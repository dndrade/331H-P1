/*
    Program: Unordered doubly linked list
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  doubly linked list with insertion, deletion,
            search, and iterators.
*/

#ifndef DOUBLYL_H
#define DOUBLYL_H

#include <iostream>

template<class T>
class doublyL {
  private:
    // node struct declaration
    struct node {
      T data; // item's date
      node* next; // next node pointer
      node* previous; // previous node pointer
      node(const T &item = T(), node* nxt = nullptr, node* prv = nullptr) : data( item ), next( nxt ), previous( nxt ) {} // node constructor
    };
  
    node* head; // first node pointer
    node* tail; // last node pointer
    int length; // node counter
    bool found = false; //
  
  public:
    doublyL(); // constructor
    ~doublyL(); // destructor
    void init(); // initialized member variables

    doublyL(const doublyL<T>& other); // copy constructor
    doublyL<T>& operator=(const doublyL<T>& other); // assignment operator
    void copy(const doublyL<T>& other); // copies the list
    void destroy(); // destroys the objects
    bool isEmpty(); // returns whether the list is empty
    int getLength(); // returns node count
    bool getFound() { return found == true; } // returns true if node is found
  
    void insertBack(T item); // inserts a item @ back of list
    void insertFront(T item); // inserts a item @ front of list
    void deleteItem(T item); // deletes a given item
    node* search(T item); // searches for a given item
    void print(); // outputs the list to the console
    class iterator; // Nested Iterator class declaration
  
    // iterators methods
    iterator begin() { return iterator(this->head); }
    iterator tend() { return iterator(this->tail); }
    iterator end() { return iterator(); }    
};
#endif // !DOUBLYL_H

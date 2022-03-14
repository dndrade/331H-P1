/*
    Program: Unordered doubly linked list
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  doubly linked list with insertion, deletion,
            search, and iterators.
*/

#ifndef NODE_H
#define NODE_H

#include <iostream> // Includes NULL and nullptr

template <class T>
struct node {
      T data; // item's date
      node* next; // next node pointer
      node* previous; // previous node pointer
      node(T item = (T)NULL, node<T> *prev = nullptr, node<T> *nxt = nullptr) : data(item), previous(prev), next(nxt) {} // node constructor
};
#endif
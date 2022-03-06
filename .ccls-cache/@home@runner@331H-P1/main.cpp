/*
    Program: unordered doubly linked list
    Student: Thamires Andrade
    Professor: Anna Salvati
    Description:  doubly linked list with insertion, deletion,
            and search.
*/

#include <iostream>
#include "doublyL.h"
#include "doublyL.cpp"

int main() {
  doublyL<int> l;

  l.insertBack(1);
  l.print();
  l.insertBack(10);
  l.print();
  l.insertBack(3);
  l.print();
  l.insertBack(2);
    
  l.print();
  l.deleteItem(3);
  l.print();

  l.insertFront(6);
  l.print();
  // l.begin();
  // l.end();


  std::cout << "\n\n Iterator \n";

  doublyL<int>::iterator itr = l.begin();
  while(itr != l.end()){
    std::cout << *itr << " ";
    itr++;
  }

    l.insertBack(2);
  
    while(itr != l.end()){
    std::cout << *itr << " ";
    itr++;
  }

  // currently, iterator doesn't show item in line 16
}
/*
    Program: unordered doubly linked list
    Student: Thamires Andrade
    Professor: Anna Salvati
    Description:  doubly linked list with insertion, deletion,
            search, an iterators
*/

#include <iostream>
#include "doublyL.h"
#include "doublyL.cpp"

int main() {
  doublyL<int> l;

  l.insertBack(1);
 
  l.insertBack(10);
  l.insertBack(3);
  l.insertBack(2);
    
  l.print();
  l.deleteItem(3);
  l.print();
  l.getHead();

  l.insertFront(6);
  l.print();
  // l.begin();
  // l.end();
  // l.insertBack(2);
  // l.insertFront(9);
  // l.insertFront(5);
  // l.print();
  // l.getHead();
  // l.front();
  // l.back();
  // std::cout << "\n\n List two (copy of l) \n";
  // doublyL<int> lTwo;
  // lTwo.copy(l);
  // lTwo.print();

  // doublyL<int> p(l);
  // p.print();

  // doublyL<int> p = l;
  // p.print();

  // std::cout << "\n\n Iterator \n";

  std::cout << "ITERATOR" << std::endl;
  doublyL<int>::iterator itr = l.tend();
  while(itr != l.end()){
    std::cout << *itr << " ";
    --itr;
  }
  // doublyL<int>::iterator iter = l.begin();
  // while(iter != l.end()){
  //   std::cout << *iter << " ";
  //   ++iter;
  // }

  
}
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

  l.insertFront(6);
  l.print();
}
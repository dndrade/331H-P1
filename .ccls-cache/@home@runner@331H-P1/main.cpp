/*
    Program: Unordered doubly linked list
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  doubly linked list with insertion, deletion,
            search, and iterators.
*/

#include "doublyL.cpp"
#include <iostream>

void mainMenu();

int main() {
  doublyL<int> l; // list objects
  int choice = 0; // menu choice input 
  int item; // list item

  while (choice != 9) {
    mainMenu();
    std::cout << "\n\nEnter your choice(int): ";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "\nCurrent List: ";
        l.print();
        std::cout << "\nEnter an int for insertion: ";
        std::cin >> item;
        l.insertFront(item);
        break;
      case 2:
        std::cout << "\nCurrent List: ";
        l.print();
        std::cout << "\nEnter an int for insertion: ";
        std::cin >> item;
        l.insertBack(item);
        break;
      case 3:
        std::cout << "\nCurrent List: ";
        l.print();
        std::cout << "\nEnter an int for deletion: ";
        std::cin >> item;
        l.deleteItem(item);
        break;
      case 4:
        std::cout << "\nEnter an int to search: ";
        std::cin >> item;
        l.search(item);
        if (l.getFound()) {
          std::cout << "\n      "<< item << " is in the list!";
        }
        break;
      case 5: {
        std::cout << "\nList: ";
        iterator<int> iter = l.begin();
          while(iter != l.end()){
            std::cout << *iter << " ";
            ++iter;
          }
        break;
      }
      case 6: {
        std::cout << "\nList: ";
        iterator<int> itr = l.tend();
        while(itr != l.end()){
          std::cout << *itr << " ";
          --itr;
        }
        break;
      }
      case 7: {
        std::cout << "\nFirst List: ";
        l.print();
        doublyL<int> d(l);
        std::cout << "\nSecond list: ";
        d.print();
        break;
      }
      case 8: {
        std::cout << "\nFirst List: ";
        l.print();
        doublyL<int> p = l;
        std::cout << "\nSecond list: ";
        p.print();
        break;
      }
      case 9:
        return 0;
      }
  }
}

void mainMenu() {
  std::cout << "\n\n--------------------------------\n";
  std::cout << "-           Main Menu          -";
  std::cout << "\n--------------------------------\n";

  std::cout << "1. Insert front";
  std::cout << "\n2. Insert back";
  std::cout << "\n3. Delete an item";
  std::cout << "\n4. Search for an item";
  std::cout << "\n5. Iterate (Front to back)";
  std::cout << "\n6. Iterate (Back to front)";
  std::cout << "\n7. Copy constructor";
  std::cout << "\n8. Assignment operator (copy)";
  std::cout << "\n9. Exit";
}
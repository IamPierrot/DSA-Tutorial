#include "LinkedList.h"

class Stack
{
private:
     LinkedList<int> *list;
     int size;

public:
     Stack(): size(list->getSize()), list(new LinkedList<int>()) {}
     
     void push(const int &data)
     {
          list->push(data);
     }
     
     int top()
     {
        return list->top()->data;  
     }
     
     int getSize()
     {
          return list->getSize();
     }
     void display()
     {
          std::cout << list;
     }
};
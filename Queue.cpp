#include <iostream>

class Queue
{
private:
     struct Node
     {
          int data;
          Node(int data): data(data) {}
     };
     
public:
     Queue(/* args */)
     {

     }

     void push(int data) 
     {
     }

     bool isEmpty()
     {
          return this == nullptr;
     }
     
     ~Queue();
};


int main()
{

     return 0;
}

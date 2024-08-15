#include <iostream>

class Node
{
public:
     int data;
     Node *left;
     Node *right;

     
};

Node *newNode(int data)
{
     Node *node = new Node;
     node->data = data;
     node->left = nullptr;
     node->right = nullptr;
     return node;
}

void insertNode(Node *&node, int data)
{
     if (node == nullptr)
     {
          node = newNode(data);
          return;
     }

     if (data > node->data)
          insertNode(node->right, data);
     else if (data < node->data)
          insertNode(node->left, data);
     else return;
}

Node *findMaxDataInTree(Node *node)
{
     if (node == nullptr)
          return nullptr;
     else
     {

          Node *leftNode = findMaxDataInTree(node->left);
          Node *rightNode = findMaxDataInTree(node->right);

          Node *maxNode = node;
          if (leftNode != nullptr && leftNode->data > maxNode->data)
               maxNode = leftNode;
          if (rightNode != nullptr && rightNode->data > maxNode->data)
               maxNode = rightNode;

          return maxNode;
     }
}

void printTree(Node *node, int level = 0)
{
     if (node == nullptr)
     {
          std::cout << "Level: " << level << ": <empty>" << std::endl;
          return;
     }

     Node *leftNode = node->left;
     Node *rightNode = node->right;

     std::cout << "Level: " << level << ": " << node->data << " - ";

     if (leftNode != nullptr)
          std::cout << "Left: " << leftNode->data << " - ";
     if (rightNode != nullptr)
          std::cout << "Right: " << rightNode->data << std::endl;
     else
          std::cout << std::endl;

     printTree(leftNode, level + 1);
     printTree(rightNode, level + 1);
}

int FatTree()
{

     Node *root = newNode(2);
     root->left = newNode(3);
     root->right = newNode(4);
     root->left->right = newNode(10);

     insertNode(root, 5);
     insertNode(root, 1);
     printTree(root);

     return 0;
}
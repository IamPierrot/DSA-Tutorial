#pragma once

#include <iostream>
class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node *left;
		Node *right;
		Node(const int &data) : data(data), left(nullptr), right(nullptr)
		{
		}
	};
	void insertRecursive(const int &data, Node *&currentNode)
	{
		if (data == currentNode->data)
			throw std::invalid_argument("error! similar data!");
		if (data < currentNode->data)
		{
			if (currentNode->left == nullptr)
				currentNode->left = new Node(data);
			else
				insertRecursive(data, currentNode->left);
		}
		else
		{
			if (currentNode->right == nullptr)
				currentNode->right = new Node(data);
			else
				insertRecursive(data, currentNode->right);
		}
	}
	Node *getMaxNodeRecursive(Node *&currentNode)
	{
		if (currentNode == nullptr)
			return nullptr;
		Node *leftNode = getMaxNodeRecursive(currentNode->left);
		Node *rightNode = getMaxNodeRecursive(currentNode->right);

		Node *maxNode = currentNode;
		if (leftNode != nullptr && leftNode->data > maxNode->data)
			maxNode = leftNode;
		else if (rightNode != nullptr && rightNode->data > maxNode->data)
			maxNode = rightNode;

		return maxNode;
	}

	int getMaxDepthNodeRecursive(Node *&currentNode)
	{
		if (currentNode == nullptr)
			return 0;
		int leftDepth = getMaxDepthNodeRecursive(currentNode->left);
		int rightDepth = getMaxDepthNodeRecursive(currentNode->right);

		if (leftDepth > rightDepth)
			return leftDepth + 1;
		else
			return rightDepth + 1;

	}

public:
	Node *root;

	BinaryTree() : root(nullptr)
	{
	}

	void insert(const int &data)
	{
		Node *newNode = new Node(data);

		if (isEmpty())
			root = newNode;
		else
			insertRecursive(data, root);
	}

	bool isEmpty() const
	{
		return root == nullptr;
	}

	Node *getMaxNodeData()
	{
		if (isEmpty())
			return nullptr;
		else
			return getMaxNodeRecursive(root);
	}

	int getMaxDepth()
	{
		if (isEmpty())
			return 0;
		else
			return getMaxDepthNodeRecursive(root);
	}

	friend std::ostream &operator<<(std::ostream &stream, const BinaryTree *tree)
	{
		int level = 0;
		Node *currentNode = tree->root;

		while (currentNode != nullptr)
		{
			
		}

		if (node == nullptr || tree->isEmpty())
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
	}
};
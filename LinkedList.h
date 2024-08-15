#pragma once

#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;

        Node(const T &data) : data(data), prev(nullptr), next(nullptr)
        {
        }
    };
    Node *first;
    Node *last;

    int size;

public:
    LinkedList() : first(nullptr), last(nullptr), size(0)
    {
    }
    LinkedList(const T &data)
    {
        Node *newNode = new Node(data);
        first = last = newNode;
        size = 1;
    };

    void push(const T &data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
        size++;
    }
    T pop()
    {
        if (isEmpty())
            throw std::runtime_error("List is empty!");
        T tempData;

        if (first == last)
        {
            tempData = first->data;
            delete first;
            first = last = nullptr;
        }
        else
        {
            tempData = last->data;
            auto temp = last->prev;
            delete last;
            last = temp;
            last->next = nullptr;
        }

        size--;
        return tempData;
    }

    T &get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of list");
        }
        Node *current = first;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }
    Node *top()
    {
        return last;
    }

    void clear()
    {
        Node *current = first;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        first = last = nullptr;
        size = 0;
    }

    bool isEmpty() const
    {
        return first == nullptr;
    }

    int getSize() const
    {
        return size;
    }

    // Định nghĩa operator[] để trả về tham chiếu đến phần tử tại vị trí index
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        Node *current = first;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    // Phiên bản const của operator[] để sử dụng với các đối tượng const
    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        Node *current = first;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    friend std::ostream &operator<<(std::ostream &stream, const LinkedList<T> *node)
    {
        std::string result = "[";
        if (node->isEmpty())
        {
            result += "]";
            stream << result << std::endl;
            return stream;
        }
        else
        {
            for (int i = 0; i < node->getSize(); i++)
            {
                if constexpr (std::is_same_v<T, std::string>)
                    result += "\"" + node->get(i) + "\"" + ", ";
                else if constexpr (std::is_same_v<T, char>)
                    result += '\'' + std::string(1, node->get(i)) + '\'' + ", ";
                else 
                    result += std::to_string(node->get(i)) + ", ";
            }
            result.pop_back();
            result.pop_back();

            result += "]";
            stream << result << std::endl;
            return stream;
        }
    }

    ~LinkedList()
    {
        clear();
    };
};

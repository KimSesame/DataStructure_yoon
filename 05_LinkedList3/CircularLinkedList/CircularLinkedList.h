#ifndef __CIRCULARLINKEDLIST_H__
#define __CIRCULARLINKEDLIST_H__

template <typename T>
class Node
{
private:
    T data;
    Node *next;

    template <typename _T> friend class CircularList;

public:
    Node(T data) : data(data) {}
};

template <typename T>
class CircularList
{
private:
    Node<T>* tail;

public:
    CircularList();
    Node<T>* search(T data);
    void append(T data);
    void print();
    T del(T data);
    ~CircularList();

};

#include "CircularLinkedList.hpp"
#endif
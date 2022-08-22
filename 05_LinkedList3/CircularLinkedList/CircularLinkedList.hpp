#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

template <typename T>
CircularList<T>::CircularList()
{
    tail = nullptr;
}

template <typename T>
Node<T> *CircularList<T>::search(T data)
{
    Node<T> *cur_node = tail;

    do
    {
        if (cur_node->data == data)
            return cur_node;

        cur_node = cur_node->next;
    } while (cur_node != tail);

    return nullptr;
}

template <typename T>
void CircularList<T>::append(T data)
{
    Node<T> *new_node = new Node<T>(data);

    if (tail == nullptr)
    {
        tail = new_node;
        tail->next = tail;
        return;
    }

    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;

    return;
}

template <typename T>
void CircularList<T>::print()
{

    Node<T> *cur_node = tail;

    do
    {
        cur_node = cur_node->next;
        cout << cur_node->data << " ";
    } while (cur_node != tail);
    cout << endl;

    return;
}

template <typename T>
T CircularList<T>::del(T data)
{
    Node<T> *cur_node = tail;
    Node<T> *prev_node = nullptr;
    Node<T> *del_node = nullptr;
    T del_data;

    // Find Location
    do
    {
        if (cur_node->next->data == data)
        {
            del_node = cur_node->next;
            prev_node = cur_node;
            break;
        }

        cur_node = cur_node->next;
    } while (cur_node != tail);
    del_data = del_node->data;

    // Delete
    if (del_node == nullptr)
        return 0;

    if (del_node == tail)
    {
        if (prev_node == tail)
            tail = nullptr;
        else
            tail = prev_node;
    }

    prev_node->next = del_node->next;
    delete del_node;

    return del_data;
}

template <typename T>
CircularList<T>::~CircularList()
{
    if (tail == nullptr)
        return;

    while (tail)
        del(tail->data);
}
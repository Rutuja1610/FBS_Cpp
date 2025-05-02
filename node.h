#pragma once

#include "book.h"
template <class T>
class Node {
public:
    T data;
    Node* next;

    // Constructor
    Node(const T& data) : data(data), next(nullptr) {}
};

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stack>

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List();
    ~List();

    void push_back(int value);
    void print();

    class reverse_iterator {
    private:
        std::stack<Node*> my_stack;

    public:
        reverse_iterator(Node* head, Node* node = nullptr);
        reverse_iterator operator++();
        bool operator!=(const reverse_iterator& other) const;
        int& operator*();
    };

    reverse_iterator rbegin();
    reverse_iterator rend();
};

#endif // LIST_H


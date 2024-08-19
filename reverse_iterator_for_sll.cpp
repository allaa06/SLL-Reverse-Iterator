#include "reverse_iterator_for_sll.h"

List::List() : head(nullptr) {}

List::~List() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::push_back(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void List::print() {
    Node* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

List::reverse_iterator::reverse_iterator(Node* head, Node* node) {
    Node* curr = head;
    while (curr != node) {
        my_stack.push(curr);
        curr = curr->next;
    }
}

List::reverse_iterator List::reverse_iterator::operator++() {
    if (!my_stack.empty()) {
        my_stack.pop();
    }
    return *this;
}

bool List::reverse_iterator::operator!=(const reverse_iterator& other) const {
    return my_stack != other.my_stack;
}

int& List::reverse_iterator::operator*() {
    return my_stack.top()->val;
}

List::reverse_iterator List::rbegin() {
    return reverse_iterator(head);
}

List::reverse_iterator List::rend() {
    return reverse_iterator(nullptr);
}



#pragma once
#include <iostream>
using namespace std;

template<typename O>
class Node {
public:
    O ch;
    Node* nextCh;

    Node(O c) : ch(c), nextCh(nullptr) {}
};

template<typename O>
class STACK {
    Node<O>* head;
    int siz;

public:
    STACK() : siz(0), head(nullptr) {}

    void push(O c) {
        Node<O>* newCh = new Node<O>(c);
        if (head == NULL) {
            head = newCh;
            siz++;
            return;
        }

        newCh->nextCh = head;
        head = newCh;
        siz++;
    }

    void pop() {
        if (head) {
            Node<O>* temp = head;
            head = head->nextCh;
            delete temp;
            siz--;
        }
        else {
            cout << "| !  STACK UNDERFLOW ! |" << endl;
        }
    }
    bool empty() const {
        return head == nullptr;
    }

    O top() {
        return head->ch;
    }

    int size() const {
        return siz;
    }
};
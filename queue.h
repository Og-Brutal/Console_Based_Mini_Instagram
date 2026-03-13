#pragma once
#include<iostream>
using namespace std;
template<typename O>
struct Qnode {
    O data;
    Qnode* next;
    Qnode(O data) {
        this->data = data;
        next = NULL;
    }
};

template<typename O>
class Queue {
private:
    Qnode<O>* front;
    Qnode<O>* rear;
    int size;
public:
    Queue() {
        size = 0;
        front = NULL;
        rear = NULL;
    }
    int getSize() {
        return this->size ;
    }
    O getFront() {
        return (front->data);
    }
    O getRear() {
        return (rear->data);
    }
    bool isEmpty() { return (front == NULL); }
    void enqueue(O input)
    {
        if (isEmpty()) {
            front = rear = new Qnode<O>(input);
            size++;
            return;
        }
        else if (rear->next == front) {
            cout << "<< OVERFLOW >>" << endl;
        }
        else {
            Qnode<O>* newN = new Qnode<O>(input);
            rear->next = newN;
            rear = newN;
            size++;
            return;
        }
    }
    void dequeue() 
    {
        if (isEmpty()) {
            cout << "<< UNDERFLOW >>" << endl;
            return;
        }
        else if (front == rear) {
            delete front;
            front = NULL;
            rear = NULL;
            size--;
            return;
        }
        else {
            Qnode<O>* temp = front;
            front = front->next;
            delete temp;
            temp = NULL;
            size--;
            return;
        }
    }
    Qnode<O>* getQueue() {
        return front;
    }
    void printQueue() {
        if (!isEmpty()) {
            Qnode<O>* temp = front;
            while (temp != NULL) {
                cout << "\t\t\t\t      " << temp->data  << endl;
                temp = temp->next;
            }
        }
        else {
            cout << "\n\t\t\t\t            " << "<< No Message Yet >>" << endl;
        }
    }
};
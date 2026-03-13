#pragma once
#include<iostream>
#include<string>
#include"queue.h"
using namespace std;
class Cnode 
{
public:
	string person;
	Queue<string> messages;
	Cnode* nextBox;
	Cnode(string person):person(person),nextBox(NULL){}
};
class MessageSection 
{
	Cnode* savedPerson;
	Cnode* chatBox;
	int size;
public:
	MessageSection(): size(0),savedPerson(new Cnode("null")), chatBox(NULL) {}
	void push(string name) 
	{
		Cnode* newBox = new Cnode(name);
		if (chatBox == NULL) {
			chatBox = newBox;
			size++;
			return;
		}

		newBox->nextBox= chatBox;
		chatBox = newBox;
		size++;
	}
	void pop() {
		if (chatBox) {
			Cnode* temp = chatBox;
			chatBox = chatBox->nextBox;
			delete temp;
			size--;
		}
		else {
			cout << "| !  STACK UNDERFLOW ! |" << endl;
		}
	}
	void pushRecentFirst() {
		savedPerson->nextBox = chatBox;
		chatBox = savedPerson;
		savedPerson = new Cnode("");
	}
	void placeAtFront(string recPerson) {
		if (chatBox == NULL) 
		{
			return;
		}
		if (chatBox->person == recPerson)
		{
			savedPerson->person = chatBox->person;
			while (!chatBox->messages.isEmpty()) {
				savedPerson->messages.enqueue(chatBox->messages.getFront());
				chatBox->messages.dequeue();
			}
			pop();
			return;
		}
		Cnode* temp2 = new Cnode(chatBox->person);
		while (!chatBox->messages.isEmpty()) {
			temp2->messages.enqueue(chatBox->messages.getFront());
			chatBox->messages.dequeue();
		}
		pop();
		placeAtFront(recPerson);
		againPush(temp2);
	}
	void againPush(Cnode* obj) {
		if (!chatBox) {
			chatBox = obj;
		}
		else {
			obj->nextBox = chatBox;
			chatBox = obj;
		}
	}
	bool searchStack(string recPerson)
	{
		if (chatBox != NULL) {
			Cnode* temp = chatBox;
			while (temp != NULL) {
				if (temp->person == recPerson) {
					return true;
				}
				temp = temp->nextBox;
			}
		}
		return false;
	}
	void sendMessage(string message) {
		chatBox->messages.enqueue(message);
	}
	bool printChatBox() {
		bool check = true;
		if (chatBox) {
			Cnode* temp = chatBox;
			while (temp) {
				cout << "\t\t\t\t      " << " - > " << temp->person <<"." << endl;
				temp = temp->nextBox;
			}
		}
		else {
			cout << "\t\t\t\t             " << "<< No Chat Box Yet >>" << endl;
			check = false;
		}
		return check;
	}
	bool printSpecificChat(string name) {
		system("cls");
		cout << "\t\t\t\t      " << "----------------------------------" << endl;
		cout << "\t\t\t\t      " << "|          Personal Chat         |" << endl;
		cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
		Cnode* temp = chatBox;
		bool check = false;
		while (temp) {
			if (temp->person == name) {
				check = true;
				break;
			}
			temp = temp->nextBox;
		}
		if (check) {
			temp->messages.printQueue();
		}
		else {
			cout << "\t\t\t\t    " << "<< Sorry! 'No Chat Box with This Name' >>" << endl;
		}
		return check;
	}
};
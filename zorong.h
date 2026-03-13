#pragma once
#include<iostream>
#include<string>
#include"Vertex.h"
using namespace std;
class Vertex;
class Node {
public:
	// NODE CONTAINS
	Vertex* user;
	int height;
	Node* left, * right;
	// INITIALIZER LIST(constructer)
	Node(Vertex* data) {
		user = data;
		height = 1;
		left = NULL;
		right = NULL;
	}
};
// GETTING HEIGHT OF ROOTS BY APPLY CONDION IF EXIST THEN RETURN
int getHeight(Node* root) {
	if (!root) {
		return 0;
	}
	return root->height;
}

// FUNCTION TO GIVE DIFFERNCE OF HEIGHT OF LEFT AND RIGHT
int checkBalance(Node* root) {
	return (getHeight(root->left) - getHeight(root->right));
}

// ROTATING NODE LEFT
Node* leftRotation(Node* root)
{
	// child is midddle node
	Node* child = root->right;
	//saiving left child of middle node
	Node* childLeft = child->left;
	child->left = root;
	root->right = childLeft;

	//updating height of both root and middle node
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	child->height = 1 + max(getHeight(child->left), getHeight(child->right));

	//returing child as root
	return child;
}
class BST
{
private:
	Node* root;
	// ROTATING NODE RIGHT
	Node* rightRotation(Node* root) {
		// child is midddle node
		Node* child = root->left;
		//saiving right child of middle node
		Node* childRight = child->right;
		child->right = root;
		root->left = childRight;

		//updating height of both root and middle node
		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		child->height = 1 + max(getHeight(child->left), getHeight(child->right));

		//returing child as root
		return child;
	}
	Node* insertion(Node* root, Vertex* data) {
		// SIMPLE INSERTION
		if (!root) {
			return new Node(data);
		}
		else if (data->name < root->user->name) {
			root->left = insertion(root->left, data);
		}
		else if (data->name > root->user->name) {
			root->right = insertion(root->right, data);
		}
		// FOR BALANCING NODES

		//UPDATING HEIGHT OF ROOT AFTER EVERY INSERTION 
		root->height = 1 + max(getHeight(root->left), getHeight(root->right));

		//CHECKING NODE BALANACE OR NOT(left_hieght-right_height)
		int _isBalance;
		_isBalance = checkBalance(root);


		// LEFT_LEFT CASE
		if (_isBalance > 1 && data->name < root->left->user->name) { // RIGHT ROTATION
			return rightRotation(root);
		}
		// RIGHT_RIGHT CASE
		else if (_isBalance<-1 && data->name > root->right->user->name) { // LEFT ROTAION
			return leftRotation(root);
		}
		// LEFT_RIGHT CASE
		else if (_isBalance > 1 && data->name > root->left->user->name) { // LEFT ROTAION THEN RIGHT ROTATION
			root->left = leftRotation(root->left);
			return rightRotation(root);
		}
		// RIGHT_LEFT CASE
		else if (_isBalance < -1 && data->name < root->right->user->name) { // RIGHT ROTAION THEN LEFT ROTATION
			root->right = rightRotation(root->right);
			return leftRotation(root);
		}
		else {
			return root;
		}
	}
	void binarySearch(Node* root, string name, bool& check) {
		if (!root) {
			return;
		}
		if (root->user->name == name) {
			check = false;
			cout << "\t\t\t\t            " << "<< Search Found >>" << endl;
			cout << "\n\t\t\t\t      " << "User Name : " << root->user->name << "\n";
			cout << "\t\t\t\t      " << "City : " << root->user->city << "\n";
			string sub = root->user->lastLoginTimeStamp.substr(0, 10);
			cout << "\t\t\t\t      " << "Last Login Date: " << sub << endl;
			sub = root->user->lastLoginTimeStamp.substr(11, root->user->lastLoginTimeStamp.length());
			cout << "\t\t\t\t      " << "Last Login Date: " << sub << endl;
			return;
		}
		binarySearch(root->left, name,check);
		binarySearch(root->right, name,check);
	}
public:
	BST() : root(NULL) {}
	void insertInBst(Vertex* obj)
	{
		root = insertion(root, obj);
	}
	void search(string searchedName) {

		if (root == NULL) {
			cout << "\t\t\t\t            " << "<< No Search Found >>" << endl;
			return;
		}
		bool check = true;
		binarySearch(root, searchedName, check);
		if (check) {
			cout << "\t\t\t\t            " << "<< No Search Found >>" << endl;
		}
	}
};
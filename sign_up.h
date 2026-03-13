//#pragma once
//#include<iostream>
//#include<string>
//using namespace std;
//class Snode {
//public:
//	string name;
//	string password;
//	string city;
//	Snode* next;
//	Snode(string name,string pass,string city): name(name) ,password(pass),city(city),next(NULL){}
//};
//class SignUpList {
//	Snode* dataBase;
//public:
//	SignUpList() : dataBase(NULL){}
//	bool uniqueName(string name) {
//		if (!dataBase) {
//			return true;
//		}
//		else {
//			Snode* current = dataBase;
//			while (current) {
//				if (current->name == name) {
//					return false;
//				}
//				current = current->next;
//			}
//			return true;
//		}
//	}
//	string getCity(string name, string pass) {
//		Snode* current = dataBase;
//		while (current) {
//			if (current->name == name && current->password == pass) {
//				return current->city;
//			}
//			current = current->next;
//		}
//		return "";
//	}
//	void signUp(string name, string pass, string city) {
//		if (uniqueName(name)) 
//		{
//			if (!dataBase) {
//				dataBase = new Snode(name, pass, city);
//				cout << "<< you are signed in >>" << endl;
//				return;
//			}
//			Snode* newUser = new  Snode(name, pass, city);
//			newUser->next = dataBase;
//			dataBase = newUser;
//			cout << "<< you are signed in >>" << endl;
//		}
//		else
//		{
//			cout << "<< this name is taken >>" << endl;
//		}
//	}
//	bool search(string name, string pass) {
//		Snode* current = dataBase;
//		while (current) {
//			if (current->name == name && current->password == pass) {
//				return true;
//			}
//			current = current->next;
//		}
//		return false;
//	}
//};

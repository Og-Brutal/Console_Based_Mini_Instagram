#pragma once
#include<iostream>
#include<string>
#include <cctype> 
using namespace std;
class ErrorHabdler
{
public:
	int intChecker() {
		int x;
		while (!(cin >> x)) {
			cout << "\t\t\t\t                 " << "CHOICE AGAIN : ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return x;
	}
	string checkEmpty() {
		string any;
		getline(cin, any);
		while (any.empty()) {
			cout << "\t\t\t\t            " << "Plz! Fill This Section : ";
			getline(cin, any);
		}
		return any;
	}
	string checkPassword(string pass) {
		while (pass.length() < 4) {
			cout << "\t\t\t\t            " << "Password Must Contain 4 Letters : ";
			getline(cin, pass);
		}
		return pass;
	}
};
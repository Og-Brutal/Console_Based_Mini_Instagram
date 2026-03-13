#pragma once
#include<iostream>
#include"Post.h"
#include"queue.h"
#include"MessageSection.h"
#include"zorong.h"
#include"Vertex.h"
#include<vector>
#include<string>
using namespace std;
class Users 
{
	vector<Vertex> user_profiles;
	int currentUser;
	BST searchEngine;
public:
	Users()  {}
	 bool uniqueName(string name) {
		 if (user_profiles.size() != 0) {
			 for (int i = 0; i < user_profiles.size(); i++) {
				 if (user_profiles[i].name == name) {
					 return false;
				 }
			 }
		 }
		 else {
			 return true;
		 }
		 return true;
	 }
	void signUp(string name, string password, string city) {
		while (!uniqueName(name)) {
			cout << "\n\t\t\t\t     " << "! This Name Is Taken! 'Try Aother' !" << endl;
			cout << "\t\t\t\t            "<< "ENTER NEW NAME : ";
			getline(cin, name);
		}
		user_profiles.push_back({ name,password,city });
		Vertex *obj=new Vertex(name, password, city);
		searchEngine.insertInBst(obj);
	}
	int isExist(string name,string password) {
		for (int i = 0; i < user_profiles.size(); i++) {
			if (user_profiles[i].name == name && user_profiles[i].password==password) {
				user_profiles[i].lastLoginTimeStamp = getCurrentTime();
				return i;
			}
		}
		return -1;
	}
	bool logIn(string name, string password) {
		currentUser = isExist(name, password);
		if(currentUser!=-1) {
			cout << "\n\t\t\t\t      " << "<< Congrats! 'You Are Logged In' >>" << endl;
			return true;
		}
		else {
			cout << "\n\t\t\t\t       " << "<< Sorry! 'Plz Signed In First' >>" << endl;
			return false;
		}
	}
	int validPerson(string name) {
		for (int i = 0; i < user_profiles.size(); i++) {
			if (user_profiles[i].name == name ) {
				return i;
			}
		}
		return -1;
	}
	void checkDestUserRequestList(int userIndex,string name,bool& check) {
		Qnode<string>* temp = user_profiles[userIndex].requests.getQueue();
		int count = 1;
		while (temp != NULL) {
			if (temp->data == name) {
				check = false;
				return;
			}
			temp = temp->next;
		}
		check = true;
	}
	void sendRequest(string name) {
			int destUser = validPerson(name);
			if (user_profiles[currentUser].name != name) {
				bool check = true;
				if (destUser != -1) {
					checkDestUserRequestList(destUser, user_profiles[currentUser].name, check);
					if (check == true) {
						user_profiles[destUser].requests.enqueue(user_profiles[currentUser].name);
						string notify = user_profiles[currentUser].name;
						notify = notify + " Sent A Friend Request To You";
						user_profiles[destUser].notifications.enqueue(notify);
						cout << "\n\t\t\t\t                " << "<< Request Sent >>" << endl;
					}
					else {
						cout << "\n\t\t\t\t      " << "<< You Already Sent Him A Friend Request >>" << endl;
					}
				}
				else {
					cout << "\n\t\t\t\t    " << "<< Sorry! 'No Account Exist With This Name' >>" << endl;
				}
			}
			else {
				cout << "\n\t\t\t\t    " << "<< You Can't Send Follow Request to Yourself >>" << endl;
			}
	}
	void viewRequest(bool& isRequests) {
		if (user_profiles[currentUser].requests.getSize() != 0) {
			Qnode<string>* temp = user_profiles[currentUser].requests.getQueue();
			int count = 1;
			while (temp != NULL) {
				cout << "\n\t\t\t\t      " << count << ". You Hve Received A Follow Request From ' " << temp->data <<" '" << endl;
				temp = temp->next;
				count++;
			}
			isRequests = true;
		}
		else {
			cout << "\n\t\t\t\t             " << "<< No Request Yet>>" << endl;
			isRequests = false;
		}
	}
	void acceptRequest() {
		string name = user_profiles[currentUser].requests.getFront();
		int senderIndex = validPerson(name);
		string notify = user_profiles[currentUser].name;
		notify = notify + "! Accepted Your Request ";
		user_profiles[senderIndex].notifications.enqueue(notify);
		user_profiles[currentUser].follwers.push_back(name);
		user_profiles[currentUser].requests.dequeue();
		cout << "\n\t\t\t\t      " <<"<< CONGRATS 'YOU GOT A FOLLOWER' >>" << endl;
	}
	void rejectRequest() {
		string name = user_profiles[currentUser].requests.getFront();
		int senderIndex = validPerson(name);
		string notify = user_profiles[currentUser].name;
		notify = notify + "! Rejected Your Request ";
		user_profiles[senderIndex].notifications.enqueue(notify);
		user_profiles[currentUser].requests.dequeue();
		cout << "\n\t\t\t\t          "<< "<< Request is Cleared >>" << endl;
	}
	void viewNotifications() {
		if (user_profiles[currentUser].notifications.getSize() != 0) {
			Qnode<string>* temp = user_profiles[currentUser].notifications.getQueue();
			while (temp != NULL) {
				cout << "\t\t\t\t      " << "* " << temp->data << endl;
				temp = temp->next;
			}
		}
		else {
			cout << "\n\t\t\t\t           " << "<< No Notification Yet >>" << endl;
		}
	}
	void addPost(string context) {
		user_profiles[currentUser].posting.pushPost(context);
	}
	void ownFeed() {
		if (user_profiles[currentUser].posting.getHead() != NULL) {
			cout << "\n\t\t\t\t                  " << "<| " << user_profiles[currentUser].name << " |>" << endl;
			user_profiles[currentUser].posting.displayPost();
		}
		else {
			cout << "\t\t\t\t          " << "<< You Post Nothing Till >>" << endl;
		}
	}
	int getSize() { return user_profiles.size(); }
	bool searchInFollowers(string name) {
		bool check = false;
		for (int i = 0; i < user_profiles[currentUser].follwers.size(); i++) {
			if (name == user_profiles[currentUser].follwers[i]) {
				check = true;
				break;
			}
		}
		return check;
	}
	void follwerList() {
		if (user_profiles[currentUser].follwers.size() != 0) {
			cout << "\n\t\t\t\t              " << "Total Followers : " << user_profiles[currentUser].follwers.size() << endl ;
			cout << "\t\t\t\t            __" << "_____________________" << endl << endl;
			for (int i = 0; i < user_profiles[currentUser].follwers.size(); i++) {
				cout << "\t\t\t\t      " << "Follower No : " << i + 1 << endl<<endl;
				cout << "\t\t\t\t      " << "Name : ";
				cout  << user_profiles[currentUser].follwers[i] << endl;
				int followerIndex = validPerson(user_profiles[currentUser].follwers[i]);
				string subStr = user_profiles[followerIndex].lastLoginTimeStamp.substr(0, 10);
				cout << "\t\t\t\t      " <<"Last Log In Date : " << subStr << endl;
				subStr = user_profiles[followerIndex].lastLoginTimeStamp.substr(11, subStr.length());
				cout << "\t\t\t\t      " << "Last Log In Time : " << subStr << endl<<endl;
			}
		}
		else {
			cout << "\n\t\t\t\t             " << "<< No Followers Yet >>" << endl;
		}
	}
	void viewFollowersPost() {
		bool check = false;
		if (user_profiles[currentUser].follwers.size() != 0) {
			for (int i = 0; i < user_profiles[currentUser].follwers.size(); i++) {
				string name = user_profiles[currentUser].follwers[i];
				int followerIndex = validPerson(name);
				if (user_profiles[followerIndex].posting.getHead() != NULL) {
					check = true;
					cout << "\t\t\t\t      " << "Posted By  " << name<<" :" << endl ;
					user_profiles[followerIndex].posting.displayPost();
					cout << "\t\t\t\t      " << "       ______________________       " << endl << endl;

				}
			}
			if (check == false) {
				cout << "\t\t\t\t      " << "<< Your Followers Posts Nothing Till >>" << endl;
			}
		}
		else {
			cout << "\t\t\t\t        " << "<< Sorry! 'No Follower Yet' >>" << endl;
		}
	}
	int showFollowers() {
		int ch=-1;
		cout << "\n\t\t\t\t                || FOLLOWERS ||" << endl;
		if (user_profiles[currentUser].follwers.size() > 0) {
			for (int i = 0;i< user_profiles[currentUser].follwers.size(); i++) {
				cout << "\t\t\t\t      " << i + 1<<" ." << user_profiles[currentUser].follwers[i] << endl;
			}
			cout << "\n\t\t\t\t      " << "Enter Follower Number : ";
			while (!(cin >> ch) || ch<0 || ch>user_profiles[currentUser].follwers.size()) {
				cout << "\t\t\t\t      " << "Enter Valid Choice: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cin.ignore();
			ch = validPerson(user_profiles[currentUser].follwers[ch-1]);
		}
		else {
			cout << "\n\t\t\t\t             " << "<< No Followers Yet >>" << endl;
			ch = -1;
		}
		return ch;
	}
	void sendText(int toPerson) {
		int receiverIndex = toPerson;
		string message;
		string temp,temp2;
		temp = user_profiles[currentUser].name;
		temp = temp + "| ";
		cout << "\n\t\t\t\t      " << "TYPE -> ";
		getline(cin, message);
		temp2 = message;
		message = temp + message;
		if (!user_profiles[receiverIndex].chats.searchStack(user_profiles[currentUser].name)) {
			user_profiles[receiverIndex].chats.push(user_profiles[currentUser].name);
			user_profiles[receiverIndex].chats.sendMessage(message);
			string notify = "You Have Received A Message From ";
			string temp = "' " + user_profiles[currentUser].name + " '";
			notify = notify + temp;
			user_profiles[receiverIndex].notifications.enqueue(notify);
			user_profiles[currentUser].chats.push(user_profiles[receiverIndex].name);
			temp = " | " + user_profiles[currentUser].name;
			temp2 = "                       " + temp2;
			temp2 = temp2 + temp;
			user_profiles[currentUser].chats.sendMessage(temp2);
			cout << "\t\t\t\t            " << "<< Message Sent >>" << endl;
		}
		else {
			user_profiles[receiverIndex].chats.placeAtFront(user_profiles[currentUser].name);
			user_profiles[receiverIndex].chats.pushRecentFirst();
			user_profiles[receiverIndex].chats.sendMessage(message);
			string notify = " You Have Received A Message From ";
			string temp = "' " + user_profiles[currentUser].name + " '";
			notify = notify + temp;
			user_profiles[receiverIndex].notifications.enqueue(notify);
			user_profiles[currentUser].chats.placeAtFront(user_profiles[receiverIndex].name);
			user_profiles[currentUser].chats.pushRecentFirst();
			temp = " |" + user_profiles[currentUser].name;
			temp2 = "                        " + temp2;
			temp2 = temp2 + temp;
			user_profiles[currentUser].chats.sendMessage(temp2);
			cout << "\t\t\t\t            " << "<< Message Sent >>" << endl;
		}
	}
	bool printPersonalChat() {
		return user_profiles[currentUser].chats.printChatBox();
	}
	bool printMessages(string name) {
		return user_profiles[currentUser].chats.printSpecificChat(name);
	}
	void searchUser(string Searchedname) {
		searchEngine.search(Searchedname);
	}
};
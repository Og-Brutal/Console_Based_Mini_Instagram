#pragma once
#include<iostream> 
#include<string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
class Post {
public: 
	string dateAndTime;
	string postContext;
	int size;
	Post* next; 
	Post(string dandt, string pc) :dateAndTime(dandt), postContext(pc),next(NULL){} 
};
class UserPost {
	Post* posts;
public:
	UserPost() : posts(NULL){}
	string getCurrentTime() {
		auto now = chrono::system_clock::now();
		time_t now_time_t = chrono::system_clock::to_time_t(now);

		tm local_time;
		localtime_s(&local_time, &now_time_t); // Safe version for Windows

		stringstream timeStream;
		// Format the time in 12-hour format with AM/PM, properly handling AM/PM
		timeStream << put_time(&local_time, "%Y-%m-%d %I:%M:%S %p");
		return timeStream.str();
	}
	void pushPost(string context) {
		if (!posts)
		{
			posts = new Post(getCurrentTime(), context);
			return;
		}
		else {
			Post* newPost = new Post(getCurrentTime(), context);
			newPost->next = posts;
			posts = newPost;
		}
	}
	void popPost() {
		if (!posts) {
			return;
		}
		else 
		{
			Post* temp = posts;
			posts = posts->next;
			delete temp;
			temp = NULL;
		}
	}
	Post* getHead() {
		return posts;
	}
	void displayPost() {
		if (!posts) {
			return;
		}
		Post* current = posts;
		string subStr;
		int count = 1;
		while (current) {
			cout << "\n\t\t\t\t      " << "Post No " << count <<" :" << endl;
			cout << "\n\t\t\t\t      " << "Post : " << current->postContext << endl;
			subStr = current->dateAndTime.substr(0, 10);
			cout << "\t\t\t\t      " << "Post_Date : " << subStr << endl;
			subStr = current->dateAndTime.substr(11, current->dateAndTime.length());
			cout << "\t\t\t\t      " << "Post_Time : " << subStr << endl<<endl;
			current = current->next;
			count++;
		}
	}
};


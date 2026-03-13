#pragma once
#include<iostream>
#include"Post.h"
#include"queue.h"
#include"MessageSection.h"
#include<vector>
#include<string>
using namespace std;
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
class Vertex
{
public:
	string name;
	string password;
	string city;
	UserPost posting;
	string lastLoginTimeStamp;
	Queue<string> notifications;
	Queue<string> requests;
	MessageSection chats;
	vector<string> follwers;
	Vertex() {}
	Vertex(string name, string password, string city) : name(name), password(password), city(city), lastLoginTimeStamp(getCurrentTime()) {}
};
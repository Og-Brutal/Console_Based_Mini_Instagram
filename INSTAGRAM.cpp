#include<iostream>
#include<string>
#include"User.h"

#include"ErrorHandling.h"
using namespace std;
void instagram(Users& insta,string userName) {
	system("cls");
	ErrorHabdler handler;
	int choice;

	string searchedName;
	bool checkRequests = true;
	int followerIndex;
	string name,post;
	while (1) {
		cout << "\t\t\t\t      " << "----------------------------------" << endl;
		cout << "\t\t\t\t      " << "         Logged-In : " <<userName<< endl;
		cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
		cout << "\t\t\t\t      " << "1.To Send Follow Request" << endl;
		cout << "\t\t\t\t      " << "2.Handle Follow Requests" << endl;
		cout << "\t\t\t\t      " << "3.Notifications" << endl;
		cout << "\t\t\t\t      " << "4.Messages" << endl;
		cout << "\t\t\t\t      " << "5.Posts Realted" << endl;
		cout << "\t\t\t\t      " << "6.Own NewsFees" << endl;
		cout << "\t\t\t\t      " << "7.Follwer List" << endl;
		cout << "\t\t\t\t      " << "8.Search Engine" << endl;
		cout << "\t\t\t\t      " << "9.To Return Home" << endl;
		cout << "\t\t\t\t      "<<"Choice: ";
		choice = handler.intChecker();
		cin.ignore();
		switch (choice) {
		case 1:
			cout << "\n\t\t\t\t " <<"Enter Name Of User Whom You Wanna Sent Request : ";
			getline(cin, name);
			insta.sendRequest(name);
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|      Follow Requests Page      |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			int ch;
			insta.viewRequest(checkRequests);
			if (checkRequests) {
				cout << "\n\t\t\t\t      " << "1.To Accept Request" << endl;
				cout << "\t\t\t\t      " << "2.To Reject Request" << endl;
				cout << "\t\t\t\t      " << "3.To Return" << endl;
				cout << "\t\t\t\t      " << "Choice: ";
				ch = handler.intChecker();
				cin.ignore();
				if (ch == 1) {
					insta.acceptRequest();
				}
				else if (ch == 2) {
					insta.rejectRequest();
				}
				else {}
			}
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|          Notification          |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			insta.viewNotifications();
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			int choi;
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|            Messages            |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			cout << "\n\t\t\t\t      " << "1.Send Message To Followers" << endl;
			cout << "\t\t\t\t      " << "2.Open Chat Box" << endl;
			cout << "\t\t\t\t      " << "3.TO RETURN" << endl;
			cout << "\t\t\t\t      "<<"Choice : ";
			choi = handler.intChecker();
			cin.ignore();
			if (choi == 1) {
				followerIndex=insta.showFollowers();
				if (followerIndex != -1) {
					insta.sendText(followerIndex);
				}
			}
			else if(choi==2){
				system("cls");
				cout << "\t\t\t\t      " << "----------------------------------" << endl;
				cout << "\t\t\t\t      " << "|            Chat Box            |" << endl;
				cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
				if (insta.printPersonalChat()) {
					cout << "\n\t\t\t\t      " << "You Wanna Open Chat(1/0) : ";
					int var;
					var = handler.intChecker();
					cin.ignore();
					if (var == 1) {
						cout << "\n\t\t\t\t      " << "Enter Person Name : ";
						name = handler.checkEmpty();
						if (insta.printMessages(name)) {
							if (insta.searchInFollowers(name)) {
								cout << "\n\t\t\t\t      " << "You Wanna Reply Him(1/0) : ";
								var = handler.intChecker();
								cin.ignore();
								if (var == 1) {

									followerIndex = insta.validPerson(name);
									insta.sendText(followerIndex);

								}
							}
							else {
								cout << "\n\t\t\t\t    " << "<< Can't Reply Him 'He Is Not Follewing You' >>" << endl;
							}
						}
					}
				}
			}
			else {}
			cout << "\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|          Posts Section         |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			int che;
			cout << "\n\t\t\t\t      " << "1.To Add Post" << endl;
			cout << "\t\t\t\t      " << "2.To View Follower's Posts" << endl;
			cout << "\t\t\t\t      " << "3.To Come Back" << endl;
			cout << "\t\t\t\t      " << "Choice : ";
			che = handler.intChecker();
			cin.ignore();
			if (che == 1) {
					cout << "\n\t\t\t\t      " << "Enter Post Content : ";
					post = handler.checkEmpty();
					cout << "\n\t\t\t\t         " << "<< Post Added Successfully >>" << endl;
					insta.addPost(post);
			}
			else if (che == 2) {
				system("cls");
				cout << "\t\t\t\t      " << "----------------------------------" << endl;
				cout << "\t\t\t\t      " << "|         Followers Post         |" << endl;
				cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
				insta.viewFollowersPost();
			}
			else {}
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|          Own Newsfeed          |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			insta.ownFeed();
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|         Follower's List        |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			insta.follwerList();
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "\t\t\t\t      " << "----------------------------------" << endl;
			cout << "\t\t\t\t      " << "|          Search Engine         |" << endl;
			cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
			
			cout << "\n\t\t\t\t      " << "Enter User Name : ";
			searchedName = handler.checkEmpty();
			insta.searchUser(searchedName);
			cout << "\n\t\t\t\t      ";
			system("pause");
			system("cls");
			break;
		case 9:
			return;
			break;
		default:
		    cout << "\n\t\t\t\t      " << "! Invalid Choice !" << endl;
			cout << "\n\t\t\t\t      ";

			system("pause");
			system("cls");
			break;
		}
	}
}
void printInterphase() 
{
	cout << "\t\t\t\t      " << "******************************************" << endl;
	cout << "\t\t\t\t      " << "*                                        *" << endl;
	cout << "\t\t\t\t      " << "*      ***************************       *" << endl;
	cout << "\t\t\t\t      " << "*      *                         *       *" << endl;
	cout << "\t\t\t\t      " << "*      *                         *       *" << endl;
	cout << "\t\t\t\t      " << "*      *       ***********       *       *" << endl;
	cout << "\t\t\t\t      " << "*      *       *         *       *       *" << endl;
	cout << "\t\t\t\t      " << "*      *       *         *       *       *" << endl;
	cout << "\t\t\t\t      " << "*      *       *         *       *       *" << endl;
	cout << "\t\t\t\t      " << "*      *       ***********       *       *" << endl;
	cout << "\t\t\t\t      " << "*      *                         *       *" << endl;
	cout << "\t\t\t\t      " << "*      *                         *       *" << endl;
	cout << "\t\t\t\t      " << "*      ***************************       *" << endl;
	cout << "\t\t\t\t      " << "*                                        *" << endl;
	cout << "\t\t\t\t      " << "******************************************" << endl;
	cout << endl;
	cout << "\t\t\t\t                " << "! WELCOM TO INSTAGRAM !" << endl;
	cout << "\t\t\t\t                " << "_______________________" << endl;
	cout << endl;
	cout << "\t\t\t\t               ";
	system("pause");
	system("cls");

}
void signInPage(Users& insta)
{
	ErrorHabdler handler;
	int choice;
	printInterphase();
	string name, password, city;
	while (1) {
		cout << "\t\t\t\t      " << "----------------------------------" << endl;
		cout << "\t\t\t\t      " << "|        REGISTRATION PAGE       |" << endl;
		cout << "\t\t\t\t      " << "----------------------------------" << endl << endl;
		cout << "\t\t\t\t               " << "  1.To Sign In" << endl;
		cout << "\t\t\t\t               " << "  2.To Log In" << endl;
		cout << "\t\t\t\t               " << "  3.To Exit" << endl;
		cout << "\t\t\t\t               " << "  Choice : ";
		choice=handler.intChecker();
		cout << endl;
		cin.ignore();
		switch (choice) {
		case 1:
			cout << "\t\t\t\t            " << "Enter User-Name : ";
			name = handler.checkEmpty();
			cout << "\t\t\t\t            " << "Set Your Password : ";
			password = handler.checkEmpty();
			password = handler.checkPassword(password);
			cout << "\t\t\t\t            " << "Enter Your City : ";
			city = handler.checkEmpty();
			insta.signUp(name, password, city);
			cout << endl;
			cout << "\t\t\t\t" << "<< Congrats! 'You Are Signed In Successfully' >>" << endl<<endl;
			cout << "\t\t\t\t            ";
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "\t\t\t\t            " << "Enter User-Name : ";
			name = handler.checkEmpty();
			cout << "\t\t\t\t            " << "Enter Password : ";
			password = handler.checkEmpty();
			if (insta.logIn(name, password)) {
				cout << "\n\t\t\t\t            ";
				system("pause");
				instagram(insta,name);

			}
			cout << "\n\t\t\t\t            ";
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "\n\t\t\t\t      " << "<< Thnx For Your Response >>" << endl;
			system("pause");
			exit(0);
		default:
			cout << "\n\t\t\t\t      " << "! Invalid Choice !" << endl;
			cout << "\n\t\t\t\t      ";

			system("pause");
			system("cls");
			break;
		}
	}
}
int main() {
	Users insta;
	signInPage(insta);
	system("pause");
}
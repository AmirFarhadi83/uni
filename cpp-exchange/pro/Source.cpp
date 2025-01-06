#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
#include "Basee.h"
#include "Exchange.h"
#include "User.h"
#include "Basee.h"

using namespace std;

void signUp();
void signIn();
int admin_menu();
void admin();
int user_menu(int UserIdSend);
int menu();

int lineCount() {
	ifstream obj("Currency_Info.txt");
	string line;
	int count = 0;
	while (getline(obj, line)) {
		count++;
	}
	obj.close();
	return count;
}
int lineCountU() {
	ifstream obj("User_Info.txt");
	string line2;
	int count = 0;
	while (getline(obj, line2)) {
		count++;
	}
	obj.close();
	return count;
}
void inputUser(User inF[]) {
	string t;
	double d;
	int n;
	ifstream obj("User_Info.txt");

	for (int i = 0; i < lineCountU(); i++)
	{
		obj >> t >> t;
		inF[i].set_userName(t);

		obj >> t >>t;
		inF[i].set_name(t);

		obj >> t >> t;
		inF[i].set_lastName(t);

		obj >> t >> t;
		inF[i].set_id(t);
 
		obj >> t >> t;
		inF[i].set_phoneNumber(t);

		obj >> t >> t;
		inF[i].set_password(t);

		obj >> t >> d;
		inF[i].set_inventory(d);
	}


	obj.close();
}
void inputCurrency(Exchange inF[]) {
	string t;
	double d;
	int n;
	ifstream obj("Currency_Info.txt");
	
	for (int i = 0; i < lineCount(); i++)
	{
		obj >> t >> t;
		inF[i].set_name(t);

		obj >> t >> t;
		inF[i].set_id(t);

		obj >> t >> d;
		inF[i].set_price(d);

		obj >> t >> n;
		inF[i].set_inventory(n);
	}
	

	obj.close();
}
void signUp() {
	User a;
	a.set_userName();
	a.set_name();
	a.set_lastName();
	a.set_id();
	a.set_phoneNumber();
	a.set_password();
	a.set_inventory();
	a.save_file();
}
void signIn() {

	int line2 = lineCountU();
	User* userObject = new User[line2];
	inputUser(userObject);

	string text, userCheck, passCheck;
	ifstream readUser("User_Info.txt");
	readUser >> text; // username
	readUser.close();
	cout << "Enter UserName: ";
	getline(cin >> ws, userCheck);
	for (int i = 0; i < line2; i++)
	{
		if (userCheck == userObject[i].get_userName())
		{
			cout << "Enter User Pass: ";
			getline(cin >> ws, passCheck);

			if (passCheck == userObject[i].get_password())
			{
				int UserIdSend = i;
				user_menu(UserIdSend);
				system("pause");
			}
		}
	}
	
}
int admin_menu()
{
	int answer;
	Exchange obj;
	do {
		cout << "Admin Menu Section" << endl;
		cout << "1-Add New Currency"
			<< "\n2-Delete A Currency"
			<< "\n3-Edit A Currency"
			<< "\n4-Back To Main Menu"
			<< "\nEnter Your Choice : ";
		cin >> answer;
		char ch;
		switch (answer) {
		case 1:
			do {
				system("cls");
				obj.set_name();
				obj.set_price();
				obj.set_inventory();
				obj.save_file();
				cout << "If You Want To Add Another Currency (Y/N): ";
				cin >> ch;
			} while (ch == 'Y' or ch == 'y');
			break;
		case 2:
			system("cls");

			break;
		case 3:
			system("cls");
			break;
		case 4:
			system("cls");
			return 0;
		default:
			cout << "Enter Correct Option";
		}
	} while (true);
}
void admin() {
	string pass = "123456789";
	string inputPass;
	char tt = ' ';
	int i = 0;

	cout << "Enter Password : ";
	while (i < pass.length() and tt != 13)
	{
		tt = _getch();
		inputPass += tt;
		i++;
		cout << "*";
	}
	cout << endl;
	if (inputPass != pass) {

		cout << "Go Home Kid!!!\n";
		system("pause");
	}
	else {
		admin_menu();
	}
}
int user_menu(int UserIdSend)
{
	system("cls");
	int answer = 0;
	string txt;

	int line = lineCount();
	Exchange* currency = new Exchange[line];
	inputCurrency(currency);

	int line2 = lineCountU();
	User* userObject = new User[line2];
	inputUser(userObject);

	do {
		ifstream buyFile("Currency_Info.txt", ios::app);
		system("cls");
		bool flag = true; 
		cout << "Menu Section" << endl;
		cout << "1-sign up"
			<< "\n2-sign in"
			<< "\n3-admin menu"
			<< "\n4-Back To Main Menu"
			<< "\nEnter : ";
		cin >> answer;
		switch (answer)
		{
		case 1:
		
		while(flag){
			
				buyFile >> txt;
				cout << txt << " "; // Name:
				buyFile >> txt; // name from file to txt
				cout << txt << " "; //name

				buyFile >> txt;
				cout << txt << " "; // Id:
				buyFile >> txt; // id from file to txt
				cout << txt << " "; //id

				buyFile >> txt;
				cout << txt << " "; // Price:
				buyFile >> txt; // Price from file to txt
				cout << txt << " "; //price

				buyFile >> txt;
				cout << txt << " "; // Inventory:
				buyFile >> txt; // inventory from file to txt
				cout << txt << " "; //inventory
			}
	buyFile.close();
		string id;
		int much;
			cout << "Choose Currency ID: ";
			cin >> id;
			for (int i = 0; i < line; i++)
			{
				if (id == currency[i].get_id())
				{
					system("cls");
					cout << "Name: " << currency[i].get_name() << "Price: " << currency[i].get_price() << endl;
					cout << "How much " << currency[i].get_name() << " do you want baby??\n";
					cin >> much;
					if (much > currency[i].get_inventory())
					{
						cout << "this is too much!";
						break;
					}
					else {
						if (much * currency[i].get_price() > userObject[UserIdSend].get_inventory())
						{
							cout << "Inventory Not Enough!";
							break;
						}
						else {
							ofstream usWa(userObject[UserIdSend].get_userName()+"Wallet_info", ios::app);
							usWa << currency[i].get_name() << ": " << much << "Value: " << much * currency[i].get_price() << endl;
							usWa.close();
							flag = false;
						}
					}
				}
			}
			
			ofstream delC("Currency_Info.txt", ios::trunc); // (empty file)
			delC.close();
			for (int i = 0; i < line; i++)
			{
				currency[i].save_file();
			}
			ofstream delU("User_Info.txt", ios::trunc); // (empty file)
			delU.close();
			for (int i = 0; i < line2; i++)
			{
				userObject[i].save_file();
			}
			cout << endl;
			system("pause");
			break;
			}
		}
		case 2:
			system("cls");
			break;
		case 3:
			system("cls");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			system("cls");
			return 0;
		default:
			cout << "Enter Correct Option";
		}
		buyFile.close();
	} while (true);

}
int menu()
{
	int answer;
	do {
		system("cls");
		cout << "welcome to sarrafi!" << endl;
		cout << "1-Sign Up"
			<< "\n2-Sign In"
			<< "\n3-Login As Admin "
			<< "\n4-Back To Main Menu"
			<< "\nEnter Your Choice : ";
		cin >> answer;
		switch (answer) {
		case 1:
			system("cls");
			signUp();
			break;
		case 2:
			system("cls");
			signIn();
			break;
		case 3:
			system("cls");
			admin();
			break;
		case 4:
			return 0;
		default:
			cout << "Enter Correct Option";
		}
	} while (true);
}
int main() {
	menu();
	cout << "exit";
}
#include "User.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "Basee.h"
#include "Basee.h"
#include "Exchange.h"

using namespace std;

void User::set_userName() {
	cout << "Enter User Name : ";
	getline(cin >> ws, userName);
}
void User::set_userName(string i) {
	userName=i;
}
string User::get_userName() {
	return userName;
}

void User::set_lastName() {
	cout << "Enter User Last Name : ";
	getline(cin >> ws, lastName);
}
void User::set_lastName(string j) {
	lastName = j;
}
string User::get_lastName() {
	return lastName;
}

void User::set_phoneNumber() {
	cout << "Enter User Phone Number : ";
	getline(cin >> ws, phoneNumber);
}
void User::set_phoneNumber(string b) {
	phoneNumber = b;
}
string User::get_phoneNumber() {
	return phoneNumber;
}

void User::set_password() {
	cout << "Enter User Password : ";
	getline(cin >> ws, password);
}
void User::set_password(string p) {
	password = p;
}
string User::get_password() {
	return password;
}

void User::save_file() {
	ofstream fileObj("User_Info.txt", ios::app);
	fileObj 
		<< "UserName: " << get_userName()
		<< " Name: " << get_name()
		<< " LastName: " << get_lastName()
		<< " ID: " << get_id()
		<< " PhoneNumber: " << get_phoneNumber()
		<< " Password: " << get_password()
		<< "" << get_inventory()
		<< endl;

	fileObj.close();
}
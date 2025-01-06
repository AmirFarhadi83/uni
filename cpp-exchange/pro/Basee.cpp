#include "Basee.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <string>
#include "Exchange.h"
#include "User.h"
#include "Basee.h"

using namespace std;

void Basee::set_name() {

	cout << "Enter Name : ";
	getline(cin >> ws, name);
}
void Basee::set_name(string n) {

	name = n;
}
string Basee::get_name() {
	return name;
}

void Basee::set_id() {
	cout << "Enter ID : ";
	getline(cin >> ws, id);
}
void Basee::set_id(string a) {
	id = a;
}
string Basee::get_id() {
	return id;
}

void Basee::set_inventory() {
	cout << "Enter Inventory : ";
	cin >> inventory;
}
void Basee::set_inventory(int n) {
	inventory = n;
}
double Basee::get_inventory() {
	return inventory;
}
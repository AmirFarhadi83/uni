#include "Exchange.h"
#include <iostream>
#include <fstream>
#include "Basee.h"
#include "Basee.h"

using namespace std;



void Exchange::set_price() {
	cout << "Enter Currency Price : ";
	cin >> price;
}
void Exchange::set_price(double p) {
	price = p;
}
double Exchange::get_price() {
	return price;
}


void Exchange::save_file() {
	ofstream fileObj("Currency_Info.txt", ios::app);
	fileObj 
		<< "Name: " <<get_name()
		<< " ID: " << get_id()
		<<" Price: " << get_price()
		<< " Inventory: " << get_inventory()
		<< endl;
	fileObj.close();
}
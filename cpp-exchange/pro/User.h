#pragma once
#include "Basee.h"
#include <string>

using namespace std;

class User : public Basee
{
	string userName;
	string lastName;
	string phoneNumber;
	string password;

public:
	void set_userName();
	void set_userName(string i);
	string get_userName();
	void set_lastName();
	void set_lastName(string j);
	string get_lastName();
	void set_phoneNumber();
	void set_phoneNumber(string b);
	string get_phoneNumber();
	void set_password();
	void set_password(string p);
	string get_password();
	void save_file();
};


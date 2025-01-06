#pragma once
#include <string>

using namespace std;

class Basee
{
	string name;
	string id;
	double inventory;

public:
	void set_name();
	void set_name(string n);
	string get_name();
	void set_id();
	void set_id(string a);
	string get_id();
	void set_inventory();
	void set_inventory(int n);
	double get_inventory();
};


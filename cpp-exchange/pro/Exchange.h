#pragma once
#include "Basee.h"
#include "Basee.h"
#include <string>

using namespace std;

class Exchange : public Basee
{
	
	double price;

public:
	void set_price();
	void set_price(double p);
	double get_price();

	void save_file();
};


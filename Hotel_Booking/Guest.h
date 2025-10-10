#include "Header.h"

#pragma once
class Guest
{
private:
	int ID;
	string name;
	int callNum;
	//history of booking
	//stored in linked list

public:
	Guest();
	~Guest();

	string getName();
	int getNum();
	int getID();
	void setID();

};


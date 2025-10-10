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
	Guest(istream& file);
	~Guest();

	void setName(string Name);
	string getName();
	void setNum(int number);
	int getNum();
	int getID();
	void setID(int idno);

};


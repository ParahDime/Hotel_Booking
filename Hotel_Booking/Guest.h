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
	Guest() : ID(0), name(""), callNum(0) {};
	Guest(istream& file);
	~Guest();

	void setName(string Name);
	 string getName() const;
	void setNum(int number);
	int getNum() const;
	int getID() const;
	void setID(int idno);

	friend std::istream& operator>>(std::istream& in, Guest& g);

};


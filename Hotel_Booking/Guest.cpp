#include "Guest.h"

Guest::Guest(istream& file)
{
	//file >> *this;
}

Guest::~Guest()
{
}

void Guest::setName(string Name)
{
	name = Name;
}
string Guest::getName()
{
	return name;
}

void Guest::setNum(int number)
{
	callNum = number;
}

int Guest::getNum()
{
	return callNum;
}

int Guest::getID()
{
	return ID;
}

void Guest::setID(int idno)
{
	ID = idno;
}

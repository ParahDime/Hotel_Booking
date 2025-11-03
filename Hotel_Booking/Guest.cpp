#include "Guest.h"
#include "Header.h"
//#include "BookingInfo.h"

Guest::Guest(string user, int id, int number)
{
	ID = id;
	name = user;
	callNum = number;
}

Guest::Guest(istream& file)
{
	file >> *this;
}

Guest::~Guest()
{
}

void Guest::setName(string Name)
{
	name = Name;
}
string Guest::getName() const 
{
	return name;
}

void Guest::setNum(int number)
{
	callNum = number;
}

int Guest::getNum() const
{
	return callNum;
}

int Guest::getID() const
{
	return ID;
}

void Guest::setID(int idno)
{
	ID = idno;
}

std::istream& operator>>(std::istream& in, Guest& g)
{
	std::unique_ptr<std::string> line = make_unique<string>();
	if (getline(in, *line)) {
		std::stringstream stream(*line);
		std::unique_ptr<std::string> idStr = make_unique<string>();
		unique_ptr<string> nameStr = make_unique<string>();
		unique_ptr<string> callStr = make_unique<string>();

		getline(stream, *idStr, ',');
		getline(stream, *nameStr, ',');
		std::getline(stream, *callStr, ',');
	
		g.ID = std::stoi(*idStr);
		g.name = *nameStr;
		g.callNum = std::stoi(*callStr);
	}

    return in; // return stream so it can be chained
}

#include "Header.h"
#pragma once
class Room
{
private:
	int ID;
	float PPN; //price per night
	bool occupied;
	enum amenities {
		Standard = 1,
		Enhanced = 2,
		Luxury = 3
	};
	enum type {
		Single = 1,
		Twin = 2,
		Double = 3,
		Executive = 4
	};

	amenities Amenities;
	type Type;

public:
	//Guest() : ID(0), name(""), callNum(0) {};
	Room() : ID(0), PPN(0.0), occupied(false), Amenities(Standard), Type(Single) {};
	Room(istream &file);
	~Room();

	void SetID(int id);
	int GetID();
	
	int GetPPN();
	void SetPPN(int price, bool discount);

	void setOccupied();
	bool IsOccupied(bool occupied);

	void setAmenities(amenities a);
	amenities getAmenities();

	type getType();
	void setType(type a);

	friend std::istream& operator>>(std::istream& in, Room& r);
};


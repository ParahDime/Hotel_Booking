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
		Single = 0,
		Twin = 1,
		Double = 2,
		Executive = 3
	};

	amenities Amenities;
	type Type;

public:
	//Guest() : ID(0), name(""), callNum(0) {};
	Room() : ID(0), PPN(0.0), occupied(false), Amenities(Standard), Type(Single) {};
	Room(istream &file);
	~Room();

	void SetID(int id);
	int GetID() const;
	
	int GetPPN() const;
	void SetPPN(int price, bool discount);

	void setOccupied();
	bool IsOccupied() const;

	void setAmenities(amenities a);
	string getAmenities() const;

	type getType() const;
	void setType(type a);

	friend std::istream& operator>>(std::istream& in, Room& r);
};


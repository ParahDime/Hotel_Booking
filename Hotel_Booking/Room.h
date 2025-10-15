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
		Single,
		Twin,
		Double,
		Executive
	};

	amenities Amenities;
	type Type;

public:
	Room(istream &file);
	~Room();

	void SetID(int id);
	int GetID();
	
	int GetPPN();
	void SetPPN(int price, bool discount);

	void setOccupied();
	bool IsOccupied(bool occupied);

	amenities setAmenities(amenities a);
	amenities getAmenities();

	type getType();
	type setType(type a);


};


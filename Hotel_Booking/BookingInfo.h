#include "Header.h"

#pragma once
class BookingInfo
{
private:
	int ID;
	//guest ref
	//room ref
	//check in 
	//check out
	float totalCost;
public:
	BookingInfo();
	~BookingInfo();

	int getID();

};


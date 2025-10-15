#include "Room.h"

Room::Room(istream& file)
{
	//file >> *this;
}

Room::~Room()
{
}

void Room::SetID(int id)
{
	ID = id;
}

int Room::GetID()
{
	return ID;
}

int Room::GetPPN()
{
	return PPN;
}

void Room::SetPPN(int price, bool discount)
{
	if (!discount)
	{
		PPN = price;
	}
	else {
		PPN = price * 0.75;
	}
}

void Room::setOccupied()
{
	if (occupied)
	{
		occupied = false;
	}
	else
	{
		occupied = true;
	}
}

bool Room::IsOccupied(bool occupied)
{
	return occupied;
}

Room::amenities Room::setAmenities(amenities a)
{
	Amenities = a;
}

Room::amenities Room::getAmenities()
{
	return Amenities;
}

Room::type Room::getType()
{
	return Type;
}

Room::type Room::setType(type a)
{
	Type = a;
}

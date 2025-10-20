#include "Room.h"

Room::Room(istream& file)
{
	file >> *this;
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

void  Room::setAmenities(amenities a)
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

void::Room::setType(type a)
{
	Type = a;
}

std::istream& operator>>(std::istream& in, Room& r) {
	std::unique_ptr<std::string> line = make_unique<string>();
	if (getline(in, *line)) {
		std::stringstream stream(*line);
		std::unique_ptr<std::string> idStr = make_unique<string>();
		std::unique_ptr<string> ppnFlt = make_unique<string>();
		std::unique_ptr<string> occuBl = make_unique<string>();
		std::unique_ptr <string> enu1 = make_unique<string>();
		std::unique_ptr<string> enu2 = make_unique<string>();

		getline(stream, *idStr, ',');
		getline(stream, *ppnFlt, ',');
		getline(stream, *occuBl, ',');
		getline(stream, *enu1, ',');
		getline(stream, *enu2, ',');

		r.ID = std::stoi(*idStr);

	}

	return in;
}
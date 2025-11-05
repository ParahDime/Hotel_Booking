#include "BookingInfo.h"

BookingInfo::BookingInfo(istream& file)
{
	file >> *this;
}

BookingInfo::~BookingInfo()
{
}

int BookingInfo::getID() const
{
	return ID;
}

void BookingInfo::setID(int id)
{
	ID = id;
}

int BookingInfo::getGuest() const
{
	return guestRef;
}

void BookingInfo::setGuest(int guest)
{
	guestRef = guest;
}

int BookingInfo::getRoom() const
{
	return roomRef;
}

void BookingInfo::setRoom(int room)
{
	roomRef = room;
}

void BookingInfo::setCheckIn(string in)
{
	checkIn = in;
}

void BookingInfo::setCheckOut(string out)
{
	checkOut = out;
}

string BookingInfo::getCheckIn() const
{
	return checkIn;
}

string BookingInfo::getCheckOut() const
{
	return checkOut;
}

void BookingInfo::setCost(int cost)
{
	totalCost = cost;
}

int BookingInfo::getCost() const
{
	return totalCost;
}

std::istream& operator>>(std::istream& in, BookingInfo& b) {
	std::unique_ptr<std::string> line = make_unique<string>();
	if (getline(in, *line)) {
		std::stringstream stream(*line);
		string idStr, gRefStr, rRefStr, cInStr, cOutStr, tCostStr;


		getline(stream, idStr, ',');
		getline(stream, gRefStr, ',');
		getline(stream, rRefStr, ',');
		getline(stream, cInStr, ',');
		getline(stream, cOutStr, ',');
		getline(stream, tCostStr);

		b.ID = std::stoi(idStr);
		b.guestRef = std::stoi(gRefStr);
		b.roomRef = std::stoi(rRefStr);
		b.checkIn = cInStr;
		b.checkOut = cOutStr;
		b.totalCost = std::stof(tCostStr);
	}
	return in;
}
#include "BookingInfo.h"

BookingInfo::BookingInfo()
{

}

BookingInfo::~BookingInfo()
{
}

int BookingInfo::getID()
{
	return int();
}

void BookingInfo::setID(int id)
{
	ID = id;
}

int BookingInfo::getGuest()
{
	return guestRef;
}

void BookingInfo::setGuest(int guest)
{
	guestRef = guest;
}

int BookingInfo::getRoom()
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

string BookingInfo::getCheckIn()
{
	return checkIn;
}

string BookingInfo::getCheckOut()
{
	return checkOut;
}

void BookingInfo::setCost(int cost)
{
	totalCost = cost;
}

int BookingInfo::getCost()
{
	return totalCost;
}

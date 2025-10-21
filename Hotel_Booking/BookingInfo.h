#include "Header.h"

#pragma once
class BookingInfo
{
private:
	int ID;
	int guestRef;//guest ref
	int roomRef;//room ref
	string checkIn;//check in 
	string checkOut;//check out
	float totalCost;
public:
	BookingInfo() : ID(0), guestRef(0), roomRef(0), checkIn("01-01-1900"), checkOut("01-01-2000"), totalCost(10.00) {};
	BookingInfo(istream& file);
	~BookingInfo();

	int getID();
	void setID(int id);

	int getGuest();
	void setGuest(int guest);

	int getRoom();
	void setRoom(int room);

	void setCheckIn(string in);
	void setCheckOut(string out);
	string getCheckIn();
	string getCheckOut();

	void setCost(int cost);
	int getCost();

	friend std::istream& operator>>(std::istream& in, BookingInfo& b);
};


#include "Header.h"
#include "Room.h"
#include "Guest.h"
#include "BookingInfo.h"

//use binary search for room ID

//merge sort for sorting rooms

//recursive function for calcing totalprice

//search for guests via hashmap

void Test() {
	cout << "Function called";
}

int ReturnInt(int low, int high)
{
	unique_ptr<int> getInt = make_unique<int>();

	do {
		cin >> *getInt;

	} while (*getInt < low || *getInt > high);

	return *getInt;
}

//used for a stylised welcome message
void welcomeMessage() {
	//stylised welcome message
}

//handles initial menu login
void loginMenu(unique_ptr<int> &menuOption) {
	welcomeMessage();

	cout << "Welcome to hotel paradise!";
	cout << "\nWe're so happy you've chosen to stay with us\n";
	bool open = true;
	do
	{
		cout << "Please choose an option from below";
		cout << "[1] Book in / out \n[2] Get a price \n [3] Create a booking \n\n [0] Manager Login";

		*menuOption = ReturnInt(0, 3);
		if (*menuOption >= 0 || *menuOption <= 3) {
			open = false;
		}
		
	} while (open);
}

void bookInOut() { //system for booking in, and booking out
	//select option to book in or out

	//book in 
	// take guest details
	// confirm room no
	// edit list to update 
	
	//book out
	//take guest info
	//confirm room booking out (return)
}

void getPrice() { //get the price of a room
	//input room
	//input availability

	//check to see if room available
	//if yes, calc price
	//potential to go to create booking

}

void createBooking() { //create a booking system for the room (modified)

}

void managerMenu() { //manager menu, helping to handle data

}

template <class S, class T> bool verifyFile(S& file, T& fileName) { //verify that a file exists
	if (!file)
	{
		cout << "ERROR!\n";
		cout << "File could not be loaded\n";
		return false;
	}
	else
	{
		cout << *fileName << " loaded successfully\n";
		return true;
	}
}

void inputGuest(ifstream& file, vector<Guest*>& vGuest) { //read a file into the system

}

void inputRoom(ifstream& file, vector<Room*>& vRoom) {

}

void inputBookings(ifstream& file, vector<BookingInfo*>& vBookings()) {

}

int main()
{
	//initialise variables
	bool programRunning = true;

	unique_ptr<int> menuOption = make_unique<int>();
	const int kRoom = 30;
	
	vector<Room> vRooms = {};
	//hash for guests by ID
	//hash for booking ID
	//hash for room ID

	//queue for guests if rooms are full
	//process check in/out in fifo stack

	//set for room ids available
	//can also be used for VIP guests

	//initialise classes

	//read in files
	unique_ptr<string> fileName = make_unique<string>();
	*fileName = "Guest.txt";
	//guest info

	//room info

	//booking info

	//program loop
	while (programRunning) {
		cout << "Welcome to hotel paradise";
		//welcome message
		loginMenu(menuOption);
		
		switch (*menuOption) {
		case 1: //book in / out
			
			break;
		case 2:	//get price
			
			break;
		case 3: //create booking
			
			break;
		case 4: //exit the system
			programRunning = false;
			break;

		case 0: //manager login
			break;
		default:
			programRunning = false;
		}
	}
	return 0;
}
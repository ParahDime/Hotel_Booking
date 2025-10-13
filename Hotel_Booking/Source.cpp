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

	return;
}

void bookInOut() { //system for booking in, and booking out
	unique_ptr<bool> usingMenu = make_unique<bool>(true);
	unique_ptr<int> subMenuOption = make_unique<int>();

	do {
		cout << "Booking In / Booking Out";

		cout << "Please select an option below";
		cout << "[1] Book In \n[2] Book Out \n [0] Return to menu";
		*subMenuOption >> ReturnInt(0, 2);

		switch (*subMenuOption) {
		case 1: //booking in
			// take guest details
			// confirm room no
			// edit list to update 
			break;
		case 2: //booking out
			//take guest info
			//confirm room booking out (return)
			break;
		case 0:
			*usingMenu = false;
			break;
		default:
			*usingMenu = false;
			break;
		};
	} while (*usingMenu);

	return;
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
	unordered_map < int, string > GuestIDs;//hash for guests by ID
	unordered_map < int, string > BookingIDs;//hash for booking ID
	unordered_map < int, string > RoomIDs;//hash for room ID

	//queue for guests if rooms are full
	//process check in/out in fifo stack

	//set for room ids available
	//can also be used for VIP guests / put into unordered map guest

	//initialise classes

	//read in files
	unique_ptr<string> fileName = make_unique<string>();
	*fileName = "Guest.txt";
	//guest info

	//room info
	*fileName = "Roominfo.txt";

	//booking info
	*fileName = "Bookinginfo.txt";


	//program loop
	while (programRunning) {
		cout << "Welcome to hotel paradise";
		//welcome message
		loginMenu(menuOption);
		
		switch (*menuOption) {
		case 1: //book in / out
			bookInOut();
			break;
		case 2:	//get price
			getPrice();
			break;
		case 3: //create booking
			createBooking();
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
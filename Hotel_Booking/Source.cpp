#include "Header.h"
#include "Room.h"
#include "Guest.h"
#include "BookingInfo.h"

//use binary search for room ID

//merge sort for sorting rooms

//recursive function for calcing totalprice

//search for guests via hashmap

//standard test function
void Test() {
	cout << "Function called";
}
///
/// Used to return specified characters
///
char ReturnChar()
{
	unique_ptr<char> getChar = make_unique<char>();

	do {
		*getChar = getchar();
	} while (*getChar != 'y' && *getChar != 'n');

	return *getChar;
}


int ReturnInt(int low, int high)
{
	unique_ptr<int> getInt = make_unique<int>();

	do {
		cin >> *getInt;

	} while (*getInt < low || *getInt > high);

	return *getInt;
}

///
///	Functions for program maintenance
/// 


void welcomeMessage() {
	//stylised welcome message
	std::cout << "\033[1;33m"; // bright yellow
	std::cout << "+---------------------------------------+\n";
	std::cout << "|        WELCOME TO HOTEL PARADISE      |\n";
	std::cout << "+---------------------------------------+\n";
	std::cout << "\033[0m"; // reset color
}

void createAcc() //create a user account
{
	//first name

	//last name

	//number to contact them

	//also assign ID number to them (can be rand)
}

//handles initial menu login
void loginMenu(unique_ptr<int> &menuOption) {
	welcomeMessage();

	cout << "Welcome to hotel paradise!";
	cout << "\nWe're so happy you've chosen to stay with us\n";
	bool open = true;
	do
	{
		cout << "Please choose an option from below\n";
		cout << "[1] Book in / out \n[2] Get a price \n [3] Create a booking \n\n [0] Quit";

		*menuOption = ReturnInt(0, 3);
		if (*menuOption >= 0 || *menuOption <= 3) {
			open = false;
		}
		
	} while (open);

	return;
}
//Function for booking in out of hotel room
void bookInOut() { 
	unique_ptr<bool> usingMenu = make_unique<bool>(true);
	unique_ptr<int> subMenuOption = make_unique<int>();
	unique_ptr<string> userName = make_unique<string>();
	char confirmChar;

	int nightStay = 0;

	do {
		cout << "Booking In / Booking Out";

		cout << "Please select an option below";
		cout << "[1] Book In \n[2] Book Out \n [0] Return to menu";
		*subMenuOption >> ReturnInt(0, 2);

		//get user info (do we have their deets)

		//if acc proceed

		//else send to get deets

		//loop while not logged in

		switch (*subMenuOption) {
		case 1: //booking in
			cout << "[1] : Booking In";// take guest details'
			//ask for room type they want
			cout << "What style of room are you looking for?";
			cout << "\nSingle\nTwin\nDouble\nExecutive";

			//ask how long
			cout << "How many nights are you looking to stay? Maximum: 7";
			nightStay >> ReturnInt(1, 7);
			//check against list

			//give details and 
			//Room number, pricetotal, price per night

			cout << "";
			cout << "Total Stay: " << "8" << "days \nPrice per night £" << "" << "\nTotal Price £" << "";
			cout << "Confirm? y/n\n";

			//confirmation

			break;
		case 2: 
			cout << "[2] : Booking Out";//booking out
			cout << "Please input your name";
			cin >> *userName; //take guest info
			
			//confirm room booking out (return)
			break;
		case 0:
			cout << "[0] : Return to Main Menu";
			*usingMenu = false;
			break;
		default:
			cout << "[0] : Return to Main menu";
			*usingMenu = false;
			break;
		};
	} while (*usingMenu);

	return;
}

void getPrice() { //get the price of a room
	unique_ptr<bool> usingMenu = make_unique<bool>(true);
	unique_ptr<int> subMenuOption = make_unique<int>();

	cout << "Please select an option\n";
	cout << "[1] Check Availability\n [2] Check Price\n [0] Return to Menu";
	*subMenuOption >> ReturnInt(0, 2);
	do {
	//input room
	//input availability

	//check to see if room available
	//if yes, calc price
	//potential to go to create booking
		*usingMenu = false;
	} while (*usingMenu);

}

void createBooking() { //create a booking system for the room (modified)
	unique_ptr<char> alreadyGuest = make_unique<char>();
	unique_ptr<string> name = make_unique<string>();
	char inputOption = ' ';
	string username;


	cout << "Create a new booking\n";
	//ask if pre existing guest
	cout << "Do you have a profile with us?\n y/n";

	//check they are in the system
	*alreadyGuest = ReturnChar();
	if (*alreadyGuest == 'y') //if yes continue
	{
		cout << "Please enter your name\n";

		//check if account is on the system

	}
	else if (*alreadyGuest == 'n') //if no, instead create a new account for them
	{
		cout << "Sorry, we couldn't find your profile. Would you like to set one up?";
		inputOption >> ReturnChar();

		if (inputOption == 'y') //if y, function set up account
		{
			createAcc();
		}
		else {//if n, tell them can't create booking, return to home menu
			cout << "Sorry, unless you have an account, you can't create a booking.\nPlease press any button to return to the menu";
			cin;
			return;
		}
	}
	
	

	//select room

	//show dates available

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

///
/// Input files into the program
/// 
void inputGuest(ifstream& file, vector<Guest*>& vGuest) { 
	Guest temp;
	while (file >> temp) { 
		vGuest.push_back(new Guest(temp));
	}
}

void inputRoom(ifstream& file, vector<Room*>& vRoom) {
	Room temp;
	while (file >> temp) {
		vRoom.push_back(new Room(temp));
	}
}

void inputBookings(ifstream& file, vector<BookingInfo*>& vBookings) {
	BookingInfo temp;
	while (file >> temp) {
		vBookings.push_back(new BookingInfo(temp));
	}
}

void updateFiles(vector<Guest*>& vGuest, vector<Room*>& vRoom, vector<BookingInfo*>& vBookings)
{
	// --- Save guests ---
	{
		std::ofstream file("Guests.txt");
		if (!file) {
			std::cerr << "Error: could not open guest.txt for writing\n";
			return;
		}
		for (const Guest* g : vGuest) {
			if (g) {
				file << g->getID() << ","
					<< g->getName() << ","
					<< g->getNum() << "\n";
			}
		}
	}

	// --- Save rooms ---
	{
		std::ofstream file("Room.txt");
		if (!file) {
			std::cerr << "Error: could not open room.txt for writing\n";
			return;
		}
		for (const Room* r : vRoom) {
			if (r) {
				file << r->GetID() << ","
					<< r->GetPPN() << ","
					<< r->IsOccupied() << ","
					<< static_cast<int>(r->getAmenities()) << ","
					<< static_cast<int>(r->getType()) << "\n";
			}
		}
	}

	// --- Save bookings ---
	{
		std::ofstream file("Bookings.txt");
		if (!file) {
			std::cerr << "Error: could not open bookings.txt for writing\n";
			return;
		}
		for (const BookingInfo* b : vBookings) {
			if (b) {
				file << b->getID() << ","
					<< b->getGuest() << ","
					<< b->getRoom() << ","
					<< b->getCheckIn() << ","
					<< b->getCheckOut() << ","
					<< b->getCost() << "\n";
			}
		}
	}

	std::cout << "All data saved successfully!\n";
}

int main()
{
	//initialise variables
	bool programRunning = true;

	unique_ptr<int> menuOption = make_unique<int>();
	const int kRoom = 30;
	
	vector<Guest*> vGuest = {};
	vector<Room*> vRoom = {};
	vector<BookingInfo*> vBookings = {};

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
	*fileName = "Guests.txt";
	//guest info
	ifstream nameFile(*fileName);
	if (verifyFile(nameFile, fileName))
	{
		inputGuest(nameFile, vGuest);
		Test();
	}
	else
	{
		return 0;
	}
	nameFile.close();

	//room info
	*fileName = "Room.txt";
	ifstream roomFile(*fileName);
	if (verifyFile(roomFile, fileName))
	{
		inputRoom(roomFile, vRoom);
	}
	else
	{
		return 0;
	}
	roomFile.close();
	//booking info
	*fileName = "Bookings.txt";
	ifstream bookingFile(*fileName);
	if (verifyFile(bookingFile, fileName))
	{
		inputBookings(bookingFile, vBookings);
	}
	else
	{
		return 0;
	}
	bookingFile.close();

	//program loop
	while (programRunning) {
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
		case 0: //exit the system
			programRunning = false;
			updateFiles(vGuest, vRoom, vBookings);
			return 0;
		default:
			programRunning = false;
			break;
		}
	}

	return 0;
}
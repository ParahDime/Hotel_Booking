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

Guest* findaGuest(const std::string& name, const vector<Guest*>& vGuest) {
	for (Guest* g : vGuest) {
		if (g && g->getName() == name) {
			return g;
		}
	}
	return nullptr;
}

BookingInfo* findBooking(int id, const vector<BookingInfo*>& vBooking)
{
	for (BookingInfo* g : vBooking) {
		if (g && g->getGuest() == id) {
			return g;
		}
	}
	return nullptr;
}

Room* findRoom(int id, const vector<Room*>& vRoom)
{
	for (Room* g : vRoom) {
		if (g && g->GetID() == id) {
			return g;
		}
	}
	return nullptr;
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

Guest* createAcc(vector<Guest*>& vGuest) //create a user account
{
	cin.ignore(); // flush newline from previous input
	//name
	string name;
	cout << "Enter your full name: ";
	getline(cin, name);

	if (name.empty()) {
		cout << "Name cannot be empty.\n";
		return nullptr;
	}

	//number to contact them

	//also assign ID number to them (can be rand)
	int newID = vGuest.size() + 1;
	int callNum = 0;

	Guest* newGuest = new Guest(name, newID, callNum);
	vGuest.push_back(newGuest);

	cout << "Account created! Your ID is: " << newID << "\n";
	return newGuest;
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

bool checkIn(vector<Room*>& vRoom, vector<BookingInfo*>& vBookings, vector<Guest*>& vGuest)
{
	unique_ptr<string> userName = make_unique<string>(); 
	
	cout << "Please input your name";
	cin >> *userName;

	Guest* g = findaGuest(*userName, vGuest);
	if (!g) {
		cout << "No guest found with that name.\n";
		return false;
	}

	// 2. find their active booking
	BookingInfo* b = findBooking(g->getID(), vBookings);
	if (!b) {
		cout << "No active booking found under your name.\n";
		return false;
	}

	// 3. find the room
	Room* r = findRoom(b->getRoom(), vRoom);
	if (!r) {
		cout << "Error: your booking refers to an invalid room.\n";
		return false;
	}

	// 4. check occupancy
	if (r->IsOccupied()) {
		cout << "This room is already marked as occupied.\n";
		return false;
	}
	else {
		r->setOccupied();
		
	}

	return true;
}

bool checkOut(vector<Room*>& vRoom, vector<BookingInfo*>& vBookings, vector<Guest*>& vGuest)
{
	unique_ptr<string> userName = make_unique<string>();

	cout << "Please input your name";
	cin >> *userName;

	Guest* g = findaGuest(*userName, vGuest);
	if (!g) {
		cout << "No guest found with that name.\n";
		return false;
	}

	// find their booking
	BookingInfo* b = findBooking(g->getID(), vBookings);
	if (!b) {
		cout << "No active booking found.\n";
		return false;
	}

	// find room
	Room* r = findRoom(b->getRoom(), vRoom);
	if (!r) {
		cout << "Error: room not found.\n";
		return false;
	}

	// mark room as free
	r->setOccupied();
	return true;
}
//
//
//***********TO DEBUG*************
//
//
//Function for booking in out of hotel room
void checkInOut(vector<Room*>& vRoom, vector<BookingInfo*>& vBookings, vector<Guest*>& vGuest) {
	unique_ptr<bool> usingMenu = make_unique<bool>(true);
	unique_ptr<int> subMenuOption = make_unique<int>();
	
	int nightStay = 0;

	do {
		cout << "Booking In / Booking Out\n";

		cout << "Please select an option below";
		cout << "[1] Check In \n[2] Check Out \n [0] Return to menu";
		*subMenuOption = ReturnInt(0, 2);

		switch (*subMenuOption) {
		case 1: //booking in
			cout << "[1] : Checking In";// take guest details'
			if (checkIn(vRoom, vBookings, vGuest)) {
				cout << "Check-in complete. Enjoy your stay!\n";
			}
			else {
				cout << "Press any key to continue..";
				cin;
			}
			*usingMenu = false;
			break;
		case 2: 
			cout << "[2] : Checking Out";//booking out
			if (checkOut(vRoom, vBookings, vGuest)) {
				cout << "Checked out. We hope you enjoyed your stay!\n";
			}
			else
			{
				cout << "Press enter to continue..";
				cin;			
			}
			*usingMenu = false;
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



void createBooking(vector<Room*>& vRoom, vector<BookingInfo*>& vBookings, vector<Guest*>& vGuest, unordered_map < int, Room* > RoomIDs) { //create a booking system for the room (modified)
	unique_ptr<char> alreadyGuest = make_unique<char>();
	unique_ptr<string> name = make_unique<string>();
	char inputOption = ' ';
	string username;
	Room* chosenRoom = nullptr;
	Guest* selectedGuest = nullptr;


	cout << "Create a new booking\n";
	//ask if pre existing guest
	cout << "Do you have a profile with us?\n y/n";

	//check they are in the system
	*alreadyGuest = ReturnChar();
	if (*alreadyGuest == 'y') //if yes continue
	{
		cout << "Please enter your name (or press Enter to skip): ";
		cin.ignore(); // clear leftover newline
		getline(cin, username);

		if (!username.empty()) {
			selectedGuest = findaGuest(username, vGuest);

			if (selectedGuest) {
				cout << "Welcome back, " << selectedGuest->getName() << "!\n";
			}
			else {
				cout << "No matching profile found.\n";
			}
		}

	}

	if (*alreadyGuest == 'n' || !selectedGuest) //if no, instead create a new account for them
	{
		cout << "Sorry, we couldn't find your profile. Would you like to set one up? y/n";
		inputOption >> ReturnChar();

		if (inputOption == 'y') //if y, function set up account
		{
			selectedGuest = createAcc(vGuest); //THEN recall function AND place return afterwards
			if (!selectedGuest) {
				cout << "Failed to create an account. Returning to main menu...";
				return;
			}
		}
		else {//if n, tell them can't create booking, return to home menu
			cout << "Sorry, unless you have an account, you can't create a booking.\nPlease press any button to return to the menu";
			cin;
			return;
		}
	}
	
	cout << "\n=== Available Rooms ===\n";
	bool foundAny = false;

	for (Room* r : vRoom) {
		if (r && !r->IsOccupied()) {
			cout << "Room ID: " << r->GetID()
				<< " | Type: " << r->getAmenities()
				<< " | Price per night: $" << r->GetPPN() << "\n";
			foundAny = true;
		}
	}

	if (foundAny)
	{
		cout << "ID: 0 | Return";
	}

	if (!foundAny) {
		cout << "Sorry, no rooms are available right now.\n";
		return;
	}

	int chosenID;
	cout << "\nEnter the Room ID you'd like to book  (0 to cancel): ";

	//select room
	while (true) {

		// step 1: validate numeric input
		if (!(std::cin >> chosenID)) {
			std::cout << "Please enter a number.\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}

		// step 2: allow cancel
		if (chosenID == 0) {
			std::cout << "Booking cancelled.\n";
			return;
		}

		// step 3: search through vRoom
		//*********************************************
		//***Edit***Use an unordered map
		//*********************************************
		auto it = RoomIDs.find(chosenID);

		if (it == RoomIDs.end()) {
			std::cout << "No room with that ID exists. Try again.\n";
			continue;
		}

		Room* room = it->second;

		if (room->IsOccupied()) {
			std::cout << "Room is already occupied. Try again.\n";
			continue;
		}

		chosenRoom = room;
		break;
	}

	chosenRoom->setOccupied();

	//create new instance of the booking class
	

	cout << "\nBooking confirmed for Room " << chosenRoom->GetID() << ".\n";
	cout << "Enjoy your stay at Hotel Paradise!\n [Press enter to continue]";
	cin;
}


void getPrice(vector<Room*>& vRoom, vector<BookingInfo*>& vBookings, vector<Guest*>& vGuest) { //get the price of a room
	unique_ptr<bool> usingMenu = make_unique<bool>(true);
	unique_ptr<int> subMenuOption = make_unique<int>();

	int roomNo;
	int nights = 0;
	Room* target = nullptr;
	float total = 0.0;

	cout << "Please select an option\n";
	cout << "[1] Check Availability\n [2] Check Price\n [0] Return to Menu";
	*subMenuOption = ReturnInt(0, 2);
	switch (*subMenuOption) {
	case 0:
		return;
	case 1:
		cout << "\nRooms available:\n";

		for (Room* r : vRoom) {
			if (r && !r->IsOccupied()) {
				cout << "Room ID: " << r->GetID()
					<< " | Type: " << r->getType()
					<< " | Price per night: $" << r->GetPPN() << "\n";
			}
		}
	case 2:
		cout << "\nEnter Room ID to check the price: ";
		
		cin >> roomNo;

		

		for (Room* r : vRoom) {
			if (r && r->GetID() == roomNo) {
				target = r;
				break;
			}
		}

		if (!target) {
			cout << "Room not found.\n";
		}

		cout << "Room " << target->GetID() << " costs £" << target->GetPPN() << " per night.\n";

		
		cout << "How many nights? ";
		nights = ReturnInt(1, 30);

		total = target->GetPPN() * nights;

		cout << "Total price for " << nights << " night(s): £" << total << "\n";

		if (!target->IsOccupied()) {
			cout << "This room is currently available.\n";
			cout << "Would you like to create a booking? (y/n): ";

			char choice = ReturnChar();

			if (choice == 'y') {
				createBooking(vRoom, vBookings, vGuest);
				*usingMenu = false;
			}
		}

	default:
		return;
	}

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
void inputGuest(ifstream& file, vector<Guest*>& vGuest, unordered_map < int, Guest* > GuestIDs) {
	Guest temp;
	while (file >> temp) { 
		Guest* g = new Guest(temp);
		vGuest.push_back(new Guest(temp));
		GuestIDs[g->getID()] = g;
	}
}

void inputRoom(ifstream& file, vector<Room*>& vRoom, unordered_map < int, Room* > RoomIDs) {
	Room temp;
	while (file >> temp) {
		Room* r = new Room(temp);
		vRoom.push_back(new Room(temp));
		RoomIDs[r->GetID()] = r;
	}
}

void inputBookings(ifstream& file, vector<BookingInfo*>& vBookings, unordered_map < int, BookingInfo* > BookingIDs) {
	BookingInfo temp;
	while (file >> temp) {
		BookingInfo* b = new BookingInfo(temp);
		vBookings.push_back(new BookingInfo(temp));
		BookingIDs[b->getID()] = b;
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

	unordered_map < int, Guest* > GuestIDs;//hash for guests by ID
	unordered_map < int, BookingInfo* > BookingIDs;//hash for booking ID
	unordered_map < int, Room* > RoomIDs;//hash for room ID

	//initialise classes

	//read in files
	unique_ptr<string> fileName = make_unique<string>();
	*fileName = "Guests.txt";
	//guest info
	ifstream nameFile(*fileName);
	if (verifyFile(nameFile, fileName))
	{
		inputGuest(nameFile, vGuest, GuestIDs);
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
		inputRoom(roomFile, vRoom, RoomIDs);
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
		inputBookings(bookingFile, vBookings, BookingIDs);
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
			checkInOut(vRoom, vBookings, vGuest);
			break;
		case 2:	//get price
			getPrice(vRoom, vBookings, vGuest);
			break;
		case 3: //create booking
			createBooking(vRoom, vBookings, vGuest, RoomIDs);
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
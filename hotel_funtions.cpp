#include<iostream>
#include<cstdlib>		//Header used for generationg random number.
#include<ctime>			//Header used to access time in computer.
#include<string>		//Header used for input command.
#include"hotel_funtions.h"
using namespace std;

void totalOfRooms(int& finalRoomTotal) {	//Pass by reference
	//Set amount of rooms from 40-80.
	do {

		//Random number from 40-80.
		finalRoomTotal = (rand() % 41) + 40;
	} while (finalRoomTotal % 2 != 0);			//Exit loop when value is even number.
	&finalRoomTotal;
}

void displayMenu() {

	system("cls");		//Clear screen

	//Display
	cout << "***************[MAIN_MENU]***************" << endl;
	cout << "Please select the number of option below:" << endl << endl;
	cout << "1. Show prices" << endl;
	cout << "2. Book a room" << endl;
	cout << "3. Show available rooms" << endl;
	cout << "4. Search customer" << endl;
	cout << "5. Exit" << endl << endl;
	cout << "*****************************************" << endl;
	cout << "Option: ";
}

void showPrices() {

	system("cls");		//Clear screen

	//Display
	cout << "---------------------------------ROOM PRICES--------------------------------" << endl;
	cout << "\nSingle room: " << singleRoomPrice << " euros per night\n";
	cout << "Double room: " << doubleRoomPrice << " euros per night\n";
	cout << endl;
	cout << "Discounts:\n";
	cout << "You have a chance to win up to 20% discount each time you reserve a room\n\n";
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Press Enter to go back . . .";

	cin.get();
}

void displayRoomType() {

	system("cls");		//Clear screen

	//Display
	cout << "***************[ROOM_TYPE]***************" << endl;
	cout << "Please select the number of option below:" << endl << endl;
	cout << "1. Single room" << endl;
	cout << "2. Double room" << endl;
	cout << "3. Back to MAIN MENU" << endl << endl;
	cout << "*****************************************" << endl;
	cout << "Option: ";
}

void displayRoomNumber() {

	system("cls");		//Clear screen

	//Display
	cout << "**************[ROOM_NUMBER]**************" << endl;
	cout << "Please select the number of option below:" << endl << endl;
	cout << "1. Select room number" << endl;
	cout << "2. Get any available room" << endl;
	cout << "3. Back to MAIN MENU" << endl << endl;
	cout << "*****************************************" << endl;
	cout << "Option: ";
}

void displayRoomOrder(int roomTotal) {

	system("cls");		//Clear screen

	cout << "-----------------PLEASE READ-----------------" << endl;
	cout << "All of our single rooms has an ODD number" << endl;
	cout << "All of our double rooms has an EVEN number" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Please enter room number between 1 and ";
	cout << roomTotal << " :\n";
}

int searchDuplicate(int customerNumber[], int size, int testNumber) {

	int counter = 0;
	int position = -1;
	bool found = false;

	//Search duplicates
	while (counter < size && !found) {

		//If duplicate is found
		if (customerNumber[counter] == testNumber) {

			//Set sentinel
			found = true;

			//Save element location
			position = counter;
		}
		counter++;
	}

	return position;
}

void getCustomerInfo(Customer roomType[], int index) {

	system("cls");		//Clear screen

	//Display
	cout << "---------------------------------PLEASE READ--------------------------------" << endl;
	cout << "Please make sure that every information you enter is correct!\n";
	cout << "Wrong given information may cause you problems or delays when checking in!\n";
	cout << "----------------------------------------------------------------------------" << endl;

	//Get name
	cout << "Please enter your name: ";
	getline(cin >> ws, roomType[index].name);		//Ignore whitespaces

	//Get address. 
	cout << "Please enter your address: ";
	getline(cin, roomType[index].address);

	//Get phone number.
	do {
		cout << "Please enter your phone number: (+358)";
		cin >> roomType[index].phoneNumber;

		//If input is not a number
		cin.clear();	//Clear previous input.
		cin.ignore(100, '\n');	//Discard previous input.

	} while (roomType[index].phoneNumber < 1);

	//Get number of nights.
	do {
		cout << "How many nights would you like to stay? ";
		cin >> roomType[index].numberOfNights;

		//If input is not a number
		cin.clear();	//Clear previous input.
		cin.ignore(100, '\n');	//Discard previous input.

	} while (roomType[index].numberOfNights < 1);
}

void paymentTotal(int roomType, int nights) {
	int discountDraw;
	int totalprice = roomType * nights;

	system("cls");		//Clear screen

	//Normal price
	cout << "The total price is " << totalprice << " euros.\n";
	cout << "Press Enter and get a chance to win up to 20% discount!\n";

	cin.get();		//Pause

	// Draw for discount.
	discountDraw = rand() % 3;

	// No discount
	if (discountDraw == 0) {
		cout << "No discounts won.";
		cout << "\nBetter luck nextime!";
		cout << "\n\nThe final price is: " << totalprice << " euros";
	}

	// 10% discount
	else if (discountDraw == 1) {
		cout << "Congratulations! You have won 10% discount!";
		cout << "\n\nThe final price is: " << totalprice * 0.9 << " euros";
	}

	// 20% discount
	else {
		cout << "Congratulations! You have won 20% discount!";
		cout << "\n\nThe final price is: " << totalprice * 0.8 << " euros";
	}

	cout << "\n\nPress Enter to confirm booking . . .";

	cin.get();	//Pause

	cout << "\nBooking Confirmed!\n";
	cout << "Thank you for your reservation.\n";

	cin.get();	//Pause
}

int reservationNumber(int reservationNumbertest1[], int reservationNumbertest2[], int roomsPerType, int customerNumber) {
	int temporaryNumber, testNumber1, testNumber2, counter = 0;
	bool available = false;

	while (!available) {


		temporaryNumber = (rand() % 89999) + 10000;
		testNumber1 = searchDuplicate(reservationNumbertest1, roomsPerType, temporaryNumber);

		//Test first array
		if (testNumber1 == -1) {
			testNumber2 = searchDuplicate(reservationNumbertest2, roomsPerType, temporaryNumber);

			//Test second array
			if (testNumber2 == -1) {

				//Return value if all test passed
				return temporaryNumber;

				//Sentinel
				available = true;
			}
		}
	}

}

void showAvailableRooms(int singleRoomNumber[], int doubleRoomNumber[], int roomsPerType, int roomTotal) {

	int counter1 = 0, counter2 = 0;

	//Count available rooms for each room type.
	for (int i = 0; i < roomsPerType; i++) {

		//Test single rooms.
		if (singleRoomNumber[i] == 0) {

			//Increment when statement is true
			counter1++;
		}

		//Test double rooms.
		if (doubleRoomNumber[i] == 0) {

			//Increment when statement is true
			counter2++;
		}
	}

	system("cls");		//Clear screen

	cout << "------------------AVAILABLE ROOMS-----------------" << endl;
	cout << "\nAll rooms in total: " << roomTotal << " rooms.\n";
	cout << "\nSingle room: " << counter1 << " rooms available.\n";
	cout << "Double room: " << counter2 << " rooms available.\n";
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Press Enter to go back . . .";
	cin.get();
}

void searchCustomer(Customer singleRoom[], Customer doubleRoom[], int reservationNumber1[], int reservationNumber2[], int roomNumber1[], int roomNumber2[], int roomsPerType) {

	int option, reservationNumber, found = 0;
	string name;

	do {
		system("cls");		//Clear screen

		cout << "**************[SEARCH_BOOKING]**************" << endl;
		cout << "Please select the number of option below:" << endl << endl;
		cout << "1. Search by Reservation Number" << endl;
		cout << "2. Search by Name" << endl;
		cout << "3. Back to MAIN MENU" << endl << endl;
		cout << "********************************************" << endl;
		cout << "Option: ";

		cin >> option;

		//If input is not a number
		cin.clear();	//Clear previous input.
		cin.ignore(100, '\n');	//Discard previous input.


		//Search by reservation number.
		if (option == 1) {

			
			do{
				system("cls");		//Clear screen

				cout << "Please enter your reservation number (10000 - 99999):\n";
				cin >> reservationNumber;

				//If input is not a number
				cin.clear();	//Clear previous input.
				cin.ignore(100, '\n');	//Discard previous input.
			} while (reservationNumber < 10000 || reservationNumber>99999);
			
			cout << "\nResult:\n\n";

			//Search single rooms.
			for (int i = 0; i < roomsPerType; i++) {

				//Find match.
				if (reservationNumber1[i] == reservationNumber) {

					//Show info when found
					cout << "Room type: Single room";
					cout << "\nName: " << singleRoom[i].name;
					cout << "\nRoom number: " << roomNumber1[i];
					cout << "\nAddress: " << singleRoom[i].address;
					cout << "\nPhone number: (+358) " << singleRoom[i].phoneNumber;
					cout << "\nNights of stay: " << singleRoom[i].numberOfNights << " night(s).";
					cout << "\nReservation number: " << reservationNumber1[i];
					cout << endl << endl;

					//Increment when found
					found++;
				}			

				//Search double rooms.
				if (reservationNumber2[i] == reservationNumber) {

					//Show info when found
					cout << "Room type: Double room";
					cout << "\nName: " << doubleRoom[i].name;
					cout << "\nRoom number: " << roomNumber2[i];
					cout << "\nAddress: " << doubleRoom[i].address;
					cout << "\nPhone number: (+358) " << doubleRoom[i].phoneNumber;
					cout << "\nNights of stay: " << doubleRoom[i].numberOfNights << " night(s).";
					cout << "\nReservation number: " << reservationNumber2[i];
					cout << endl << endl;

					//Increment when found
					found++;
				}
			}

			//Display if not found
			if (found == 0) {
				cout << "Reservation number not found!";
			}

			cout << "\n\nPress Enter to go back . . .";

			//Avoid unwanted skips
			cin.clear();
			cin.ignore();	//Discard previous input.
			found = 0;
		}

		//Search by Name
		if (option == 2) {

			system("cls");		//Clear screen

			cout << "Please enter name:\n";
			getline(cin, name);

			cout << "\nResult:\n\n";

			//Search single rooms.
			for (int i = 0; i < roomsPerType; i++) {

				//Find match.
				if (singleRoom[i].name == name) {

					//Show info when found
					cout << "Room type: Single room";
					cout << "\nName: " << singleRoom[i].name;
					cout << "\nRoom number: " << roomNumber1[i];
					cout << "\nAddress: " << singleRoom[i].address;
					cout << "\nPhone number: (+358) " << singleRoom[i].phoneNumber;
					cout << "\nNights of stay: " << singleRoom[i].numberOfNights << " night(s).";
					cout << "\nReservation number: " << reservationNumber1[i];
					cout << endl << endl;

					//Increment when found
					found++;
				}
			}

			//Search double rooms.
			for (int i = 0; i < roomsPerType; i++) {

				//Find match.
				if (doubleRoom[i].name == name) {

					//Show info when found
					cout << "Room type: Double room";
					cout << "\nName: " << doubleRoom[i].name;
					cout << "\nRoom number: " << roomNumber2[i];
					cout << "\nAddress: " << doubleRoom[i].address;
					cout << "\nPhone number: (+358) " << doubleRoom[i].phoneNumber;
					cout << "\nNights of stay: " << doubleRoom[i].numberOfNights << " night(s).";
					cout << "\nReservation number: " << reservationNumber2[i];
					cout << endl << endl;

					//Increment when found
					found++;
				}
			}

			//Display if not found
			if (found == 0) {
				cout << "Reservation number not found!";
			}

			cout << "\n\nPress Enter to go back . . .";

			//Avoid unwanted skips
			cin.clear();
			cin.ignore();	//Discard previous input.

			//Reset counter
			found = 0;
		}

	} while (option != 3);

}

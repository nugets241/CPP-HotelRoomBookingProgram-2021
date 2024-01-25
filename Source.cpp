#include<iostream>
#include<cstdlib>		//Header used for generationg random number.
#include<ctime>			//Header used to access time in computer.
#include<string>		//Header used for input command.
#include"hotel_funtions.h"
using namespace std;

int main() {
	//Value of "time(0)" is ever changing.
	//Perfect for changing algorithm of srand() or for resetting seed:
	srand(time(0));

	int const MAX = 50;		//Set maximum array element per room type.
	Customer singleRoom[MAX], doubleRoom[MAX];

	//Arrays for room and booking number
	int singleRoomNumber[MAX] = { 0 }, singleReservationNumber[MAX] = { 0 };
	int doubleRoomNumber[MAX] = { 0 }, doubleReservationNumber[MAX] = { 0 };

	//Reserved room counters.
	int singleRoomCounter = 0, doubleRoomCounter = 0;

	int finalRoomTotal;
	totalOfRooms(finalRoomTotal);		//Randomized total amount of room.
	int roomsPerType = finalRoomTotal / 2;		//Maximun room amount per type.

	//Variables for testing.
	int temporaryNumber, testNumber, index = 0;
	bool available = false, found = false;


	cout << "Welcome to EJ Hotel"; 
	cout << "\n\nPress Enter to continue . . .\n";
	cin.get();		//System pause

	int option; 
	do
	{
		displayMenu();
		cin >> option;

		//If input is not a number
		cin.clear();	//Clear previous input.
		cin.ignore(100, '\n');	//Discard previous input.

		switch (option) {

		case 1:	//1. Show prices selected 
			showPrices();
			break;

		case 2:	 //2. Book a room selected
			do {
				displayRoomType();
				cin >> option;

				//If input is not a number
				cin.clear();	//Clear previous input.
				cin.ignore(100, '\n');	//Discard previous input.

				
				switch (option) {

					//1. Single room selected
				case 1:  
					do {
						displayRoomNumber();
						cin >> option;

						//If input is not a number
						cin.clear();	//Clear previous input.
						cin.ignore(100, '\n');	//Discard previous input.

						//	1. Select room number
						if (option == 1) {

							//Ensure that entered number is valid.
							do {
							
								displayRoomOrder(finalRoomTotal);	//This shows how rooms are organized.
								cin >> temporaryNumber;

								//If input is not a number
								cin.clear();	//Clear previous input.
								cin.ignore(100, '\n');	//Discard previous input.		

							} while (temporaryNumber % 2 == 0 || temporaryNumber <= 0 || temporaryNumber >= finalRoomTotal);

							//Test if room number is for duplicates.
							testNumber = searchDuplicate(singleRoomNumber, roomsPerType, temporaryNumber);

							//Inform room availability.
							(testNumber == -1) ?		//Conditional operator. Short if else statement.
								cout << "\nThis room is available." :		//Display if true
								cout << "Sorry this room is currently unavailable.";		//Display if false

							cout << "\nPress Enter to continue";
							cin.get();		//system pause

							//If room is not reserved.
							if (testNumber == -1) {

								//Save room number
								singleRoomNumber[singleRoomCounter] = temporaryNumber;

								//Get customer information
								getCustomerInfo(singleRoom, singleRoomCounter);
								
								//Calculate and show payment
								paymentTotal(singleRoomPrice, singleRoom[singleRoomCounter].numberOfNights);

								//Draw a reservation number.													
								singleReservationNumber[singleRoomCounter] = 
									reservationNumber(singleReservationNumber, doubleReservationNumber, roomsPerType, singleRoomCounter);

								//Display reservation number.
								cout << "Your reservation number is: ";
								cout <<singleReservationNumber[singleRoomCounter];
								cin.get();		//Pause

								//Increment to move to next array
								singleRoomCounter++;
							}								
								
						}

						// 2. Get any available room
						if (option == 2) {

							//Check room availability
							for (int i = 0; i < roomsPerType; i++) {

								if (singleRoomNumber[i] == 0) {
									available = true;
								}

								else {
									available = false;
								}

							}

							//Run when available room found
							if (available) {

								//Find room
								do {
									do {
										temporaryNumber = rand() % finalRoomTotal + 1;
									} while (temporaryNumber % 2 == 0);


									testNumber = searchDuplicate(singleRoomNumber, roomsPerType, temporaryNumber);
									if (testNumber == -1) {

										//Show room number
										cout << "\nYou have been given the room number: " << temporaryNumber;
										cout << "\nPress Enter to continue";
										cin.get();

										//Save room number
										singleRoomNumber[singleRoomCounter] = temporaryNumber;

										//Get customer information
										getCustomerInfo(singleRoom, singleRoomCounter);

										//Calculate and show payment
										paymentTotal(singleRoomPrice, singleRoom[singleRoomCounter].numberOfNights);

										//Draw a reservation number.													
										singleReservationNumber[singleRoomCounter] =
											reservationNumber(singleReservationNumber, doubleReservationNumber, roomsPerType, singleRoomCounter);

										//Display reservation number.
										cout << "Your reservation number is: ";
										cout << singleReservationNumber[singleRoomCounter];
										cin.get();		//System pause

										//Increment to move to next array
										singleRoomCounter++;
									}
								} while (testNumber != -1);

							}
							
							//Inform 
							else {
								cout << "\nSorry all of our single rooms are currently unavailable.";
								cout << "\n\nPress Enter to continue";
								cin.get();
							}
							
						}

					} while (option != 3);
					break;

					//1. Double room selected
				case 2:
					do {
						displayRoomNumber();
						cin >> option;

						//If input is not a number
						cin.clear();	//Clear previous input.
						cin.ignore(100, '\n');	//Discard previous input.

						//	1. Select room number
						if (option == 1) {

							//Ensure that entered number is valid.
							do {
								displayRoomOrder(finalRoomTotal);	//This shows how rooms are organized.
								cin >> temporaryNumber;

								//If input is not a number
								cin.clear();	//Clear previous input.
								cin.ignore(100, '\n');	//Discard previous input.		

							} while (temporaryNumber % 2 != 0 || temporaryNumber <= 0 || temporaryNumber >= (finalRoomTotal + 1) || cin.fail());

							//Test if room number is for duplicates.
							testNumber = searchDuplicate(doubleRoomNumber, roomsPerType, temporaryNumber);

							//Inform room availability.
							(testNumber == -1) ?		//Conditional operator. Short if else statement.
								cout << "\nThis room is available." :		//Display if true
								cout << "Sorry this room is currently unavailable.";		//Display if false

							cout << "\nPress Enter to continue";
							cin.get();		//system pause

							//If room is not reserved.
							if (testNumber == -1) {

								//Save room number
								doubleRoomNumber[doubleRoomCounter] = temporaryNumber;

								//Get customer information
								getCustomerInfo(doubleRoom, doubleRoomCounter);

								//Calculate and show payment
								paymentTotal(doubleRoomPrice, doubleRoom[doubleRoomCounter].numberOfNights);

								//Draw a reservation number.													
								doubleReservationNumber[doubleRoomCounter] =
									reservationNumber(doubleReservationNumber, singleReservationNumber, roomsPerType, doubleRoomCounter);

								//Display reservation number.
								cout << "Your reservation number is: ";
								cout << doubleReservationNumber[doubleRoomCounter];

								cin.ignore();    //Discard previous input.
								cin.get();		//System pause

								doubleRoomCounter++;	//Increment booking is successful.															
							}

						}

						// 2. Get any available room
						if (option == 2) {

							//Check room availability
							for (int i = 0; i < roomsPerType; i++) {

								if (doubleRoomNumber[i] == 0) {
									available = true;
								}

								else {
									available = false;
								}

							}

							//Run when available room found
							if (available) {

								//Find room
								do {
									do {
										temporaryNumber = rand() % finalRoomTotal + 1;
									} while (temporaryNumber % 2 != 0);


									testNumber = searchDuplicate(doubleRoomNumber, roomsPerType, temporaryNumber);
									if (testNumber == -1) {

										//Show room number
										cout << "\nYou have been given the room number: " << temporaryNumber;
										cout << "\nPress Enter to continue";
										cin.get();

										//Save room number
										doubleRoomNumber[doubleRoomCounter] = temporaryNumber;

										//Get customer information
										getCustomerInfo(doubleRoom, doubleRoomCounter);

										//Calculate and show payment
										paymentTotal(doubleRoomPrice, doubleRoom[doubleRoomCounter].numberOfNights);

										//Draw a reservation number.													
										doubleReservationNumber[doubleRoomCounter] =
											reservationNumber(doubleReservationNumber, singleReservationNumber, roomsPerType, doubleRoomCounter);

										//Display reservation number.
										cout << "Your reservation number is: ";
										cout << doubleReservationNumber[doubleRoomCounter];

										cin.ignore();		//Discard previous input.
										cin.get();		//System pause

										doubleRoomCounter++;	//Increment booking is successful.
									}
								} while (testNumber != -1);

							}

							//Inform 
							else {
								cout << "\nSorry all of our single rooms are currently unavailable.";
								cout << "\n\nPress Enter to continue";
								cin.get();
							}

						}

					} while (option != 3 || cin.fail());
				}


			} while (option != 3 || cin.fail());
			break;

		case 3:	//3. Show available rooms
			showAvailableRooms(singleRoomNumber, doubleRoomNumber, roomsPerType, finalRoomTotal);
			break;

		case 4:

			searchCustomer(singleRoom, doubleRoom, singleReservationNumber, doubleReservationNumber, singleRoomNumber, doubleRoomNumber, roomsPerType);
			break;





		}	
	} while (option != 5);

	system("pause>0");	//Remove junk text.
	return 0;
}

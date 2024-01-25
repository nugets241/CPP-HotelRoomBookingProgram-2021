#pragma once
#include<iostream>
#include<cstdlib>		//Header used for generationg random number.
#include<ctime>			//Header used to access time in computer.
#include<string>		//Header used for input command.
using namespace std;
int const singleRoomPrice = 100, doubleRoomPrice = 150;		//Prices.

struct Customer {
	string name;
	string address;
	int phoneNumber;
	int numberOfNights;
};
void totalOfRooms(int& finalRoomTotal);
void displayMenu();
void displayRoomType();
void displayRoomNumber();
void displayRoomOrder(int finalRoomTotal);
void showPrices();
void showAvailableRooms(int singleRoomNumber[], int doubleRoomNumber[], int roomsPerType, int roomTotal);
int searchDuplicate(int customerNumber[], int size, int testNumber);
void paymentTotal(int roomType, int nights);
void getCustomerInfo(Customer roomType[], int index);
int reservationNumber(int reservationNumbertest1[], int reservationNumbertest2[], int roomsPerType, int customerNumber);
void searchCustomer(Customer singleRoom[], Customer doubleRoom[], int reservationNumber1[], int reservationNumber2[], int roomNumber1[], int roomNumber2[], int roomsPerType);

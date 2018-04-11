#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"


/*Function: mainMenu
  in: Reference to Interger choice
  out: Modified choice
  Purpose: To choose an option from the displayed menu*/
void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
	cout<< "	2. Add Customer\n\n";
	cout<< "	3. Add Vehicle\n\n";
	cout<< "	4. Remove Customer\n\n";
	cout<< "	5. Remove Vehicle\n\n";
	cout<< "	6. Print Mechanics\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 6) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}

/*Function: printCustomers
  in: Reference to templated LinkedList of Customer class type list
  out: Modified output of entire customer's avaialable data
  Purpose: Prints the data formatted by the output operator from the list itself*/
void View::printCustomers(LinkedList<Customer>& list) const {
    cout << endl << "CUSTOMERS: " << endl << endl << endl;

	cout << list << endl;
}

/*Function: printMechanics
  in: Reference to templated LinkedList of Mechanic class type list
  out: Modified output of entire mechanic's avaialable data
  Purpose: Prints the data formatted by the output operator from the list itself*/
void View::printMechanics(LinkedList<Mechanic>& list) const {
	cout << endl << "MECHANICS: " << endl << endl << endl;

	cout << list << endl;
}

/*Function: promptCustomerInfo
  in: Reference to string f, l, a and p
  out: Modified string f,l,a and p
  Purpose: Prompt user input for first name, last name, address and phone number for the created customer*/
void View::promptCustomerInfo(string &f, string &l, string &a, string &p) const {

	//User input for customer info
	cout << "\nFirst name: ";
	getline(cin, f);

	cout << "Last name: ";
	getline(cin, l);

	cout << "Address: ";
	getline(cin, a);

	cout << "Phone number: ";
	getline(cin, p);

	cout << "\n*****Customer " << f << " " << l << " added to shop database!*****" << endl << endl;
}

/*Function: promptId
  out: Modified typedId
  Purpose: Prompt user for entered in id*/
int View::promptId() const {
	string str;
	int typedId;

	cout << "Customer ID: ";
	getline(cin, str);
    stringstream checkUser(str);
    checkUser >> typedId;

	return typedId;
}

/* Function: checksCustomerExists
   in: Location of Customer cust and integer enteredId
   Purpose: Let's the shopcontroller know to continue if the customer exists or not, if it doesn't then it will print a message stating so*/
int View::checksCustomerExists(Customer *cust, int enteredId)  const {
	if (cust == NULL) {
		cout << "\n*****Customer with id #" << enteredId << " does not exist in our database.*****" << endl << endl;
		return 0;
	}
	else 
		return 1;
}

/* Function: printsCustomerRemoved
   in: Location of Customer cust
   Purpose: Prints out message for removing the selected customer*/
void View::printsCustomerRemoved(Customer *cust) const {
	cout << "\n*****Customer " << cust->getFname() << " " << cust->getLname() << " is removed from the shop database!*****" << endl << endl;
}

/* Function: promptVehicleInfo 
   in: Location of Customer cust and Vehicle vehicle, references to string m, m2, c, integers y, m3, n and to char h
   out: Modified type, m, m2, c, y, m3, n and h
   Purpose: Prompts user input for type of vehicle and it's required components to make it*/
int View::promptVehicleInfo(Customer *cust, string &m, string &m2, string &c, int &y, int &m3, int &n, char &h) const {
	string str; //To take in an integer input using getline so it doesn't leave a '\n'
	int type;
	
	//User input for vehicle info
	cout << "\nVehicle Type (1: Car, 2: Truck, 3: Motorcycle): ";
	getline(cin, str);
	stringstream checkType(str);
	checkType >> type;

	while (type < 1 || type > 3) {
		cout << "Incorrect type (1: Car, 2: Truck, 3: Motorcycle): ";
		getline(cin, str);
		stringstream checkType(str);
		checkType >> type;
	}

	if (type >= 1 && type <= 3) {
		cout << "\nMake: ";
		getline(cin, m);

		cout << "Model: ";
		getline(cin, m2);

		cout << "Colour: ";
		getline(cin, c);

		cout << "Year: ";
		cin >> y;

		cout << "Mileage: ";
		cin >> m3;

		if (type == 1)  { //If the created vehicle is a car
			cout << "\n*****Car added for Customer " << cust->getFname() << " " << cust->getLname() << "!*****" << endl << endl;
			return type;
		}
	
		else if (type == 2) { //If the created vehicle is a truck
			cout << "Number of axles: ";
			cin >> n;	
		
			cout << "\n*****Truck added for Customer " << cust->getFname() << " " << cust->getLname() << "!*****" << endl << endl;
			return type;
		}		
		else if (type == 3) { //If the created vehicle is a motorcycle
			cout << "Has sidecar(y/n): ";
			cin >> h;

			cout << "\n*****Motorcycle added for Customer " << cust->getFname() << " " << cust->getLname() << "!*****" << endl << endl;
			return type;
		}
	}
}

/* Function: promptVehicleIndex
   in: Location of Customer cust and integer maxSize
   out: Modified num
   Purpose: Prompt user to enter in a number for a targeted vehicle index*/
int View::promptVehicleIndex(Customer *cust, int maxSize) const {
	int num;

	cout << "\nVehicle at index #: ";
	cin >> num;

	if (num < 0 || num > maxSize-1) {
		cout << "\n*****Sorry, vehicle at position " << num << " does not exist in " << cust->getFname() << " " << cust->getLname() << "'s vehicles.*****" << endl << endl;	
		return -1;
	}
	else {
		cout << "\n*****Vehicle at position " << num << " is removed from " << cust->getFname() << " " << cust->getLname() << "'s vehicles!*****" << endl << endl;
		return num;
	}
}

/*Function: pause
  out: Modified str
  Purpose: To simply pause after each operation was completed*/
void View::pause() const {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

/*Function: add
  out: Modified num
  Purpose: Handles user input for the menu*/
int View::readInt() {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
#include "Customer.h"

int Customer::nextId = 1000;

//Customer class 4-parameter Constructor
Customer::Customer(string f, string l, string a, string p) 
	: Person(f,l,a,p), id(nextId++) 
{

}

/*Function: +=
  in: Location of Vehicle v
  Purpose: Adds the vehicle to it's vehicle list by calling it's += operator*/
LinkedList<Vehicle>& Customer::operator+=(Vehicle *v) {
	return this->vehicles+=v;
}

/*Function: <<
  in: Reference to outstream output and Customer c
  out Modified output
  Purpose: Contains each customer's data in a string format*/
ostream& operator<<(ostream& output, Customer& c) {
	    ostringstream name;
        name << c.getFname() << " " << c.getLname();

		output << "Customer ID " << c.getId() << endl << endl
		         << "    Name: " << setw(40) << name.str() << endl 
		         << "    Address: " << setw(37) << c.getAddress() << endl
		         << "    Phone Number: " << setw(32) <<  c.getPhoneNumber() << endl;

			
		if (c.getVehicles().getSize() >= 1) 
			output << endl << setw(7) << "(" << c.getVehicles().getSize() << ") vehicles:" << endl << endl;
		else
			output << endl << setw(20) << "*****NO VEHICLES*****" << endl << endl;
		
		output << c.getVehicles();
		output << endl;

		return output;
}

/*Function: <
  in: Reference to Customer c
  Purpose: Returns if customer's last name is greater than the other compared customer's last name*/
bool Customer::operator<(Customer& c) const {
	if (this->getLname() < c.getLname()) 
		return true;
	return false;
}

/*Function: >
  in: Reference to Customer c
  Purpose: Returns if customer's last name is less than the other compared customer's last name*/
bool Customer::operator>(Customer& c) const {
	if (this->getLname() > c.getLname()) 
		return true;
	return false;
}

/*Function: getId
  Purpose: returns the id of the customer*/
int Customer::getId() const {
	return id;
}

/*Function: getNumVehicles
  Purpose: returns the function "getSize" from vehicles*/
int Customer::getNumVehicles() const{
	return vehicles.getSize();
}

/*Function: getVehicles
  Purpose: returns the VehicleArray from the customer*/
LinkedList<Vehicle>& Customer::getVehicles() {
	return vehicles;
}

#include "Vehicle.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

//Vehicle class 5-parameter constructor
Vehicle::Vehicle(string m, string m2, string c, int y, int m3) {
	make = m;
	model = m2;
	colour = c;
	year = y;
	mileage = m3;
}

/*Function: getMake
  Purpose: returns the make of the vehicle*/
string Vehicle::getMake() const {
	return make;
}

/*Function: getModel
  Purpose: returns the model of the vehicle*/
string Vehicle::getModel() const {
	return model;
}

/*Function: getColour
  Purpose: returns the colour of the vehicle*/
string Vehicle::getColour() const {
	return colour;
}

/*Function: getYear
  Purpose: returns the year of the vehicle*/
int Vehicle::getYear() const {
	return year;
}

/*Function: getMilage
  Purpose: returns the milage of the vehicle*/
int Vehicle::getMilage() const {
	return mileage;
}

/*Function: <<
  in: Reference to outstream output and Vehicle v
  Purpose: Calls it's toString method to modify it's specific output*/
ostream& operator<<(ostream& output, Vehicle& v) {
	output << v.toString();
	return output;
}

/*Function: toString
  in: Reference to outstream out
  out Modified out
  Purpose: Returns the vehicle's data that was put into a string format*/
string Vehicle::toString() const {
	ostringstream make_model, output;
     make_model << this->getMake() << " " << this->getModel();

	output << setw(7) << this->getColour() << " " 
         << this->getYear() << " " << setw(17) << make_model.str() << " (" 
         << this->getMilage() << "km)" << endl;	

	return output.str();
}

/*Function: <
  in: Reference to Vehicle v
  Purpose: Returns if vehicle's year is greater than the other compared vehicle's year*/
bool Vehicle::operator<(Vehicle& v) const {
	if (this->getYear() < v.getYear()) 
		return true;
	return false;
}

/*Function: >
  in: Reference to Vehicle v
  Purpose: Returns if vehicle's year is less than the other compared vehicle's year*/
bool Vehicle::operator>(Vehicle& v) const {
	if (this->getYear() > v.getYear())
		return true;
	return false;
}


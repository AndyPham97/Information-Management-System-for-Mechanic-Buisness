#include "Truck.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

//6-parameter Truck class constructor
Truck::Truck(string m, string m2, string c, int y, int m3, int n) 
	:Vehicle(m, m2, c, y, m3)
{
	numAxles = n;
}

/* Function: toString
   out: Modified output
   Purpose: Returns the truck's data into a string format*/
string Truck::toString() const {
	ostringstream make_model, output;
     make_model << this->getMake() << " " << this->getModel();

	if (this->numAxles == 1) {
		output << setw(15) << "TRUCK:" << setw(14) <<this->getColour() << " " 
		     << this->getYear() << " " << setw(20) << make_model.str() << " (" 
		     << this->getMilage() << "km), " << "1 axle" << endl;	
	}

	else {
		output << setw(15) << "TRUCK:" << setw(14) <<this->getColour() << " " 
		     << this->getYear() << " " << setw(20) << make_model.str() << " (" 
		     << this->getMilage() << "km), " << this->numAxles << " axles" << endl;	
	}

	return output.str();
}

#include "Motorcycle.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

//6-parameter Motorcycle class constructor
Motorcycle::Motorcycle(string m, string m2, string c, int y, int m3, bool has) 
	:Vehicle(m, m2, c, y, m3)
{
	hasSideCar = has;
}

/* Function: toString
   out: Modified output
   Purpose: Returns the motorcycle's data into a string format*/
string Motorcycle::toString() const {
	ostringstream make_model, output;
     make_model << this->getMake() << " " << this->getModel();
		
	if (this->hasSideCar == true) {
		output << setw(20) << "MOTORCYCLE:" << setw(13) << this->getColour() << " " 
		     << this->getYear() << " " << setw(20) << make_model.str() << " (" 
		     << this->getMilage() << "km), " << "has sidecar" << endl;	
	}

	else {
		output << setw(20) << "MOTORCYCLE:" << setw(10) << this->getColour() << " " 
		     << this->getYear() << " " << setw(15) << make_model.str() << " (" 
		     << this->getMilage() << "km), " << "doesn't have sidecar" << endl;	
	}

	return output.str();
}

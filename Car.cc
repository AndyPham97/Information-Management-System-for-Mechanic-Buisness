#include "Car.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

//5-parameter Car class constructor
Car::Car(string m, string m2, string c, int y, int m3) 
	:Vehicle(m, m2, c, y, m3)
{
}

/* Function: toString
   out: Modified output
   Purpose: Returns the car's data into a string format*/
string Car::toString() const {
	ostringstream make_model, output;
     make_model <<this->getMake() << " " << this->getModel();

	output << setw(13) << "CAR:" << setw(17) << this->getColour() << " " 
         << this->getYear() << " " << setw(22) << make_model.str() << " (" 
         << this->getMilage() << "km)" << endl;	

	return output.str();
}

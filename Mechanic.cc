#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
#include "Mechanic.h"

int Mechanic::nextId = 5000;

//Mechanic class 5-parameter Constructor
Mechanic::Mechanic(string f, string l, string a, string p, int s) 
	: Person(f,l,a,p), id(nextId++), salary(s)
{

}

/*Function: <<
  in: Reference to outstream output and Mechanic m
  out Modified output
  Purpose: Contains each Mechanic's data in a string format*/
ostream& operator<<(ostream& output, Mechanic& m) {
	    ostringstream name;
        name << m.getFname() << " " << m.getLname();

		output << "Employee ID " << m.getId() << endl << endl
		         << "    Name: " << setw(40) << name.str() << endl 
		         << "    Address: " << setw(37) << m.getAddress() << endl
		         << "    Phone Number: " << setw(32) <<  m.getPhoneNumber() << endl
				 << "    Salary: " << setw(38) << m.getSalary() << endl;
		
		output << endl;

		return output;
}

/*Function: getId
  Purpose: returns the id of the mechanic*/
int Mechanic::getId() const {
	return id;
}

/*Function: getSalary
  Purpose: returns the salary of the mechanic*/
int Mechanic::getSalary() const {
	return salary;
}

/*Function: <
  in: Reference to Mechanic m
  Purpose: Returns if mechanic's salary is greater than the other compared mechanic's salary*/
bool Mechanic::operator<(Mechanic& m) const {
	if (this->getSalary() < m.getSalary()) 
		return true;
	return false;
}

/*Function: >
  in: Reference to Mechanic m
  Purpose: Returns if mechanic's salary is less than the other compared mechanic's salary*/
bool Mechanic::operator>(Mechanic& m) const {
	if (this->getSalary() > m.getSalary()) 
		return true;
	return false;
}

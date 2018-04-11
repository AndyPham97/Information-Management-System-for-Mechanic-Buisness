#include "Person.h"
using namespace std;

//Person class 4-parameter Constructor
Person::Person(string f, string l, string a, string p) 
{
	firstName = f;
	lastName = l;
	address = a;
	phoneNumber = p;
}

/*Function: getFname
  Purpose: returns the first name of the person*/
string Person::getFname() const {
	return firstName;
}

/*Function: getLname
  Purpose: returns the last name of the person*/
string Person::getLname() const {
	return lastName;
}

/*Function: getAddress
  Purpose: returns the address of the person*/
string Person::getAddress() const {
	return address;
}

/*Function: getPhoneNumber
  Purpose: returns the phone number of the person*/
string Person::getPhoneNumber() const {
	return phoneNumber;
}

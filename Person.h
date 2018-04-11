#ifndef PERSON_H
#define PERSON_H
using namespace std;
#include <string>

class Person
{
  public:
	 Person(string="", string="", string="", string="");
     string getFname() const;
     string getLname() const;
     string getAddress() const;
     string getPhoneNumber() const;

  protected:
	 string address;
     string phoneNumber;

  private:
     string firstName;
     string lastName;
};

#endif

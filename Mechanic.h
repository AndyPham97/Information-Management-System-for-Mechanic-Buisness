#ifndef MECHANIC_H
#define MECHANIC_H
using namespace std;
#include <string>
#include "Person.h"

class Mechanic : public Person
{

  friend ostream& operator<<(ostream&, Mechanic&);

  public:
	 Mechanic(string="", string="", string="", string="", int = 0);
     int getSalary() const;
	 int getId() const;

	bool operator<(Mechanic&) const;
	bool operator>(Mechanic&) const;

  private:
	static int nextId;

	const int id;
    int salary;
};

#endif

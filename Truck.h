#ifndef TRUCK_H
#define TRUCK_H
#include <string>
#include "Vehicle.h"
using namespace std;

class Truck: public Vehicle {

    public:
        Truck(string, string, string, int, int, int);
		string toString() const;

	private:
		int numAxles;
};

#endif

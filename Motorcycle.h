#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include <string>
#include "Vehicle.h"
using namespace std;

class Motorcycle: public Vehicle {

    public:
        Motorcycle(string, string, string, int, int, bool);
		string toString() const;

	private:
		bool hasSideCar;
};

#endif

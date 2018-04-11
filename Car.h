#ifndef CAR_H
#define CAR_H
#include <string>
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle {

    public:
        Car(string, string, string, int, int);
		string toString() const;
};

#endif

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {

	friend ostream& operator<<(ostream&, Vehicle&);

    public:
        Vehicle(string, string, string, int, int);
        string getMake() const;
        string getModel() const;
        string getColour() const;
        int getYear() const;
        int getMilage() const;
		virtual string toString() const = 0;

		bool operator<(Vehicle&) const;
		bool operator>(Vehicle&) const;

    private:
        string make;
        string model;
        string colour;
        int year;
        int mileage;
};

#endif

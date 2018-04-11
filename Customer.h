#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Person.h"
#include "Vehicle.h"
#include "LinkedList.h"
//#include "VehicleList.h"
using namespace std;

class Customer: public Person 
{

	friend ostream& operator<<(ostream&, Customer&);

    public:
        Customer(string="", string="", string="", string="");
        int getId() const;
        int getNumVehicles() const;
    	LinkedList<Vehicle>& getVehicles();

		LinkedList<Vehicle>& operator+=(Vehicle*);
		bool operator<(Customer&) const;
		bool operator>(Customer&) const;
        
    private:
        static int nextId;
  
        const int id;
        //VehicleList vehicles;
	    LinkedList<Vehicle> vehicles;
};

#endif

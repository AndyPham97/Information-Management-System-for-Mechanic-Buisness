#ifndef VIEW_H
#define VIEW_H

#include "LinkedList.h"
#include "Mechanic.h"
#include "Customer.h"
#include "Vehicle.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(LinkedList<Customer>&) const;
		int promptId() const;
		int checksCustomerExists(Customer*, int) const;
		void promptCustomerInfo(string&, string&, string&, string&) const;
		void printsCustomerRemoved(Customer*) const;
		int promptVehicleInfo(Customer*, string&, string&, string&, int&, int&, int&, char&) const;
		int promptVehicleIndex(Customer*, int) const;
		void printMechanics(LinkedList<Mechanic>&) const;
        void pause() const;

    private:
        int readInt();
};

#endif

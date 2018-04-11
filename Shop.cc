#include "Shop.h"
#include "defs.h"
using namespace std;

/*Function: getCustomer
  in: Interger id
  Purpose: Calls the [] operator from the customers list*/
Customer& Shop::getCustomer(int id) const { 
	int i = 0;
	Customer *exists = customers[i];

	while (exists != 0) {
		if (exists->getId() == id)
			break;
		i++;
		exists = customers[i];
	}

	return *exists; 
} 

/*Function: getCustomers()
  Purpose: Returns it's list called 'customers'*/
LinkedList<Customer>& Shop::getCustomers() { return customers; }


/*Function: getMechanics
  in: Interger i
  Purpose: returns it's list called 'mechanics' */
LinkedList<Mechanic>& Shop::getMechanics() {
	return mechanics;
}

/*Function: +=
  in: Location of Customer c
  Purpose: Adds the customer to it's customers list by calling it's += operator by the list itself*/
LinkedList<Customer>& Shop::operator+=(Customer* c) {
	return this->customers+=c;
}

/*Function: -=
  in: Location of Customer c
  Purpose: Deletes the customer from it's customers list by calling it's -= operator by the list itself*/
LinkedList<Customer>& Shop::operator-=(Customer* c) {
	return this->customers-=c;
}

/*Function: +=
  in: Location of Mechanic m
  Purpose: Adds the mechanic from it's mechanics list by calling it's += operator by the list itself*/
LinkedList<Mechanic>& Shop::operator+=(Mechanic *m) {
	return this->mechanics+=m;
}

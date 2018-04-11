#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "LinkedList.h"
#include "Mechanic.h"

class Shop{

    public:
        Customer& getCustomer(int) const;
        LinkedList<Customer>& getCustomers();

        LinkedList<Mechanic>& getMechanics();

		LinkedList<Customer>& operator+=(Customer*);
		LinkedList<Customer>& operator-=(Customer*);
		LinkedList<Mechanic>& operator+=(Mechanic*);

    private:
		LinkedList<Customer> customers;
		LinkedList<Mechanic> mechanics;

};

#endif

#include "ShopController.h"
#include "LinkedList.h"

#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
ShopController::ShopController() {

    initShop();

}

/*Function: launch
  Purpose: Calls the appropriate functions to perform the operation for each option on the menu*/
void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);
        
        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } else if (choice == 2) {
			addCustomer();
			view.pause();
        } else if (choice == 3) {
			addVehicle();
			view.pause();
        } else if (choice == 4) {
      		removeCustomer();
			view.pause();
        } else if (choice == 5) {
			removeVehicle();
			view.pause();
		} else if (choice == 6) {
			view.printMechanics(mechanicShop.getMechanics());
			view.pause();
		}else {
            break;
        }
    }
}

/*Function: initShop
  out: Modified shop's customers, customers' vehicles and shop's mechanics
  Purpose: Creates default customers with own set of vehicles in the shop as well as mechanics*/
void ShopController::initShop() {

    //add data fill here
	//Creating the dynamically allocated Customer objects
	Customer *cust1 = new Customer("Andy", "Pham", "2441 Falcon Avenue", "(807)220-4422");
	Customer *cust2 = new Customer("Randi", "Price", "2441 Falcon Avenue", "(807)323-2998");
	Customer *cust3 = new Customer("Fox", "McCloud", "20XX Lane", "(807)220-2020");
	Customer *cust4 = new Customer("Falco", "Lambardi", "20BX Drive", "(807)220-2121");
	Customer *cust5 = new Customer("Captain", "Falcon", "20GX Falcon Avenue", "(807)220-4444");
	Customer *cust6 = new Customer("Marth", "Tipper", "6040 Avenue", "(807)220-6040");

	//Creating the dynamically allocated Vehicle objects	
	Vehicle *vehicle1 = factory.create("Toyota", "Highlander", "Crimson", 2018, 50000);
	Vehicle *vehicle2 = factory.create("Toyota", "Prius", "Teal Blue", 2012, 10000);
	Vehicle *vehicle3 = factory.create("Toyota", "Avalon", "Silver", 2010, 15000);
	Vehicle *vehicle4 = factory.create("Toyota", "Corolla", "White", 2011, 15000);
	Vehicle *vehicle5 = factory.create("Dodge", "Dakota", "Rice", 2007, 30000, 8);
	Vehicle *vehicle6 = factory.create("Ford", "Super Duty", "Black", 2010, 20000, 4);
	Vehicle *vehicle7 = factory.create("Honda", "Africa Twin", "Navy Blue", 2013, 20000, true);
	Vehicle *vehicle8 = factory.create("Honda", "Zinga", "Eggshell", 2014, 20000, false);
	Vehicle *vehicle9 = factory.create("Ford", "Omega Lead", "Flesh", 2016, 10000, 6);
	Vehicle *vehicle10 = factory.create("Cheverlot", "Beast", "Green", 2011, 10000, 6);
	Vehicle *vehicle11 = factory.create("Nissan", "Versa", "Orange", 2012, 15000);
	Vehicle *vehicle12 = factory.create("Nissan", "Leaf", "Green", 2009, 8000);

	//Creating the dynamically allocated Mechanic objects
	Mechanic *mech1 = new Mechanic("Bruce", "Wayne", "1007 Mountain Drive", "(879)550-6649", 92000);
	Mechanic *mech2 = new Mechanic("Tony", "Stark", "10880 Malibu Point", "(999)224-7851", 124000);
	Mechanic *mech3 = new Mechanic("Charles", "Xavier", "2005 Blue Pinnacle", "(809)227-7788", 35000);

	//Addding 4 vehicles to customer 1
	*cust1+=vehicle1;
	*cust1+=vehicle12;
	*cust1+=vehicle5;
	*cust1+=vehicle6;

	//Adding 3 vehicles to customer 2
	*cust2+=vehicle2;
	*cust2+=vehicle4;
	*cust2+=vehicle9;

	//Adding 2 vehicles to customer 3
	*cust3+=vehicle3;
	*cust3+=vehicle7;

	//Adding one vehicle each to customers 4,5,and 6
	*cust4+=vehicle8;
	*cust5+=vehicle10;
	*cust6+=vehicle11;

	//Registering the customers to the mechanic shop
	mechanicShop+=cust1;
	mechanicShop+=cust2;
	mechanicShop+=cust3;
	mechanicShop+=cust4;
	mechanicShop+=cust5;
	mechanicShop+=cust6;

	//Registering the mechanics to the mechanic shop
	mechanicShop+=mech1;
	mechanicShop+=mech2;
	mechanicShop+=mech3;

}

/*Function: addCustomer
  in: Location of Customer newCust
  out: Modified shop's customers and Customer newcust
  Purpose: Calls promptCustomerInfo to take in user input to create the new customer and add it to the shop*/
void ShopController::addCustomer() {
	string newf_Name, newl_Name, newAddress, newPhone;

	view.promptCustomerInfo(newf_Name, newl_Name, newAddress, newPhone);
	Customer *newCust = new Customer(newf_Name, newl_Name, newAddress, newPhone);

	mechanicShop+=newCust;	
}

/*Function: addVehicle
  in: Location of Customer cust and Vehicle newVehicle
  out: Modified customer's vehicles, Customer cust and Vehicle newVehicle
  Purpose: Calls promptId, checksCustomerExists and promptVehicleInfo to create the required vehicle for the selected customer*/
void ShopController::addVehicle() {
	string newMake, newModel, newColour;
	int newYear, newMilage, num;
	char has;
	int id, type, exists;
	Customer *cust;
	Vehicle *newVehicle;

	id = view.promptId();

	cust = &(mechanicShop.getCustomer(id)); //Points to a customer's address that has an id matched with 'id'
	exists = view.checksCustomerExists(cust, id); 

	if (exists == 0) //If no customer in the database exists
		return;

	else {
		type = view.promptVehicleInfo(cust, newMake, newModel, newColour, newYear, newMilage, num, has);

		if (type == 1) 
			newVehicle = factory.create(newMake, newModel, newColour, newYear, newMilage);
		else if (type == 2)
			newVehicle = factory.create(newMake, newModel, newColour, newYear, newMilage, num);
		else if (type == 3) {
			if (has == 'y')
				newVehicle = factory.create(newMake, newModel, newColour, newYear, newMilage, true);
			else
				newVehicle = factory.create(newMake, newModel, newColour, newYear, newMilage, false);
		}
		else
			return;

		*cust+=newVehicle;
	}
}

/*Function: removeCustomer
  in: Location of Customer cust
  out: Modified customers list from the selected customer
  Purpose: Calls promptId, checksCustomerExists and printsCustomerRemoved to delete the customer from the database*/
void ShopController::removeCustomer() {
	int id, exists;
	Customer *cust;
	
	id = view.promptId();

	cust = &(mechanicShop.getCustomer(id)); //Points to a customer's address that has an id matched with 'id'
	exists = view.checksCustomerExists(cust, id);

	if (exists == 0) //If no customer in the database exists
		return;

	else {
		view.printsCustomerRemoved(cust);
		mechanicShop-=cust;	
	}
}

/*Function: +=
  in: Location of Customer cust
  out: Modified vehicles list from the selected customer
  Purpose: Calls promptId, checksCustomerExists and promptVehicleInfo to delete the vehicle from the selected customer's vehicles */
void ShopController::removeVehicle() {
	int id, exists, position;
	Customer *cust;

	id = view.promptId();

	cust = &(mechanicShop.getCustomer(id)); //Points to a customer's address that has an id matched with 'id'
	exists = view.checksCustomerExists(cust, id);

	if (exists == 0) //If no customer in the database exists
		return;

	else {
		LinkedList<Vehicle>& list = cust->getVehicles();
		position = view.promptVehicleIndex(cust, list.getSize());
		if (position == -1)  
			return;
		else {
			
			if (position < 0 || position > cust->getNumVehicles()-1) 
				return;
			else {
				Vehicle *v = list[position];
				list-=v;
			}
		}
	}
}

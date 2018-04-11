#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include "View.h"
#include "VehicleFactory.h"
#include "Shop.h"

class ShopController {

    public:
        ShopController();
		void addCustomer();
		void addVehicle();
		void removeCustomer();
		void removeVehicle();
        void launch();

		void traverseMechanics();
    private:
        Shop mechanicShop;
		VehicleFactory factory;
        View view;
        void initShop();
};

#endif

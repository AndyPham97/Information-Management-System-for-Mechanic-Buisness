OBJ = main.o ShopController.o View.o Shop.o VehicleFactory.o Customer.o Vehicle.o Car.o Truck.o Motorcycle.o Person.o Mechanic.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc -g

ShopController.o:	ShopController.cc ShopController.h LinkedList.h 
	g++ -c ShopController.cc -g

View.o:	View.cc View.h 
	g++ -c View.cc -g

Shop.o:	Shop.cc Shop.h 
	g++ -c Shop.cc -g

VehicleFactory.o: VehicleFactory.cc VehicleFactory.h
	g++ -c VehicleFactory.cc -g

Mechanic.o: Mechanic.cc Mechanic.h Person.h
	g++ -c Mechanic.cc -g

Customer.o:	Customer.cc Customer.h Person.h
	g++ -c Customer.cc -g

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -c Vehicle.cc -g

Car.o: Car.cc Car.h
	g++ -c Car.cc -g

Truck.o: Truck.cc Truck.h
	g++ -c Truck.cc -g

Motorcycle.o: Motorcycle.cc Motorcycle.h
	g++ -c Motorcycle.cc -g

Person.o: Person.cc Person.h
	g++ -c Person.cc -g

clean:
	rm -f $(OBJ) mechanicshop

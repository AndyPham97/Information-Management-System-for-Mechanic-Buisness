# Information-Management-System-for-Mechanic-Buisness

*****PURPOSE*****
A small program that simulates an automotive mechanic business having a record
database that keeps track of their customers and their vehicles and employees as well, also with the capabilities
for the insertion and deletion of both for customers and vehicles for any customer in the database. 

*****LIST OF FILES*****
- There is 12 c++ files and they are Customer.cc, main.cc, Mechanic.cc,
Person.cc, Shop.cc, ShopController.cc, Vehicle.cc, Car.cc, Truck.cc, Motorcycle.cc, VehicleFactory.cc and View.cc
- There is 13 header files and they are Customer.h, LinkedList.h, defs.h, 
Mechanic.h, Person.h, Shop.h, ShopController.h, Vehicle.h, VehicleFactory.h, Car.h, Truck.h, Motorcycle.h and View.h
- There is 12 object files and they are Customer.o, main.o, 
Mechanic.o, Person.o, Shop.o, ShopController.o, Vehicle.o, VehicleFactory.o, Car.o, Truck.o, Motorcycle.o and View.o
- There is only 1 executable file and that is mechanicshop
- There is only 1 Makefile

*****COMPILATION*****
 Type in the exact commands in the LXTerminal:
1.  make clean (This deletes the object files)
2. make (Creates and links all of the object files together to produce the executable 'machineshop'

*****LAUNCHING & OPERATING INSTRUCTIONS*****
Type in the exact command after compiing the program: ./machineshop
To check memory leaks while running the program, type in: valgrind ./machineshop

After that, you will see a menu with choices 1, 2, 3, 4,  5, 6 or 0.
'1' prints out each registered customer's data and their owned vehicles' data as well
'2' prompts them a series of user input for first name, last name, address and phone number 
to register the new customer into the shop database
'3' prompts to enter in an id to find the targeted customer with that matched entered in id. If
it does not match it stops and returns to the menu, but if it does then it prompts you again
with a series of user input for make, model, colour, year and mileage for adding in a new vehicle for
that specific customer
'4' prompts to enter in an id to find the targeted customer with that matched entered in id. If
it does not match it stops and returns to the menu, but if it does then it deletes the customer
from the database
'5' prompts to enter in an id to find the targeted customer with that matched entered in id. If
it does not match it stops and returns to the menu, but if it does then it prompts you again for 
entering in the index position of the vehicle in it's vehicle list (0- (# of vehicles-1)). If the # is not
in that range, it will return to the menu, if it doesn't then it deletes the vehicle from it's list
'6' prints out each employee's data 
'0' exits the program


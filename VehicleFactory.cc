#include "VehicleFactory.h"
#include <string>
using namespace std;

/*Function: create
  in: string m, m2, c and integers y and m3
  out: Modified car
  Purpose: Creates a car object*/
Vehicle* VehicleFactory::create(string m, string m2, string c, int y, int m3) {
	Vehicle *car = new Car(m, m2, c, y, m3);
	return car;
}

/*Function: create
  in: string m, m2, c and integers y, m3 and n
  out: Modified truck
  Purpose: Creates a truck object*/
Vehicle* VehicleFactory::create(string m, string m2, string c, int y, int m3, int n) {
	Vehicle *truck = new Truck(m, m2, c, y, m3, n);
	return truck;
}

/*Function: create
  in: string m, m2, c and integers y and m3 and boolean  has
  out: Modified cycle
  Purpose: Creates a motorcycle object*/
Vehicle* VehicleFactory::create(string m, string m2, string c, int y, int m3, bool has) {
	Vehicle *cycle = new Motorcycle(m, m2, c, y, m3, has);
	return cycle;
}

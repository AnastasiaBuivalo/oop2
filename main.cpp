#include "interfaces.h"


int main()
{
    ccar car;
    car.init_car(1, true, 100);

    car_park park;
    park.init_car_park();
    park.add_car(car);

    ccargo cargo;
    cargo.init_cargo(1, 50);
    storage garage;
    garage.init_storage();
    garage.to_storage(cargo);

    rroute route;
    route.init_route(20, 1);
    if(park.search_car(&car, cargo, route) == 1){
        park.car_is_busy(car);
        car.output();
        garage.of_storage(&cargo);
        cargo.output();
    }
    return 0;
}


//
// Created by настя буйвало on 18/02/2022.
//

#ifndef OOP2NEW_INTERFACES_H
#define OOP2NEW_INTERFACES_H

struct ccar{
    int type;      //1-легковая, 2-грузовая, 3-спец техника
    bool status;   //1-свободна, 0-занята
    int payload;  //грузоподъемность
    int number; //номер машины в базе автодиспетчера

    void init_car(int, bool, int);
    void output();
};

//маршрут
struct rroute{
    int length;  //протяженность
    int type;  //требуемый тип машины

    void init_route(int, int);
};

//груз
struct ccargo{
    int size;  //1-маленький, 2-средний, 3-большой
    int weight; //вес
    int number;//артикул(-1, если не числится на складе)

    void init_cargo(int, int);
    void output();
};

struct car_park{
    ccar cars[100];
    int count;   //количество свободных машин

    void init_car_park();
    void add_car(ccar);
    int search_car(ccar*, ccargo, rroute);
    void car_is_busy(ccar);
};

struct storage{
    ccargo cargo_s[1000];//1000-максимальная вместимость
    int count;  //кол-во грузов на складе

    void init_storage();
    int to_storage(ccargo);
    void of_storage(ccargo*);
};

#endif //OOP2NEW_INTERFACES_H

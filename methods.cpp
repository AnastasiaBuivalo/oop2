//
// Created by настя буйвало on 18/02/2022.
//

#include <iostream>
#include "interfaces.h"

using namespace std;


void ccar::init_car(int ttype, bool tstatus, int tpayload) {
    type = ttype;      //1-легковая, 2-грузовая, 3-спец техника
    status = tstatus;   //1-свободна, 0-занята
    payload = tpayload;  //грузоподъемность
}

void ccargo::init_cargo(int tsize , int tweight) {
    size = tsize;  //1-маленький, 2-средний, 3-большой
    weight = tweight; //вес
}

void rroute::init_route(int tlength, int ttype) {
    length = tlength;
    type = ttype;
}

void storage::init_storage() {
    count = 0;
}

void car_park::init_car_park() {
    count = 0;
}

void ccar::output() {
    cout << "Тип машины(1-легковая, 2-грузовая, 3-спец техника): " << type << endl;
    cout << "Статус(1-свободна, 0-занята): " << status << endl;
    cout << "Грузоподъемность: " << payload << endl;
    cout << "Номер в автопарке: " << number << endl;
}

void ccargo::output() {
    cout << "Размер груза (1-маленький, 2-средний, 3-большой): " << size << endl;
    cout << "Вес: " << weight << endl;
    cout << "Артикул: " << number << endl;//артикул(-1, если не числится на складе)
}

//добавление новой машины в автоопарк
void car_park::add_car(ccar car) {
    cars[count].payload = car.payload;
    cars[count].type = car.type;
    cars[count].status = true;
    cars[count].number = count;
    count++;
}

//поиск подходящей машины для маршрута route и груза cargo
int car_park::search_car(ccar* car, ccargo cargo, rroute route) {
    int fl = 0;
    int n = 0;
    while(fl == 0 && n < count){
        if(cars[n].status == true && cars[n].payload >= cargo.weight && cars[n].type == route.type){
            car->type = cars[n].type;
            car->payload = cars[n].payload;
            car->status = false;
            car->number = n;
            fl = 1;
        }
    }
    if(fl == 1)
        return 1;
    else
        return -1;
}

//машина уехала на заказ
void car_park::car_is_busy(ccar car) {
    cars[car.number].status = false;
    count--;
}

//получение груза на склад
int storage::to_storage(ccargo cargo){
    if(count < 999){ //проверка на наличие места на сладе
        int i = 0;
        while(cargo_s[count].weight != 0)
            i++;
        cargo_s[i].number = i;
        cargo_s[i].weight = cargo.weight;
        cargo_s[i].size = cargo.size;
        count++;
        return 1;
    }
    else
        return 0;
}

void storage::of_storage(ccargo* cargo){
    cargo->size = cargo_s[cargo->number].size;
    cargo->weight = cargo_s[cargo->number].weight;
    count--;
    cargo_s[cargo->number].size = 0;
    cargo_s[cargo->number].weight = 0;
    cargo->number = -1;
}

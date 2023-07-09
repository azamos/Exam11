
#include "exam.h"

int count1=0; // do not change!

void fx1(){
    count1++;
}

int main()
{
    SoftwareUpdate su1 = { .softwareVersion = "v.1.1.1",.date = {1,1,2020},.description = "alpha" };
    SoftwareUpdate su2 = { .softwareVersion = "v.1.1.2",.date = {2,1,2020},.description = "1st patch" };
    SoftwareUpdate su3 = { .softwareVersion = "v.1.1.3",.date = {3,1,2020},.description = "2nd patch" };
    SoftwareUpdate su4 = { .softwareVersion = "v.1.2.1",.date = {1,2,2020},.description = "minor update 1" };
    SoftwareUpdate su5 = { .softwareVersion = "v.1.3.1",.date = {2,2,2020},.description = "minor update 2" };
    SoftwareUpdate su6 = { .softwareVersion = "v.1.4.1",.date = {2,3,2020},.description = "minor update 3" };
    SoftwareUpdate su7 = { .softwareVersion = "v.2.1.1",.date = {1,1,2021},.description = "MAJOR update 1" };
    SoftwareUpdate su8 = { .softwareVersion = "v.2.2.1",.date = {1,6,2021},.description = "minor update to MAJOR update 1" };
    SoftwareUpdate su9 = { .softwareVersion = "v.3.1.1",.date = {1,1,2022},.description = "MAJOR update 2" };
    SoftwareUpdate su10 = { .softwareVersion = "v.3.2.1",.date = {1,6,2022},.description = "minor update to MAJOR update 2" };
    SoftwareUpdate su11 = { .softwareVersion = "v.3.2.2",.date = {5,9,2022},.description = "patch update to minor update to MAJOR update 2" };
    SoftwareUpdate* teslaSoftware[11] = {&su1,&su2,&su3,&su4,&su5,&su6,&su7,&su8,&su9,&su10,&su11};
    TeslaCar** tesla_cars = NULL;
    TeslaDB tesla = { .cars = tesla_cars,.numCars = 0,.numSofwareUpdaes = 11,.updates = &teslaSoftware };
    TeslaCar tc1 = { .batteryLevel = 100,.color = "white",.location = {.x = 0,.y = 0},.numOfSoftwareUpdates = 0,
        .plateNumber="111111111",.software=NULL,.type="model s",.yearOfManufacture=2019};
    TeslaCar tc2 = { .batteryLevel = 97,.color = "silver",.location = {.x = 1000,.y = 1000},.numOfSoftwareUpdates = 0,
        .plateNumber = "111111112",.software = NULL,.type = "model x",.yearOfManufacture = 2020 };
    TeslaCar tc3 = { .batteryLevel = 100,.color = "black",.location = {.x = 1100,.y = 1000},.numOfSoftwareUpdates = 0,
        .plateNumber = "111111113",.software = NULL,.type = "model t",.yearOfManufacture = 2021 };
    //Q1 - A
    int sum = 0;
    sum += addNewCar(&tesla, tc1);
    sum += addNewCar(&tesla, tc2);
    sum += addNewCar(&tesla, tc3);
    /*adding duplcates, should not actualy add them*/
    sum += addNewCar(&tesla, tc1);
    sum += addNewCar(&tesla, tc2);
    sum += addNewCar(&tesla, tc3);
    if (sum != 3) {
        printf("error in q3.a: addNewCar is wrong");
    }
    printf("%d cars were added to the array\n", sum);
    printf("\nq1-a test was a success\n");
    //Q2-B
    Location l1 = { .x = 10,.y = 10 };
    Location l2 = { .x = 1001,.y = 1001 };
    Location l3 = { .x = 1099, .y = 1000 };
    OTAUpdate(&tesla, l1, 100, su1);//should only apply for TeslaCar tc1
    OTAUpdate(&tesla, l2, sqrt(2), su7);//tc2
    OTAUpdate(&tesla, l2, 100, su8);//for tc2 AND tc3
    OTAUpdate(&tesla, l3, 1, su9);
    printf("done");
    return 0;
}

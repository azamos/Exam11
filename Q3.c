#include "exam.h"

/*calculates euclidean distance in certasian system*/
float distance(Location l1, Location l2) {
	return sqrt(pow((l1.x - l2.x), 2) + pow((l1.y - l2.y), 2));
}

/*recieves the entire string version, and the index of the least significant bit
of a given sub_version(e.g, for v.11.22.33, if I want to get 22, right will be 6)*/
int subver_to_int(char* str,int right) {
	/*start at the ones digit of the subversion*/
	int i = right;
	int sub_ver = 0;
	int exp = 1;
	while(i>=0 && str[i]!='.') {
		int d = str[i] - '0';
		sub_ver += d * exp;
		exp *= 10;
		i--;
	}
	return sub_ver;
}
/*returns integer array with 3 cells, such that: arr=[major,minor,patch]*/
int* deconstruct_ver(char* str) {
	int* deconstructed = (int*)malloc(sizeof(int) * 3);
	int i = 2;
	for(int j= 0; j<3;j++){
		while (i < 20 && str[i] != '.' && str[i]!='\n') {
			i++;
		}
		deconstructed[j] = subver_to_int(str, i - 1);
		i += 1;//Because right now, str[i]=='.'
	}
	return deconstructed;
}
/*like strcmp, only for version
* returns: 1 if v1>v2, -1 if v1<v2, and 0 if v1==v2.
*/
int vercmp(char* v1, char* v2){
	int* v1_decon = deconstruct_ver(v1);
	int* v2_decon = deconstruct_ver(v2);
	int v1_major = v1_decon[0];
	int v2_major = v2_decon[0];
	if (v1_major == v2_major) {
		int v1_minor = v1_decon[1];
		int v2_minor = v2_decon[1];
		if(v1_minor==v2_minor){
			int v1_patch = v1_decon[2];
			int v2_patch = v2_decon[2];
			if (v1_patch == v2_patch) {
				return 0;
			}
			return v1_patch > v2_patch ? 1 : -1;
		}
		return v1_minor > v2_minor ? 1 : -1;
	}
	return v1_major > v2_major ? 1 : -1;
}

int addNewCar(TeslaDB* tesla, TeslaCar car)
{
	int i = 0;
	while (i < tesla->numCars) {
		TeslaCar* existing_car = tesla->cars[i];
		if(strcmp(car.plateNumber,existing_car->plateNumber) == 0){
			return 0;
		}
	}
	tesla->cars = (TeslaCar**)realloc(tesla->cars, sizeof(TeslaCar*) * (1 + tesla->numCars));
	/*Assummption: all allocations are succesful.*/
	/*Create a copyof teslaCar.*/
	TeslaCar* newCar = (TeslaCar*)malloc(sizeof(TeslaCar));
	newCar->type = (char*)malloc(sizeof(char) * (1 + strlen(car.type)));
	strcpy(newCar->type, car.type);
	newCar->color = (char*)malloc(sizeof(char) * (1 + strlen(car.color)));
	strcpy(newCar->plateNumber, car.plateNumber);
	newCar->yearOfManufacture = car.yearOfManufacture;
	newCar->numOfSoftwareUpdates = car.numOfSoftwareUpdates;
	newCar->batteryLevel = car.batteryLevel;
	newCar->location.x = car.location.x;
	newCar->location.y = car.location.y;
	/*
	* Now to allocate SoftwareUpdate list, and populate it with the same refs.
	*/
	newCar->software = (SoftwareUpdate**)malloc(sizeof(SoftwareUpdate*) * (car.numOfSoftwareUpdates));
	for (int i = 0; i < car.numOfSoftwareUpdates; i++) {
		newCar->software[i] = car.software[i];
	}
	return 1;//Added car to DB
}
void OTAUpdate(TeslaDB* tesla, Location location, float radius, SoftwareUpdate udate)
{
	for (int i = 0; i < tesla->numCars; i++) {
		TeslaCar* car = tesla->cars[i];
		/*first, check if car is in radius from location,
		and if udate.version is newer than current version car has installed*/
		if (distance(car->location, location) <= radius &&
			vercmp(udate.softwareVersion,
				car->software[car->numOfSoftwareUpdates - 1]>0)
			) {
			/*Now, check if one of the previously installed
			software is the same as udate*/
			for (int j = 0; j < car->numOfSoftwareUpdates; j++) {
				if (vercmp(car->software[j], udate.softwareVersion) == 0) {
					return;//Updated is unnecesarry
				}
			}
			//if program reaches here, we need to update:

			/*reallocate*/
			car->software = (SoftwareUpdate**)realoc(car->software,
				sizeof(SoftwareUpdate*) * (1+car->numOfSoftwareUpdates));
			//create a deep-copy of udate. first, malloc:
			SoftwareUpdate* newUpdate = (SoftwareUpdate*)malloc(sizeof(SoftwareUpdate));
			strcpy(newUpdate->softwareVersion, udate.softwareVersion);
			newUpdate->date.day = udate.date.day;
			newUpdate->date.month = udate.date.month;
			newUpdate->date.day = udate.date.year;
			newUpdate->description = (char*)malloc(sizeof(char) * (1 + strlen(udate.description)));
			strcpy(newUpdate->description, udate.description);
			/*finally, add deep copy to car's swupdate list*/
			car->software[car->numOfSoftwareUpdates++] = newUpdate;
		}
	}
}
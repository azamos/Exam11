#include "exam.h"

int replaceDigit(int num)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	
	/*Write your code down here*/	
	if (num == 0) {
		return 0;
	}
	int d = num % 10;
	int new_d;
	if(d){
		new_d = d % 2 ? d - 1 : d - 2;
	}
	else {
		new_d = 9;
	}
	return new_d + 10 * replaceDigit(num / 10);
}

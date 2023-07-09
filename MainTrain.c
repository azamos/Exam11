
#include "exam.h"

int count1=0; // do not change!

void fx1(){
    count1++;
}

int main()
{
    //1
    int matrix[ROWS][COLS] = {{0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,1,1,1,0,0,0,0},
                             {0,0,1,1,1,1,1,0,0,0},
                             {0,1,1,1,1,1,1,1,0,0}};
    int size = 0;

    int* arr = FromMatToArr(matrix, ROWS, COLS, &size);

    if (arr[2] != 326)
        printf("FromMatToArr function is wrong for train1_1 (-8)\n");



    int matrix1[ROWS][COLS] = {{0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,1,1,0,0,0,0},
                             {0,0,0,1,1,1,1,0,0,0},
                             {0,0,0,0,1,1,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0}};
    size = 0;
    arr = FromMatToArr(matrix1, ROWS, COLS, &size);


    if (arr[0] + arr[1] != 381)
        printf("FromMatToArr function is wrong for train1_2 (-8)\n");

    int matrix2[ROWS][COLS] = { {0,0,0,0,0,0,0,0,0,0},
                             {0,1,1,1,1,1,1,0,0,0},
                             {0,0,1,1,1,1,1,1,0,0},
                             {0,1,1,1,1,1,1,0,0,0},
                             {0,0,1,1,1,1,1,1,0,0} };

    size = 0;
    arr = FromMatToArr(matrix2, ROWS, COLS, &size);

    if (size != 4 && arr[3] != 427)
        printf("FromMatToArr function is wrong for train1_3 (-9)\n");

       
	// 2
	

    int res = replaceDigit(2349);
   
    if(count1<2)
        printf("replaceDigit function is not recursive (-8)\n");
    else{
       if (res!=228)
	    printf("replaceDigit function is wrong for train2_1  (-8)\n");
    }
	count1 = 0;
	
    res = replaceDigit(345);
   
    if(count1<2)
        printf("replaceDigit function is not recursive (-8)\n");
    else{
       if (res!=224)
	    printf("replaceDigit function is wrong for train2_2  (-8)\n");
    }
	count1 = 0;	
	
    res = replaceDigit(918);
   
    if(count1<2)
        printf("replaceDigit function is not recursive (-9)\n");
    else{
       if (res!=806)
	printf("replaceDigit function is wrong for train2_3  (-9)\n");
    }

	//3
	printf("Question 3 will be checked manually, don't worry (-50)\n");
	printf("done");
    return 0;
}

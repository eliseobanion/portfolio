#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Elise O'Banion
//Program 4, CounterSort
//October 2019

int CounterSort (int * data, int length)
{
    //arrays
    int csa[] = {0,0,0,0,0,0,0,0,0,0};   //CounterSort array, counts integers

    //counters
    int lvc1 = 0;   //counter one, initialize
    int lvc2 = 0;   //counter two, initialize
    int lvc3 = 0;   //counter three, initialize

    /**********************************************
     * Sorts all values from data into array csa. *
     * It will count each integer and increment   *
     * the count of the integer's index located   *
     * in array csa.                              *
     * *********************************************/
    for (lvc1 = 0; lvc1 < length; lvc1++)
    {
       csa[data[lvc1]]++;                //increments index in csa of data
    }//for

    /**********************************************************************
     * Sorts array csa into data. csa stands for counter sort array and   *
     * data stands for new array. It goes through each spot in csa and    *
     * decrements the value there until zero. For every time it           *
     * decrements, the index will be added to the data array, effectively *
     * sorting it.                                                        *
     **********************************************************************/
    for (lvc1 = 0; lvc1 < 10; lvc1++) //goes through each index of csa
    {
       for (lvc2 = csa[lvc1]; lvc2 > 0; lvc2--) //goes through each n in csa
       {
            data[lvc3] = lvc1;                  //adds index value to na
            lvc3++;                             //increases lvc3
       }//inner for
    }//outer for


  /*****************************************
   * prints sorted array                   *
   * for (lvc1 = 0; lvc1 < length; lvc1++) *
   * {                                     *
   *     printf("%d", data[lvc1]);         *
   * }//for                                *
   * printf("\n End of Array\n");          *
   * ***************************************/

    /*****************************
     * Returns if sort was false *
     *****************************/
 
    for (lvc1 = 1; lvc1 < length; lvc1++) //goes through na
    {
        if (data[lvc1 - 1] > data[lvc1])      //if value a-1 is > a, false
        {
            return 0;                     //return false
        }//if
    }//for

    /***************************************
     * Returns if sort was successful/true *
     ***************************************/
    return 1;   //return 1 for true




};//CounterSort



void main()
{
    //counters
    int lvc1 = 0;   //initialize first counter
    int lvc2 = 0;   //initialize second counter

    //array and relevant data
    int length = 0; //initialize length
    int a[100];     //initialize array of ints
    int n = 0; /*initialize n, the number of times the array is tested*/

    //successes and failures
    int s = 0;      //initialize success
    int f = 0;      //initialize failure
    int temp = 0;    //initalizes temp


    srand(time(0)); //make the random, true random


   /**********************************************
    * input n, the number of arrays to be sorted *
    **********************************************/
   printf("Please input the number of arrays you would like sorted:\n");
   scanf("%d", &n); //getting the input

    /**************************************
     *fill array n times and counter sort *
     **************************************/
    for (lvc1 = 0; lvc1 < n; lvc1++) //loop n times
    {
        length = rand() % 90 + 10;             //creates random length

        /***************
         * fills array *
         ***************/
        // printf("array values: \n");          //pt1
        for (lvc2 = 0; lvc2 < length; lvc2++)   //loop length times
        {
            a[lvc2] = rand() % 9 + 1;           /*randomly inputs an integer
                                                 between 10 and 1 */
           // printf("%d", a[lvc2]);            //prints array pt2n
        }//inner for

       // printf("\nend of values\n");          prints array pt3

       /***************************************
        * sort and add failures and successes *
        ***************************************/
       temp = CounterSort(a, length);   //temp is boolean, 0 = f, else t
       if (temp == 0)                   //if false, make failure
           f++;                         //adds to failures
        else                            //if true, make success
           s++;                         //adds to successes

    }//outer loop

    /********************************
     * print failures and successes *
     ********************************/
    printf("Successes           Failures\n");       //header
    printf("    %d                  %d   \n", s, f);   //successes and failures

}//main

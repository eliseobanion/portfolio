#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>


//Elise O'Banion
//Algorithms and Data Structures
//Program 3

struct node
{
    char * info;//will contain the char array
    struct node *next; //moves node by one
};

int enqueue(char * string, struct node ** front, struct node ** back)
{
    struct node * newNode = NULL;

    newNode = (struct node *) malloc (sizeof(struct node)); //create new node

    newNode->info = string;         //assign data to new node
    newNode->next = NULL;           //make sure new node initially doesn't point to anything

    if((*back))
        (*back)->next = newNode;    //link new node with last node

    *back = newNode;    //new node should be at back

    if (!(*front))
        *front = *back; //link first node to front if NULL

    return 1;

}//enqueues to the queue

char * dequeue(struct node ** front, struct node ** back)
{

   if (*front == NULL)
        return NULL;

   char * str2;

   struct node *nodeToDequeue = NULL;

    nodeToDequeue = *front;     //grab element to dequeue
    *front = (*front)->next;    //move front up one

    if (*front == *back)
    {front = NULL;
        back = NULL;
    }//if


    str2 = nodeToDequeue->info; //puts char array in str2

    free(nodeToDequeue);        //garbage collecting

    return str2;                //returns char array that was dequeued

}//dequeues items from queue

void main()
{
    char * str;             //pointers to char array

    time_t t;
    srand((unsigned) time (&t)); //makes numbers truly random

   struct node *back, *front;     //pointers to back and front nodes

    back = NULL;            //back is nothing
    front = NULL;           //front is nothing

    long lvc1 = 0;          //first counter
    long lvc2 = 0;          //second counter
    srand((unsigned) time (&t)); //makes numbers truly random

   struct node *back, *front;     //pointers to back and front nodes

    back = NULL;            //back is nothing
    front = NULL;           //front is nothing

    long lvc1 = 0;          //first counter
    long lvc2 = 0;          //second counter
    long lvc3 = 0;          //third counter
    long lvc4 = 0;          //fourth counter
    long lvc5 = 0;          //fifth counter
    long DQ = 0;            //counter of dequeues


    //load ten nodes
    for (lvc1 = 0; lvc1 < 10; lvc1++)
    {
     	str = (char *) calloc(1000000, sizeof(char));
        for (lvc2 = 0; lvc2 < 1000000; lvc2++)
        {
            str[lvc2] = rand() % 24 + 65;
        }//loads str with one million characters

        enqueue(str, &front, &back);
    //   free(str);
     }//enqueues ten nodes


    //load and deload nodes, test 100, 1000, 10000, and final 100000
    for (lvc3 = 0; lvc3 < 100000; lvc3++)
    {
     	str = (char *) calloc (1000000, sizeof(char));
        for (lvc4 = 0; lvc4 < 1000000; lvc4++)
        {
            str[lvc4] = rand() % 24 + 65;
      }//loads str with one million characters

        enqueue(str, &front, &back);
    //   free(str);
     }//enqueues ten nodes


    //load and deload nodes, test 100, 1000, 10000, and final 100000
    for (lvc3 = 0; lvc3 < 100000; lvc3++)
    {
     	str = (char *) calloc (1000000, sizeof(char));
        for (lvc4 = 0; lvc4 < 1000000; lvc4++)
        {
            str[lvc4] = rand() % 24 + 65;
        }//for

        enqueue(str, &front, &back);

        str = (char *) calloc (1000000, sizeof(char));
        str = dequeue(&front, & back);
        DQ++;
       printf("%d\n", DQ);
       free(str);
    }//for

    //dequeues twelve nodes
    for (lvc5 = 0; lvc5 < 12; lvc5++)
    {
      str = dequeue(&front, &back);
      DQ++;
      printf("%d\n", DQ);
      free(str);
    }

    printf("%d\n", DQ);



}//main

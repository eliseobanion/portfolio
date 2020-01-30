#include <limits.h>

int main()
{
//Elise O'Banion
//Program 1
//Algorithms and Data Structures


	int matrix1[5][5] = {
		//row a  b  c  d  e
			{0, 15, 4, 0, 0}, //row 1
			{15, 0, 0, 2, 6}, //row 2
			{4, 0, 0, 1, 0}, // row 3
			{0, 2, 1, 0, 8}, //row 4
			{0, 6, 0, 8, 0} //row 5
			}; //end matrix1 declaration
			
			
	int visit[5] = {0, 0, 0, 0, 0}; //distance declaration, set to 0
	int prev[5] = {0, 0, 0, 0, 0}; //previous declaration, set to 0		
	int cost[5] = {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX}; //cost declaration, set to 0
	int remb = 0;
	
	int temp = INT_MAX - 10000;
	int i = 0;	
			for (int lcv15 = 0; lcv15 < 5; lcv15++) //loop through all nodes
			{
			temp = INT_MAX - 10000;
				for (int j = 0; j < 5; j++) //loop down 3 column chart and accross the current row of the matrix
				{
					if (matrix1[i][j] != 0 && visit[j] == 0 && (matrix1[i][j] < cost[j]))
					{
						cost[j] = (matrix1[i][j]);
						prev[j] = i;
					}//if
				}//first inner for
				
				for (int k = 0; k < 5; k++) //loop down the 3 column chart
				{
					//if you find a lower-cost univisted node, remember the cost and which node it is
					if (visit[k] == 0 && temp > cost[k])
					{
						temp = cost[k];
						remb = k;
					}//if
				}//second inner for
				i = remb;
				visit[remb] = 1;
				
			}//outer for
			
			printf("Visited   Previous   Cost\n"); //print out headers
			
			for (int m = 0; m < 5; m++)
			{
				printf("%d            %d         %d\n", visit[m],prev[m],cost[m]);
			}//for
}//main

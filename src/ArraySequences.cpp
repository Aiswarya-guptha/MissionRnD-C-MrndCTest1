/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL || len<=3)
		return NULL;
	
	int *result = (int*) malloc(6 * sizeof(int));
	result[0] = 0; result[1] = 0; result[2] = 0; result[3] = 0; result[4] = 0; result[5] = 0;
	float div = (arr[1] / (1.0*arr[0]));
	int dif = (arr[1] - arr[0]), gs = 0, as = 0;

	for (int iter = 2; iter < len; iter++){
		//arithmetic sequences
		if ((result[3] == 0) && ((arr[iter] - arr[iter - 1]) != dif)){
			if (iter - as >= 3){
				if (result[1] == 0){
					result[0] = as;
					result[1] = iter - 1;
					dif = arr[iter] - arr[iter - 1];
					as = iter - 1;
				}
				else{
					result[2] = as;
					result[3] = iter - 1;
				}
			}
			else{
				dif = arr[iter] - arr[iter - 1];
				as = iter - 1;
			}
		}
		else if (result[3] == 0 && (iter == len -1)){
			result[2] = as;
			result[3] = iter;
		}
		//geometric sequence
		if (result[5] == 0 && ((arr[iter] / (1.0*arr[iter - 1])) != div)){
			if (iter - gs >= 3){
				result[4] = gs;
				result[5] = iter - 1;
			}
			else{
				div = arr[iter] / (1.0*arr[iter - 1]);
				gs = iter - 1;
			}
		}
		else if (result[5] == 0 && (iter == len - 1)){
			result[4] = gs;
			result[5] = iter ;
		}
	}
	return result;
}
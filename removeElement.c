#include <stdio.h>
/**
 * Give an array nums and a value val, remove all instances of that value in-place and 
 * return a new length.  Do not allocate extra space for another array, you must do this
 * by modifying the input array in-place with O(1) extra memory. 
 * The orders of elements can be changed. It doesn't matter what you leave beyond the new 
 * length.
 *
 * Example 1:
 * Give nums = [3,2,2,3] val 3,
 * Your function should return length = 2, with the first two elements of numbs being 2. 
 *
 * It doesn't matter what you leave beyond the returned new length. 
 *
 * Example 2:
 * Give nums = [0,1,2,2,3,0,4,2], val = 2,
 *
 * YOur function should return length = 5, with the first five elements of nums
 * containing 0, 1, 3, 0, 4. Note that the orders of those 5 elements can be arbitrary.
 * It doesn't matter what values are set the returned length.
 *
 * array is passed by reference, which means modifications to input array known to the 
 * caller as well. 
 */
int removeElement(int* a, int numsSize, int val) 
{

	// int *pointer_to_nums = nums;
	// Checking for empty array
	if (numsSize == 0) return 0;
	int front_pointer = 0;						// int *front_pointer = a;
	int last_pointer = numsSize-1;			// int *last_pointer = (a+numsSize-1);
	int remain_element = 0;
	while(front_pointer <= last_pointer) 
	{
			
      while(a[front_pointer] != val)
		{						
			if(front_pointer==last_pointer) break;				  
			front_pointer++;
		}
		// a[front_pointer] right here: is either reach the end or have value different than val
		while(a[last_pointer] == val)
		{
				  if(last_pointer == front_pointer)
				  {
						last_pointer--;
						break;
				  }
			

			last_pointer--;			
		}
		// a[last_pointer] right here: is either reach the front or have the value different than val
		if(front_pointer >= last_pointer) break;
		a[front_pointer++] = a[last_pointer--];
		remain_element++;

	}
	if (last_pointer < 0) return 0;
	return last_pointer + 1;
}

int main(void) 
{
	
	//int a[] = {3,2,2,3};
	int a[] = {2,0,2,0,0,3,0,0,4,0};
	int* pointer_to_array_a = a;
	int after_remove =	removeElement(a,10,4);
	int i = 0;
	printf("\n\n");	
	while(i < after_remove) 
	{
		printf("%d  \n",*(pointer_to_array_a++));
		i++;
	}	
	return 0;
}

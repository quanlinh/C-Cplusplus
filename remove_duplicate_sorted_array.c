#include <stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	// always check for degenerate case, meaning less if 0 size
	if(numsSize == 0) return 0;
	int i = 0, j = 1;
	// in this while loop the invariant is that guranteed j 
	// never go off the fences, since it only increase in once 
	// in if else branch. Besides, the i pointer only increase 
	// when it has the different to swap, therefore it will need
	// to increase 1 when it swap. However, the j pointer is already
	// different with it previous element, thus it will swap, then increase. 
	while(j < numsSize) 
	{
		if(nums[j-1] == nums[j]) j++;
		else nums[++i] = nums[j++];
	}
	// return i+1 because 0 index base, and we need to return the size. 
	return i+1;
}

int main(void)
{
	int nums[] = {0,0,1,1,2,2,3,3,4};	  
	printf("\n%d\n",removeDuplicates(nums,9));
	return 0;
}

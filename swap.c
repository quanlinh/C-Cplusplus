#include <stdio.h>

void swap(int *pointer_to_x, int *pointer_to_y) 
{
	int temp = *pointer_to_x;	// stored the value of whatever x point to to temp
	*pointer_to_x =*pointer_to_y;	// stored the value of whaterver y point to to x
	*pointer_to_y = temp;
}

int main(void)
{
	int a = 3;
	int b = 4;
	swap (&a,&b);
	printf ("a = %d, b = %d\n", a, b);
	return 0;
}

/**
 * Let us consider why we need to indentify the type of varialbe that
 * pointers pointst to, as in:
 *
 * 	int *ptr;
 * One reason for doing so that later, once ptr "points to" something, 
 * if we write:
 *
 * 	*ptr = 2;
 * the compiler know how many bytes to copy into that memory location 
 * to by ptr. If ptr was declared as pointing to an integer, 2 bytes 
 * would be copied, if a long, 4 copied. But, defining the type that 
 * the pointer points to permits a number of other intersting ways 
 * a compiler can intepret code. For example, consider block in memory 
 * consisting if ten integers in a row. That is, 20 bytes of memory are 
 * set aside to hold 10 integers.
 *
 * Now, let's say we point our integer pointer ptr at the first of these 
 * integers. Futhermore lets say tha integer is located at memory location
 * 100 (decimal). What happends when we write:
 * 
 * 	ptr + 1;	// This is "pointer arithmetic"
 * Because the compiler knows this is a pointer (i.e. its value is an address)
 * and that if points to an integer(its current address, 100, is the address 
 * of an integer), its adds 2 to ptr instead of 1, so the pointer "point to" 
 * the next integer, at memory location 102. 
 * Similary, were the ptr declared as a pointer to a long, it would add 4 to 
 * it instead of 1. 
 *
 * ptr + 1 is equivalent with ++ptr or ptr++
 *
 * Since  a block of 10 integers located contigously in memory is, an array of 
 * integers, htis brings up an interesting relation ship between pointers and arrays.
 *
 * Consider the following:
 *
 * 	int my_array[] = {1, 23, 17, 4, -5, 100};
 * Here we have an array of 6 integers. We refer to each of these integers by means 
 * of a subscript to my_array, i.e. using my_array[0] through my_array[5]. But, we
 * could alternative access them via a ponter as follows:
 *
 * 	int *ptr;
 * 	ptr = &my_array[0];	// point our pointer to the first integer in the array
 * Then we could print out our array either using  the array notation or by deferencing
 * our pointer.
 */

#include <stdio.h>

int my_array[] = {1,23,17,4,-5,100};
int *ptr;
int main(void)
{
	int i;
//	ptr = &my_array[0];
	ptr = my_array;	// the name of the array is the address in the first element of the array
	printf("\n\n");
	for	(i = 0; i < 6; i++) 
	{
		printf("my_array[%d] = %d	",i, my_array[i]);
		//printf("ptr + %d = %d\n",i, *(ptr + i));
		printf("ptr + %d = %d\n", i, *ptr++);
		//printf("ptr + %d = %d\n",i, *(++ptr));
	}
	return 0;
}

/**
 * Some writes will refer to an array's name as a constant pointer. 
 *
 * Think of 
 * 
 * 	int i, k;
 * 	int *ptr;
 * 	i = 2
 * 	ptr = my_array;
 *
 * 	Here since 2 is a constant, it cannot be change, 
 * 	we can connot deferencing 2 to other place
 * 	So does for my_array. we cannot change my_array to hold another 
 * 	adress sincei it address is fixed to hold whatever it had been assigned. 
 *
 * 	As it turns out it is also possible that the size of a pointer can vary
 * 	depending ont the data type of the object to which it points. Thus, as 
 * 	with integers where you can run into trouble attempting to assign a long 
 * 	integer to a variable short integer, you can run into troulbe attempting
 * 	to assign the values of pointers of various types of pointer variables of 
 * 	other types. 
 *
 * 	To minimize this problems, C provides a pointer of type void. We can declare 
 * 	such a pointer by writing:
 *
 * 	void* *vptr;
 *
 * 	A void pointer is sort of a generic pointer. For example, while C will not 
 * 	permit the comparision of a pointer to type integer with a pointer to type
 * 	character, for example, either can be compared to a void pointer. Of course, 
 * 	as with other variables, casts can be used to convert form one type fo pointer
 * 	to another under the proper circumtances.
 *
 *
 *

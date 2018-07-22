// int k;
/**
 * When we declare a variable we inform the compilers two things:
 * the name of the variable and the type of the variable
 *
 * On seeing the "int" part, compilers set aside two bytes of memory
 * It also set up the symbol table. In that table it adds the symbol k
 * and the relative memory where those 2 bytes were set aside. 
 *
 * */
//	k = 2;
/**
 * we epect that, at run time when statement is executed, the value 2 
 * will be placed in that memory location reserved fo the storage of 
 * the value of k. In C we refer to a variable such as the integer 
 * k as an "object". 
 * So I think: k will have an address such that the value of that address
 * is the value 2. 
 *
 * There are two "values" that associated with the object k. One is the value
 * of the integer stored there ( 2 in the above example) ahte other "value" of the 
 * memory location the address of k. 
 *
 * So think the address of k is being keep track by the symbol table.
 *
 *
 * According to K&R (page 197): [1]
 *
 * 	" An object is a named region of storage; and lvalue is an expression
 * 	referring to an object."
 * 
 * Okay, now consider:
 *
 * */
//	int j, k; // these two adrress j and k is reseved two bytes each. 

//	k = 2;
//	j = 7;	<-- line 1
//	k = j; 	<-- line 2	// Go to j address and get what is stored in that address
  								// move to or replace what have been stored in address of k

/*
 * In the above, the compilers inteprets the j in line 1 as the address of the variable j
 * its( lvalue) and create a code copy to that address. 
 *
 * So I think j is the address that have two bytes and cand hold number 7 0x0000111
 *
 * In line 2, however, the j is interpret as its rvalue since it is on the right hand side 
 * of the assigment "=". 
 * That is, here the j refers to the value "stored" at the memory location 
 * 
 * Now, let's say that we have a reason for wanting a variable designed to hold an lvalue
 * ( an address). Such variable is called a "pointer variable". 
 * */
//	int *ptr;	// this is a null pointer int. This pointer address stored an address for 
					// and int value. But right now, it is not stored anything yet. 
	/**
	 * ptr is the name of our variable( just a k was the name of our integer variable). The "*"
	 * informs the compiler that we want a pointer variable, to set aside however many bytes is 
	 * required to stored an address in memory. 
	 * The int say that we intend to use the our pointer variale to stored the address of an integer. 
	 * Such pointer is said to "point to" an integer.
	 * 
	 * The actual bit pattern used for a null pointer may or may not evalutate to zero sinc it
	 * depends on the system on which the code is developed. To make the source code compatible
	 * between various compilers on various system, a macro is used to represent a null pointer. 
	 * Similary, just a one can test for a integer value of zero, if(k==0), we can test for a null 
	 * pointer using if(ptr == NULL). 
	 *
	 * But, back to using our new variable ptr. Suppose we want to store in ptr the address of our 
	 * integer variable k. To do this we use the unary & operator and write:
	 **/
//	ptr = &k; // & tell the compiler to retrieve it value as a left hand sight
	
	/*
	 * What the & operator does is retrieve the lvalue (address) of k, even though k is on the 
	 * right hand sight of  the assigment operator "=", and copies that to contents of our pointer
	 * ptr. Now, ptr is said to "point to" k. Bear with us now, there is only one more operator we 
	 * need to diccuss. 
	 *
	 * The "dereference operator" is the asterisk and it used as follows:
	 **/

//	*ptr = 7;	// '*' tell the compiler stored 0x0000111 to address 
					// in the content of ptr stored 
					// pointer address is 0xabc [ptr]: [address 0xffffff] 
					// So compilers: store 7 to this address 0xfffff. not 
					// 0xabc address. 
	/* *
	 * will copy 7 to the address pointed to by ptr. Thus if ptr "point to"
	 * (contains the address of) k, the above statement will set the value 
	 * of k to 7. That is, when we use the '*' hits way we are referring to 
	 * the value of that which ptr is pointing to, not he value of the pointer
	 * itself. 
	 **/
//	printf("%d\n", *ptr);

	/**
	 * To print to the screen the integer value stored at the address pointed to
	 * by ptr.
	 *
	 * 
	 *
	 *
	 *
	 **/
#include <stdio.h>

int j, k;
int *ptr;

int main(void)
{
	j = 1;
	k = 2;
	ptr = &k;		// ptr contents now is the address of k
	printf("\n");
	printf("j has the value %d and is stored at %p\n", j, (void *)&j);
	printf("k has the value %d and is stored at %p\n", k, (void *)&k);
	printf("ptr has the value %p and is stored at %p\n", ptr, (void *)&ptr);
	printf("The value of the integer pointed to by ptr is %d\n", *ptr);

	return 0;


}


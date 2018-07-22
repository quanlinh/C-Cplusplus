/**
 * In C, string are arrays of characters. It must be terminated by '\0'
 *
 * char my_string[40]; // 40 bytes long to hold characters. 
 *
 * my_string[0] = 'T';
 * my_string[1] = 'e';
 * my_string[2] = 'd';
 * my_string[3] = '\0';		// '\0' is a nul character ; it is not NULL;
 *
 * The nul refers to a zero as defined by the escape sequence '\0'. That 
 * is it occupies one byte of memory. NULL, on the other hand, is the name 
 * of the macro used to innitialized null pointers. NULL is #defined in a 
 * header file in your C compiler, nul may not be #defined at all. 
 *
 *
 * char my_string[40] = {'T', 'e', 'd', '0\'};	
 * char my_string[40] = "Ted";
 * */
#include <stdio.h>

char strA[80] = "A string to be used for demonstration purposes";
char strB[80];
char *my_strcpy(char *destination, char *source) 
{
   char *p = destination;
	while(*source != '\0')
	{
		*p++ = *source++;		
	}
	*p = '\0';
	return destination;
}

int main(void)
{
	char *pA;					// a pointer to type character
	char *pB;					// a pointer to type character
	puts(strA);					// show string A
	pA = strA;					// point pA at string A
	puts(pA);					// show what pA is pointing to 
	pB = strB;					// point pB at string B
	putchar('\n');				// move down one line in the screen
	//while(*pA != '\0')		// line A 
	//{
	//	*pB++ = *pA++;			// line B
	//}
	//*pB = '\0';					// line C
	my_strcpy(strB, strA);
	puts(strB);					// show strB on screen
	return 0;
	
}

/**
 * consider
 * int puts(const char *s);
 *
 * The paramter passed to puts() is a pointer, that is the value of
 *  a pointer (since all parameters in C are passed by value), and the 
 *  value of a pointer is the address to which it points , or, simply, 
 *  an adress. Thus when we write puts(strA); as we have seen, we are
 *  passing the address of strA[0];
 *
 *  Similarly, when we write puts(pA); we are passing the same address, 
 *  since we have set pA=strA;
 *  Line B states: copy the character pointed to pA to space pointed to by pB, then
 *  increment pA so it points to the next character and pB so it points to the next
 *  space.
 *
 *  When we have copied the last character, pA now points to the termninating nul 
 *  character and the loop ends. However, we have not copy the last character '\0'
 *  to pB spaced. So we have assinged it at the end after the while loop breaks.
 *
 *
 *
char *my_strcpy(char *destination, char *source) 
{
	char *p = destination;
	while (*source != '\0')
	{
		*p++ = *source++;
	}
	*p = '\0';
	return destination;

}
 
 * I have followed the practice used in the standard routine of returning a 
 * pointer to the destination. 
 */

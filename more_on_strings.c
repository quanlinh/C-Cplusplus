/**
 * Consider the following function:
 * char *my_strcpy(char dest[], char source[]) 
 * {
 *		int i = 0;
 *		while (source[i] != '\0')
 *		{
 *			dest[i] = source[i];
 *			i++;
 *		}
 *		dest[i] = '\0';
 *		return dest;	
 * }
 * Since parameters are passed by value, in both the passing of a character pointer
 * or the name of the array as above, what actually gets passed is the address of 
 * the first element of each array. Thus, the numerical value of the parameter passed
 * is the same whether we use a character pointer or an array name as a parameter.
 * This would tend to imply that somehow source[i] is the same as *(p+i).
 *
 * In fact, this is true, i.e wherever one writes a[i] it can be replaced with 
 * *(a + i) without any problems. In fact, the compiler will create the same code in 
 * either case. Thus we see that pointer airthmetic is the same thing as an array 
 * indexing. Either syntax produces the same results. 
 *
 * This is NOT saying that pointers and arrays are the same thing, they are not. We are
 * only saying that to indetify a given element of an array we have the choice of two 
 * syntaxes, one using array indexing and the other using pointer arithmetic, which yield
 * identical results. 
 *
 * Now, looking at this last expression, part of it..(a + i), is a simple addition using 
 * the + operator and the rules fo C state that such an expression is commutative. That 
 * is (a+i) is identical to (i+a). Thus we could write *(i+a) just as easily as *(a+i).
 *
 * But *(i+a) could have come from i[a] ! From all of this comes the curious truth that if:
 *
 * 	char a[20];
 * 	int i;
 * writing 
 * a[3] = 'x';
 *
 * is the same as writing 
 * 3[a] = 'x';
 *
 *
 * Now, looking at our function above, when we write:
 * 	dest[i] = source[i];
 * due to the fact that array indexing and pointer arithmetic yield identical results, 
 * we can write this as:
 * 	*(dest + i) = *(source + i);
 * 

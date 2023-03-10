/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:47:43 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:09:50 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!size)
		ptr = (void *)malloc(sizeof(void));
	else
		ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

// TEST
/* int	main(void)
{
	char	**str;

	printf("Allocating memory with ft_calloc()\n");
	printf("Using ft_calloc(6, sizeof(char))...\n");
	printf("Actual size: %ld\n\n", sizeof(str));
	str = (char **)ft_calloc(6, sizeof(char));
	printf("-----------------------------------------\n");
	printf("\nResult:\t-> %ld\n", sizeof(str));
	free(str);
	return (0);
}
*/

// DESCRIPTION
/* The  malloc()  function  allocates size bytes and returns a pointer to
 * the allocated memory.  The memory is not initialized.  If size  is  0,
 * then  malloc() returns either NULL, or a unique pointer value that can
 * later be successfully passed to free().
 *
 * The  calloc() function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.  The
 * memory  is  set to zero.  If nmemb or size is 0, then calloc() returns
 * either NULL, or a unique pointer value that can later be  successfully
 * passed  to  free().  If the multiplication of nmemb and size would re‐
 * sult in integer overflow, then calloc() returns  an  error.   By  con‐
 * trast, an integer overflow would not be detected in the following call
 * to malloc(), with the result that an incorrectly sized block of memory
 * would be allocated:
 * 	
 * 	malloc(nmemb * size);
 *
 * The  malloc() and calloc() functions return a pointer to the allocated
 * memory, which is suitably aligned for any built-in  type.   On  error,
 * these  functions return NULL.  NULL may also be returned by a success‐
 * ful call to malloc() with a size of zero, or by a successful  call  to
 * calloc() with nmemb or size equal to zero.
 */

// DETAILS
/* When you call calloc, it allocates a block of memory large enough to 
 * hold num elements of size size. It then initializes all the bytes in the
 * allocated block to zero. This ensures that the memory block is in a 
 * consistent state before it is used in the program.
 *
 * calloc is similar to the malloc function, which also allocates a block of
 * memory. However, malloc does not initialize the memory, so the
 * contents of the memory block are undefined. If you need to initialize the
 * memory to a specific value, you can use memset or memcpy functions
 * after allocating memory with malloc.
 *
 * In summary, calloc is a function that allocates memory for an array of 
 * elements and initializes them to zero. It is useful for initializing dynamic
 * memory structures, such as arrays or structures, before using them in
 * your program.

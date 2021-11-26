#include "libft.h"

void
	*ft_memset(void *ptr, int ch, size_t size)
{
	while (size)
	{
		size -= 1;
		((unsigned char *) ptr)[size] = ch;
	}
	return (ptr);
}

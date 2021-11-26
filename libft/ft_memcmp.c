#include "libft.h"

int
	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *) ptr1)[i] != ((unsigned char *) ptr2)[i])
			return (((unsigned char *) ptr1)[i] - ((unsigned char *) ptr2)[i]);
		i += 1;
	}
	return (0);
}

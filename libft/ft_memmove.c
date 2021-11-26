#include "libft.h"

void
	*ft_memmove(void *dst, const void *src, size_t size)
{
	if (src >= dst)
		return (ft_memcpy(dst, src, size));
	while (0 < size)
	{
		size -= 1;
		((unsigned char *) dst)[size] = ((unsigned char *) src)[size];
	}
	return (dst);
}

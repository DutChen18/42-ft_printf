#include "libft.h"
#include <stdlib.h>

char
	*ft_substr(const char *str, unsigned int idx, size_t max)
{
	size_t	len;
	char	*res;

	if (FT_SAFE >= 1 && str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (idx >= len)
		idx = len;
	if (idx + max >= len)
		max = len - idx;
	res = malloc(max + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, str + idx, max);
	res[max] = '\0';
	return (res);
}

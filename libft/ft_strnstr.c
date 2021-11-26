#include "libft.h"

char
	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	str2len;

	i = 0;
	str2len = ft_strlen(str2);
	while (i <= len)
	{
		if (!ft_strncmp(str1 + i, str2, str2len) && i + str2len <= len)
			return ((char *) str1 + i);
		if (!str1[i])
			return (NULL);
		i += 1;
	}
	return (NULL);
}

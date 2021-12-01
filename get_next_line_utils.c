#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	free_space;
	char			*ptr_dst;

	free_space = size;
	ptr_dst = dst;
	while (*ptr_dst && free_space != 0)
	{
		ptr_dst++;
		free_space--;
	}
	if (free_space == 0)
		return (ft_strlen(src) + size);
	while (*src && free_space > 1)
	{
		*ptr_dst++ = *src++;
		free_space--;
	}
	*ptr_dst = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size <= 0)
		return (len);
	while (i < len && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}


char	*ft_strjoin(char *cand, char *s2)
{
	char	*joined_str;
	size_t	len;

	if (!cand || !s2)
		return (NULL);
	len = ft_strlen(cand) + ft_strlen(s2) + 1;
	joined_str = malloc(sizeof(char) * len);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, cand, len);
	ft_strlcat(joined_str, s2, len);
	if (cand)
		free(cand);
	return (joined_str);
}

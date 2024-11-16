#include "torche.h"

size_t	ft_test_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t i;

	srclen = strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

size_t	ft_test_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = strlen(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	else
		ft_test_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (dstlen + srclen);
}

char	*ft_test_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	str_len;
	size_t	substr_len;

	if (!str && n == 0)
		return (NULL);
	str_len = strlen(str);
	substr_len = strlen (substr);
	if (n > str_len)
		n = str_len;
	while (n >= substr_len)
	{
		if (strncmp(str, substr, substr_len) == 0)
			return ((char *)str);
		++str;
		--n;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:12:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/15 18:46:38 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	print_str(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i += write(fd, &s[i], 1);
	return (i);
}

int	print_error_fd(char *s1, char *s2, int fd)
{
	int	i;

	i = 0;
	i = print_str("Error\n", fd);
	i += print_str(s1, fd);
	if (s2)
	{
		i += write(fd, ": ", 2);
		i += print_str(s2, fd);
	}
	i += write(fd, "\n", 1);
	return (i);
}

/*
* DESCRIPTION
*	allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
*	result of the concatenation of s1 and s2.
* PARAMETRES
*	#1 - First string.
*	#2 - String to be concatenate to the first string.
* RETURN
*	New string.
*	NULL if the allocation fails.
*/
char	*ft_strjoin_no_free(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	return (str);
}

/*
* DESCRIPTION
*	Convert ASCII string to integer
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str [i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*
* DESCRIPTION
*	copy memory area
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	destcpy = dest;
	srccpy = src;
	if (!dest && !src)
		return (0);
	while (n--)
		*destcpy++ = *srccpy++;
	return (dest);
}

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen >= size)
		return (size + srclen);
	while (src[i] != '\0' && dstlen + i < size - 1)
	{	
		dst[dstlen + i] = src [i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

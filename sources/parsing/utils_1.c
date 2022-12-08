/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:12:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/07 14:33:39 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** possible to add another skips like"|| line[*i] == '\t' || line[*i] == '\v'
** || line[*i] == '\f' || line[*i] == '\r') // a confirmer
*/
int	ft_skip(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\n'))
		(*i)++;
	return (0);
}

int	ft_skip_char(char *line, int *i, char c)
{
	int	j;

	j = 0;
	while (line[*i] != c)
	{
		j++;
		(*i)++;
	}
	return (j);
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
** s1 ans s2 are not free.
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:48:40 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/07 17:03:35 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_strlen_path(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_path(char *src)
{
	int		index;
	char	*dest;

	index = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen_path(src) + 1));
	if (dest == NULL)
	{
		msg_err("ft_strdup: malloc failed", NULL, 2);
		return (NULL);
	}
	while (src[index] && src[index] != '\n')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*dest;

	index = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
	{
		msg_err("ft_strdup: malloc failed", NULL, 2);
		return (NULL);
	}
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/*
* DESCRIPTION
*	Fill a byte string with a byte value
*/
void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;
	size_t	i;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:48:40 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/08 18:38:57 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static size_t	ft_strlen_path(const char *s)
// {
// 	unsigned int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\n' && s[i] != '\0')
// 		i++;
// 	return (i);
// }

int	ft_scan_line(char *line)
{
	int	i;
	int	j;

	i = ft_count_to_char(line, ' ');
	j = i;
	if (i > 0)
	{
		ft_skip(line, &i);
		if (line[i] != '\0')
		{
			msg_err("ft_scan_line: invalide path", line, 2);
			return (-1);
		}
	}
	return (j);
}

char	*ft_strdup_path(char *src)
{
	int		index;
	int		j;
	char	*dest;

	index = 0;
	j = ft_scan_line(src);
	if (j < 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (j + 1));
	if (dest == NULL)
	{
		msg_err("ft_strdup_path", "malloc failed", 2);
		return (NULL);
	}
	while (src[index] && src[index] != '\n' && index != j)
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

int	check_file_name(char *name, char *base)
{
	int	i;
	int	j;

	i = ft_strlen(name) - 1;
	j = ft_strlen(base) - 1;
	if (i <= j || name[i - j - 1] == '/')
		return (1);
	while (j >= 0)
	{
		if (name[i] != base[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:38:32 by agouet            #+#    #+#             */
/*   Updated: 2022/12/02 16:23:11 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_mstrchr(const char *s, char c)
{
	char	*s_end;
	int		i;

	s_end = NULL;
	i = 0;
	if (BUFFER_SIZE == 1)
		return (NULL);
	while (s[i])
	{
		if (((char)s[i]) == c)
		{
			if (s[i + 1] == '\0')
				return (NULL);
			s_end = (ft_substr(s, i + 1, ft_strlen(s) - i));
			return (s_end);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*piece_s;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		len = 0;
	piece_s = (char *) malloc (sizeof (char) * (len + 1));
	if (!piece_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		piece_s[i] = s[start + i];
		i++;
	}
	piece_s[i] = '\0';
	return (piece_s);
}

char	*ft_p_strcpy(char *dest, char const *src, int *pt_i, int *pt_j)
{
	int	i;
	int	j;

	i = *pt_i;
	j = *pt_j;
	while (src[j])
	{
		dest[i] = src [j];
		i++;
		j++;
	}
	dest [i] = '\0';
	*pt_i = i;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		ft_p_strcpy(s, s1, &i, &j);
		free((void *)s1);
	}
	j = 0;
	if (s2)
		ft_p_strcpy(s, s2, &i, &j);
	return (s);
}

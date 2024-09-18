/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:26:35 by polmo-lo          #+#    #+#             */
/*   Updated: 2024/09/18 18:16:16 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(((len1 + len2) * sizeof(char)) + 1);
	if (str == 0)
	{
		return (NULL);
	}
	i = -1;
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	j = 0;
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*reserve;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	reserve = (char *)malloc(len);
	if (!reserve)
		return (NULL);
	while (i < len)
	{
		reserve[i] = s[i];
		i++;
	}
	return (reserve);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:11:42 by polmo-lo          #+#    #+#             */
/*   Updated: 2024/09/18 19:23:16 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*stract_line(char *stack)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!stack || !*stack)
		return (NULL);
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		line[j] = stack[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*new_stack;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\0')
	{
		free(stack);
		return (NULL);
	}
	i++;
	new_stack = malloc(sizeof(char) * ft_strlen(stack + i) + 1);
	if (!new_stack)
		return (NULL);
	while (stack[i])
		new_stack[j++] = stack[i++];
	new_stack[j] = '\0';
	free (stack);
	return (new_stack);
}

char	*concat_stack(char *stack, char *buffer)
{
	char	*temp;

	if (!stack)
		return (ft_strdup(buffer));
	temp = ft_strjoin(stack, buffer);
	free(stack);
	return (temp);
}

char	*read_to_stack(int fd, char *stack)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	while (!stack || !ft_strchr(stack, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0 && stack)
				break ;
			free(stack);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stack = concat_stack(stack, buffer);
		if (!stack)
			return (NULL);
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	stack[fd] = read_to_stack(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);

	line = stract_line(stack[fd]);
	stack[fd] = update_stack(stack[fd]);
	return (line);
}

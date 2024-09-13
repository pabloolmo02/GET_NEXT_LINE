/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 00:26:43 by polmo-lo          #+#    #+#             */
/*   Updated: 2024/09/13 17:36:59 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stract_line(char *stack)
{
	char	*line;
	int	i;
	int	j;

	i = 0;
	if (!stack || !*stack)
		return (NULL);
	//incrementamso i hasta encontrar salto de linea o el final
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	//asignacion de memoria para la linea +1 para caracter final
	line = malloc(sizeof(char) * (i + 1));
	//copiamos la primera linea en "linea" y añadimos el caracter final
	while (j < 1)
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
	
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\0')
	{
		free(stack);
		return(NULL);
	}
	i++;
	new_stack = malloc(sizeof(char) * ft_strlen(stack) - i + 1);
	if (!new_stack)
		return(NULL);
	while (stack[i])
		new_stack[j++] = stack[i++];
	new_stack[i] = '\0';
	return (new_stack);
}
char *get_next_line(int fd)
{
	static	char	*stack; //Almacena cualquier dato sobrante después de que se haya encontrado una línea completa
	char			buffer[BUFFER_SIZE + 1]; //Cada vez que read() se llama, llena este buffer con datos del archivo. Luego, esos datos se procesan y se combinan con stack para formar líneas completa
	ssize_t			bytes_read;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(stack, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (!stack)
			return (NULL);
	}
	line = stract_line(stack);
	stack = update_stack(buffer);
}

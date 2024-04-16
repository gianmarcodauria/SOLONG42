/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:12:05 by gd-auria          #+#    #+#             */
/*   Updated: 2024/03/26 15:24:31 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*fd2str(int fd)
{
	char	*result;
	char	buffer[6];
	char	*temp_free;
	int		rdr;

	rdr = 1;
	result = ft_calloc(sizeof(char), 1);
	if (fd < 0)
		perror ("FD PROBLEM OCCURRED");
	else
	{
		while (rdr > 0)
		{
			rdr = read(fd, buffer, 5);
			buffer[rdr] = 0;
			temp_free = result;
			result = ft_strjoin(temp_free, buffer);
			free(temp_free);
		}
	}
	if (ft_strlen(result) == 0)
		perror("LENGHT PROBLEM OCCURRED");
	close(fd);
	return (result);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

int	wallCheck(t_first *walle)
{
	int height;
	int width;
	
	height = 0;
	width = 0;
	while (walle->matrix[height++][width])
	{
		if (height == 0 || height == walle->Ymax - 1)
		{
			if (walle->matrix[height][width] == '1')
				width++;
			else
				return(0);
		}
		else if (walle->matrix[height][0] == '1' && walle->matrix[height][walle->Xmax - 1] == '1')
			width++;
		else
			return(0);
	}
	width = 0;
	return (1);
}

int	shapeCheck(char **shape, t_first *m)
{
	int Y;
	
	Y = 0;
	m->Xmax = ft_strlen(shape[Y]);
	while (shape[Y++])
	{
		if (ft_strlen(shape[Y]) != (size_t) m->Xmax)
			return (1);
	}
	m->Ymax = Y;
	m->matrix = shape;
	return (1);
}

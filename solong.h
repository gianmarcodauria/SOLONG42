/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:30:25 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/16 15:30:29 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "struct_slong.h"

int		dot_ber(char *fileber);
char	*fd2str(int fd);
char	**second_matrix(t_first *gameM);
void	flood_fill(t_first *floodmap, int height, int width, char **dupMap);
int		letter_check(t_first *letters);
int		shapeCheck(char **shape, t_first *m);
int		wallCheck(t_first *walle);
int		last_floodcheck(char **dupMap);
int		main_check(t_first *check);

#endif

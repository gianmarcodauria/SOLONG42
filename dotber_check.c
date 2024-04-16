/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morecheks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:23:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/03 14:23:22 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int dot_ber(char *fileber)
{
    int glen;

    glen = ft_strlen(fileber) - 1;
    while (glen--)
    {
        if(fileber[glen--] == 'r' && fileber[glen--] == 'e'
            && fileber[glen--] == 'b' && fileber[glen--] == '.')
                return (1);
        else
        {
            perror("not dotber");
            return (0);
        }
    }
    return (1);
}

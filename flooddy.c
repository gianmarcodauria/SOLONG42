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

void flood_fill(t_first *floodmap, int height, int width, char **dupMap)
{
    int Ylen;
    int Xlen;

    Ylen = floodmap->Ymax;
    Xlen = floodmap->Xmax;
    if (dupMap[height][width] == 0 || dupMap[height][width] == 'C'
        || dupMap[height][width] == 'E'
        || dupMap[height][width] == 'N' || dupMap[height][width] == 'P')
        {
            dupMap[height][width] = '3';
            {
                printf("%s\n", dupMap[height]);
                if (height > 0 && (!(dupMap[height - 1][width] == '1')))
                    flood_fill(floodmap, height - 1, width, dupMap);
                if (width > 0 && (!(dupMap[height][width - 1] == '1')))   
                    flood_fill(floodmap, height, width - 1, dupMap);
                if (height + 1 < Ylen && (!(dupMap[height + 1][width] == '1')))
                    flood_fill(floodmap, height + 1, width, dupMap);
                if (width + 1 < Xlen && (!(dupMap[height][width + 1] == '1')))
                    flood_fill(floodmap, height, width + 1, dupMap);
            }
        }
}

int last_floodcheck(char **dupMap)
{
    int Y;
    int X;

    Y = 0;
    while (dupMap[Y++][X] == '3')
    {
        X = 0;
        if (dupMap[Y][X] == 'P' || dupMap[Y][X] == 'E' || dupMap[Y][X] == 'C'
            || dupMap[Y][X] == 'N')
            return (0);
        while (dupMap[Y][X++] == '3')
        {
            if (dupMap[Y][X] == 'P' || dupMap[Y][X] == 'E'
                || dupMap[Y][X] == 'C' || dupMap[Y][X] == 'N')
                return (0);
        }
    }
    return (1);
}

char   **second_matrix(t_first *gameM)
{
    char    **secMap;
    int     n;

    n = 0;
    secMap = ft_calloc(sizeof(char **), gameM->Ymax + 1);
    while (n <= gameM->Ymax)
    {
        secMap[n] = ft_strdup(gameM->matrix[n]);
        n++;
    }
    return (secMap);
}

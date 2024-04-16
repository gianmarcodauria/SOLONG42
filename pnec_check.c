/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:02:01 by gd-auria          #+#    #+#             */
/*   Updated: 2024/04/03 15:02:06 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solong.h"

static int  p_check(t_first *letters)
{
    int he;
    int wi;
    // letters->map.P;
    he = 0;
    wi = 0;
    while (letters->matrix[he] && he < letters->Xmax)
    {
        while (letters->matrix[he][wi] && wi < letters->Ymax)
        {
            if (letters->matrix[he][wi] == 'P')
            {
                letters->map.P++;
                if (letters->map.P == 1)
                {
                    perror ("WRONG P");
                    return (0);
                }
            }
            wi++;
        }
        he++;
    }
    return (1);
}

static int n_check(t_first *letters)
{
    int he;
    int wi;
    // letters->map.N;

    he = 0;
    wi = 0;
    while (letters->matrix[he++])
    {
        while (letters->matrix[he][wi++])
        {
            if (letters->matrix[he][wi] == 'N')
            {
                letters->map.N++;
                if (letters->map.N == 1)
                {
                    perror ("WRONG N");
                    return (0);
                }
            }
        }
    }
    return (1);
}
static int e_check(t_first *letters)
{
    int he;
    int wi;

    he = 0;
    wi = 0;
    while (letters->matrix[he++])
    {
        while (letters->matrix[he][wi++])
        {
            if (letters->matrix[he][wi] == 'E')
            {
                letters->map.E++;
                if (letters->map.E == 1)
                {
                    perror ("WRONG E");
                    return (0);
                }
            }
        }
    }
    return (1);
}

static int c_check(t_first *letters)
{
    int he;
    int wi;
    // letters->map.C;

    he = 0;
    wi = 0;
    while (letters->matrix[he++])
    {
        while (letters->matrix[he][wi++])
        {
            if (letters->matrix[he][wi] == 'C')
                letters->map.C++;
        }
    }
    if (letters->map.C == 0)
    {
        perror ("WRONG C");
        return (0);
    }
    return (1);
}

int letter_check(t_first *letters)
{
    if (p_check(letters) == 1 || e_check(letters) == 1 || n_check(letters) == 1 || c_check(letters) == 1)
        return (1);
    else
        return (0);
}

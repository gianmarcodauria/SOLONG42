#ifndef STRUCT_SLONG_H
#define STRUCT_SLONG_H

#define COLLECTABLES 6
#define XPM_MAX 6

typedef struct s_second
{
    int     P;
    int     C;
    int     E;
    int     N;

} t_second;

typedef struct s_first
{
    char    **matrix;
    char    *floodmap;
    int     Xmax;
    int     Ymax;

    t_second    map;

} t_first;

#endif

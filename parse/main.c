#include "../execute/cub3d.h"

int main(int ac, char *av[])
{
    t_game cub;
    t_ray ray;
    t_path  load;
    cub.ray = &ray;
    cub.path = &load;
    char    *ptr;
    int     n;

    n = 0;
    if (ac == 2)
    {
        // load_path(&load);
        if (check_interput(av[1]) == 0)
            return 0;
        int j = open(av[1], F_OK, R_OK);
        if (j == -1)
        {
            ft_putendl_fd("Error : No such file of Directory .", 2);
            return 0;
        }
        while (1)
        {
            ptr = get_next_line(j);
            if (!ptr)
                break;
            if (parametre_map(ptr, &load) == 0 && empty_line(ptr) == 1)
                n += 1;
            if (load.NO && load.SO && load.WE && load.EA && load.F && load.C)
            {
                break;
                free(ptr);
            }
            free(ptr);
        }
        int t = open(av[1], F_OK, R_OK);
        if (t == -1)
            return 0;
        load_map(n, &load);
        n = 0;
        while (1)
        {
            ptr = get_next_line(t);
            if (ptr == NULL)
                break;
            if (parametre_map(ptr, &load) == 0 && empty_line(ptr) == 1)
            {
                load.map[n] = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
                load.map[n] = ptr;
                n += 1;
            }
        }
        load.map[n] = NULL;
        check_parametre(&load);
        check_map(load.map, n - 1);
        // n = 0;
        // while (load.map[n])
        // {
        //     printf("%s", load.map[n]);
        //     n++;
        // }
    }
    cub.size = 32;
    cub.rows = 14;
    cub.cols = 33;
    // while (cub.path->map[cub.rows])
	// 	cub.rows++;
    start_game(&cub);
}

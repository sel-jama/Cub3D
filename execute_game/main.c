#include "cub3d.h"

int main(){
    t_game cub;

    cub.rows = 11;
    cub.cols = 15;
    cub.size = 32;
    cub.window_w = cub->cols * cub->size;
    cub.window_h = cub->rows * cub->size;

    start_game(&cub);
}
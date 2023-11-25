#include "cub3d.h"

int main(){
    t_game cub;
    t_ray ray;
    cub.ray = &ray;

    cub.rows = 5;
    cub.cols = 6;
    cub.size = 64;
    // ray->angle = 0.5;
    char cub_map[][6] = {
    [0] = {1, 1, 1, 1, 1, 1},
    [1] = {1, 0, 0, 1, 0, 1},
    [2] = {1, 0, 0, 0, 0, 1},
    [3] = {1, 0, 0, 0, 0, 1},
    [4] = {1, 1, 1, 1, 1, 1}
};

    for (int i=0; i<cub.cols; i++){
        for(int j=0; j<cub.rows; j++){
            cub.map[i][j] = cub_map[i][j];
        }
    }
    cub.window_w = cub.cols * cub.size;
    cub.window_h = cub.rows * cub.size;

    start_game(&cub);
}
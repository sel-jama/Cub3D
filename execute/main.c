#include "cub3d.h"

int main(){
    t_game cub;
    t_ray ray;
    t_path path;
    cub.ray = &ray;
    cub.path = &path;

    cub.rows = 5;
    cub.cols = 6;
    cub.size = 32;
    // ray->angle = 0.5;
    char cub_map[][6] = {
    [0] = {1, 1, 1, 1, 1, 1},
    [1] = {1, 0, 0, 1, 0, 1},
    [2] = {1, 0, 0, 0, 0, 1},
    [3] = {1, 0, 0, 0, 0, 1},
    [4] = {1, 1, 1, 1, 1, 1}
    };
    // cub.map = cub_map;
    // for (int i=0; i<cub.rows; i++){
    //     for(int j=0; j<cub.cols; j++){
    //         cub.map[i][j] = cub_map[i][j];
    //     }
    // }
    
    
    // start_game(&cub);
}
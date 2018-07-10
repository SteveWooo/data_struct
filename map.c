/*
 * with C:
 */
#include "map.h"
#include <stdlib.h>
#define MAX 100
typedef struct Map{
    char* Vex;
    int** Edg;
}Map;
Map* createMap(){
    Map* map;
    map = (Map*)malloc(sizeof(Map));
    map->Vex = (char*)malloc(MAX * sizeof(char));
    map->Edg = (int**) malloc(MAX * sizeof(int));
    int i = 0;
    for(;i<MAX;i++){
        map->Edg[i] = (int*)malloc(MAX * sizeof(int));
    }
    return map;
}
void map(){
    printf ("map\n");
    Map* map = createMap();
    map->Edg[0][0] = 1;
    printf("data:%d\n", map->Edg[0][0]);
}

/*
 * with javascript
 let map = {
     Vex : [],
     Edg : []
 }
 */



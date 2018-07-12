/*
 * with C:
 */
#include "map.h"
#include <stdlib.h>
#define MAX 100
// 邻接矩阵法：
//typedef struct Map{
//    char* Vex;
//    int** Edg;
//}Map;
//Map* createMap(){
//    Map* map;
//    map = (Map*)malloc(sizeof(Map));
//    map->Vex = (char*)malloc(MAX * sizeof(char));
//    map->Edg = (int**) malloc(MAX * sizeof(int));
//    int i = 0;
//    for(;i<MAX;i++){
//        map->Edg[i] = (int*)malloc(MAX * sizeof(int));
//    }
//    return map;
//}
//void map(){
//    printf ("map\n");
//    Map* map = createMap();
//    map->Edg[0][0] = 1;
//    printf("data:%d\n", map->Edg[0][0]);
//}

/*
 * with javascript
 let map = {
     Vex : [],
     Edg : []
 }
 */
//邻接表法:
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next_arc;
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode* first_arc;
}VNode;

typedef struct {
    VNode* list;
    int vexnum, arcnum;
    int kind;
}Map;

int getPosotion(Map* map, char data){
    int i;
    for(i=0;i<map->vexnum;i++){
        if(data == map->list[i].data){
            return i;
        }
    }
    return -1;
}

Map* initMap(){
    Map* map;
    map = (Map*)malloc(sizeof(Map));
    
    char data[] = {'A', 'B', 'C', 'D'};
    char arc[][2] = {{'A', 'B'}, {'B', 'C'}, {'A', 'D'}};
    
    map->vexnum = sizeof(data) / sizeof(data[0]);
    map->arcnum = sizeof(arc) / sizeof(arc[0]);
    
    map->list = (VNode*)malloc(sizeof(VNode) * map->vexnum);
    int i;
    for(i=0;i<map->vexnum;i++){
        VNode node;
        node.data = data[i];
        node.first_arc = NULL;
        map->list[i] = node;
    }
    
    for(i=0;i<map->arcnum;i++){
        char tail = arc[i][0];
        char head = arc[i][1];
        int head_position = getPosotion(map, head);
        int tail_position = getPosotion(map, tail);
        ArcNode* arcnode = (ArcNode*)malloc(sizeof(ArcNode));
        arcnode->next_arc = NULL;
        arcnode->adjvex = head_position;
        if(map->list[tail_position].first_arc == NULL){
            map->list[tail_position].first_arc = arcnode;
        } else {
            ArcNode* temp = map->list[tail_position].first_arc;
            while(temp->next_arc != NULL){
                temp = temp->next_arc;
            }
            temp->next_arc = arcnode;
        }
    }
    
    return map;
}

int getNextAdj(Map* map, int v, int w){
    ArcNode *temp = map->list[v].first_arc;
    while(temp!=NULL){
        if(temp->adjvex == w){
            return temp->next_arc == NULL ? -1 : temp->next_arc->adjvex;
        }
        temp = temp->next_arc;
    }
    
    return -1;
}

int* visited;
void DFS(Map* map, int v){
    if(visited[v] == 1){
        return ;
    }
    visited[v] = 1;
    printf("visit:%c\n", map->list[v].data);
    if(map->list[v].first_arc == NULL){
        return ;
    }
    int w;
    for(w = map->list[v].first_arc->adjvex;w>=0;w = getNextAdj(map, v, w)){
        DFS(map, w);
    }
    
}
void initDFS(Map* map){
    visited = (int*)malloc(sizeof(int) * map->vexnum);
    int i;
    for(i=0;i<map->vexnum;i++){
        visited[i] = 0;
    }
    
    for(i=0;i<map->vexnum;i++){
        DFS(map, i);
    }
}

void map(){
    Map* map = initMap();
    initDFS(map);
}

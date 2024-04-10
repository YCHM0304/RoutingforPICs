#include "Vertex_Pair.h"


Vertex_Pair::Vertex_Pair(int x1, int y1, int x2, int y2){
    this -> x1 = x1;
    this -> y1 = y1;
    this -> x2 = x2;
    this -> y2 = y2;
}

int Vertex_Pair::getDistance(){
    return abs(x1 - x2) + abs(y1 - y2);
}

int Vertex_Pair::getDirection(int current_x, int current_y){
    if(current_x != x2){
        if(current_x < x2){
            return R;
        }
        else {
            return L;
        }
    }
    else if(current_y != y2){
        if(current_y < y2){
            return U;
        }
        else{
            return D;
        }
    }
    return S;
}

void Vertex_Pair::getPath(int current_x, int current_y, int d, vector<pair<int, int>>& path) {
    if(current_x == x2 && current_y == y2){
        path.push_back(make_pair(current_x, current_y));
        return;
    }
    d = getDirection(current_x, current_y);
    int next_x = current_x;
    int next_y = current_y;
    if(d == U) next_y = current_y + 1;
    if(d == D) next_y = current_y - 1;
    if(d == R) next_x = current_x + 1;
    if(d == L) next_x = current_x - 1;
    getPath(next_x, next_y, d, path);
    path.push_back(make_pair(current_x, current_y));
}

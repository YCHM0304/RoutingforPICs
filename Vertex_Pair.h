#include <iostream>
#include <vector>
using namespace std;
#define U 0
#define R 1
#define D 2
#define L 3
#define S 4

class Vertex_Pair{
public:
    int x1;
    int y1;
    int x2;
    int y2;
    Vertex_Pair(int x1, int y1, int x2, int y2);
    void getPath(int current_x, int current_y, int d, vector<pair<int, int>>& path);
    int getDistance();
    int getDirection(int current_x, int current_y);
};
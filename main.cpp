#include <cstdlib>
#include <fstream>
#include <cstring>
#include "Vertex_Pair.h"
using namespace std;

// int main(int argc, char **argv)
// {
//     if(argc != 3)
//     {
//         cout << "Usage: ./[exe] [input file] [output file]" << endl;
//     //    system("pause");
//         exit(1);
//     }

//     // open the input file
//     fstream fin;
//     fin.open(argv[1], fstream::in);
//     if(!fin.is_open())
//     {
//         cout << "Error: the input file is not opened!!" << endl;
//         exit(1);
//     }
int main()
{
    // open the input file
    fstream fin;
    fin.open("pic5x5.in", fstream::in);
    if(!fin.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }
    // parse the input file
    cout << "======================" << endl;
    cout << "        Parser        " << endl;
    cout << "======================" << endl;

    char buffer[100];
    int grid_x;
    int grid_y;
    int p_loss;
    int c_loss;
    int b_loss;
    int num;

    for(int n = 0; n < 15; n++){
        fin >> buffer;
        if(n == 1)grid_x = atoi(buffer);
        if(n == 2)grid_y = atoi(buffer);
        if(n == 5)p_loss = atoi(buffer);
        if(n == 8)c_loss = atoi(buffer);
        if(n == 11)b_loss = atoi(buffer);
        if(n == 14)num = atoi(buffer);
	}
    vector<vector<pair<int, int>>> path(num,vector<pair<int, int>>(0,pair<int, int>(0, 0)));
    vector<Vertex_Pair> vp(0, Vertex_Pair(1, 1, 1, 1));
    for(int n = 0; n < 5 * num; n++){
        int a, b, c, d;
        fin >> buffer;
        if(n % 5 == 1)a = atoi(buffer);
        if(n % 5 == 2)b = atoi(buffer);
        if(n % 5 == 3)c = atoi(buffer);
        if(n % 5 == 4){
            d = atoi(buffer);
            vp.push_back(Vertex_Pair(a, b, c, d));
        }
	}

    cout << grid_x << grid_y << p_loss << c_loss << b_loss;
    // open the output file
    fstream fout;
    fout.open("pic5x5.out",fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
	    exit(1);
    }

    for(int i = 0; i < num; i++){
        vp[i].getPath(vp[i].x1, vp[i].y1, S, path[i]);
        fout << i << " " << path[i].size() << endl;
        for(int j = path[i].size()-1; j > 0; j--){
            fout << path[i][j].first << " " << path[i][j].second << " " << path[i][j-1].first << " " << path[i][j-1].second << endl;
        }
    }
    return 0;
}


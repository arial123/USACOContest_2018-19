#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

vector < pair<int,int> > valid;

// Below arrays details all 4 possible movements
int row[] = { 0, 0, 1,-1};
int col[] = {-1, 1, 0, 0};


// check if it is possible to go to pixel (x, y) from
// current pixel. The function returns false if the pixel
// has different color or it is not a valid pixel
bool isSafe(int mat[][10], int x, int y, int target, int dimension, bool visited[][10])
{
    int M = dimension;
   // cout << "checking square" << endl;
    return (x >= 0 && x < M && y >= 0 && y < 10)
        && mat[x][y] == target && (!visited[x][y]);
}

// Flood fill using BFS
void floodfill(int mat[][10], int x, int y, int dimension, bool visited[][10])
{
   // cout << M << " " << N << endl;
    // create a queue and enqueue starting pixel
    queue< pair<int, int> > q;
    q.push({x, y});

    // get target color
    int target = mat[x][y];

    // run till queue is not empty
    while (!q.empty())
    {
      //  cout << "q not empty" << endl;
        // pop front node from queue and process it
        pair<int, int> node = q.front();
        q.pop();

        // (x, y) represents current pixel
        int x = node.first;
        int y = node.second;
       // cout << x << " " << y << endl;

        // replace current pixel color with that of replacement
       // mat[x][y] = replacement;
        valid.push_back(make_pair(x,y));
        visited[x][y] = true;

        // process all 4 adjacent pixels of current pixel and
        // enqueue each valid pixel
        for (int k = 0; k < 4; k++)
        {
            // if adjacent pixel at position (x + row[k], y + col[k]) is
            // a valid pixel and have same color as that of current pixel
            if (isSafe(mat, x + row[k], y + col[k], target, dimension, visited))
            {
              // cout << "safe square" << endl;
                // enqueue adjacent pixel
                q.push({x + row[k], y + col[k]});
                visited[x + row[k]][y + col[k]] = true;

            }
        }
    }
}

// main function
int main()
{
   ifstream fin("mooyomooyo.in");
   ofstream fout("mooyomooyo.out");
   int M;
   int counter = 0;
   fin >> M;
    int k;
    fin >> k;
    int mat[M][10];
    int numOfRows = M;
    for(int r = 0; r < M; r++){
        string s;
        fin >> s;
        for(int c = 0; c < 10; c++)
            mat[r][c] = s[c] - '0';
    }
    int x, y;

    // LOOPING TO CHECK IF MORE THINGS IT CAN BE SIMPLIFIED
    bool dirty = true;
    while (dirty) {
        bool visited[M][10];
        for(int r = 0; r < M; r++){
        for(int c =0; c< 10; c++){
            visited[r][c] = false;
        }
        }
        dirty = false;
      //  cout << "doing floodfilling" << endl;
        for(int r = 0; r < M; r++){
        for(int c =0; c< 10; c++){
            if(mat[r][c]!=0){
              // cout << mat[r][c] << endl;
                x = r;
                y = c;
                floodfill(mat, x, y, numOfRows, visited);
              //  cout << mat[r][c] << " " << valid.size() << endl;
                if(valid.size()>=k){
                        //cout << mat[r][c] << endl;
                        dirty = true;
                   //     cout << "reached" << endl;
                    for(int i =0; i < valid.size();i++){
                       // cout << valid.at(i).first << " " << valid.at(i).second << endl;
                        mat[valid.at(i).first][valid.at(i).second] = 0;

                    }
                }
                valid.clear();

            }
        }
    }
   // cout << "doing gravity" << " " << dirty << endl;
    if(dirty){
        counter++;
        for(int o = 0; o < 10; o++){

        int h = M-1;
        for (int i = M-1; i >-1; i--) {
        if (mat[i][o] != 0) {
            mat[h][o] = mat[i][o];
            if (i != h)
                mat[i][o] = 0;
            h--;
  }
}


}
      }
    }
if(counter==0){
    for(int o = 0; o < 10; o++){

        int h = M-1;
        for (int i = M-1; i >-1; i--) {
        if (mat[i][o] != 0) {
            mat[h][o] = mat[i][o];
            if (i != h)
                mat[i][o] = 0;
            h--;
  }
}


}
}
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 10; j++){
            fout << mat[i][j];
        }
        fout << endl;

    }
}



#include<bits/stdc++.h>
using namespace std;
#define M 6
#define N 6
void floodFillUtil(char mat[][N], int x, int y, char prevV, char newV)
{
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (mat[x][y] != prevV)
        return;
    mat[x][y] = newV;

    floodFillUtil(mat, x+1, y, prevV, newV);
    floodFillUtil(mat, x-1, y, prevV, newV);
    floodFillUtil(mat, x, y+1, prevV, newV);
    floodFillUtil(mat, x, y-1, prevV, newV);
}
int replaceSurrounded(char mat[][N])
{
   for (int i=0; i<M; i++)
      for (int j=0; j<N; j++)
          if (mat[i][j] == 'O')
             mat[i][j] = '-';

   for (int i=0; i<M; i++)  
      if (mat[i][0] == '-')
        floodFillUtil(mat, i, 0, '-', 'O');
   for (int i=0; i<M; i++)  
      if (mat[i][N-1] == '-')
        floodFillUtil(mat, i, N-1, '-', 'O');
   for (int i=0; i<N; i++) 
      if (mat[0][i] == '-')
        floodFillUtil(mat, 0, i, '-', 'O');
   for (int i=0; i<N; i++) 
      if (mat[M-1][i] == '-')
        floodFillUtil(mat, M-1, i, '-', 'O');

   for (int i=0; i<M; i++)
      for (int j=0; j<N; j++)
         if (mat[i][j] == '-')
             mat[i][j] = 'X';
 
}

int main()
{
    char mat[][N] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
    replaceSurrounded(mat);
 
 
    for (int i=0; i<M; i++)
    {
      for (int j=0; j<N; j++)
          cout << mat[i][j] << " ";
      cout << endl;
    }
    return 0;
}
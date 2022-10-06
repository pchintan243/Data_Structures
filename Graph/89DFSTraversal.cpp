#include <iostream>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int a[7][7] = {{0, 1, 1, 1, 0, 0, 0},
               {1, 0, 1, 0, 0, 0, 0},
               {1, 1, 0, 1, 1, 0, 0},
               {1, 0, 1, 0, 1, 0, 0},
               {0, 0, 1, 1, 0, 1, 1},
               {0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    visited[i] = 1;
    cout << i << " ";

    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j]) {
            DFS(j);
        }
    }
}
int main()
{
    // DFS Implementation
    DFS(0);
    return 0;
}
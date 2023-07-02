// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAX 509

using namespace std;

int16_t H, W;
char maze[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char cycle[] = {'s', 'n', 'u', 'k', 'e'};

bool dfs(int x, int y, int depth);

int main(){
    cin >> H >> W;

    rep(i, 0, H + 2){
        rep(j, 0, W + 2){
            if(i == 0 || i == H+1 || j == 0 || j == W+1){
                visited[i][j] = true;
            } else{
                visited[i][j] = false;
                cin >> maze[i][j];
            }
        }
    }

    if(dfs(1, 1, 0)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

bool dfs(int x, int y, int depth){
    // printf("(%d, %d)\n", x, y);
    if(x == H && y == W){
        return(true);
    }

    visited[x][y] = true;
    rep(i, 0, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nd = (depth + 1) % 5;
        if(visited[nx][ny] || maze[nx][ny] != cycle[nd]){
            continue;
        }
        if(dfs(nx, ny, nd)){
            return(true);
        }
    }
    // 同じ文字が含まれないため戻さなくてよい
    // visited[x][y] = false;

    return(false);
}
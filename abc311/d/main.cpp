// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 209
#define MAXM 209

using namespace std;

int16_t N, M;
char grid[MAXN][MAXM];
bool stop[MAXN][MAXM];

int16_t dx[] = {1, 0, -1, 0};
int16_t dy[] = {0, 1, 0, -1};

void move_on_ice(int16_t x, int16_t y);

int main(){
    cin >> N >> M;

    rep(i, 1, N){
        rep(j, 1, M){
            cin >> grid[i][j];
            stop[i][j] = false;
        }
    }

    grid[2][2] = '*';
    move_on_ice(2, 2);

    int16_t answer = 0;
    rep(i, 1, N){
        rep(j, 1, M){
            if(grid[i][j] == '*'){
                answer++;
            }
        }
    }

    cout << answer << endl;
    return(0);
}

void move_on_ice(int16_t x, int16_t y){
    if(stop[x][y]){
        return;
    }
    stop[x][y] = true;

    int16_t nx, ny;
    rep(i, 0, 3){
        nx = x;
        ny = y;

        if(grid[nx + dx[i]][ny + dy[i]] != '#'){
            while(grid[nx + dx[i]][ny + dy[i]] != '#'){
                nx += dx[i];
                ny += dy[i];
                grid[nx][ny] = '*';
            }
            move_on_ice(nx, ny);
        }
    }

    return;
}
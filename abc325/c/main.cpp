// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX 1009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i16 H, W;
char grid[MAX][MAX];
bool visited[MAX][MAX];

i16 dx[] = {1, 0, -1};
i16 dy[] = {1, 0, -1};

bool check_bound(i16 i, i16 j);
void dfs(i16 i, i16 j);

int main(){
    cin.tie(nullptr);

    cin >> H >> W;

    rep(i, 1, H){
        rep(j, 1, W){
            cin >> grid[i][j];
        }
    }

    i32 cnt = 0;
    rep(i, 1, H){
        rep(j, 1, W){
            if(grid[i][j] == '#'){
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;
    return(0);
}

bool check_bound(i16 i, i16 j){
    if(!(1 <= i && i <= H)){
        return false;
    }
    if(!(1 <= j && j <= W)){
        return false;
    }

    return true;
}

void dfs(i16 i, i16 j){
    if(!check_bound(i, j)){
        return;
    }

    if(visited[i][j]){
        return;
    }

    visited[i][j] = true;
    grid[i][j] = '.';

    rep(x, 0, 2){
        rep(y, 0, 2){
            i16 nx = i + dx[x];
            i16 ny = j + dy[y];
            if(grid[nx][ny] == '#'){
                dfs(nx, ny);
            }
        }
    }

    return;
}

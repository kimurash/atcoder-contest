// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 50

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template<typename T>
using vec = vector<T>;

i16 N;
i16 dx[] = {0, 1, 0, -1};
i16 dy[] = {1, 0, -1, 0};
i16 grid[MAX][MAX];

void dfs(i32 x, i32 y, i32 n, i16 dir);
void print_grid();

int main(){
    cin.tie(nullptr);

    cin >> N;
    rep(j, 0, N){
        grid[0][j]   = -1;
        grid[N+1][j] = -1;
    }
    rep(i, 0, N){
        grid[i][0]   = -1;
        grid[i][N+1] = -1;
    }
    
    dfs(1, 1, 1, 0);

    return(0);
}

void dfs(i32 x, i32 y, i32 n, i16 dir){
    if(n >= N * N){
        print_grid();
    }

    grid[x][y] = n;

    i16 nx = x + dx[dir];
    i16 ny = y + dy[dir];
    if(grid[nx][ny] != 0){
        dir = (dir + 1) % 4;
        nx = x + dx[dir];
        ny = y + dy[dir];
    }

    dfs(nx, ny, n + 1, dir);
    return;
}

void print_grid(){
    rep(i, 1, N){
        rep(j, 1, N){
            if(i == (N + 1) / 2 && j == (N + 1) / 2){
                cout << "T";
            } else{
                cout << grid[i][j];
            }
            if(j < N){
                cout << " ";
            }
        }
        cout << endl;
    }

    exit(0);
}
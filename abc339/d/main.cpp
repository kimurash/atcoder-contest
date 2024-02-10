// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 65

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef string str;

template<typename T>
using vec = vector<T>;

i16 dx[] = {0, 1, 0, -1};
i16 dy[] = {1, 0, -1, 0};

char grid[MAX][MAX];
i32 dist[MAX][MAX][MAX][MAX];

void init_dist(i16 N);

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 x1, y1, x2, y2;
    bool first = true;
    rep(i, 0, N + 1){
        rep(j, 0, N + 1){
            if(i == 0 || i == N + 1 || j == 0 || j == N + 1){
                grid[i][j] = '#';
            } else{
                cin >> grid[i][j];
                if(grid[i][j] == 'P'){
                    if(first){
                        x1 = i;
                        y1 = j;
                        first = false;
                    }else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
    }

    init_dist(N);
    
    queue<array<i16, 4>> yet;
    yet.push({x1, y1, x2, y2});
    dist[x1][y1][x2][y2] = 0;
    
    while(!yet.empty()){
        array<i16, 4> arr = yet.front();
        yet.pop();

        rep(i, 0, 3){
            i16 nx1 = arr[0] + dx[i];
            i16 ny1 = arr[1] + dy[i];
            if(grid[nx1][ny1] == '#'){
                nx1 = arr[0];
                ny1 = arr[1];
            }
            i16 nx2 = arr[2] + dx[i];
            i16 ny2 = arr[3] + dy[i];
            if(grid[nx2][ny2] == '#'){
                nx2 = arr[2];
                ny2 = arr[3];
            }

            if(dist[nx1][ny1][nx2][ny2] == -1){
                dist[nx1][ny1][nx2][ny2] = dist[arr[0]][arr[1]][arr[2]][arr[3]] + 1;
                yet.push({nx1, ny1, nx2, ny2});
            }
        }
    }

    i32 ans = INT32_MAX;
    rep(i, 1, N){
        rep(j, 1, N){
            if(dist[i][j][i][j] != -1){
                ans = min(ans, dist[i][j][i][j]);
            }
        }
    }

    cout << (ans == INT32_MAX ? -1 : ans) << endl;
    return(0);
}

void init_dist(i16 N){
    rep(i, 1, N){
        rep(j, 1, N){
            rep(k, 1, N){
                rep(l, 1, N){
                    dist[i][j][k][l] = -1;
                }
            }
        }
    }
}
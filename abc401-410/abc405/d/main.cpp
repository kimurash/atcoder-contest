// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

const i32 MAX = 1009;

char grid[MAX][MAX];
char answer[MAX][MAX];
i32 dist[MAX][MAX];

// 右, 下, 左, 上
i32 di[] = {0, 1, 0, -1};
i32 dj[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);

    i32 H, W;
    cin >> H >> W;

    vector<pi32> exits;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            } else{
                cin >> grid[i][j];
                answer[i][j] = grid[i][j];

                if(grid[i][j] == 'E'){
                    exits.push_back(make_pair(i, j));
                } else{
                    dist[i][j] = MAX * MAX;
                }
            }
        }
    }

    queue<pi32> yet;

    for(pi32 exit: exits){
        yet.push(exit);
    }

    while(!yet.empty()){
        pi32 now = yet.front();
        yet.pop();

        i32 ci = now.first;
        i32 cj = now.second;

        rep(i, 0, 3){
            i32 ni = ci + di[i];
            i32 nj = cj + dj[i];

            if(grid[ni][nj] == '#'){
                continue;
            }
            if(grid[ni][nj] == 'E'){
                continue;
            }

            if(dist[ci][cj] + 1 < dist[ni][nj]){
                dist[ni][nj] = dist[ci][cj] + 1;
                if(i == 0){
                    answer[ni][nj] = '<';
                } else if(i == 1){
                    answer[ni][nj] = '^';
                } else if(i == 2){
                    answer[ni][nj] = '>';
                } else{
                    answer[ni][nj] = 'v';
                }
                yet.push(make_pair(ni, nj));
            }
        }
    }

    rep(i, 1, H){
        rep(j, 1, W){
            cout << answer[i][j];
        }
        cout << endl;
    }

    return(0);
}

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 10009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

char grid[MAX][MAX];
i32 dist[MAX][MAX];

i32 di[] = {0, 0, 1, -1};
i32 dj[] = {1, -1, 0, 0};

int main(){
    cin.tie(nullptr);

    i32 H, W, D;
    cin >> H >> W >> D;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            grid[i][j] = '#';
            dist[i][j] = -1;
        }
    }

    i32 ans = 0;
    queue<pi32> yet;

    rep(i, 1, H){
        rep(j, 1, W){
            cin >> grid[i][j];
            if(grid[i][j] == 'H'){
                yet.push({i, j});
                dist[i][j] = 0;
                ans++;
            }
        }
    }
    
    i32 ci, cj;
    while(!yet.empty()){
        tie(ci, cj) = yet.front();
        yet.pop();
    
        rep(k, 0, 3){
            i32 ni = ci + di[k];
            i32 nj = cj + dj[k];

            if(grid[ni][nj] != '.'){
                continue;
            }

            if(dist[ni][nj] != -1){
                continue;
            }

            i32 d = dist[ci][cj] + 1;
            if(d <= D){
                dist[ni][nj] = d;
                yet.push({ni, nj});
                ans++;
            }
        }
    }

    cout << ans << endl;
    return(0);
}

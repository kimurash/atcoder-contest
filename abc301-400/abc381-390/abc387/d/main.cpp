// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 1009

#define HRZ 0
#define VRT 1

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef struct state{
    i32 i;
    i32 j;
    i16 d;
} State;

i16 di[] = {0, 1, 0, -1};
i16 dj[] = {1, 0, -1, 0};

char grid[MAX][MAX];
i32 dist[MAX][MAX][2];

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    i32 si, sj;
    i32 gi, gj;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            }else{
                cin >> grid[i][j];
                if(grid[i][j] == 'S'){
                    si = i;
                    sj = j;
                } else if(grid[i][j] == 'G'){
                    gi = i;
                    gj = j;
                }
            }
            dist[i][j][0] = INT32_MAX;
            dist[i][j][1] = INT32_MAX;
        }
    }

    queue<State> yet;
    dist[si][sj][0] = 0;
    dist[si][sj][1] = 0;
    yet.push({si, sj, 0});
    yet.push({si, sj, 1});

    while(!yet.empty()){
        State now = yet.front();
        yet.pop();

        rep(i, 0, 3){
            if((i & 1) == now.d){
                continue;
            }

            i32 ni = now.i + di[i];
            i32 nj = now.j + dj[i];
            i16 nd = now.d ^ 1;

            if(grid[ni][nj] == '#'){
                continue;
            }
            
            i32 d = dist[now.i][now.j][now.d] + 1;
            if(d < dist[ni][nj][nd]){
                dist[ni][nj][nd] = d;
                yet.push({ni, nj, nd});
            }
        }
    }

    i32 ans = min(dist[gi][gj][0], dist[gi][gj][1]);

    if(ans == INT32_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return(0);
}

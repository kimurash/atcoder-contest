// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX1D 1000
#define MAX2D 1001'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef string str;

template<typename T>
using vec = vector<T>;

i32 di[] = {1, 0, -1, 0};
i32 dj[] = {0, 1, 0, -1};

vec<i32> G[MAX2D];
i32 visited[MAX2D];

i32 dfs(i32 start, i32 now);

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    char cell;
    char grid[H + 2][W + 2];
    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '+'; // 周囲のマス
            } else{
                cin >> cell;
                grid[i][j] = cell;
            }
        }
    }

    rep(i, 1, H){
        rep(j, 1, W){
            i32 src = i * MAX1D + j; // 現在のマス番号
            // 未訪問を表す-1で初期化
            visited[src] = -1;

            // 磁石のマスからは移動できない
            if(grid[i][j] == '#'){
                continue;
            }
            bool free = true; // 現在のマスから移動できるか
            rep(d, 0, 3){
                i32 ni = i + di[d];
                i32 nj = j + dj[d];
                // 隣接するマスが磁石であれば移動できない
                if(grid[ni][nj] == '#'){
                    free = false;
                    break;
                }
                // グリッド内の空マスであれば隣接リストに追加
                if(grid[ni][nj] == '.'){
                    i32 dst = ni * MAX1D + nj;
                    G[src].push_back(dst);
                }
            }
            // 移動できない場合は隣接リストをclear
            if(!free){
                G[src].clear();
            }
        }
    }

    i32 ans = 1; // 自由度の最大値
    rep(i, 1, H){
        rep(j, 1, W){
            // 磁石のマスはスキップ
            if(grid[i][j] == '#'){
                continue;
            }
            // 未訪問の空マスからDFS
            i32 now = i * MAX1D + j;
            if(visited[now] < 0){
                i32 cnt = dfs(now, now);
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;
    return(0);
}

i32 dfs(i32 start, i32 now){
    if(visited[now] == start){
        return(0);
    }

    visited[now] = start;

    i32 cnt = 1;
    for(i32 adj : G[now]){
        if(visited[adj] != start){
            cnt += dfs(start, adj);
        }
    }

    return(cnt);
}

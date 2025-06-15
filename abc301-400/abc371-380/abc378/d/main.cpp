// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 19

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

i16 di[] = {0, 1, 0, -1};
i16 dj[] = {1, 0, -1, 0};

i32 K;
i64 ans;

char grid[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int32_t i, int32_t j, int32_t k);
void clear();

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W >> K;

    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            }
            else{
                cin >> grid[i][j];
            }
        }
    }

    rep(i, 1, H){
        rep(j, 1, W){
            if(grid[i][j] == '.'){
                dfs(i, j, 0);
                clear();
            }
        }
    }

    cout << ans << endl;

    return(0);
}

void dfs(int32_t i, int32_t j, int32_t k){
    if(K <= k){
        ans++;
        return;
    }

    visited[i][j] = true;

    rep(d, 0, 3){
        int32_t ni = i + di[d];
        int32_t nj = j + dj[d];

        if(grid[ni][nj] == '.' && !visited[ni][nj]){
            dfs(ni, nj, k + 1);
        }
    }

    visited[i][j] = false;

    return;
}

void clear(){
    rep(i, 1, 10){
        rep(j, 1, 10){
            visited[i][j] = false;
        }
    }
}

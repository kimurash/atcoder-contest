// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    char grid[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            cin >> grid[i][j];
        }
    }

    i32 row_cnt[N + 1];
    rep(i, 1, N){
        i32 cnt = 0;
        rep(j, 1, N){
            if(grid[i][j] == 'o'){
                cnt++;
            }
        }
        row_cnt[i] = cnt;
    }

    i32 col_cnt[N + 1];
    rep(j, 1, N){
        i32 cnt = 0;
        rep(i, 1, N){
            if(grid[i][j] == 'o'){
                cnt++;
            }
        }
        col_cnt[j] = cnt;
    }

    i64 ans = 0;
    rep(i, 1, N){
        rep(j, 1, N){
            if(grid[i][j] == 'o'){
                ans += (row_cnt[i] - 1) * (col_cnt[j] - 1);
            }
        }
    }

    cout << ans << endl;
/*
    rep(i, 1, N){
        printf("%d ", row_cnt[i]);
    }
    cout << endl;
    rep(j, 1, N){
        printf("%d ", col_cnt[j]);
    }
    cout << endl;
*/
    return(0);
}
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

int main(){
    cin.tie(nullptr);

    char grid[10][10];
    bool row[10], col[10];
    rep(i, 1, 8){
        row[i] = true;
        col[i] = true;
    }


    rep(i, 1, 8){
        rep(j, 1, 8){
            cin >> grid[i][j];
            if(grid[i][j] == '#'){
                if(row[i]){
                    row[i] = false;
                }
                if(col[j]){
                    col[j] = false;
                }
            }
        }
    }

    i32 ans = 0;
    rep(i, 1, 8){
        rep(j, 1, 8){
            if(grid[i][j] == '.' && row[i] && col[j]){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return(0);
}

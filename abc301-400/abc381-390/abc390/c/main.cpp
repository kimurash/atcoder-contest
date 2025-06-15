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

    i32 H, W;
    cin >> H >> W;

    i32 minr = H;
    i32 maxr = 0;
    i32 minc = W;
    i32 maxc = 0;

    char grid[H + 1][W + 1];
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> grid[i][j];
            if(grid[i][j] == '#'){
                minr = min(minr, i);
                maxr = max(maxr, i);
                minc = min(minc, j);
                maxc = max(maxc, j);
            }
        }
    }

    bool ans = true;
    rep(i, minr, maxr){
        rep(j, minc, maxc){
            if(grid[i][j] == '.'){
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return(0);
}

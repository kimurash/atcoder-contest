// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef string str;

template<typename T>
using vec = vector<T>;

i32 H, W, K;
str grid[MAX];

i32 check_row();
i32 check_col();

int main(){
    cin.tie(nullptr);

    cin >> H >> W >> K;
    grid[0] = string(W+1, '#');
    
    str S;
    rep(i, 1, H){
        cin >> S;
        grid[i] = '#' + S;
    }

    i32 ans = max(H, W) + 1;
    i32 min_row = check_row();
    if(min_row <= W){
        ans = min(ans, min_row);
    }

    i32 min_col = check_col();
    if(min_col <= H){
        ans = min(ans, min_col);
    }

    if(max(H, W) < ans){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }
    return(0);
}

i32 check_row(){
    i32 min_opr = 2 * W;

    rep(i, 1, H){
        i32 accd[W + 1] = {0};
        i32 accx[W + 1] = {0};
        rep(j, 1, W){
            accd[j] = accd[j - 1] + (grid[i][j] == '.');
            accx[j] = accx[j - 1] + (grid[i][j] == 'x');
        }
        rep(j, K, W){
            i32 cntx = accx[j] - accx[j - K];
            if(0 < cntx){
                continue;
            }
            i32 cntd = accd[j] - accd[j - K];
            min_opr = min(min_opr, cntd);
        }
    }

    return(min_opr);
}

i32 check_col(){
    i32 min_opr = 2 * H;

    rep(j, 1, W){
        i32 accd[H + 1] = {0};
        i32 accx[H + 1] = {0};
        rep(i, 1, H){
            accd[i] = accd[i - 1] + (grid[i][j] == '.');
            accx[i] = accx[i - 1] + (grid[i][j] == 'x');
        }
        rep(i, K, H){
            i32 cntx = accx[i] - accx[i - K];
            if(0 < cntx){
                continue;
            }
            i32 cntd = accd[i] - accd[i - K];
            min_opr = min(min_opr, cntd);
        }
    }

    return(min_opr);
}
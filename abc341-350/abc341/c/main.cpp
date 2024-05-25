// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 509

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef string str;

template<typename T>
using vec = vector<T>;

str T;
char grid[MAX][MAX];

bool wander(i16 i, i16 j, i32 N);

int main(){
    cin.tie(nullptr);

    i16 H, W, N;
    cin >> H >> W >> N;

    cin >> T;

    rep(i, 1, H){
        rep(j, 1, W){
            cin >> grid[i][j];
        }
    }

    i32 ans = 0;
    rep(i, 1, H){
        rep(j, 1, W){
            if(grid[i][j] == '.'){
                if(wander(i, j, N)){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return(0);
}

bool wander(i16 i, i16 j, i32 N){
    rep(n, 0, N - 1){
        switch(T[n]){
            case 'L':
                if(grid[i][j - 1] == '.'){
                    j--;
                } else{
                    return false;
                }
                break;
            case 'R':
                if(grid[i][j + 1] == '.'){
                    j++;
                } else{
                    return false;
                }
                break;
            case 'U':
                if(grid[i - 1][j] == '.'){
                    i--;
                } else{
                    return false;
                }
                break;
            case 'D':
                if(grid[i + 1][j] == '.'){
                    i++;
                } else{
                    return false;
                }
                break;
        }
    }
    return true;
}
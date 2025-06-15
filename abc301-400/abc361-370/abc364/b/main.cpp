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

    i16 H, W;
    cin >> H >> W;

    i32 si, sj;
    cin >> si >> sj;

    char grid[H + 2][W + 2];
    rep(i, 0, H + 1){
        rep(j, 0, W + 1){
            if(i == 0 || i == H + 1 || j == 0 || j == W + 1){
                grid[i][j] = '#';
            } else{
                cin >> grid[i][j];
            }
        }
    }
    
    string X;
    cin >> X;

    rep(i, 0, X.size() - 1){
        if(X[i] == 'L'){
            if(grid[si][sj - 1] != '#'){
                sj--;
            }
        } else if(X[i] == 'R'){
            if(grid[si][sj + 1] != '#'){
                sj++;
            }
        } else if(X[i] == 'U'){
            if(grid[si - 1][sj] != '#'){
                si--;
            }
        } else if(X[i] == 'D'){
            if(grid[si + 1][sj] != '#'){
                si++;
            }
        }
    }

    cout << si << " " << sj << endl;
    return(0);
}

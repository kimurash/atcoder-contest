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

    i32 H, W, N;
    cin >> H >> W >> N;

    vi32 rowvec[H + 1]; // rowvec[i]: i行目に落ちているゴミの列番号
    vi32 colvec[W + 1]; // colvec[i]: i列目に落ちているゴミの行番号

    i32 rowcnt[H + 1]; // rowcnt[i]: i行目に落ちているゴミの数
    i32 colcnt[W + 1]; // colcnt[i]: i列目に落ちているゴミの数

    rep(i, 1, H){
        rowcnt[i] = 0;
    }
    rep(i, 1, W){
        colcnt[i] = 0;
    }

    i32 X, Y;
    rep(i, 1, N){
        cin >> X >> Y;

        rowvec[X].push_back(Y);
        colvec[Y].push_back(X);

        rowcnt[X]++;
        colcnt[Y]++;
    }

    i32 Q;
    cin >> Q;

    i16 query;
    rep(i, 1, Q){
        cin >> query;

        if(query == 1){
            cin >> X;
            
            cout << rowcnt[X] << endl;

            for(i32 y : rowvec[X]){
                if(0 < colcnt[y]){
                    colcnt[y]--;
                }
            }

            rowcnt[X] = 0;
            rowvec[X].clear();
        } else if(query == 2){
            cin >> Y;

            cout << colcnt[Y] << endl;

            for(i32 x : colvec[Y]){
                if(0 < rowcnt[x]){
                    rowcnt[x]--;
                }
            }

            colcnt[Y] = 0;
            colvec[Y].clear();
        }
    }

    return(0);
}

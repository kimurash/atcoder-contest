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

int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    i32 A[H][W], B[H][W];
    rep(i, 0, H - 1){
        rep(j, 0, W - 1){
            cin >> A[i][j];
        }
    }
    rep(i, 0, H - 1){
        rep(j, 0, W - 1){
            cin >> B[i][j];
        }
    }

    vector<i32> row(H);
    rep(i, 0, H - 1){
        row[i] = i;
    }

    vector<i32> col(W);
    rep(j, 0, W - 1){
        col[j] = j;
    }

    i32 ans = INT32_MAX;
    do{
        do{
            bool match = true;
            rep(i, 0, H - 1){
                rep(j, 0, W - 1){
                    if(A[row[i]][col[j]] != B[i][j]){
                        match = false;
                    }
                }
            }
            if(!match){
                continue;
            }

            i32 row_inv = 0;
            rep(i, 0, H - 1){
                rep(j, 0, H - 1){
                    if(i < j && row[i] > row[j]){
                        row_inv++;
                    }
                }
            }

            i32 col_inv = 0;
            rep(i, 0, W - 1){
                rep(j, 0, W - 1){
                    if(i < j && col[i] > col[j]){
                        col_inv++;
                    }
                }
            }

            ans = min(ans, row_inv + col_inv);
        } while(next_permutation(all(col)));
    } while(next_permutation(all(row)));

    cout << (ans == INT32_MAX ? -1 : ans) << endl;
    return(0);
}
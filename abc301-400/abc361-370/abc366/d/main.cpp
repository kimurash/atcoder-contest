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

    i16 N;
    cin >> N;

    i16 A[N + 1][N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            rep(k, 1, N){
                cin >> A[i][j][k];
            }
        }
    }

    i32 acc[N + 1][N + 1][N + 1];
    rep(i, 0, N){
        rep(j, 0, N){
            rep(k, 0, N){
                if(i == 0 || j == 0 || k == 0){
                    acc[i][j][k] = 0;
                }else{
                    acc[i][j][k] = (
                        acc[i - 1][j][k]
                        + acc[i][j - 1][k]
                        + acc[i][j][k - 1]
                        - acc[i - 1][j - 1][k]
                        - acc[i - 1][j][k - 1]
                        - acc[i][j - 1][k - 1]
                        + acc[i - 1][j - 1][k - 1]
                        + A[i][j][k]
                    );
                }
            }
        }
    }

    i32 Q;
    cin >> Q;

    i16 Lx, Rx, Ly, Ry, Lz, Rz;
    rep(i, 1, Q){
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        i32 ans = (
            acc[Rx][Ry][Rz]
            - acc[Lx - 1][Ry][Rz]
            - acc[Rx][Ly - 1][Rz]
            - acc[Rx][Ry][Lz - 1]
            + acc[Lx - 1][Ly - 1][Rz]
            + acc[Lx - 1][Ry][Lz - 1]
            + acc[Rx][Ly - 1][Lz - 1]
            - acc[Lx - 1][Ly - 1][Lz - 1]
        );
        cout << ans << endl;
    }

    return(0);
}

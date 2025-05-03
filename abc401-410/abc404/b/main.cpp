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

    i32 N;
    cin >> N;

    char S[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            cin >> S[i][j];
        }
    }

    char T[N + 1][N + 1];
    rep(i, 1, N){
        rep(j, 1, N){
            cin >> T[i][j];
        }
    }

    i32 ans = INT32_MAX;
    rep(d, 0, 3){
        i32 cnt = 0;
        rep(i, 1, N){
            rep(j, 1, N){
                char c;
                if(d == 0){
                    c = S[i][j];
                } else if(d == 1){
                    c = S[N - j + 1][i];
                } else if(d == 2){
                    c = S[N - i + 1][N - j + 1];
                } else if(d == 3){
                    c = S[j][N - i + 1];
                }
                if(c != T[i][j]){
                    cnt++;
                }
            }
        }
        ans = min(ans, d + cnt);
    }

    cout << ans << endl;
    return(0);
}

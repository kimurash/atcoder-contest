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

    i32 side = 1;
    char carpet[730][730];
    carpet[0][0] = '#';

    rep(n, 1, N){
        rep(i, 0, 2){
            rep(j, 0, 2){
                if(i == 0 && j == 0){
                    continue;
                }
                if(i == 1 && j == 1){
                    rep(k, 0, side - 1){
                        rep(l, 0, side - 1){
                            carpet[i * side + k][j * side + l] = '.';
                        }
                    }
                } else{
                    rep(k, 0, side - 1){
                        rep(l, 0, side - 1){
                            carpet[i * side + k][j * side + l] = carpet[k][l];
                        }
                    }
                }
            }
        }
        side *= 3;
    }

    rep(i, 0, side - 1){
        rep(j, 0, side - 1){
            cout << carpet[i][j];
        }
        cout << endl;
    }

    return(0);
}

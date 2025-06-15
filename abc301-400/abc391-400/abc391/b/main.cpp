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

i16 N, M;

char S[60][60];
char T[60][60];

bool check(i32 i, i32 j);

int main(){
    cin.tie(nullptr);

    cin >> N >> M;

    rep(i, 0, N - 1){
        rep(j, 0, N - 1){
            cin >> S[i][j];
        }
    }

    rep(i, 0, M - 1){
        rep(j, 0, M - 1){
            cin >> T[i][j];
        }
    }

    rep(i, 0, N - M){
        rep(j, 0, N - M){
            if(check(i, j)){
                printf("%d %d\n", i + 1, j + 1);
                return(0);
            }
        }
    }

    return(0);
}

bool check(i32 i, i32 j){
    rep(k, 0, M - 1){
        rep(l, 0, M - 1){
            if(S[i + k][j + l] != T[k][l]){
                return(false);
            }
        }
    }
    return(true);
}

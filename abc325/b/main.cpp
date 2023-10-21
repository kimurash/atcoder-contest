// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

bool in_wtime(i16  t){
    return(9 <= t && t <= 18);
}

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 W[N + 1];
    i16 X[N + 1];
    rep(i, 1, N){
        cin >> W[i] >> X[i];
    }

    i32 ans = 0;
    rep(t, 0, 23){
        i32 attend = 0;
        rep(i, 1, N){
            i16 begin = (t     + X[i]) % 24;
            i16 end   = (t + 1 + X[i]) % 24;
            if(in_wtime(begin) && in_wtime(end)){
                attend += W[i];
            }
        }
        ans = max(ans, attend);
    }

    cout << ans << endl;
    return(0);
}
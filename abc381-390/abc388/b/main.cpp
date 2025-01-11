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

typedef struct snake{
    i32 T;
    i32 L;
} Snake;

int main(){
    cin.tie(nullptr);

    i16 N, D;
    cin >> N >> D;

    i32 T, L;
    Snake snakes[N + 1];
    rep(i, 1, N){
        cin >> T >> L;
        snakes[i] = {T, L};
    }

    rep(k, 1, D){
        i32 maxw = 0;
        rep(j, 1, N){
            i32 w = snakes[j].T * (snakes[j].L + k);
            maxw = max(maxw, w);
        }
        cout << maxw << endl;
    }

    return(0);
}

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i64 pow_of(i32 n){
    i64 r = n;
    rep(i, 2, n){
        r *= n;
    }
    return(r);
}

int main(){
    cin.tie(nullptr);

    i64 B;
    cin >> B;

    rep(i, 1, 15){
        i64 cand = pow_of(i);
        if(cand == B){
            cout << i << endl;
            return(0);
        }
    }

    cout << -1 << endl;
    return(0);
}
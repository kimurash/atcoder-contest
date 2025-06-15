// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    map<i32, i64> value;

    i64 S, C;
    rep(i, 1, N){
        cin >> S >> C;
        while((S & 1) == 0){
            S >>= 1;
            C <<= 1;
        }
        value[S] += C; // mapの初期値は0
    }

    i64 ans = 0;
    auto itr = value.begin();
    while(itr != value.end()){
        ans += __builtin_popcountll(itr->second);
        itr++;
    }

    cout << ans << endl;
    return(0);
}
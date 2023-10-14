// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    string S;
    cin >> S;

    i16 avail[10] = {0};
    rep(i, 0, N - 1){
        avail[S[i] - '0']++;
    }

    i64 ub = 1;
    rep(i, 1, N){
        ub *= 10;
    }

    i64 ans = 0;
    for(i64 base = 0; base * base < ub; base++){
        string T = to_string(base * base);
        T.resize(N, '0');

        i16 need[10] = {0};
        rep(i, 0, N - 1){
            need[T[i] - '0']++;
        }

        i16 digit;
        for(digit = 0; digit < 10; digit++){
            if(need[digit] != avail[digit]){
                break;
            }
        }
        if(digit == 10){
            ans++;
        }
    }

    cout << ans << endl;
    return(0);
}
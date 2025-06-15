// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, M, P;
    cin >> N >> M >> P;

    if(N < M){
        cout << 0 << endl;
    } else{
        cout << (N - M) / P + 1 << endl;
    }

    return(0);
}
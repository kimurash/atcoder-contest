// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 M;
    cin >> M;

    i16 D[M + 1];
    i16 sum = 0;
    rep(i, 1, M){
        cin >> D[i];
        sum += D[i];
    }

    i16 half = (sum + 1) / 2;

    i16 month = 1;
    while(D[month] < half){
        half -= D[month];
        month++;
    }

    printf("%d %d\n", month, half);
    return(0);
}
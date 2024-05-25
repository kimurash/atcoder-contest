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

    i16 M, D;
    i16 y, m, d;
    cin >> M >> D;
    cin >> y >> m >> d;

    d++;
    if(d > D){
        d = 1;
        m++;
    }
    if(m > M){
        m = 1;
        y++;
    }

    printf("%d %d %d\n", y, m, d);
    return(0);
}
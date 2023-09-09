// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define range(v, b, e) v + b, v + e

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, D, P;
    cin >> N >> D >> P;

    i32 fare[N + 1];
    rep(i, 1, N){
        cin >> fare[i];
    }

    sort(range(fare, 1, N + 1));

    i64 acc[N + 1];
    acc[0] = 0;
    rep(i, 1, N){
        acc[i] = acc[i - 1] + fare[i];
    }

    i64 sum = 0;
    i32 tail = N;

    while(tail > 0){
        i64 lastd = acc[tail] - acc[max(0, tail - D)];

        if(lastd < P){
            break;
        } else{
            sum += P;
            tail -= D;
        }
    }

    if(tail > 0){
        sum += acc[tail] - acc[0];
    }

    cout << sum << endl;
    return(0);
}

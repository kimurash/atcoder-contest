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

    i16 N, M;
    cin >> N >> M;

    i16 sup[N + 1];
    rep(i, 1, N){
        sup[i] = 0;
    }

    i16 A, B;
    rep(i, 1, M){
        cin >> A >> B;
        sup[B]++;
    }

    i16 answer = -1;
    rep(i, 1, N){
        if(sup[i] == 0){
            if(answer != -1){
                cout << -1 << endl;
                return(0);
            }

            answer = i;
        }
    }

    cout << answer << endl;
    return(0);
}
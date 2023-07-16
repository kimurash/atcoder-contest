// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    int32_t P, Q, D;
    cin >> N >> P >> Q;

    int32_t min_amnt = P;
    rep(i, 0, N){
        cin >> D;
        min_amnt = min(min_amnt, Q + D);
    }

    cout << min_amnt << endl;
    return(0);
}
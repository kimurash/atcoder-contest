// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 F, S;
    pi32 icecrm[N + 1];
    rep(i, 1, N){
        cin >> F >> S;
        icecrm[i] = make_pair(S, F);
    }

    sort(icecrm + 1, icecrm + N + 1);

    i64 same = icecrm[N].first;
    i32 flavor = icecrm[N].second;
    for(int i = N - 1; i > 0; i--){
        if(icecrm[i].second == flavor){
            same += icecrm[i].first / 2;
            break;
        }
    }

    i64 diff = icecrm[N].first;
    for(int i = N - 1; i > 0; i--){
        if(icecrm[i].second != flavor){
            diff += icecrm[i].first;
            break;
        }
    }

    cout << max(same, diff) << endl;
    return(0);
}
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define ALPH 26

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    string S;
    cin >> N >> S;

    i32 idx = 0;
    i32 cnt_map[ALPH] = {0};

    while(idx < N){
        i32 cnt = 1;
        while(idx < N - 1 && S[idx] == S[idx + 1]){
            cnt++;
            idx++;
        }
        cnt_map[S[idx] - 'a'] = max(cnt_map[S[idx] - 'a'], cnt);

        idx++;
    }

    i32 sum = 0;
    rep(i, 0, ALPH - 1){
        sum += cnt_map[i];
    }
    cout << sum << endl;

    return(0);
}
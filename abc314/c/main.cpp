// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    i32 color;
    vector<i32> clf[M + 1];
    rep(i, 1, N){
        cin >> color;
        clf[color].push_back(i - 1);
    }

    char T[N + 1];
    rep(i, 1, M){
        i32 total = clf[i].size();
        rep(j, 0, total - 1){
            T[clf[i][(j + 1) % total]] = S[clf[i][j]];
        }
    }
    T[N] = '\0';

    cout << T << endl;
    return(0);
}
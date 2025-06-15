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

    i32 N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    queue<i32> cand;
    bool hist[N + 1] = {false};

    auto check = [&](i32 i){
        if(hist[i]){
            return;
        }

        bool result = true;
        rep(j, 0, M - 1){
            if(i + j > N - 1){
                result = false;
                break;
            }
            result &= (S[i + j] == '#') || (S[i + j] == T[j]);
        }
        if(result){
            cand.push(i);
            hist[i] = true;
        }
    };

    rep(i, 0, N - M){
        check(i);
    }

    while(!cand.empty()){
        i32 s = cand.front();
        cand.pop();
        rep(i, 0, M - 1){
            S[s + i] = '#';
        }

        rep(i, max(s - M + 1, 0), min(s + M - 1, N - M)){
            check(i);
        }
    }

    cout << (S == string(N, '#') ? "Yes" : "No") << endl;

    return(0);
}
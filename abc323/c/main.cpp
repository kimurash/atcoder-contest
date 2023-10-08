// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N, M;
    cin >> N >> M;

    i16 A[M + 1] = {0};
    rep(i, 1, M){
        cin >> A[i];
    }

    string S[N + 1];
    i32 score[N + 1] = {0};
    i32 max_score = 0;
    rep(i, 1, N){
        cin >> S[i];
        rep(j, 1, M){
            if(S[i][j - 1] == 'o'){
                score[i] += A[j];
            }
        }
        score[i] += i;
        max_score = max(max_score, score[i]);
    }

    rep(i, 1, N){
        i32 crnt_score = score[i];
        if(crnt_score == max_score){
            cout << 0 << endl;
            continue;
        }

        vector<i16> rem;
        rep(j, 1, M){
            if(S[i][j - 1] == 'x'){
                rem.push_back(A[j]);
            }
        }

        sort(rall(rem));

        i16 ans = 0;
        while(crnt_score <= max_score && ans < rem.size()){
            crnt_score += rem[ans++];
        }
        cout << ans << endl;
    }

    return(0);
}
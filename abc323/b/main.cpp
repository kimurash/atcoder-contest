// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 score[N + 1] = {0};
    string S;
    rep(i, 1, N){
        cin >> S;
        rep(j, 1, N){
            if(S[j - 1] == 'o'){
                score[i]++;
            }
        }
    }

    vector<pi16> result;
    rep(i, 1, N){
        result.push_back(make_pair(score[i], -i));
    }

    sort(rall(result));

    cout << -result[0].second;
    rep(i, 1, N - 1){
        cout << " " << -result[i].second;
    }
    cout << endl;

    return(0);
}

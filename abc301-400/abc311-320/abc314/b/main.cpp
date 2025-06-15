// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define LIMIT 36

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 A, C;
    vector<pi16> bet[LIMIT + 1];
    rep(i, 1, N){
        cin >> C;
        rep(j, 1, C){
            cin >> A;
            bet[A].push_back(make_pair(C, i));
        }
    }

    i16 X;
    cin >> X;

    vector<pi16> winner = bet[X];
    if(winner.size() == 0){
        printf("0\n\n");
        return(0);
    }

    sort(all(winner));

    i16 cmin = winner[0].first;
    vector<i16> answer;
    for(pi16 p: winner){
        if(p.first <= cmin){
            answer.push_back(p.second);
        } else{
            break;
        }
    }

    cout << answer.size() << endl;
    cout << answer[0];
    rep(i, 1, answer.size() - 1){
        cout << " " << answer[i];
    }
    cout << endl;

    return(0);
}
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef struct Score{
    int32_t idx;
    int32_t num;
    int32_t den;
} Score;

bool comp(const Score &a, const Score &b){
    return((int64_t)a.num * b.den > (int64_t)b.num * a.den);
}

int main(){
    int32_t N;
    cin >> N;

    int32_t A, B;
    vector<Score> C;
    rep(i, 0, N){
        cin >> A >> B;
        Score score = {i + 1, A, A + B};
        C.push_back(score);
    }

    stable_sort(all(C), comp);

    cout << C.at(0).idx;
    rep(i, 1, N){
        printf(" %d", C.at(i).idx);
    }
    cout << endl;
}
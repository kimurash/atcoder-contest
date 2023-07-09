#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef pair<int32_t, int32_t> pi32;

int main(){
    int32_t N, K;
    cin >> N >> K;

    int64_t med_sum = 0;
    vector<pi32> med(N);
    rep(i, 0, N){
        cin >> med[i].first >> med[i].second;
        med_sum += med[i].second;
    }

    if(med_sum <= K){
        cout << 1 << endl;
        return(0);
    }

    sort(all(med));

    rep(i, 0, N){
        med_sum -= med[i].second;
        if(med_sum <= K){
            cout << med[i].first + 1 << endl;
            break;
        }
    }
}
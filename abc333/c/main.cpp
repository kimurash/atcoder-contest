// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i64 repnit[15];
    repnit[0] = 1;
    rep(i, 1, 11){
        repnit[i] = repnit[i - 1] * 10 + 1;
    }

    vector<i64> cand;
    rep(i, 0, 11){
        rep(j, i, 11){
            rep(k, j, 11){
                cand.push_back(repnit[i] + repnit[j] + repnit[k]);
            }
        }
    }

    sort(all(cand));

    cout << cand[N - 1] << endl;
    return(0);
}
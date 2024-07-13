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

typedef long long ll;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i64 min_sum = 0;
    i64 max_sum = 0;
    i32 L[N + 1], R[N + 1];
    rep(i, 1, N){
        cin >> L[i] >> R[i];
        min_sum += L[i];
        max_sum += R[i];
    }

    if(0 < min_sum || max_sum < 0){
        cout << "No" << endl;
        return(0);
    }

    ll xsum = min_sum; // min_sum <= 0
    i32 X[N + 1];
    rep(i, 1, N){
        X[i] = L[i];
    }

    rep(i, 1, N){
        // 必要以上は足さないためxsumが正になることはない
        i32 d = min(1LL * R[i] - L[i], -xsum);
        xsum += d;
        X[i] += d;
    }

    cout << "Yes" << endl;
    rep(i, 1, N){
        if(i != 1){
            cout << " ";
        }
        cout << X[i];
    }
    cout << endl;

    return(0);
}

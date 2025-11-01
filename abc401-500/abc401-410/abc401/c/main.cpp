// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MOD 1000'000'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    if(N < K){
        cout << 1 << endl;
        return(0);
    }

    i32 A[N + 1], acc[N + 1];
    A[0] = acc[0] = 1;
    rep(i, 1, K - 1){
        A[i] = 1;
        acc[i] = (acc[i - 1] + A[i]) % MOD;
    }

    A[K] = acc[K - 1];
    acc[K] = (acc[K - 1] + A[K]) % MOD;

    rep(i, K + 1, N){
        A[i] = (acc[i - 1] - acc[i - K - 1] + MOD) % MOD;
        acc[i] = (acc[i - 1] + A[i]) % MOD;
    }
    cout << A[N] << endl;

    return(0);
}

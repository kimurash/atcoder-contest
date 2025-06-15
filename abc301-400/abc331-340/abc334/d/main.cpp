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

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    i32 N, Q;
    cin >> N >> Q;

    i32 R[N + 1];
    rep(i, 1, N){
        cin >> R[i];
    }

    sort(R + 1, R + N + 1);

    i64 acc[N + 1];
    acc[0] = 0;
    rep(i, 1, N){
        acc[i] = acc[i - 1] + R[i];
    }

    i64 X;
    rep(i, 1, Q){
        cin >> X;
        i32 idx = upper_bound(acc + 1, acc + N + 1, X) - acc;
        cout << idx - 1 << endl;
    }
    return(0);
}
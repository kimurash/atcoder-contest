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
typedef string str;

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i64 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 S[N], T[N];
    rep(i, 1, N - 1){
        cin >> S[i] >> T[i];
    }

    rep(i, 1, N - 1){
        i64 exch = A[i] / S[i];
        A[i + 1] += exch * T[i];
    }

    cout << A[N] << endl;
    return(0);
}
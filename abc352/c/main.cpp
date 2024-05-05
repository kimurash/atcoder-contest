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

    i64 sum = 0;
    i32 A[N], B[N];
    rep(i, 0, N - 1){
        cin >> A[i] >> B[i];
        sum += A[i];
    }

    i64 ans = 0;
    rep(i, 0, N - 1){
        i64 cand = sum - A[i] + B[i];
        ans = max(ans, cand);
    }

    cout << ans << endl;
    return(0);
}

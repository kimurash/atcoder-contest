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

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A[N + 1];
    i64 sum = 0;
    rep(i, 1, N){
        cin >> A[i];
        sum += A[i];
    }

    i64 sums[N + 1];
    sums[1] = sum;
    rep(i, 2, N){
        sums[i] = sums[i - 1] - A[i - 1];
    }

    i64 ans = 0;
    rep(i, 1, N - 1){
        ans += A[i] * sums[i + 1];
    }

    cout << ans << endl;

    return(0);
}

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;
using mint = atcoder::modint998244353;

typedef string str;

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

    i64 A[N + 1];
    mint acc[N + 1];
    i32 digit[N + 1];

    acc[0] = 0;
    rep(i, 1, N){
        cin >> A[i];
        acc[i] = acc[i - 1] + A[i];
        digit[i] = static_cast<i32>(log10(A[i])) + 1;
    }

    mint pow[11];
    pow[0] = 1;
    rep(i, 1, 10){
        pow[i] = pow[i - 1] * 10;
    }

    mint ans = 0;
    rep(i, 2, N){
        ans += acc[i - 1] * pow[digit[i]];
        ans += A[i] * (i - 1);
    }

    cout << ans.val() << endl;
    return(0);
}

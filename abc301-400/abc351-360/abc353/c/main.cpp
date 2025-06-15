// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MOD 10000'0000

using namespace std;

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

    i64 ans = 0;
    i64 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
        ans += A[i] * (N - 1);
    }

    sort(A, A + N);

    i64 cnt = 0;
    rep(i, 1, N - 1){
        i32 rem = MOD - A[i];
        i32 lb = (A + N) - lower_bound(A + i, A + N, rem);
        cnt += lb;
    }

    ans -= cnt * MOD;
    cout << ans << endl;
    return(0);
}

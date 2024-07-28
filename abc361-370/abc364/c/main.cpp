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

i32 get_upper_bound(i32 *C, i32 N, i64 Z){
    i32 cnt = 1;
    i64 acc = C[1];
    rep(i, 2, N){
        if(Z < acc){
            break;
        }
        acc += C[i];
        cnt++;
    }
    return(cnt);
}

int main(){
    cin.tie(nullptr);

    i32 N;
    i64 X, Y;
    cin >> N >> X >> Y;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 B[N + 1];
    rep(i, 1, N){
        cin >> B[i];
    }

    sort(A + 1, A + N + 1, greater<i32>());
    sort(B + 1, B + N + 1, greater<i32>());

    i32 ans = N;
    ans = min(ans, get_upper_bound(A, N, X));
    ans = min(ans, get_upper_bound(B, N, Y));

    cout << ans << endl;
    return(0);
}

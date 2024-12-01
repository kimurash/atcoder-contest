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

    i32 N, M;
    cin >> N >> M;

    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    i32 B[M];
    rep(i, 0, M - 1){
        cin >> B[i];
    }

    i32 C[N];
    C[0] = A[0];
    rep(i, 1, N - 1){
        C[i] = min(C[i - 1], A[i]);
    }
    rep(i, 0, N - 1){
        C[i] = -C[i];
    }

    rep(i, 0, M - 1){
        i32 ans = lower_bound(C, C + N, -B[i]) - C;
        if(ans == N){
            cout << -1 << endl;
        } else {
            cout << ans + 1 << endl;
        }
    }

    return(0);
}

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

    i16 N;
    cin >> N;

    i32 Q[N + 1], A[N + 1], B[N + 1];
    rep(i, 1, N){
        cin >> Q[i];
    }
    rep(i, 1, N){
        cin >> A[i];
    }
    rep(i, 1, N){
        cin >> B[i];
    }

    i32 mina = INT32_MAX;
    rep(i, 1, N){
        if(A[i] == 0){
            continue;
        }
        i32 a = Q[i] / A[i];
        mina = min(mina, a);
    }

    i32 ans = 0;
    rep(na, 0, mina){
        i32 cnt = na;
        i32 minb = INT32_MAX;
        rep(i, 1, N){
            if(B[i] == 0){
                continue;
            }
            i32 rem = Q[i] - A[i] * na;
            i32 b = rem / B[i];
            minb = min(minb, b);
        }
        ans = max(ans, cnt + minb);
    }

    cout << ans << endl;
    return(0);
}
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

    i64 A, M, L, R;
    cin >> A >> M >> L >> R;

    i64 ans;
    if(L <= A && A <= R){
        i64 X = (A - L) / M;
        i64 Y = (R - A) / M;
        ans = X + Y + 1; // +1はAを含むため
    } else{
        i64 X = abs(L - A) / M;
        i64 Y = abs(R - A) / M;
        i64 rem = 0;
        if(A < L){
            rem = (L - A) % M;
        } else if(R < A){
            rem = (A - R) % M;
        }
        ans = abs(X - Y) + (rem == 0 ? 1 : 0);
    }

    cout << ans << endl;
    return(0);
}
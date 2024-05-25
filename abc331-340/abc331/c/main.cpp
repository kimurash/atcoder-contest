// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A[N + 1], B[N + 1];
    rep(i, 1, N){
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B + 1, B + N+1);

    i64 acc[N + 1] = {0};
    rep(i, 1, N){
        acc[i] = acc[i - 1] + B[i];
    }

    rep(i, 1, N){
        i32 ub_idx = upper_bound(B + 1, B + N+1, A[i]) - B;
        
        if(i != 1){
            cout << " ";
        }
        if(ub_idx == N + 1){
            cout << 0;
        } else{
            cout << acc[N] - acc[ub_idx - 1];
        }
    }
    cout << endl;

    return(0);
}
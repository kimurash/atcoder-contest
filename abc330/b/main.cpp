// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, L, R;
    cin >> N >> L >> R;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    rep(n, 1, N){
        if(n != 1){
            cout << " ";
        }
        if(A[n] < L){
            cout << L;
        } else if(A[n] > R){
            cout << R;
        } else {
            cout << A[n];
        }
    }
    cout << endl;

    return(0);
}
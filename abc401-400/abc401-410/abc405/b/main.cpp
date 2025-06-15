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

    i32 A[N + 1];
    i32 B[M + 1];
    rep(i, 1, M){
        B[i] = 0;
    }
    rep(i, 1, N){
        cin >> A[i];
        B[A[i]]++;
    }

    rep(i, 1, M){
        if(B[i] == 0){
            cout << 0 << endl;
            return(0);
        }
    }

    i32 cnt = 0;
    for(i32 i = N; 0 < i; i--){
        B[A[i]]--;
        cnt++;
        if(B[A[i]] == 0){
            break;
        }
    }

    cout << cnt << endl;

    return(0);
}

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

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

    i16 N, K;
    cin >> N >> K;

    i16 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 rem = K;
    i32 cnt = 0;
    rep(i, 1, N){
        if(rem < A[i]){
            cnt++;
            rem = K - A[i];
        } else{
            rem -= A[i];
        }
    }
    if(rem < K){
        cnt++;
    }

    cout << cnt << endl;
    return(0);
}

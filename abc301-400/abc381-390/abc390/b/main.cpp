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

    i16 N;
    cin >> N;

    i64 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    rep(i, 1, N - 2){
        i64 a = A[i + 1] * A[i + 1];
        i64 b = A[i] * A[i + 2];
        if(a != b){
            cout << "No" << endl;
            return(0);
        }
    }

    cout << "Yes" << endl;

    return(0);
}

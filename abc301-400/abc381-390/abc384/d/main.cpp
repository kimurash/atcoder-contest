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

    i32 N;
    i64 S;
    cin >> N >> S;

    i32 A[N];
    i64 sum = 0;
    rep(i, 0, N - 1){
        cin >> A[i];
        sum += A[i];
    }

    S %= sum;

    vi64 acc(2 * N + 1);
    acc[0] = 0;
    rep(i, 1, 2 * N){
        acc[i] = acc[i - 1] + A[(i - 1) % N];
    }

    rep(i, 0, 2 * N){
        bool result = binary_search(all(acc), acc[i] + S);
        if(result){
            cout << "Yes" << endl;
            return(0);
        }
    }

    cout << "No" << endl;
    return(0);
}

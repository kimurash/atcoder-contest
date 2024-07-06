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
    cin >> N;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }
    i32 W[N + 1];
    i64 sum = 0;
    rep(i, 1, N){
        cin >> W[i];
        sum += W[i];
    }

    i32 max_weight[N + 1] = {0};
    rep(i, 1, N){
        i32 box = A[i];
        if(max_weight[box] < W[i]){
            max_weight[box] = W[i];
        }
    }

    i64 ans = sum;
    rep(i, 1, N){
        ans -= max_weight[i];
    }

    cout << ans << endl;
    return(0);
}

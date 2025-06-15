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

bool check(vi32 A, i32 K);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    vi32 A(N);
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    i32 low = 0;
    i32 high = N / 2 + 1;

    while(low + 1 < high){
        i32 mid = (low + high) / 2;
        if(check(A, mid)){
            low = mid;
        } else{
            high = mid;
        }
    }

    cout << low << endl;
    return(0);
}

bool check(vi32 A, i32 K){
    rep(k, 0, K - 1){
        i32 l = k;
        i32 r = (A.size() - K) + k;

        if(r <= l){
            return(false);
        }

        if(A[r] < 2LL * A[l]){
            return(false);
        }
    }

    return(true);
}

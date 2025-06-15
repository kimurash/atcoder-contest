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

i64 calc_amount(i64 *A, i64 N, i64 x);

int main(){
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    i64 A[N];
    i64 maxa = 0;
    rep(i, 0, N - 1){
        cin >> A[i];
        maxa = max(maxa, A[i]);
    }

    i64 left = 0, right = 1e9 + 10;
    while(left + 1 < right){
        i64 mid = (left + right) / 2;
        i64 amount = calc_amount(A, N, mid);
        if(M < amount){
            right = mid;
        } else{
            left = mid;
        }
    }

    if(maxa < left){
        cout << "infinite" << endl;
    } else{
        cout << left << endl;
    }

    return(0);
}

i64 calc_amount(i64 *A, i64 N, i64 x){
    i64 amount = 0;
    rep(i, 0, N - 1){
        amount += min(x, A[i]);
    }
    return(amount);
}

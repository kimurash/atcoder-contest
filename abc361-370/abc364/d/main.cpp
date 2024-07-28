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

    i32 N, Q;
    cin >> N >> Q;

    i64 a[N + 1];
    rep(i, 1, N){
        cin >> a[i];
    }
    sort(a + 1, a + N + 1);

    i64 b, k;
    rep(j, 1, Q){
        cin >> b >> k;

        i64 left = -1, right = 2e8 + 10;
        while(left + 1 < right){
            i64 mid = (left + right) / 2;
            i32 ub = upper_bound(a + 1, a + N + 1, b + mid) - a;
            i32 lb = lower_bound(a + 1, a + N + 1, b - mid) - a;
            if(k <= ub - lb){
                right = mid;
            }else{
                left = mid;
            }
        }
        cout << right << endl;
    }

    return(0);
}

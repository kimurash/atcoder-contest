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

    i64 R;
    cin >> R;

    i64 cnt = 0;
    rep(i, 0, R){
        i64 low = 0;
        i64 high = R + 1;

        while(low + 1 < high){
            i64 mid = (low + high) / 2;
            double a = (mid + 0.5) * (mid + 0.5);
            double b = R * R - (i + 0.5) * (i + 0.5);
            if(a <= b){
                low = mid;
            } else {
                high = mid;
            }
        }
        cnt += low;
    }

    cout << cnt * 4 + 1 << endl;

    return(0);
}

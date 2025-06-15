// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <iomanip>

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

    i16 X, Y;
    cin >> X >> Y;

    i32 cnt = 0;
    rep(i, 1, 6){
        rep(j, 1, 6){
            if(X <= i + j){
                cnt++;
            } else if(Y <= abs(i - j)){
                cnt++;
            }
        }
    }

    double ans = cnt / 36.0;
    cout << fixed << setprecision(10) << ans << endl;

    return(0);
}

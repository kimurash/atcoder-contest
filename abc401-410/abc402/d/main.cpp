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

    i64 N, M;
    cin >> N >> M;

    map<i64, i64> mp;

    i32 A, B;
    rep(i, 1, M){
        cin >> A >> B;
        mp[(A + B) % N]++;
    }

    i64 ans = M * (M - 1) / 2;
    for(auto [sum, cnt] : mp){
        if(1 < cnt){
            ans -= cnt * (cnt - 1) / 2;
        }
    }
    cout << ans << endl;

    return(0);
}

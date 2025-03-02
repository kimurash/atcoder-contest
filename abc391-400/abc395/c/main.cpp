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

    i32 ans = INT32_MAX;
    map<i32, i32> mp;
    rep(i, 1, N){
        if(0 < mp.count(A[i])){
            i32 pos = mp[A[i]];
            i32 len = i - pos + 1;
            ans = min(ans, len);
        }
        mp[A[i]] = i;
    }

    if(ans == INT32_MAX){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }

    return(0);
}

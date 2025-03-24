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

typedef pair<int32_t, int32_t> pi32;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A;
    map<i32, vi32> mp;
    rep(i, 1, N){
        cin >> A;
        mp[A].push_back(i);
    }

    i32 ans = -1;
    i32 maxn = 0;
    for(pair<i32, vi32> p : mp){
        vi32 v = p.second;
        if(v.size() == 1){
            if(maxn < p.first){
                ans = v[0];
                maxn = p.first;
            }
        }
    }

    cout << ans << endl;
    return(0);
}

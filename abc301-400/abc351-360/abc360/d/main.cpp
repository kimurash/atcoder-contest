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

    i32 N, T;
    cin >> N >> T;

    string S;
    cin >> S;

    i32 pos;
    vi32 pls, mns;
    rep(i, 1, N){
        cin >> pos;
        if(S[i - 1] == '0'){
            mns.push_back(pos);
        } else{
            pls.push_back(pos);
        }
    }

    sort(all(mns));

    i64 ans = 0;
    for(i32 ant : pls){
        i32 start = lower_bound(all(mns), ant) - mns.begin();
        i32 end = upper_bound(all(mns), ant + 1LL * 2 * T) - mns.begin();
        ans += max(end - start, 0);
    }

    cout << ans << endl;
    return(0);
}

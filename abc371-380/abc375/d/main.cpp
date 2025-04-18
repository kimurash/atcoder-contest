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

    string S;
    cin >> S;

    i64 ans = 0;
    i64 cnt[30] = {0};
    i64 acc[30] = {0};

    rep(i, 0, S.length() - 1){
        i32 c = S[i] - 'A';
        ans += (i - 1) * cnt[c] - acc[c];
        cnt[c]++;
        acc[c] += i;
    }

    cout << ans << endl;
    return(0);
}

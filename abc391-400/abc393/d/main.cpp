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
    string S;
    cin >> N >> S;

    i32 cnt = 0;
    vi32 pos;
    rep(i, 0, N - 1){
        if(S[i] == '1'){
            cnt++;
            pos.push_back(i - cnt);
        }
    }

    i32 median;
    if(cnt & 1){ // 奇数
        median = pos[cnt / 2];
    } else{ // 偶数
        median = (pos[(cnt / 2) - 1] + pos[cnt / 2]) / 2;
    }

    i64 ans = 0;
    for(i32 p : pos){
        ans += max(0, abs(median - p));
    }
    
    cout << ans << endl;

    return(0);
}

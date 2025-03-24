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

    i32 N, R, C;
    cin >> N >> R >> C;

    string S;
    cin >> S;

    i32 r = 0;
    i32 c = 0;

    string ans = "";
    set<pi32> smokes;
    smokes.emplace(0, 0);
    rep(i, 0, N - 1){
        if(S[i] == 'N'){
            r++;
        } else if(S[i] == 'S'){
            r--;
        } else if(S[i] == 'W'){
            c++;
        } else if(S[i] == 'E'){
            c--;
        }
        smokes.emplace(r, c);
        if(0 < smokes.count({r + R, c + C})){
            ans += "1";
        } else{
            ans += "0";
        }
    }

    cout << ans << endl;
    return(0);
}

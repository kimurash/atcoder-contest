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

typedef uint32_t ui32;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    ui32 ans = 0;
    rep(i, 0, S.size() - 1){
        char c = (i+1 + ans) & 1 ? 'i' : 'o';
        if(S[i] != c){
            ans++;
        }
    }
    if((S.size() + ans) & 1){
        ans++;
    }

    cout << ans << endl;
    return(0);
}

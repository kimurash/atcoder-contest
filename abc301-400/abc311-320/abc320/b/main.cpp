// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    i16 len = S.length();
    i16 ans = 1;

    rep(l, 2, len){
        rep(i, 0, len - l){
            string substr = S.substr(i, l);
            string rev = substr;
            reverse(all(rev));
            if(substr == rev){
                ans = l;
                break;
            }
        }
    }

    cout << ans << endl;
    return(0);
}
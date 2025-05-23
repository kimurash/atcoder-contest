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

    string S, T;
    cin >> S >> T;

    i32 slen = S.length();
    i32 tlen = T.length();

    i32 idx = 0;
    while(idx < slen && idx < tlen){
        if(S[idx] == T[idx]){
            idx++;
        } else {
            cout << idx + 1 << endl;
            return(0);
        }
    }

    if(slen == tlen){
        cout << "0" << endl;
    } else {
        cout << idx + 1 << endl;
    }

    return(0);
}

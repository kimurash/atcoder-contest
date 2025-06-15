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
typedef string str;

template<typename T>
using vec = vector<T>;

int main(){
    cin.tie(nullptr);

    str S;
    cin >> S;

    if(S[0] != S[1] && S[1] == S[2]){
        cout << 1 << endl;
        return(0);
    }
    
    i16 len = S.size();
    rep(i, 1, len - 2){
        if(S[i - 1] != S[i] && S[i] != S[i + 1]){
            cout << i + 1 << endl;
            return(0);
        }
    }

    cout << len << endl;
    return(0);
}
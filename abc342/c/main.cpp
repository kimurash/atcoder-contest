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

    i32 N, Q;
    str S;
    cin >> N >> S >> Q;

    map<char, char> mp;
    rep(c, 'a', 'z'){
        mp[c] = c;
    }

    char c, d;
    rep(i, 1, Q){
        cin >> c >> d;
        for(auto& p : mp){
            if(p.second == c){
                p.second = d;
            }
        }
    }

    rep(i, 0, N - 1){
        cout << mp[S[i]];
    }
    cout << endl;
    
    return(0);
}
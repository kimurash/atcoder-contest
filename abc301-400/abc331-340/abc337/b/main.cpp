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

    i32 idx = 0;
    i32 len = S.length();
    while(idx < len && S[idx] == 'A'){
        idx++;
    }
    while(idx < len && S[idx] == 'B'){
        idx++;
    }
    while(idx < len && S[idx] == 'C'){
        idx++;
    }

    if(idx == len){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return(0);
}
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

    i16 a, b, A = 0, B = 0;
    rep(i, 1, 9){
        cin >> a;
        A += a;
    }
    rep(j, 1, 8){
        cin >> b;
        B += b;
    }

    if(A < B){
        cout << 0 << endl;
    } else{
        cout << A - B + 1 << endl;
    }

    return(0);
}

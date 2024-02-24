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

    i16 N;
    cin >> N;

    i16 P;
    i16 pos[N + 1];
    rep(i, 1, N){
        cin >> P;
        pos[P] = i;
    }

    i16 Q;
    cin >> Q;

    i16 A, B;
    rep(i, 1, Q){
        cin >> A >> B;
        if(pos[A] < pos[B]){
            cout << A << endl;
        } else{
            cout << B << endl;
        }
    }

    return(0);
}
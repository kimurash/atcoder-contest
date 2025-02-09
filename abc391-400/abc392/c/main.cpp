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
    cin >> N;

    // zekken[i] = i番目の人が身につけているゼッケンの番号
    i32 zekken[N + 1];
    // person[i] = 数iのゼッケンを身につけている人の番号
    i32 person[N + 1];
    // look[i] = i番目の人が見ている人の番号
    i32 look[N + 1];

    i32 P, Q;
    rep(i, 1, N){
        cin >> P;
        look[i] = P;
    }
    rep(i, 1, N){
        cin >> Q;
        zekken[i] = Q;
        person[Q] = i;
    }

    rep(i, 1, N){
        i32 p = person[i];
        i32 l = look[p];
        i32 z = zekken[l];
        if(i != 1){
            cout << " ";
        }
        cout << z;
    }
    cout << endl;

    return(0);
}

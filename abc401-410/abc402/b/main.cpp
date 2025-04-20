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

    i32 Q;
    cin >> Q;

    i16 query;
    queue<i16> q;
    rep(i, 1, Q){
        cin >> query;
        if(query == 1){
            i16 X;
            cin >> X;
            q.push(X);
        } else if(query == 2){
            cout << q.front() << endl;
            q.pop();
        }
    }

    return(0);
}

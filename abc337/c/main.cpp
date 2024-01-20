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

    i32 N;
    cin >> N;

    i32 next[N + 1];
    rep(i, 1, N){
        next[i] = -1;
    }

    i32 prev;
    vec<i32> ans;
    rep(i, 1, N){
        cin >> prev;
        if(prev == -1){
            ans.push_back(i);
        } else {
            next[prev] = i;
        }
    }

    i32 crnt = ans[0];
    while(crnt != -1){
        crnt = next[crnt];
        ans.push_back(crnt);
    }

    rep(i, 0, N - 1){
        cout << ans[i];
        if(i != N - 1){
            cout << " ";
        } else{
            cout << endl;
        }
    }
    return(0);
}
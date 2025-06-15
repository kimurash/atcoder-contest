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

    i32 M;
    cin >> M;

    i32 power[11];
    power[0] = 1;
    rep(i, 1, 10){
        power[i] = power[i - 1] * 3;
    }

    vector<i32> ans;
    for(int i = 10; 0 <= i; i--){
        while(power[i] <= M){
            M -= power[i];
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    rep(i, 0, ans.size() - 1){
        if(i != 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return(0);
}

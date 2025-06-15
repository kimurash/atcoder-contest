// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef string str;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, K;
    cin >> N >> K;

    i32 P;
    i32 pos[N + 1];
    rep(n, 1, N){
        cin >> P;
        pos[P] = n;
    }

    set<i32> cont;
    i32 ans = N;

    rep(n, 1, N){
        if(n < K){
            cont.insert(pos[n]);
        } else{
            if(K < n){
                cont.erase(pos[n - K]);
            }
            cont.insert(pos[n]);

            i32 maxidx = *cont.rbegin();
            i32 minidx = *cont.begin();
            ans = min(ans, maxidx - minidx);
        }
    }

    cout << ans << endl;
    return(0);
}

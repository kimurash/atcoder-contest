// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

set<i32> G[MAX];

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 u, v;
    i32 cnt = 0;
    rep(i, 1, M){
        cin >> u >> v;
        if(u == v){
            cnt++;
        } else if(G[u].count(v) != 0){
            cnt++;
        } else if(G[v].count(u) != 0){
            cnt++;
        } else{
            G[u].insert(v);
            G[v].insert(u);
        }
    }

    cout << cnt << endl;

    return(0);
}

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

vi32 G[MAX];
bool visited[MAX];

i32 dfs(int32_t now);

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 u, v;
    rep(i, 1, M){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    i32 cnt = 0;
    rep(i, 1, N){
        if(!visited[i]){
            cnt += dfs(i) - 1;
        }
    }

    cout << M - cnt << endl;

    return(0);
}

i32 dfs(int32_t now){
    visited[now] = true;

    i32 cnt = 1;

    for(int32_t adj : G[now]){
        if(!visited[adj]){
            cnt += dfs(adj);
        }
    }

    return(cnt);
}

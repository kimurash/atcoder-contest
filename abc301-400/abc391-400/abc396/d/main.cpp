// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 19

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

struct Edge{
    i32 to;
    i64 cost;
};

i32 N, M;

vector<Edge> G[MAX];
bool visited[MAX];

i64 ans = INT64_MAX;

void dfs(int32_t now, i64 sum);

int main(){
    cin.tie(nullptr);

    cin >> N >> M;

    i32 u, v;
    i64 w;
    rep(i, 1, M){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dfs(1, 0);
    cout << ans << endl;

    return(0);
}

void dfs(int32_t now, i64 sum){
    if(now == N){
        ans = min(ans, sum);
        return;
    }

    visited[now] = true;

    for(Edge edge : G[now]){
        i32 to   = edge.to;
        i64 cost = edge.cost;

        if(!visited[to]){
            dfs(to, sum ^ cost);
        }
    }

    visited[now] = false;
    return;
}

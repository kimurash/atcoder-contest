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

typedef struct edge{
    i32 dst;
    i32 weight;
} Edge;

i64 ans[MAX];
bool visited[MAX];
vector<Edge> G[MAX];

void dfs(int32_t now);

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 u, v, w;
    rep(i, 1, M){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, -w});
    }

    rep(i, 1, N){
        if(!visited[i]){
            ans[i] = 0;
            dfs(i);
        }
    }

    rep(i, 1, N){
        if(i != 1){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return(0);
}

void dfs(int32_t now){
    visited[now] = true;

    for(Edge edge: G[now]){
        if(!visited[edge.dst]){
            ans[edge.dst] = ans[now] + edge.weight;
            dfs(edge.dst);
        }
    }

    return;
}

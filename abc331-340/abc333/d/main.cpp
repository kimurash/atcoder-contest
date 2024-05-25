// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 300'009

using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

vector<i32> G[MAX];
bool visited[MAX];

i32 dfs(i32 now);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 u, v;
    rep(i, 1, N - 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(G[1].size() == 1){
        cout << 1 << endl;
        return(0);
    }

    vector<i32> forest;
    visited[1] = true;
    for(i32 next : G[1]){
        forest.push_back(dfs(next));
    }

    sort(all(forest));

    i32 acc = accumulate(all(forest), 0);
    acc -= forest[forest.size() - 1];

    cout << acc + 1 << endl;
    return(0);
}

i32 dfs(i32 now){
    visited[now] = true;

    i32 cnt = 1;
    for(i32 next : G[now]){
        if(visited[next]){
            continue;
        }
        cnt += dfs(next);
    }

    return(cnt);
}
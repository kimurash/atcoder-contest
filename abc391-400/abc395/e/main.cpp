// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 400'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;
typedef pair<int64_t, int32_t> pi63;

vector<pi32> G[MAX];
i64 dist[MAX];
bool locked[MAX];

int main(){
    cin.tie(nullptr);

    i32 N, M, X;
    cin >> N >> M >> X;

    rep(i, 1, N){
        i32 u = i;
        i32 v = u + N;

        G[u].push_back(make_pair(v, X));
        G[v].push_back(make_pair(u, X));
    }

    rep(i, 1, M){
        i32 u, v;
        cin >> u >> v;

        G[u].push_back(make_pair(v, 1));

        i32 s = u + N;
        i32 t = v + N;
        
        G[t].push_back(make_pair(s, 1));
    }

    rep(i, 1, 2 * N){
        dist[i] = INT64_MAX;
        locked[i] = false;
    }

    // (距離の暫定値, 頂点番号)
    priority_queue<pi63, vector<pi63>, greater<pi63>> pq;
    pq.push(make_pair(0, 1));

    int32_t now;
    int64_t mindist;
    while (!pq.empty()) {
        // 待ち行列から未確定頂点が現れるまで取り出す
        tie(mindist, now) = pq.top(); pq.pop();
        if (locked[now]) {
            continue;
        }
    
        // 最短距離を確定する
        dist[now] = mindist;
        locked[now] = true;
    
        for (pi32 to : G[now]) {
            if (locked[to.first]) {  // 確定済み
                continue;
            }
            
            int32_t next = to.first;
            int64_t cost = to.second;
    
            // 隣接する頂点の距離を更新する
            if (mindist + cost < dist[next]) {
                dist[next] = mindist + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    i64 ans = min(dist[N], dist[2 * N]);
    cout << ans << endl;

    return(0);
}

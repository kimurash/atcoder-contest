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
typedef string str;

typedef pair<int32_t, int32_t> pi32;
typedef pair<int64_t, int32_t> pi63;

template<typename T>
using vec = vector<T>;

i64 dist[MAX];
bool locked[MAX];
vec<pi32> G[MAX];

void dijkstra(i32 N);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A, B, X;
    rep(n, 1, N - 1){
        cin >> A >> B >> X;
        G[n + 1].push_back(make_pair(n, A));
        G[X].push_back(make_pair(n, B));
    }

    dijkstra(N);

    cout << dist[1] << endl;
    return(0);
}

void dijkstra(i32 N) {
    priority_queue<pi63, vec<pi63>, greater<pi63>> pq;
    pq.push(make_pair(0, N));

    rep(i, 1, N){
        dist[i] = INT64_MAX;
        locked[i] = false;
    }

    int32_t now;
    int64_t mindist;
    while (!pq.empty()) {
        // pqから未確定頂点が現れるまで取り出す
        tie(mindist, now) = pq.top(); pq.pop();
        if (locked[now]) {
            continue;
        }

        // 最短距離を確定する
        dist[now] = mindist;
        locked[now] = true;

        for (pi63 adj: G[now]) {
            int32_t to = adj.first;
            int64_t w = adj.second;

            if (locked[to]) {  // 確定済み
                continue;
            }

            // 隣接する頂点の距離を更新する
            if (mindist + w < dist[to]) {
                dist[to] = mindist + w;
                pq.push(make_pair(dist[to], to));
            }
        }
    }

    return;
}
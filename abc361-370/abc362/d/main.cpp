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

typedef pair<int32_t, int64_t> pi36;
typedef pair<int64_t, int32_t> pi63;

bool locked[MAX];
i64 dist[MAX];
vector<pi36> G[MAX];

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    i32 U, V, B;
    rep(i, 1, M){
        cin >> U >> V >> B;
        G[U].push_back(make_pair(V, 1LL * B + A[V]));
        G[V].push_back(make_pair(U, 1LL * B + A[U]));
    }

    rep(i, 1, N){
        dist[i] = INT64_MAX;
    }

    // (距離の暫定値, 頂点番号)
    priority_queue<pi63, vector<pi63>, greater<pi63>> pq;
    pq.push(make_pair(A[1], 1));
    
    int32_t now;
    int64_t mindist;
    while (!pq.empty()) {
        // Qから未確定頂点が現れるまで取り出す
        tie(mindist, now) = pq.top(); pq.pop();
        if (locked[now]) {
            continue;
        }
    
        // 最短距離を確定する
        dist[now] = mindist;
        locked[now] = true;
    
        for (pi36 to: G[now]) {
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

    rep(i, 2, N){
        if(i != 2){
            cout << " ";
        }
        cout << dist[i];
    }
    cout << endl;

    return(0);
}

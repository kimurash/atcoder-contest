// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int64_t, int32_t> pi63;

int main(){
    cin.tie(nullptr);

    i32 N, M, L;
    cin >> N >> M >> L;

    i32 a[N], b[M];
    rep(i, 0, N - 1){
        cin >> a[i];
    }
    rep(i, 0, M - 1){
        cin >> b[i];
    }

    i32 c, d;
    set<i32> tabu[N];
    rep(i, 1, L){
        cin >> c >> d;
        tabu[c - 1].insert(d - 1);
    }

    i32 desc_idx[M];
    rep(i, 0, M - 1){
        desc_idx[i] = i;
    }

    // 降順にソートしたindexの配列
    sort(desc_idx, desc_idx + M, [&](i32 i, i32 j){
        return b[i] > b[j];
    });

    // 大きい順に取り出す
    priority_queue<pi63> pq;
    i32 cur[N];
    rep(i, 0, N - 1){
        pq.push(make_pair(a[i] + b[desc_idx[0]], i));
        cur[i] = 0;
    }

    i64 cost;
    i32 idx;
    while(true){
        tie(cost, idx) = pq.top();
        pq.pop();

        if(tabu[idx].count(desc_idx[cur[idx]]) == 0){
            break;
        }

        cur[idx]++;
        if(cur[idx] < M){
            pq.push(make_pair(
                a[idx] + b[desc_idx[ cur[idx]]],
                idx
            ));
        }
    }

    cout << cost << endl;
    return(0);
}
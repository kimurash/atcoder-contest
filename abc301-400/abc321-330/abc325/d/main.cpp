// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int64_t, int64_t> pi64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i64 T[N];
    i64 D[N];
    vector<pi64> sect;
    rep(i, 0, N - 1){
        cin >> T[i] >> D[i];
        sect.push_back(make_pair(T[i], T[i] + D[i]));
    }

    sort(all(sect));

    rep(i, 0, N - 1){
        T[i] = sect[i].first;
        D[i] = sect[i].second;
    }

    // 印字可能な商品を格納する優先度付きキュー
    // 印字機から出ていくのが早い順に出力する
    priority_queue<i64, vector<i64>, greater<i64>> pq;

    i32 ans = 0;
    i32 idx = 0;
    i64 crnt_time = 0;
    while(true){
        if(pq.empty()){
            if(idx == N){
                break;
            }
            crnt_time = T[idx];
        }

        // 印字可能な商品を優先度付きキューに格納する
        while(idx < N && T[idx] <= crnt_time){
            pq.push(D[idx++]);
        }

        if(crnt_time <= pq.top()){ // 印字可能な商品がある
            pq.pop();
            crnt_time++; ans++;
        }

        // 印字機から出て行く商品を削除する
        while(!pq.empty() && pq.top() < crnt_time){
            pq.pop();
        }
    }

    cout << ans << endl;
    return(0);
}


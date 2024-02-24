// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef string str;

typedef pair<int64_t, int32_t> pi63;

template<typename T>
using vec = vector<T>;

typedef struct trian{
    i32 first; // 始発
    i32 interval; // 便の間隔
    i64 total; // 便の総数
    i32 dist; // 駅間の距離
    i32 from; // 出発駅
    i32 to; // 到着駅

    // time_limitまでに駅toに到着できる最も遅い便の出発時刻を求める
    i64 get_last_dpt(i64 time_limit){
        if(time_limit < first + dist){
            return(0);
        }

        i64 last_srv = min(
            total - 1,
            (time_limit - first) / interval
        );
        last_srv = min(last_srv, total - 1);
        
        return(first + last_srv * interval);
    }

} Train;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 l, d, k, c, A, B;
    vec<vec<Train>> train_info(N + 1);
    rep(i, 1, M){
        cin >> l >> d >> k >> c >> A >> B;
        train_info[B].push_back({l, d, k, c, A, B});
    }

    // (到着時刻, 到着駅)を大きい順に取り出す
    priority_queue<pi63> pq;
    // 各駅の最終出発時刻
    i64 ans[N + 1] = {0};

    pq.push(make_pair(INT64_MAX, N));
    ans[N] = INT64_MAX;

    i32 now;
    i64 maxarrv;
    while (!pq.empty()) {
        tie(maxarrv, now) = pq.top(); pq.pop();
        // もっと遅く到着する便がある場合はスキップ
        // 最終出発時刻には確実に到着していることに注意
        if (ans[now] > maxarrv) {
            continue;
        }

        for (Train train: train_info[now]) {
            // 出発駅
            i32 from = train.from;
            // 最終出発時刻
            auto last_dpt = train.get_last_dpt(maxarrv);

            if (last_dpt && ans[from] < last_dpt) {
                ans[from] = last_dpt;
                pq.push(make_pair(ans[from], from));
            }
        }
    }

    rep(i, 1, N - 1){
        if(ans[i]){
            cout << ans[i] << endl;
        } else{
            cout << "Unreachable" << endl;
        }
    }

    return(0);
}
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

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef struct block{
    i32 no;
    i32 X;
    i32 Y;

    bool operator<(const block &b) const {
        return Y < b.Y;
    }

    bool operator>(const block &b) const {
        return Y > b.Y;
    }
} Block;

int main(){
    cin.tie(nullptr);

    i32 N, W;
    cin >> N >> W;

    Block blocks[N + 1];
    rep(i, 1, N){
        blocks[i].no = i;
        cin >> blocks[i].X;
        cin >> blocks[i].Y;
    }

    // time[i]: i番目のブロックが消える時刻
    i64 time[N + 1];
    rep(i, 1, N){
        time[i] = INT64_MAX;
    }

    priority_queue<Block, vector<Block>, greater<Block>> pq[W + 1];
    rep(i, 1, N){
        i32 x = blocks[i].X;
        pq[x].push(blocks[i]);
    }

    i32 cnt = N;
    rep(i, 1, W){
        i32 size = pq[i].size();
        if(size < cnt){
            cnt = size;
        }
    }

    while(0 < cnt){
        i32 max_time = 0;
        rep(i, 1, W){
            Block top = pq[i].top();
            max_time = max(max_time, top.Y);
        }
        rep(i, 1, W){
            Block top = pq[i].top();
            time[top.no] = max_time;
            pq[i].pop();
        }

        cnt--;
    }

    i32 Q;
    cin >> Q;

    i32 T;
    i32 A;
    rep(i, 1, Q){
        cin >> T >> A;
        if(T < time[A]){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return(0);
}

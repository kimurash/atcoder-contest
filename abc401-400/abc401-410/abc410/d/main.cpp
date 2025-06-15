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

struct Edge{
    i32 to;
    i32 cost;
};

struct State{
    i32 now;
    i32 sum;
};

const i32 N = 1009;
const i32 W = 1 << 10;

vector<Edge> G[N];
bool visited[N][W];

int main(){
    cin.tie(nullptr);

    i32 n, m;
    cin >> n >> m;

    rep(i, 1, m){
        i32 a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
    }

    queue<State> yet;
    
    yet.push({1, 0});
    visited[1][0] = true;
    
    while(!yet.empty()){
        State state = yet.front();
        i32 now = state.now;
        i32 sum = state.sum;
        yet.pop();
    
        for(Edge edge: G[now]){
            i32 to = edge.to;
            i32 cost = edge.cost;

            i32 next_sum = sum ^ cost;

            if(visited[to][next_sum] == false){
                visited[to][next_sum] = true;
                yet.push({to, next_sum});
            }
        }
    }

    i32 ans = 1 << 10;
    rep(i, 0, W - 1){
        if(visited[n][i] == true){
            ans = min(ans, i);
        }
    }

    if(ans == 1 << 10){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return(0);
}

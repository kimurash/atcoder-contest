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

vi32 G[MAX];

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 a, b;
    rep(i, 1, M){
        cin >> a >> b;
        G[a].push_back(b);
    }

    i32 dist[N + 1];
    rep(i, 1, N){
        dist[i] = -1;
    }
    queue<int32_t> yet;
    
    yet.push(1);
    dist[1] = 0;
    
    while(!yet.empty()){
        int32_t now = yet.front();
        yet.pop();
    
        for(int32_t adj: G[now]){
            if(adj == 1){
                cout << dist[now] + 1 << endl;
                return(0);
            }
            if(dist[adj] == -1){
                dist[adj] = dist[now] + 1;
                yet.push(adj);
            }
        }
    }

    cout << -1 << endl;
    return(0);
}

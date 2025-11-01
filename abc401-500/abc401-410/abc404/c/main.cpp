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
bool visited[MAX];

void dfs(int32_t now);

int main(){
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    i32 A, B;
    rep(i, 1, M){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    bool answer = true;
    rep(i, 1, N){
        if(G[i].size() != 2){
            answer = false;
            break;
        }
    }

    dfs(1);
    rep(i, 1, N){
        if(!visited[i]){
            answer = false;
            break;
        }
    }

    cout << (answer ? "Yes" : "No") << endl;
    return(0);
}

void dfs(int32_t now){
    visited[now] = true;

    for(int32_t adj : G[now]){
        if(!visited[adj]){
            dfs(adj);
        }
    }

    return;
}

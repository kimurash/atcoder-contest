// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 N, M;
vector<i32> adjlst[MAX];

/*
-1: 未訪問
 0: 頂点に0が書き込まれている
 1: 頂点に1が書き込まれている
*/
i16 X[MAX];
bool bipartite = true;

void dfs(i32 now, i32 x);

int main(){
    cin.tie(nullptr);

    cin >> N >> M;

    i32 A[M + 1], B[M + 1];
    rep(i, 1, M){
        cin >> A[i];
    }
    rep(i, 1, M){
        cin >> B[i];
    }
    rep(i, 1, M){
        adjlst[A[i]].push_back(B[i]);
        adjlst[B[i]].push_back(A[i]);
    }

    rep(i, 1, N){
        X[i] = -1;
    }
    rep(i, 1, N){
        if(X[i] == -1){
            dfs(i, 0);
        }
    }

    cout << (bipartite ? "Yes" : "No") << endl;
    return(0);
}

void dfs(i32 now, i32 x){
    X[now] = x;
    for(i32 next: adjlst[now]){
        if(X[next] == -1){
            dfs(next, 1 - x);
        } else if(X[next] == x){
            bipartite = false;
        }
    }

    return;
}

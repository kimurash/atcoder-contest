// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXN 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

vector<i32> adjlst[MAXN];
vector<i32> answer;
bool visited[MAXN];

void dfs(i32 now);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 C, P;
    rep(i, 1, N){
        cin >> C;
        rep(j, 1, C){
            cin >> P;
            adjlst[i].push_back(P);
        }
    }

    rep(i, 1, N){
        visited[i] = false;
    }

    dfs(1);

    cout << answer[0];
    rep(i, 1, answer.size() - 2){
        printf(" %d", answer[i]);
    }
    cout << endl;

    return(0);
}

void dfs(i32 now){
    // post-orderで木をなぞる
    for(i32 adj: adjlst[now]){
        if(!visited[adj]){
            dfs(adj);
        }
    }

    answer.push_back(now);
    visited[now] = true;

    return;
}
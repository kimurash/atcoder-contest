// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

#define MAX 11

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int32_t> pi1632;

i64 answer;

vector<pi1632> adjlst[MAX];
bool visited[MAX];

void dfs(i32 start, i32 now, i64 acc);

int main(){
    cin.tie(nullptr);

    i16 N, M;
    cin >> N >> M;

    i16 A, B;
    i32 C;
    
    rep(i, 1, M){
        cin >> A >> B >> C;
        adjlst[A].push_back(make_pair(B, C));
        adjlst[B].push_back(make_pair(A, C));
    }

    rep(i, 1, N){
        dfs(i, i, 0);
    }

    cout << answer << endl;
    return(0);
}

void dfs(i32 start, i32 now, i64 acc){
    if(visited[now]){
        return;
    }

    answer = max(answer, acc);
    visited[now] = true;

    for(pi1632 adj: adjlst[now]){
        if(visited[adj.first]){
            continue;
        }

        dfs(start, adj.first, acc + adj.second);
    }

    visited[now] = false;
    return;
}
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define MAX 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;
typedef pair<int64_t, int64_t> pi64;
typedef pair<i32, pi32> rltvloc;

vector<rltvloc> relative[MAX];
bool visited[MAX];
pi64 pos[MAX];

void dfs(i32 now);

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 A, B, X, Y;
    rep(i, 1, M){
        cin >> A >> B >> X >> Y;
        relative[A].push_back(
            make_pair(B, make_pair(X, Y))
        );
        relative[B].push_back(
            make_pair(A, make_pair(-X, -Y))
        );
    }

    pos[1] = make_pair(0, 0);
    rep(i, 1, N){
        visited[i] = false;
    }

    dfs(1);

    rep(i, 1, N){
        if(visited[i]){
            printf("%ld %ld\n", pos[i].first, pos[i].second);
        } else{
            cout << "undecidable" << endl;
        }
    }

    return(0);
}

void dfs(i32 now){
    if(visited[now]){
        return;
    }

    visited[now] = true;
    for(rltvloc loc: relative[now]){
        i32 next = loc.first;
        i32 dx = loc.second.first;
        i32 dy = loc.second.second;

        if(!visited[next]){
            pos[next] = make_pair(
                1LL * pos[now].first + dx,
                1LL * pos[now].second + dy
            );
            dfs(next);
        }
    }

    return;
}

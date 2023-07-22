// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    int32_t adjlst[N + 1];
    rep(i, 1, N){
        cin >> adjlst[i];
    }

    bool visited[N + 1];
    rep(i, 1, N){
        visited[i] = false;
    }

    int32_t now = 1;
    vector<int32_t> path;
    while(!visited[now]){
        path.push_back(now);
        visited[now] = true;
        now = adjlst[now];
    }

    bool in_cycle = false;
    vector<int32_t> cycle;
    for(int32_t v: path){
        if(v == now){
            in_cycle  = true;
        }
        if(in_cycle){
            cycle.push_back(v);
        }
    }

    cout << cycle.size() << endl;
    cout << cycle[0];
    rep(i, 1, cycle.size() - 1){
        printf(" %d", cycle[i]);
    }
    cout << endl;

    return(0);
}


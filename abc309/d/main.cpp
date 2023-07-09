#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define MAXV 300'000

using namespace std;

vector<vector<int32_t>> adjlst(MAXV + 1);
int32_t dist[MAXV + 1];

int32_t calc_diameter(int32_t initv);

int main(){
    int32_t N1, N2, M;
    cin >> N1 >> N2 >> M;

    int32_t a, b;
    rep(i, 0, M){
        cin >> a >> b;
        adjlst[a].push_back(b);
        adjlst[b].push_back(a);
    }

    rep(i, 1, MAXV + 1){
        dist[i] = -1;
    }

    int32_t d1 = calc_diameter(1);
    int32_t d2 = calc_diameter(N1 + N2);

    cout << d1 + d2 + 1 << endl;
}

int32_t calc_diameter(int32_t initv){
    queue<int32_t> yet; // 訪問すべき頂点
    int32_t diameter = 0;

    yet.push(initv);
    dist[initv] = 0;

    while(yet.size() > 0){
        int32_t v = yet.front();
        yet.pop();

        for(int32_t nv: adjlst[v]){
            if(dist[nv] != -1){ // 未訪問であれば
                continue;
            }

            dist[nv] = dist[v] + 1;
            yet.push(nv);

            diameter = max(diameter, dist[nv]); // 直径の更新
        }
    }

    return(diameter);
}
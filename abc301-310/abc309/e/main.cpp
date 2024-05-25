// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int32_t N, M;
    cin >> N >> M;

    int32_t parent[N + 1], cover[N + 1];
    cover[1] = -1;
    rep(i, 2, N + 1){
        cin >> parent[i];
        cover[i] = -1;
    }

    int32_t x, y;
    rep(i, 0, M){
        cin >> x >> y;
        cover[x] = max(cover[x], y);
    }

    rep(i, 2, N + 1){
        cover[i] = max(cover[i], cover[parent[i]] - 1);
    }

    int32_t answer = 0;
    rep(i, 1, N + 1){
        if(cover[i] >= 0){
            answer++;
        }
    }

    cout << answer << endl;
}
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, Q;
    cin >> N >> Q;

    i32 ball;
    set<i32> box[N + 1];
    rep(i, 1, N){
        cin >> ball;
        box[i].insert(ball);
    }

    i32 a, b;
    rep(i, 1, Q){
        cin >> a >> b;
        if(box[a].size() < box[b].size()){
            for(i32 ball : box[a]){
                box[b].insert(ball);
            }
            box[a].clear();
        } else{
            for(i32 ball : box[b]){
                box[a].insert(ball);
            }
            box[b].clear();
            swap(box[a], box[b]);
        }
        cout << box[b].size() << endl;
    }

    return(0);
}
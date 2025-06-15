// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define ANIMAL 109
#define ZOO 19

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

struct Zoo{
    i32 fee;
    vi32 animals;
};

i32 N; // 動物園
i32 M; // 動物
i64 ans = INT64_MAX;

i32 animal_cnt[ANIMAL];
Zoo zoos[ZOO];

void recur(i32 now, i64 sum);

int main(){
    cin.tie(nullptr);

    cin >> N >> M;

    i32 C;
    rep(i, 1, N){
        cin >> C;
        zoos[i] = {C, {}};
    }

    rep(i, 1, M){ // 動物
        i32 K;
        cin >> K;

        rep(j, 1, K){ // 動物園
            i32 A;
            cin >> A;

            zoos[A].animals.push_back(i);
        }
    }

    recur(1, 0);
    cout << ans << endl;

    return(0);
}

void recur(i32 now, i64 sum){
    if(N < now){
        rep(i, 1, M){
            if(animal_cnt[i] < 2){
                return;
            }
        }
        ans = min(ans, sum);
        return;
    }

    Zoo zoo = zoos[now];
    rep(i, 0, 2){
        for(i32 animal : zoo.animals){
            animal_cnt[animal] += i;
        }

        recur(now + 1, sum + zoo.fee * i);

        for(i32 animal : zoo.animals){
            animal_cnt[animal] -= i;
        }
    }

    return;
}

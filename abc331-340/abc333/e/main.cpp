// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template<typename T>
using vec = vector<T>;

template <typename T>
bool chmax(T &a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    vec<i32> prt_turn;
    stack<i32> holder[N + 1];
    i32 stock[N + 1] = {0};
    bool hist[N + 1] = {false};

    i32 event, type;
    rep(t, 1, N){
        cin >> event >> type;

        if(event == 1){ // ポーション
            holder[type].push(t);
            prt_turn.push_back(t);

        } else if(event == 2){ // モンスター
            if(holder[type].empty()){
                cout << -1 << endl;
                return(0);
            }

            i32 turn = holder[type].top();
            stock[turn]++;
            stock[t]--;
            hist[turn] = true;
            holder[type].pop();
        }
    }

    i32 acc[N + 1];
    acc[0] = 0;
    rep(i, 1, N){
        acc[i] = acc[i - 1] + stock[i];
    }

    i32 ans = 0;
    rep(i, 1, N){
        chmax(ans, acc[i]);
    }
    cout << ans << endl;

    rep(i, 0, prt_turn.size() - 1){
        i32 t = prt_turn[i];
        cout << (hist[t] ? 1 : 0);
        if(i != prt_turn.size() - 1){
            cout << ' ';
        } else{
            cout << endl;
        }
    }
    
    return(0);
}
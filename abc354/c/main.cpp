// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef string str;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef struct card{
    i32 idx;
    i32 strength;
    i32 cost;
} Card;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 A, C;
    vector<Card> cards(N);
    rep(i, 0, N - 1){
        cin >> A >> C;
        cards[i] = {i, A, C};
    }

    sort(all(cards), [](Card a, Card b){
        return a.cost < b.cost;
    });

    i32 strmax = 0;
    vi32 ans;
    rep(i, 0, N - 1){
        i32 strength = cards[i].strength;
        if(strmax < strength){
            strmax = strength;
            ans.push_back(cards[i].idx);
        }
    }

    sort(all(ans));

    cout << ans.size() << endl;
    rep(i, 0, ans.size() - 1){
        if(i != 0){
            cout << " ";
        }
        cout << ans[i] + 1;
    }
    cout << endl;


    return(0);
}

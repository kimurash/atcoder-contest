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

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

double dist(pi32 a, pi32 b);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    double cost = 0;
    pi32 cur = make_pair(0, 0);

    i32 X, Y;
    rep(i, 1, N){
        cin >> X >> Y;
        pi32 next = make_pair(X, Y);
        cost += dist(cur, next);
        cur = next;
    }

    cost += dist(cur, make_pair(0, 0));

    cout << fixed << setprecision(10) << cost << endl;
    return(0);
}

double dist(pi32 a, pi32 b){
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

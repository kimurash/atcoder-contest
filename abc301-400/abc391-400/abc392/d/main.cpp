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

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 K[N + 1];
    set<i32> st[N + 1];
    map<i32, i32> cnt[N + 1];
    
    rep(i, 1, N){
        cin >> K[i];

        i32 A;
        rep(j, 1, K[i]){
            cin >> A;
            if(st[i].count(A) == 0){
                st[i].insert(A);
            }
            cnt[i][A]++;
        }
    }

    double ans = 0.0;
    rep(i, 1, N - 1){
        rep(j, i + 1, N){
            set<i32> cand;
            set_intersection(all(st[i]), all(st[j]), inserter(cand, cand.end()));
            
            double sum = 0.0;
            for(i32 A : cand){
                double p1 = (1.0 * cnt[i][A]) / K[i];
                double p2 = (1.0 * cnt[j][A]) / K[j];
                sum += p1 * p2;
            }
            if(ans < sum){
                ans = sum;
            }
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return(0);
}

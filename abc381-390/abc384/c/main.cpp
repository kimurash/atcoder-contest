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

typedef pair<i32, string> pis;

int main(){
    cin.tie(nullptr);

    i32 point[5];
    rep(i, 0, 4){
        cin >> point[i];
    }

    char diff[] = {'A', 'B', 'C', 'D', 'E'};

    vector<pis> ans;
    for(int i = 1; i < (1 << 5); i++){
        bitset<5> bs(i);

        i32 score = 0;
        string name = "";
        
        for(int j = 0; j < 5; j++){
            if(bs.test(j)) {
                score += point[j];
                name += diff[j];
            }
        }

        ans.push_back(make_pair(score, name));
    }

    stable_sort(all(ans), [](const pis &a, const pis &b){
        if(a.first == b.first){
            return a.second < b.second;
        } else{
            return a.first > b.first;
        }
    });

    rep(i, 0, ans.size() - 1){
        cout << ans[i].second << endl;
    }

    return(0);
}

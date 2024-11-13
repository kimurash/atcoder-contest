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

    i32 Q;
    cin >> Q;

    i16 query;
    i32 param;

    i64 now = 0;
    queue<i64> plant;
    rep(i, 1, Q){
        cin >> query;
        switch(query){
            case 1:
                plant.push(now);
                break;

            case 2:
                cin >> param;
                now += param;
                break;
            case 3:
                cin >> param;

                i32 cnt = 0;
                while(!plant.empty()){
                    i64 height = now - plant.front();
                    if(param <= height){
                        plant.pop();
                        cnt++;
                    } else {
                        break;
                    }
                }
                cout << cnt << endl;
                break;
        }
    }

    return(0);
}

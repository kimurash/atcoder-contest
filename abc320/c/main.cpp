// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 M;
    cin >> M;

    string reel[3];
    rep(r, 0, 2){
        cin >> reel[r];
    }

    i32 ans = 3 * M;
    vector<i16> pmt = {0, 1, 2}; // リールを止める順番

    rep(n, 0, 9){ // 揃える数字
        do{
            i32 time = 0;
            bool able = true;

            for(i16 r: pmt){
                bool find = false;
                rep(t, 0, M){
                    if(reel[r][time++ % M] == '0' + n){
                        find = true;
                        break;
                    }
                }
                able &= find;
            }

            if(able){
                ans = min(ans, time - 1);
            }
        } while(next_permutation(all(pmt)));
    }

    if(ans < 3 * M){
        cout << ans << endl;
    } else{
        cout << -1 << endl;
    }

    return(0);
}


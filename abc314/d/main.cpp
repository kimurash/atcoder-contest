// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, Q;
    string S;
    cin >> N >> S >> Q;

    i16 mode = 0;
    set<i32> except;

    i16 q; i32 x; char c;
    rep(i, 1, Q){
        cin >> q >> x >> c;
        switch(q){
            case 1:
                S[x - 1] = c;
                except.insert(x - 1);
                break;
            case 2:
                mode = 2;
                except.clear();
                break;
            case 3:
                mode = 3;
                except.clear();
                break;
        }
    }

    if(mode != 2 && mode != 3){
        cout << S;
    } else{
        rep(i, 0, N - 1){
            if(except.count(i) > 0){
                cout << S[i];
            } else{
                if(mode == 2){
                    printf("%c", tolower(S[i]));
                } else{
                    printf("%c", toupper(S[i]));
                }
            }
        }
    }
    cout << endl;

    return(0);
}
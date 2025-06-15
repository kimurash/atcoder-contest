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

    i32 N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    i32 cnt = 0;
    rep(i, 0, N - 3){
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C'){
            cnt++;
            i += 2;
        }
    }

    S = "--" + S + "--";

    i32 X;
    char C;
    rep(i, 1, Q){
        cin >> X >> C;
        X += 1;

        if(S[X] != C){
            switch(S[X]){
                case 'A':
                    if(S[X + 1] == 'B' && S[X + 2] == 'C'){
                        cnt--;
                    }
                    break;
                case 'B':
                    if(S[X - 1] == 'A' && S[X + 1] == 'C'){
                        cnt--;
                    }
                    break;
                case 'C':
                    if(S[X - 2] == 'A' && S[X - 1] == 'B'){
                        cnt--;
                    }
                    break;
            }
            S[X] = C;
            switch(C){
                case 'A':
                    if(S[X + 1] == 'B' && S[X + 2] == 'C'){
                        cnt++;
                    }
                    break;
                case 'B':
                    if(S[X - 1] == 'A' && S[X + 1] == 'C'){
                        cnt++;
                    }
                    break;
                case 'C':
                    if(S[X - 2] == 'A' && S[X - 1] == 'B'){
                        cnt++;
                    }
                    break;
            }
        }
        cout << cnt << endl;
    }

    return(0);
}

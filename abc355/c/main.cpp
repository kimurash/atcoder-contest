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

int main(){
    cin.tie(nullptr);

    i32 N, T;
    cin >> N >> T;

    i32 A[T + 1];
    rep(i, 1, T){
        cin >> A[i];
        A[i]--;
    }

    i32 col[N] = {0}, row[N] = {0};
    i32 diag[] = {0, 0};

    bool bingo = false;
    rep(t, 1, T){
        i32 r = A[t] / N;
        i32 c = A[t] % N;

        row[r]++;
        if(row[r] >= N){
            cout << t << endl;
            bingo = true;
            break;
        }

        col[c]++;
        if(col[c] >= N){
            cout << t << endl;
            bingo = true;
            break;
        }

        if(r == c){
            diag[0]++;
            if(diag[0] >= N){
                cout << t << endl;
                bingo = true;
                break;
            }
        }

        if(r == N - c - 1){
            diag[1]++;
            if(diag[1] >= N){
                cout << t << endl;
                bingo = true;
                break;
            }
        }
    }

    if(!bingo){
        cout << -1 << endl;
    }

    return(0);
}

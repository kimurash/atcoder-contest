// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef tuple<i16, i16, i16> ti16;

int main(){
    cin.tie(nullptr);

    i16 num[9];
    i16 pmt[9]; // i番目のマスが何番目に開けられるか
    double whole = 1;
    rep(i, 0, 8){
        cin >> num[i];
        pmt[i] = i;
        whole *= i + 1;
    }

    ti16 line[] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {1, 4, 8},
        {2, 4, 6},
    };

    double cnt = 0;
    do{
        bool disappointed = false;

        for(ti16 tpl: line){
            i16 a = get<0>(tpl);
            i16 b = get<1>(tpl);
            i16 c = get<2>(tpl);

            if(num[a] == num[b] && pmt[a] < pmt[c] && pmt[b] < pmt[c]){
                disappointed = true;
                break;
            }

            if(num[b] == num[c] && pmt[b] < pmt[a] && pmt[c] < pmt[a]){
                disappointed = true;
                break;
            }

            if(num[a] == num[c] && pmt[a] < pmt[b] && pmt[c] < pmt[b]){
                disappointed = true;
                break;
            }
        }

        if(!disappointed){
            cnt++;
        }
    } while(next_permutation(pmt, pmt + 9));

    printf("%.10f\n", cnt / whole);
    return(0);
}
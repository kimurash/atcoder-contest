#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef vector<int32_t> vi32;

typedef struct product{
    int32_t price;
    vi32 feature;
} Product;

bool is_superior(Product *p1, Product *p2){
    if(!(p1->price >= p2->price)){
        return(false);
    }
    
    // p2はp1の機能を全て持っているか
    if(!includes(all(p2->feature), all(p1->feature))){
        return(false);
    }

    if((p1->price > p2->price) || !includes(all(p1->feature), all(p2->feature))){
        return(true);
    } else{
        return(false);
    }
}

int main(){
    int16_t N, M;
    cin >> N >> M;

    int32_t P;
    int16_t C;
    Product products[N];
    rep(n, 0, N){
        cin >> P >> C;

        vi32 F(C);
        rep(c, 0, C){
            cin >> F[c];
        }
        sort(all(F));

        products[n] = {P, F};
    }

    rep(i, 0, N){
        rep(j, 0, N){
            if(i == j){
                continue;
            }

            if(is_superior(products + i, products + j)){
                cout << "Yes" << endl;
                return(0);
            }
        }
    }

    cout << "No" << endl;
    return(0);
}

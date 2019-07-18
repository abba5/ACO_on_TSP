#include <bits/stdc++.h>
#define int long long int
#define error cout << "here\n";exit(0)
using namespace std;

struct DATA
{
    int value = -1;
    std::vector<int> v;
}dp[18][262144+1];

int n, q;
int dis[105][105];


void fill(int n){

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dis[i][j] = i == j ? 0 : INT_MAX;
}

void print(int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <n; ++j)
            cout << dis[i][j] << " \n"[j == n-1];
}

void print(std::vector<int> &v){
    for(int &i: v)
        cout << i+1 << ' ';
    cout << '\n';
}

DATA f(int per, int last, int bit_arr){
        

    if(dp[last][bit_arr].value != -1){
        return dp[per][bit_arr];
    }

    if(bit_arr == 0){
        DATA temp;
        temp.value = dis[last][per];
        temp.v = {last, per};
        return temp;

    }else{

        DATA ans;
        ans.value = INT_MAX;


        for(int i = 0; i < n; ++i){
            if(bit_arr & (1 << i)){
                
                DATA temp = f(i, last, bit_arr ^(1 << i));


                if(temp.value + dis[per][i] < ans.value){
                    ans.value = temp.value + dis[per][i];
                    ans.v = temp.v;
                }
            }
        }

        ans.v.push_back(per);

        return dp[last][bit_arr] = ans;
    }

}

int32_t main(){

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;

    fill(n);

    for(int i = 0; i < q; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        dis[u][v] = w;
        dis[v][u] = w;
    }

    int bit_arr = 0;

    for(int i = 0; i < n; ++i){
        bit_arr |= (1 << i);
    }

    DATA min_cost;
    min_cost.value = INT_MAX;

    
    for(int i = 0; i < n; ++i){

        DATA ans;
        ans.value = INT_MAX;

        for(int j = 0; j < n; ++j){

            if(i == j) continue;

            DATA temp = f(i, j, bit_arr^(1 << j)^(1 << i));

            if(temp.value + dis[i][j] < ans.value){
                ans.value = temp.value + dis[i][j];
                ans.v = temp.v;
            }
        }

        if(min_cost.value > ans.value){
            min_cost.value = ans.value;
            min_cost.v = ans.v;
        }
    }

    cout << min_cost.value << '\n';

    for(auto i: min_cost.v){
        cout << i + 1<< ' ';
    }
    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define int long long int
#define error cout << "here\n";exit(0)
using namespace std;



int dp[18][262144+1];
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

int f(int per, int last, int bit_arr){

	if(dp[last][bit_arr] != -1){
		return dp[per][bit_arr];
	}

	if(bit_arr == 0){

		return dis[last][per];

	}else{

		int temp = INT_MAX;

		for(int i = 0; i < n; ++i){
			if(bit_arr & (1 << i)){
				temp = min(temp, dis[per][i] + f(i, last, bit_arr ^(1 << i)));
			}
		}

		return dp[last][bit_arr] = temp;
	}

}

int32_t main(){

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);

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

	int min_cost = INT_MAX;

	for(int i = 0; i < n; ++i){

		int temp = INT_MAX;

		for(int j = 0; j < n; ++j){

			if(i == j) continue;

			temp = min(temp, dis[i][j] + f(i, j, bit_arr ^ (1 << j)^(1 << i)) );
		}

		min_cost = min(min_cost, temp);

	}

	cout << min_cost << '\n';


	return 0;
}
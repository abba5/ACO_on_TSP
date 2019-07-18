#include <bits/stdc++.h>
#define int long long int
#define error cout << "here\n";exit(0)
using namespace std;

int dis[105][105];
int n, q;	

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

	// print(n);
	std::vector<int> v(n), TSP_path;
	int min_cost = INT_MAX;
	iota(v.begin(), v.end(), 0);

	do{
		int temp = 0;
		for(int i = 1; i < n; ++i){
			temp += dis[v[i-1]][v[i]];
		}
		temp += dis[v[n-1]][v[0]];

		if(temp < min_cost){
			min_cost = temp;
			TSP_path = v;
		}

	}while(next_permutation(v.begin(), v.end()));

	print(TSP_path);
	cout << min_cost << '\n';

	return 0;
}
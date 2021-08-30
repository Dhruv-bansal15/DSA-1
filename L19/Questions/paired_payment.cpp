// #include<bits/stdc++.h>
// Pulkit chhabra code
#include <iostream>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e12
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
	FIO;
	int n, m; cin >> n >> m;

	vector<vector<pii> > adj(n + 1);

	while (m--)
	{
		int i, j, k; cin >> i >> j >> k;
		adj[i].pb({j, k});
		adj[j].pb({i, k});
	}

	vector<vi> d(n + 1, vi(51, inf));
	set<vi> s;
	s.insert({0, 1, 0});
	d[1][0] = 0;

	while (!s.empty())
	{
		auto it = s.begin();
		int cur = (*it)[0], i = (*it)[1], j = (*it)[2];
		s.erase(it);

		for (auto &e : adj[i])
		{
			int to = e.ff, w = e.ss;

			if (!j)
			{
				if (cur < d[to][w])
				{
					s.erase({d[to][w], to, w});
					d[to][w] = cur;
					s.insert({d[to][w], to, w});
				}
			}

			else
			{
				int add = (j + w) * (j + w);
				if (cur + add < d[to][0])
				{
					s.erase({d[to][0], to, 0});
					d[to][0] = cur + add;
					s.insert({d[to][0], to, 0});
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		if (d[i][0] != inf)
			cout << d[i][0] << ' ';
		else
			cout << -1 << ' ';

	cout << '\n';
	return 0;
}
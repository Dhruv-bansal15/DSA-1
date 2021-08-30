//pulkit chhabra code
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
// using namespace __gnu_pbds;
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
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int largest(vi &v, int val, int n)
{
	int ans = 0, cur = 0;
	vi pre_min(n + 1);

	for (int j = 1; j <= n; ++j)
	{
		if (v[j] >= val)
			cur++;
		else
			cur--;

		//cout << cur << ' ';

		pre_min[j] = min(pre_min[j - 1], cur);

		//smallest i s.t. pre[i] < pre[j] -> ans = j - i
		int beg = 0, end = j - 1, i = j;
		while (beg <= end)
		{
			int mid = (beg + end) / 2;

			if (pre_min[mid] < cur)
				i = mid, end = mid - 1;

			else
				beg = mid + 1;
		}

		ans = max(ans, j - i);
	}

	//cout << '\n';

	return ans;
}

int32_t main()
{
	FIO;
	int n, k; cin >> n >> k;
	vi v(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	int beg = 1, end = n, ans;

	while (beg <= end)
	{
		int mid = (beg + end) / 2;

		if (largest(v, mid, n) >= k)
			ans = mid, beg = mid + 1;

		else
			end = mid - 1;

	}

	cout << ans << '\n';
	return 0;
}
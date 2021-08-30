// given two arrays of length n, construct a new array which have n*n elements which are just sum of two no of all permutations 
// of elements of both the arrays
// u have to find the kth largest element in new formed array
// size of given arrays are can be large as 10**15
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
using namespace std;
#define int long long 
#define vi vector<int>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define tester int t;cin>>t;while(t--)
#define looper(a,b,c) for(int a=b;a<c;a++)
#define ss second
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int> >
#define mod 1000000007
#define vs vector<string>
#define mp map<int,int>
#define ump unordered_map<int,int>
#define space ' '
#define stc stack<char>
#define sti stack<int>
#define all(arr) arr.begin(),arr.end()
#define looprev(i,a,b) for(int i=a;i>=(b);i--)
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<space;std::cout<<std::endl;
#define si set<int>
int gCd(int a,int b){
    if(b==0)
        return a;
    return gCd(b,a%b);
}
int fact(int n){
    int res=1;
    for(int i=2;i<=n;i++)
        res = (res*i)%mod;
    return res;
}
int nCr(int n,int r){
    return fact(n)/ (fact(r)*fact(n-r));
}
    
bool compare(pair<int,int> &one, pair<int,int> &two){
    return one.second < two.second;
}
int32_t main(){
    int n,k;cin>>n>>k;
    vi a,b;
    a.pb(-1),b.pb(-1); // to make one based indexing
    looper(i,0,n){
        int x;cin>>x;
        a.pb(x);
    }  
    looper(i,0,n){
        int x;cin>>x;
        b.pb(x);
    }   
    map<pii,int> m;
    priority_queue<std::pair<int,std::pair<int,int>>> q;
    q.push({a[n] + b[n],{n,n}});
    m[{n,n}]=1;
    int ans;
    while(k--){
        int i = q.top().ss.ff,j=q.top().ss.ss;
        ans=q.top().ff;
        q.pop();
        if(i>1 & m[{i-1,j}]!=1){
            q.push({a[i-1] + b[j],{i-1,j}});
            m[{i-1,j}]=1;
        }
        if(j>1 & m[{i,j-1}]!=1){
            q.push({a[i] + b[j-1],{i,j-1}});
            m[{i,j-1}]=1;
        }
    }
    cout<<ans;
    return 0;
}
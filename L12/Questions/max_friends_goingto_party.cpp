// Their are people which are frnd of each other (given in ques) , only those can come to party whose min k frnds
// are coming to party, find no of people coming to the party
// we will use adjacency list to store frnds coresponding to a particular person
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
    int n,m,k;cin>>n>>m>>k;
    vector<vi> adj(n+1); //will store name of frnds corresponding to every person
    vi num(n+1); //will store count of no of friends of i ,num[i] coming to party,initially we assume everyone coming to the party
    vector<bool> coming(n+1,true);
    while(m--){
        int i,j;cin>>i>>j;
        adj[i].pb(j);adj[j].pb(i);
        num[i]++,num[j]++;
    }   
    queue<int> q;
    looper(i,1,n+1){
        if(num[i]<k){
            q.push(i);
            coming[i]=false;
        }
    }
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(int j:adj[i]){
            num[j]--;
            if(coming[j]==true && num[j]<k ){
                coming[j]=false;q.push(j);
            }
        }
    }
    int cnt=0;
    looper(i,1,n+1){
        if(coming[i]==true){
            cout<<i<<space;
            cnt++;
        }
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
// https://www.geeksforgeeks.org/the-stock-span-problem/
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
// int32_t main(){
//     int n;cin>>n;
//     stack<int> arr,ans;
//     looper(i,0,n){
//         int x;cin>>x;
//         if(arr.empty()){
//             arr.push(x);ans.push(1);
//         }else{
//             if(arr.top()<x){
//                 arr.push(x);
//                 ans.push(ans.top()+1);
//             }else{
//                 arr.push(x);ans.push(1);
//             }
//         }
//     }
//     vi temp;
//     while(!ans.empty()){
//         temp.pb(ans.top());ans.pop();
//     }
//     for(int i=n-1;i>=0;i--){
//         cout<<temp[i]<<space;
//     }
//     cout<<endl;
//     return 0;
// } // wrong attempt 

int32_t main(){
    int n;cin>>n;
    vi arr(n),prev_greater(n);
    looper(i,0,n){
        cin>>arr[i];
    }
    stack<int> s; //store the indices
    looper(i,0,n){
        while(!s.empty() & arr[s.top()]<=arr[i]){
            s.pop();
        }
        s.empty() ? prev_greater[i]=-1 : prev_greater[i]= s.top();
        s.push(i);
    }
    looper(i,0,n){
        cout<< i - prev_greater[i]<<space;
    }
    cout<<endl;
    return 0;
}
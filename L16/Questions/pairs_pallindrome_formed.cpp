// We have a list of strings named W. find no of pairs of (i,j) s.t 0<=i<j<=n-1
// and W[i] + W[j] can be rearranged to form a pallindrome 
// above we did concatenation to be precize 
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
// let me describe u the soln, with hash fun we obtained a binary no of 26 digits where 
//for digit , it is 1 if it occurs odd no of times, otherwise it is zero
// two strings can form pallindrome , if they are same (line no 77), otherwise if only 1 char is odd when we concatenate both(line 78-79)
int hash_func(string s){
    int ans=0; // initially all characters are occured zero times, thus considered to be even 
    for(char ch:s){
        int i = ch - 'a'; //bit to which it will corresponds in our final ans
        ans^= (1<<i); // basically XOR with 2**i
    }
    return ans;
}
int32_t main(){
    int n;cin>>n;
    unordered_map<int,int> m;
    int ans=0;
    looper(i,0,n){
        string s;cin>>s;
        int num= hash_func(s);
        ans+= m[num];
        looper(j,0,26){
            ans+= m[num^(1<<j)]; // 1<<j = pow(2,j)
        }

    }   
    cout<<ans<<endl;
    return 0;
}
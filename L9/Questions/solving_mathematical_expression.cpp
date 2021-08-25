// expressions are of two types
// in fix expression -> 2*2 + 6/9 + 2 + 3 - 4/2
// in post fix/Polish Notation operands are written first and then comes the operator between them
// also in cpp preference of * and / is same , so whichever comes first is evaluated first
// eg-> 5 + 10*15 + 8 - 9/3
// ->   5 + 10 15 * + 8 - 9/3
//      5 + 10 15 * + 8 - 9 3 /
//      5 10 15 * + 8 - 9 3 /
//      5 10 15 * + 8 + 9 3 / - -> this is final post fix expression  
// for a valid post fix exp-> no of operands = no of operators + 1
// no of operands - no of operators >=2 whenever we encounter a operator 

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
void evaluate(stack<int> &arr,char ch){
    int b = arr.top();
    arr.pop();
    int a= arr.top();
    arr.pop();
    switch(ch){
        case '+' : 
            arr.push(a+b);
            break;
        case '-' : 
            arr.push(a-b);
            break;
        case '*' : 
            arr.push(a*b);
            break;
        case '/' : 
            arr.push(a/b);
            break;
    }
}
int32_t main(){
    string s;cin>>s; //valid post fix expression as input
    stack<int> arr;
    for(char ch:s){
        if(isdigit(ch)){
            arr.push(ch - '0');
        }else{
            evaluate(arr,ch);
        }
    }
    cout<<arr.top()<<endl;
    return 0;
}
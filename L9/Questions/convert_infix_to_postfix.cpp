// during conversion we append the operands directly and push operators in a stack, then wait weather the next
// operator is having low preference or not, if low then push that prev operator and move ahead
// otherwise puah the next high priority in stack too and at last push all the operators in order 
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
int prec(char ch){
    if(ch=='*' | ch=='/'){
        return 2;
    }else if(ch=='+' | ch=='-'){
        return 1;
    }else{
        return -1; //returning -1 will not make the while loop to run in case we encounter any oprand or bracket
    }
}
int32_t main(){
    string s;cin>>s; //contains operators ,brackets and operands(single digit)
    stack<char> arr;
    string ans;
    for(char ch:s){
        if(isalpha(ch)){
            ans+=ch;
        }else if(ch=='('){
            arr.push(ch);
        }else if(ch==')'){
            while(arr.top()!='('){
                ans+= arr.top();arr.pop();
            }
            arr.pop(); // to remove corresponding opening bracket 

        }else{
            while(arr.size() & prec(arr.top())>= prec(ch)){
                ans+= arr.top(),arr.pop();
            
            }
            arr.push(ch);
        }
    } 
    while(!arr.empty()){
        ans+= arr.top(),arr.pop();
    }

    cout<<ans<<endl;
    return 0;
}
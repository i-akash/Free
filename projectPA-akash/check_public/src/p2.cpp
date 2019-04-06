#include <bits/stdc++.h>
#define mx 1005 
#define mod 1000007
#define ll long long

using namespace std;

int n,k,arr[mx];
ll dp[mx][mx][3];
ll mxx=1e15;

ll rec(int pos,int need,int turn){
      if(need==0)return 0;
      if(pos==n)return -mxx;
      
      if(dp[pos][need][turn]!=-1)return dp[pos][need][turn];
      ll ans=0;

      if(turn)
         ans=max(rec(pos+1,need-1,0)+(ll)arr[pos],rec(pos+1,need,turn));    
      else
         ans=max(rec(pos+1,need-1,1)-(ll)arr[pos],rec(pos+1,need,turn));    
      
      dp[pos][need][turn]=ans;

      return ans;
}



int main(){
    ios::sync_with_stdio(false);
    ifstream fin;
    fin.open("p2.in");
    ofstream fout;
    fout.open("p2.out");
   
    fin>>n>>k;
    for(int i=0;i<n;i++)
        fin>>arr[i];
    sort(arr,arr+n,greater<int>());
    memset(dp,-1,sizeof(dp)); 
    fout<<rec(0,n-k,1)<<"\n";
    return 0;
}

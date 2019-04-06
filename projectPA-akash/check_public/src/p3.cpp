#include <bits/stdc++.h>
#define mx 1005
#define ll long long

using namespace std;

int n,arr[mx];
ll dp[mx][mx][3];

ll rec(int i,int j,int turn){
     if(i==j && turn)return arr[i];
     if(i==j && !turn)return -arr[i];
     if(dp[i][j][turn]!=-1)return dp[i][j][turn];
     
     ll ans=0;
     
     if(turn)ans=max(rec(i+1,j,turn^1)+(ll)arr[i],rec(i,j-1,turn^1)+(ll)arr[j]);
     else  ans=min(rec(i+1,j,turn^1)-(ll)arr[i],rec(i,j-1,turn^1)-(ll)arr[j]); 

     dp[i][j][turn]=ans;
     return ans;
}

int main(){
    ios::sync_with_stdio(false);
    ifstream fin;
    fin.open("p3.in");
    ofstream fout;
    fout.open("p3.out");
         
    fin>>n;
    for(int i=0;i<n;i++)
       fin>>arr[i];

    memset(dp,-1,sizeof(dp));
    fout<<rec(0,n-1,1)<<"\n";
    return 0;
}

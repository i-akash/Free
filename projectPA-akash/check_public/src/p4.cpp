#include <bits/stdc++.h>
#define mod 1000000007
#define mx 100
#define ll long long

using namespace std;


int n,k,v,dp[mx][mx][mx+mx];

ll rec(int taken,int lastValue,int sum){
	if(taken==n)return (sum==k);
    
    if(dp[taken][lastValue][sum]!=-1)return dp[taken][lastValue][sum];
    
    ll ans=0,offset=0;
    if(taken%2)offset=-1;
    else offset=1;


    for(int i=lastValue-1;i>=1;i--){
       int ia=rec(taken+1,i,sum+(offset*i));
       ans+=ia;
       ans%=mod;
    }
    
    dp[taken][lastValue][sum]=(int)ans;
    return ans;
}


int main(){
	ios::sync_with_stdio(false);
	
   ifstream fin;
   fin.open("p4.in");
   ofstream fout;
   fout.open("p4.out");

	fin>>n>>k>>v;

	memset(dp,-1,sizeof(dp));

	ll ans=rec(0,v+1,0);

	while(n){
		ans*=n;
		ans%=mod;
		n--;
	}

	fout<<ans<<"\n";
}
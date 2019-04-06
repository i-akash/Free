#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){

   ifstream fin;
   fin.open("p1.in");
   ofstream fout;
   fout.open("p1.out");
   
   int n;fin>>n;

   int arr[n+10];
   ll tuzgu=0,ritza=0;

   for(int i=0;i<n;i++){
   	   fin>>arr[i];
   }

   sort(arr,arr+n,greater<int>());

   for(int i=0;i<n;i++){
   	   if(i%2)ritza+=(ll)arr[i];
   	   else   tuzgu+=(ll)arr[i];
   }

   fout<<tuzgu-ritza<<"\n";
}

int main(){
   solve();
}

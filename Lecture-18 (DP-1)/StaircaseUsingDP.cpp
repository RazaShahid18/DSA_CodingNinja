#include<bits/stdc++.h>
using namespace std;

#define ll long long

int staircase(int n){

  ll x= pow(10,9)+7;

  ll a=1, b=1, c=2, d=0;;

  for(int i=3;i<=n;i++){
    d=(a+b+c)%x;
    a=b;
    b=c;
    c=d;
  }

  return c;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<staircase(n)<<endl;
  }
}

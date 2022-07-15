#include<bits/stdc++.h>
using namespace std;

//Brute Force
/*
int lcs(string s, string t){
  //Base case
  if(s.length()==0 || t.length()==0){
    return 0;
  }

  //Recursive calls
  if(s[0]==t[0]){
    return 1+lcs(s.substr(1),t.substr(1));
  }
  else{
    int a=lcs(s,t.substr(1));
    int b=lcs(s.substr(1),t);
    int c=lcs(s.substr(1),t.substr(1));

    return max(a,max(b,c));
  }
}
*/


//Memoisation
/*
int lcs_help(string s, string t, int** arr){
  int a=s.length();
  int b=t.length();
  if(a==0 || b==0){
    return 0;
  }

  if(arr[a][b]!=-1){
    return arr[a][b];
  }

  int ans;
  if(s[0]==t[0]){
    ans=1+lcs_help(s.substr(1),t.substr(1),arr);
  }

  else{
    int a=lcs_help(s,t.substr(1),arr);
    int b=lcs_help(s.substr(1),t,arr);
    int c=lcs_help(s.substr(1),t.substr(1),arr);

    ans= max(a,max(b,c));
  }

  arr[a][b]=ans;
  return arr[a][b];
}

int lcs(string s, string t){
  int m=s.length();
  int n= t.length();
  int **ans= new int*[m+1];
  for(int i=0;i<m+1;i++){
    ans[i]= new int[n+1];
  }

  for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
      ans[i][j]=-1;
    }
  }

  return lcs_help(s,t,ans);
}
*/

//DP

int lcs(string s, string t){
  int m=s.length();
  int n= t.length();
  int **arr= new int*[m+1];
  for(int i=0;i<m+1;i++){
    arr[i]= new int[n+1];
  }

  //filling the first column and first row ,i.e. when m==0 or n==0
  for(int i=0;i<=m;i++){
    arr[i][0]=0;
  }
  for(int j=0;j<=n;j++){
    arr[0][j]=0;
  }

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      int a=arr[i][j-1];
      int b=arr[i-1][j];
      int c=arr[i-1][j-1];

      if(s[m-i]==t[n-j]){
        arr[i][j]=1+arr[i-1][j-1];
      }

      else{
        arr[i][j]= max(a,max(b,c));
      }

    }
  }

  return arr[m][n];
}


int main(){
  string s,t;
  cin>>s>>t;
  cout<<lcs(s,t);
}

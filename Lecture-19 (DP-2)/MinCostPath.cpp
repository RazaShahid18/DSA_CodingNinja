#include <bits/stdc++.h>
using namespace std;

//Brute Force
/*
int minCostPath(int **input, int m, int n){
	//Write your code here
  if(m==0 || n==0){
    return INT_MAX;
  }
  if(m==1 && n==1){
    return input[0][0];
  }
  int x= minCostPath(input,m-1,n-1);
  int y= minCostPath(input,m,n-1);
  int z= minCostPath(input,m-1,n);

  return input[m-1][n-1]+min(x,min(y,z));
}*/



//Memoisation
/*
int minCostPath(int **input,int m, int n, int **ans){
  if(m==0 || n==0){
    return INT_MAX;
  }
  if(m==1 && n==1){
    return input[0][0];
  }

  if(ans[m-1][n-1]!=-1){
    return ans[m-1][n-1];
  }

  int x= minCostPath(input,m-1,n-1,ans);
  int y= minCostPath(input,m,n-1,ans);
  int z= minCostPath(input,m-1,n,ans);

  ans[m-1][n-1]= input[m-1][n-1]+ min(x,min(y,z));

  return ans[m-1][n-1];
}

int minCostPath(int **input, int m, int n){
  int **arr= new int *[n];

  for(int i=0;i<n;i++){
    arr[i]= new int[m];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      arr[i][j]=-1;
    }
  }

  return minCostPath(input, m,n,arr);
}*/



//DP

int minCostPath(int **input, int m, int n){
  int **arr= new int *[n];

  for(int i=0;i<n;i++){
    arr[i]= new int[m];
  }

  if(m==0 || n==0){
    return INT_MAX;
  }
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      if(i==n-1 && j==m-1){
        arr[i][j]=input[m-1][n-1];
      }
      else{
        if(i+1>=n ){
          arr[i][j]=input[i][j]+arr[i][j+1];
        }
        else if(j+1>=m){
          arr[i][j]=input[i][j]+arr[i+1][j];
        }
        else{
          int a=arr[i+1][j];
          int b=arr[i][j+1];
          int c=arr[i+1][j+1];

        arr[i][j]=input[i][j]+min(a,min(b,c));
        }
      }
    }
  }

  return arr[0][0];
}


int main(){
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++)		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}

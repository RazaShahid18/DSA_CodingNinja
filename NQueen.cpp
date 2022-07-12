#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool isPossible(int n, int row, int col){
    //checking vertically if any queen is already present
    for(int i=row-1;i>=0;i--){
      if(board[i][col]==1)
        return false;
    }

    //checking diagonally upper left
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
      if(board[i][j]==1)
        return false;
    }
    //checking diagonally upper right
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
      if(board[i][j]==1)
        return false;
    }

    return true;
}

void place(int n, int row){
    //base case i.e. if we reach the last row that means we have a solution so we print the solution
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j]=1;
            place(n,row+1);
            board[row][j]=0;
        }
    }
}

void Nqueen(int n){
    memset(board,0,11*11*sizeof(int));
    place(n,0);
}

int main(){
    int n;
    cin>>n;

    Nqueen(n);
    return 0;
}

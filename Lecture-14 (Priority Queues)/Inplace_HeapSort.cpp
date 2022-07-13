#include<bits/stdc++.h>
using namespace std;

void heapSort(int pq[], int n) { // pq= input array   n=size of the array

  //insertion of elements
  for(int i=1;i<n;i++){
    int childIndex=i;
    int parentIndex= (childIndex-1)/2;
    while(parentIndex>=0){
      if(pq[parentIndex] > pq[childIndex]){
        int temp= pq[childIndex];
        pq[childIndex]=pq[parentIndex];
        pq[parentIndex]= temp;
      }
      else
        break;
      childIndex=parentIndex;
      parentIndex=(childIndex-1)/2;
    }
  }

  for(int i=0;i<n;i++){
    cout<<pq[i]<<" ";
  }
  cout<<endl;


  //removeMin function to sort the elements
  int i=n;
  while(i!=0){
    //swapping the first and last element
    int temp = pq[0];
    pq[0]=pq[i-1];
    pq[i-1]=temp;

    i--;
    //putting the last swapped element to its correct position
    int parentIndex_new=0;


    while(2*parentIndex_new+1 < i){
      int childIndex_l= 2*parentIndex_new+1;
      int childIndex_r= 2*parentIndex_new+2;

      //if right child doesn't exist
      if(childIndex_r >=i){
        if(pq[parentIndex_new] > pq[childIndex_l]){
          int temp= pq[childIndex_l];
          pq[childIndex_l]=pq[parentIndex_new];
          pq[parentIndex_new]= temp;
        }

        break;
      }

      //if both the children exist
      int minIndex=0;
      if(pq[childIndex_l] < pq[childIndex_r]){
        minIndex= childIndex_l;
      }
      else{
        minIndex= childIndex_r;
      }

      if(pq[parentIndex_new] > pq[minIndex]){
        int temp= pq[minIndex];
        pq[minIndex]=pq[parentIndex_new];
        pq[parentIndex_new]= temp;
      }

      else
        break;

      parentIndex_new= minIndex;
    }
  }
}


int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }

    delete[] input;
}

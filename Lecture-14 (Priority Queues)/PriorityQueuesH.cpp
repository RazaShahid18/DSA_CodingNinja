#include<vector>

class PriorityQueues{
  vector<int> pq;

public:
  PriorityQueues(){
    nextIndex=0;
  }

  bool isEmpty(){
    return pq.size()==0;
  }

  int getsize(){
    return pq.size();
  }

  int getMin(){
    if(isEmpty())
      return 0;//if the PriorityQueue is empty i.e. no elements in the vector we will retunr zero

    return pq[0];
  }

  void insert(int element){
    pq.push_back(element);

    int childIndex= pq.size()-1;

    while(childIndex > 0){
      int parentIndex= (childIndex-1)/2;

      if(pq[childIndex] < pq[parentIndex]){
        int temp= pq[childIndex];
        pq[childIndex]=pq[parentIndex];
        pq[parentIndex]= temp;
      }

      else
        break;

      childIndex= parentIndex;
    }

  }



    int removeMin() {
          // Complete this function
          int ans= pq[0];
          pq[0]= pq[pq.size()-1];
          pq.pop_back();

          int parentIndex=0;
          int minIndex=0;

          while(parentIndex*2+1 <pq.size()){

            int childIndex_l= parentIndex*2+1;
            int childIndex_r= parentIndex*2+2;

            //checking if the right child of the parent doesn't exist
            if(childIndex_r >= pq.size()){
              //checking if the parent's values is greater than the left child
              if(pq[parentIndex] > pq[childIndex_l]){
                int temp= pq[childIndex_l];
                pq[childIndex_l]=pq[parentIndex];
                pq[parentIndex]= temp;
              }

              //since right child doesn't exist, so no more further nodes exist in the CBT
              break;
            }

            //if both children of the parent exist

            //determining index of the two smaller of the two children
            if(pq[childIndex_l]< pq[childIndex_r]){
              minIndex= childIndex_l;
            }
            else
              minIndex= childIndex_r;

            //checking if the parent's values is greater than minimum of its children
            if(pq[parentIndex] > pq[minIndex]){
              int temp= pq[minIndex];
              pq[minIndex]=pq[parentIndex];
              pq[parentIndex]= temp;
            }

            //if the parent's value is at its proper position, we exit the loop
            else
              break;

            parentIndex=minIndex;
          }
          return ans;
          // Write your code here
      }
};

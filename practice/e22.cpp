#include<iostream>
using namespace std;

const int MAX_STUDENTS=100;

void heapifyDown(int heap[],int size,int idx){
  int largest=idx;
  int leftChild=2*idx+1;
  int rightChild=2*idx+2;
  
  if(leftChild<size && heap[leftChild]>heap[largest]){
    largest=leftChild;
  }
  if(rightChild<size && heap[rightChild]>heap[largest]){
    largest=rightChild;
  }
  if(largest!=idx){
    swap(heap[idx],heap[largest]);
    heapifyDown(heap,size,largest);
  }
}

void buildMaxHeap(int heap[],int size){
  for(int i=size/2-1;i>=0;--i){
    heapifyDown(heap,size,i);
  }
}

void findMinMaxMarks(const int marks[],int numStudents,int& maxMarks,int& minMarks){
  int maxHeap[MAX_STUDENTS];
  int minHeap[MAX_STUDENTS];
  
  for (int i=0;i<numStudents;i++){
    maxHeap[i]=marks[i];
    minHeap[i]=marks[i];
  }
  
  buildMaxHeap(maxHeap,numStudents);
  maxMarks=maxHeap[0];
}


int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    int marks[MAX_STUDENTS];

    // Read the marks of the students
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter marks of student " << i+1 << ": ";
        std::cin >> marks[i];
    }

    int maxMarks, minMarks;
    findMinMaxMarks(marks, numStudents, maxMarks, minMarks);

    std::cout << "Maximum marks: " << maxMarks << std::endl;
    std::cout << "Minimum marks: " << minMarks << std::endl;
    for(int i=0;i<numStudents;i++){
      cout<<marks[i]<<endl;
    }  
    return 0;
}

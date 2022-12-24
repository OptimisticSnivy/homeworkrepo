#include<iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    // Find the minimum element in the unsorted portion of the array
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    // Swap the minimum element with the element at the current position
    T temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

int main(){
    int arr[] = {3, 7, 4, 9, 5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<"\n";
    }
    cout<<sizeof(arr);
}

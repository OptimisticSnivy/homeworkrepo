
#include <iostream>

// Function to build a max-heap from an array of marks
void buildMaxHeap(int marks[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Perform max heapify operation on each non-leaf node
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && marks[left] > marks[largest]) {
            largest = left;
        }

        if (right < n && marks[right] > marks[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(marks[i], marks[largest]);
            // Recursively heapify the affected subtree
            buildMaxHeap(marks, n);
        }
    }
}

// Function to find the maximum mark from the max-heap
int findMaximumMark(int marks[], int n) {
    return marks[0];
}

// Function to find the minimum mark from the max-heap
int findMinimumMark(int marks[], int n) {
    int minMark = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] < minMark) {
            minMark = marks[i];
        }
    }
    return minMark;
}

int main() {
    // Example marks
    int marks[] = { 76, 89, 95, 82, 68, 91, 77 };
    int n = sizeof(marks) / sizeof(marks[0]);

    // Build a max-heap from the marks
    buildMaxHeap(marks, n);

    // Find the maximum and minimum marks
    int maximumMark = findMaximumMark(marks, n);
    int minimumMark = findMinimumMark(marks, n);

    std::cout << "Maximum mark: " << maximumMark << std::endl;
    std::cout << "Minimum mark: " << minimumMark << std::endl;

    return 0;
}

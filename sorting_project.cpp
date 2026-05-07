#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// Function to visualize the array as bars
void visualizeArray(const vector<int>& arr, int n, int active1 = -1, int active2 = -1) { 
    // Clear screen (works on most terminals)
    cout << "\033[2J\033[H"; 
    
    cout << "--- UI Animation Sorting Visualization (Bubble Sort) ---\n\n";
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " | ";
        
        // Highlight active elements being compared or swapped
        if (i == active1 || i == active2) {
            cout << "\033[1;31m"; // Red for active
        } else {
            cout << "\033[1;34m"; // Blue for others
        }
        
        for (int j = 0; j < arr[i]; j++) {
            cout << "█";
        }
        cout << "\033[0m" << endl; // Reset color
    }
    cout << "\n";
}

int main() {
    int n = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Nothing to sort.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int swapCount = 0;

    cout << "Press Enter to start the visualization...";
    cin.ignore();
    cin.get();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            visualizeArray(arr, n, j, j + 1); 
            cout << "Comparing " << arr[j] << " and " << arr[j + 1] << "...\n";
            this_thread::sleep_for(chrono::milliseconds(500));

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
                
                visualizeArray(arr, n, j, j + 1);
                cout << "SWAPPED " << arr[j+1] << " and " << arr[j] << "!\n";
                cout << "Total Swaps: " << swapCount << "\n";
                this_thread::sleep_for(chrono::milliseconds(800));
            }
        }
    }

    // Final visualization
    visualizeArray(arr, n);
    cout << "Sorting Complete!\n";
    cout << "Final Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTotal Swaps: " << swapCount << endl;

    return 0;
}

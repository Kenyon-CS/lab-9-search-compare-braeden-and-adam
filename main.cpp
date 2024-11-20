#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


// Sequential search with start and stop range
int seq_search(vector<int> &keys, int key, int start, int stop, int &numCmp) {
    for (int i=start;i < stop;i++){
        numCmp++;
        if (keys[i]==key){
            return i;
        }
    }
    return -1;
}

// Sequential search
int seq_search(vector<int> &keys, int key, int &numCmp) {
    int start=0;
    return seq_search(keys,key,start,keys.size(),numCmp);
}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {
    int low = 0;
    int high = keys.size() - 1;

    while (low <= high) {
        numCmp++;
        int middle = low + (high - low) / 2;
        int cmpVal = keys[middle];

        if (cmpVal == key) {
            return middle;
        } else if (cmpVal > key) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {
    int low = 0;
    int high = keys.size() - 1;

    while (low-high > 15) {
        numCmp++;
        int middle = low + (high - low) / 2;
        int cmpVal = keys[middle];

        if (cmpVal == key) {
            return middle;
        } else if (cmpVal > key) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return seq_search(keys,key,low,high,numCmp);
}


// Test the search algorithms
int main() {
    // Test implementations
    //cout << 2/3 << endl;

    // vector<int> srtvec={1,2,3,4,5,6,7,8,9,10};
    // int numcmp=0;
    // cout << "Found at index: " <<seq_search(srtvec,8,numcmp) << " with " << numcmp << "comparisons" <<endl;
    // numcmp=0;
    // cout << "Found at index: " <<bin_search(srtvec,8,numcmp) << " with " << numcmp << "comparisons" <<endl;


    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
    vector<int> arr(100000);
    for (int i = 0; i < 100000; ++i) {
        arr[i] = rand(); // Generate random integers
    }

    // Sort the vector using STL sort
    sort(arr.begin(), arr.end());

    // Generate 50 random numbers from the data (guaranteed to be in the array)
    vector<int> guaranteed;
    for (int i = 0; i < 50; i++) {
        int index = rand() % 100000; // Random index within the range
        guaranteed.push_back(arr[index]);
    }
    // Generate 50 random numbers (may or may not be in the array)
    vector<int> random;
    for (int i = 0; i < 50; i++) {
        random.push_back(rand());
    }
    // Test each search algorithm, output results

    return 0;
}

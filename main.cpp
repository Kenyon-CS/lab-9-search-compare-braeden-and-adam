#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Sequential search
int seq_search(vector<int> &keys, int key, int &numCmp) {
    return seq_search(keys,key,0,keys.size(),numCmp);
}

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

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {
    vector<int> searchvec=keys;
    bool found=false;
    while (!found){
        numCmp++;
        int middle=searchvec.size()/2;
        int cmpVal=searchvec[middle];
        if (cmpVal==key){
            return middle;
        } else {
            vector<int> tmp;
            numCmp++; 
            if (cmpVal > key) {
                copy(searchvec.begin(),searchvec.begin()+middle,tmp.begin());
            } else {
                copy(searchvec.begin()+middle+1,searchvec.end(),tmp.begin());
            }
            searchvec=tmp;
        }
    }
}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {

}

// Test the search algorithms
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
 
    // Sort the vector using STL sort

    // Generate 50 random numbers from the data (guaranteed to be in the array)

    // Generate 50 random numbers (may or may not be in the array)

    // Test each search algorithm, output results

    return 0;
}

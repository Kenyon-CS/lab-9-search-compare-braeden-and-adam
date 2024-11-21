#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <sstream>

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

int bSearchStep(vector<int> &keys, int key, int &numCmp,int &low,int &high){
    numCmp++;
    int middle = low + (high - low) / 2;
    int cmpVal = keys[middle];

    if (cmpVal == key) {
        return middle;
    } else {
        numCmp++;
        if (cmpVal > key) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {
    int low = 0;
    int high = keys.size() - 1;
    while (low <= high) {
        int possSol=bSearchStep(keys,key,numCmp,low,high);
        if (possSol != -1){
            return possSol;
        }
    }
    return -1;
}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {
    int low = 0;
    int high = keys.size() - 1;

    while (high - low > 15) {
        int possSol=bSearchStep(keys,key,numCmp,low,high);
        if (possSol != -1){
            return possSol;
        }
    }
    return seq_search(keys,key,low,high,numCmp);
}

void printEqual(stringstream &ss, int size){
    for (int i = 0;i < size;i++ ){
        char d;
        if ( ss >> d){
            cout << d;
        } else {
            cout << ' ';
        }
    }
}

void printEqual(string in,int size){
    stringstream ss;
    ss << in;
    printEqual(ss,size);
}

void printEqual(int in,int size){
    stringstream ss;
    ss << in;
    printEqual(ss,size);
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
    srand(time(0));

    // Create a vector of 100,000 integers
    vector<int> arr;
    arr.reserve(100000);
    for (int i = 0; i < 100000; ++i) {
        arr.push_back(rand()); // Generate random integers
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

    vector<vector<int>> toFind={guaranteed,random};
    // Test each search algorithm, output results
    cout << " Search         Found      Seq. Search   Bin Search  Enhanced Search" << endl;
    for (vector<int> vec: toFind){
        for (int i=0; i < 50; i++){
            int searchElement=vec[i];
            int sCount=0;
            int sresult=seq_search(arr,searchElement,sCount);
            int bCount=0;
            int bresult=bin_search(arr,searchElement,bCount);
            int eCount=0;
            int eresult=bin2_search(arr,searchElement,eCount);
            if (!(arr[sresult] == arr[bresult]) && (arr[bresult] == arr[eresult])){
                cout << "ERROR got S: " << arr[sresult] << "  B: " << arr[bresult] << "  E:" << arr[eresult] << endl;
            }
            vector<int> vals={searchElement,sresult,sCount,bCount,eCount};
            cout << "  ";
            for (int val:vals){
                printEqual(val,14);
            }
            cout << endl;
        }
    }
    return 0;
}

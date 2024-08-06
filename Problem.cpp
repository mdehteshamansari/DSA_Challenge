#include<iostream>
#include<vector>
using namespace std;
// Given an array of integers, implement a function to find the maximum sum of a contiguous subarray. Describe your approach and the time complexity of your solution.

int util(int n,vector<int> &arr){
    //If the array is empty then we cannot find the subarray sum
    if(arr.empty()) return 0;
    //initializing two variables for current and global max
    int cur = arr[0],maxCur = arr[0];
    //Iterating over the array for finding the subarray sum
    for(int i=1;i<n;i++){
        cur = max(cur,arr[i]+cur);
        if(cur>maxCur) maxCur = cur;
    }
    return maxCur;
}
int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int ans = util(n,arr);
    cout<<"The maximum subarray sum "<<ans;
    return 0;
}

//Time Complexity: - O(N) because we are only running one for loop to iterate over thearray
// Space Complexity: - O(N) because we are only using two variables to store the  current nad global max 
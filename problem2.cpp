#include<iostream>
#include<vector>
using namespace std;
//2.  Implement a function to rotate an array by k positions. Explain your method and the space complexity of your solution.
void rotate(vector<int> &arr,int k){
    int n = arr.size();
    if(n==0) return;
    k = k%n;
    // reversing the array
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());

}
//sample input and output
//Enter the size of array 5
//enter k 2
//1 2 3 4 5
//1 2 3 4 5 
//4 5 1 2 3 
int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int k;
    cout<<"enter k";
    cin>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    // before reversing
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    //after reversing 
    rotate(arr,k);
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

// Time Complexity: - overall O(N) because reverse function uses O(N) complexity 
// Space Complexity: - O(1) because no external space is used
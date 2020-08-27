// Hello this program demostrates how we can use binary search to find
// element in a sorted array.
// I have made a function for both recursive and iterative solution of binary search
// Time complexity:
// as you can see the if we don't find a solution in middle we search for left
// if the number is smaller and else right
// so if the length of array is say x then in next iteration
// it becomes x/2 then in next it becomes x/4
// so total iteration required is x/2 + x/4 +x/8...= log x
// for example if x is 8 then 8/2 8/4 8/8 = 3 iteration.
// where we consider log base as 2 and x as 8;
// So time complexity is O(log n)
#include<iostream>
using namespace std;
int binarySearchIterative(int arr[],int size, int n){
    int start=0;
    int end=size-1;
    int mid;
    while(start<=end){
         mid=(start+end)/2; 
        if(n==arr[mid])
        {
            return mid;
        }
        else if(n<arr[mid])
        {
            end=mid-1;  
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int binarySearchRecursive(int arr[],int n,int start, int end){
    int mid= (start+end)/2;
    if(start>end){
        return -1;
    }
    if(arr[mid]==n){
        return mid;
    }
    else if(n<arr[mid]){
        return binarySearchRecursive(arr,n,start,mid-1);
    }
    else{
        return binarySearchRecursive(arr,n,mid+1,end);
    }
}
int main(){
    int arr[]={1,2,4,10,20,30};
    int size= sizeof(arr)/sizeof(arr[0]);
    int n=-1;
    int index=-1;
    int start=0;
    int end=size-1;
    cout<<"Enter the number to find: ";
    cin>>n;
    // index= binarySearchIterative(arr,size,n);
    index=binarySearchRecursive(arr,n,start,end);
    if(index==-1){
        cout<<"Not found!";
    }
    else{
    cout<<"Index and number is: "<<index<<" "<<arr[index];  
    }
    
    return 0;
}

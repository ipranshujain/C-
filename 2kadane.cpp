//What is Kadane Algorithm
//This is an algorithm that allows us to find the maximum continous sum of the array's subarray.
//This is a great Algo 
//It can be implemented in various ways also, also it is very easy
//Time Complexity: O(n)

#include<iostream>
#include<climits>
using namespace std;
int kadane(int arr[],int size){
    int s=0;
    int start=0;
    int end=0;
    //INT_MIN is used to find the minimum value that is possible
    //INT_MIN is found in climits so don't forgot to include it
    int max_sum=INT_MIN;
    int max_last=0;
    for(int i=0;i<size;i++){
        max_last= max_last  + arr[i];
        if(max_last<0){
            max_last=0;
            s=s+1;
        }
        else if(max_last>max_sum){
            max_sum= max_last;
            start=s;
            end=i;
        }
    }
    cout<<"Start Index is: "<<start<<" End Index is: "<<end<<"\n";
    return max_sum;
}
int main(){
    int a[]={0,1,-2,10,-1,20,3,-1,8,-10};
    //Output should be 39
    int size= sizeof(a)/sizeof(a[0]);
    int answer = kadane(a,size);
    cout<<"Answer is (Maximum Contiuous sum in subarray is) :"<<answer;
    return 0;
}
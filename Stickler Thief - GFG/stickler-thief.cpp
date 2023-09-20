//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
int spaceOptimised(int arr[], int n){
        int num1 = 0, num2 = 0, num3 = 0;
        
        for(int i=n-1; i>=0; i--){
            int include = arr[i] + num3;
            int exclude = 0 + num1;
            
            num1 = max(include, exclude);
            num3 = num2;
            num2 = num1;
        }
        return num1;
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // vector<int> dp(n, -1);
        // return solve(0, arr, n, dp);
        
        // return solveTab(arr, n);
        
        return spaceOptimised(arr, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
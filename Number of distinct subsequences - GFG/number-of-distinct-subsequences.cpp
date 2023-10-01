//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  const int MOD = 1e9 + 7;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	        int n = s.length();
    vector<int> dp(n + 1, 0); // dp[i] will store the count of distinct subsequences ending with s[i-1]

    // Initialize dp[0] to 1, as there is an empty subsequence.
    dp[0] = 1;

    // Create a map to store the last index of each character.
    unordered_map<char, int> lastIdx;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD; // Double the count by not taking s[i-1] and taking s[i-1] separately.

        if (lastIdx.find(s[i - 1]) != lastIdx.end()) {
            // If the character s[i-1] has appeared before, subtract the count of subsequences ending at the previous index of s[i-1].
            dp[i] = (dp[i] - dp[lastIdx[s[i - 1]] - 1] + MOD) % MOD;
        }

        // Update the last index of the current character.
        lastIdx[s[i - 1]] = i;
    }

    // Subtract 1 to exclude the empty subsequence.
    return (dp[n]  + MOD) % MOD;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
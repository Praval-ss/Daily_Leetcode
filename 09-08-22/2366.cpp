// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n=nums.size();
	    long long ans=0;
        long long  previous=nums[n-1];
	for(int i=n-2;i>=0;i--){
		int nt=nums[i]/previous;   
		if((nums[i])%previous!=0){
			nt++;
			previous=nums[i]/nt;
		}   
		ans+=nt-1;
	}
	return ans;
    }
};
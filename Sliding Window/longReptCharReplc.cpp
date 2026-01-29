// Problem statement:-
// You are given a string s and an integer k.
// You can replace at most k characters in the string with any uppercase English letter.
// Return the length of the longest substring containing the same character after performing at most k replacements.




// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int left = 0;
//         int maxLen = 0;
//         int maxFreq = 0;
//         int n = s.size();
//         vector<int> arr(26,0);

//         for(int right=0; right<n; right++){
//             arr[s[right] - 'A']++;          //plot the chracter to their correct idx position | eg s[right] = C, 'C' - 'A' = 67 - 65 = 2
//             maxFreq = max(maxFreq, arr[s[right]-'A']);
//             if((right-left+1)-maxFreq > k){
//                 arr[s[left]-'A']--;
//                 left++;
//             }
//             if((right-left+1)-maxFreq <= k){
//                 maxLen = max(maxLen, right-left+1);
//             }
//         }
//         return maxLen;
        
//     }
// };
14. Longest Common Prefix
=========================

# Description
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

## Example 1:
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

# Solution
Create an iterator integer variable with initial value. Get the letter at the position given by iterator from the first string.
For every string there after, if letter changes break out the for loop and while loop.
```c
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool okay = true;
        int i = 0;
        prefix = "";
        while(okay) {
            p = strs[0][0];
            for (string s: strs) {
                if (s[0] != p) 
                    okay = !okay;
                	break
                else
                    prefix += p;
            }
        }
        return prefix;
    }
};
```

# 412. Fizz Buzz

## Description
Given an integer n, return a string array answer (1-indexed) where:

`answer[i] == "FizzBuzz"` if i is divisible by `3` and `5`.
`answer[i] == "Fizz"` if i is divisible by `3`.
`answer[i] == "Buzz"` if i is divisible by `5`.
`answer[i] == i` (as a string) if none of the above conditions are true.


## Solution
A straight forward solution with if statements printing out the required word by the appropriate condition.
```c
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> out(n);
        for(int i = 1; i <= n; i++) {
            string out_str = "";
            auto valid = false;
            if (i % 3 == 0) {
                out_str += "Fizz";
                valid = true;
            } 
            if (i % 5 == 0) {
                out_str += "Buzz";
                valid = true;
            }
            if (valid == false) {
                out_str += to_string(i);
            }
            out[i-1] = out_str;
        }
        return(out);
    }
};
```

## Results
Runtime: 3 ms, faster than 87.04% of C++ online submissions for Fizz Buzz.
Memory Usage: 7.1 MB, less than 96.87% of C++ online submissions for Fizz Buzz.

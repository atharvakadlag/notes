#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n;
    bool okay = true;
    std::cin >> n;
	std::vector<int> A(n);
	for (int i = 0; i < n; i++) {
	    std::cin >> A[i];
	}
	// got the array
	
    int p_top = A[0];
    int q_top = A[0];
    
    for (int j = 2; j < n; j++) {
        if (A[j] => p_top & A[j] <= q_top) {
            p_top = A[j];
        } else if (q_top < A[j])
            q_top = A[j];
        else
            okay = false;
    }
    if (okay) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
 //    int t;
 //    std::cin >> t;
 //    for (int i = 0; i < t; i++) {
 //        std::cout << solve() << std::endl;
 //    }
	// return 0;
    int n = 6;
    bool okay = true;
    // std::cin >> n;
    std::vector<int> A {4,5,6,1,2,3};
    // for (int i = 0; i < n; i++) {
    //     std::cin >> A[i];
    // }
    // got the array
    
    int p_top = A[0];
    int q_top = A[0];
    
    for (int j = 2; j < n; j++) {
        if (A[j] => p_top && A[j] <= q_top) {
            p_top = A[j];
        } else if (q_top < A[j])
            q_top = A[j];
        else
            okay = false;
    }
    if (okay) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

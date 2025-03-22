// Author: Harein Abeysekera
// 03/21/25

#include <iostream>
#include "bdc.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Convert a vector of integers to a formatted string
string vec_to_string(vector<int> v){
    string s = "[";
    for (int i = 0; i < v.size(); i++){
        s += to_string(v[i]);
        if (i < v.size() - 1){
            s += ", ";
        }
    }
    s += "]";
    return s;
}

// Check if a number can be added to the conglomerate while maintaining the divisibility requirement
bool is_divisible(vector<int>& conglomerate, int num) {
    for (int n : conglomerate) {
        if (n % num != 0 && num % n != 0) {
            return false;  
        }
    }
    return true;  
}

// Recursive function to build the largest conglomerate
vector<int> build_conglomerate(vector<int>& sorted_list, int i, vector<int> current_conglomerate){
    if (i < 0){
        return current_conglomerate;
    }

    vector<int> exclude_vec = build_conglomerate(sorted_list, i - 1, current_conglomerate);

    vector<int> include_vec;
    if (is_divisible(current_conglomerate, sorted_list[i])) {
        vector<int> new_conglomerate = current_conglomerate;
        new_conglomerate.push_back(sorted_list[i]);
        include_vec = build_conglomerate(sorted_list, i - 1, new_conglomerate);
    }

    return (include_vec.size() > exclude_vec.size()) ? include_vec : exclude_vec;
}

// Find the largest conglomerate that meets the divisibility requirement
vector<int> biggest_divisible_conglomerate(vector<int> input){
    if (input.empty() || input.size() == 1){
        return input;
    }

    // Sort in descending order to prioritize larger numbers
    sort(input.rbegin(), input.rend());
    vector<int> result = build_conglomerate(input, input.size() - 1, {});

    return result;
}

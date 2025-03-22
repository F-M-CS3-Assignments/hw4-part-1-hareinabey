
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!

	// Test 3 - empty list, should give nothing back
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans.empty());

	// Test 4 - just one number, should spit it right back
	values = {42};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans == values);

	// Test 5 - no pairs work, should give me one number
	values = {7, 11, 13, 17}; // all primes, no divisibility here
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans == vector<int>{17} || ans == vector<int>{7});

	// Test 6 - small list with some options
	values = {4, 8, 2, 16};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet6(ans.begin(), ans.end());
	soln = {16, 8, 4, 2}; // all powers of 2 work together
	assert(answerSet6 == soln);

	// Test 7 - mixed bag, let’s see what happens
	values = {25, 5, 15, 3, 9};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet7(ans.begin(), ans.end());
	soln = {25, 5}; // 5 divides 25
	bool opt1 = (answerSet7 == soln);
	soln = {15, 3}; // 3 divides 15
	bool opt2 = (answerSet7 == soln);
	soln = {9, 3}; // 3 divides 9
	bool opt3 = (answerSet7 == soln);
	assert(opt1 || opt2 || opt3); // Allow all valid outputs

	cout << "All tests passed, woohoo!" << endl;

	return 0;
}
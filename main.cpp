// Author: Harein Abeysekera
// 03/21/25

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

	// Test 3 - Empty list
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans.empty());

	// Test 4 - Single number
	values = {42};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans == values);

	// Test 5 - No divisible pairs, should return one number
	values = {7, 11, 13, 17};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans == vector<int>{17} || ans == vector<int>{7});


	// Test 6 - Multiple possible answers
	values = {25, 5, 15, 3, 9};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet7(ans.begin(), ans.end());
	soln = {25, 5};
	bool opt1 = (answerSet7 == soln);
	soln = {15, 3};
	bool opt2 = (answerSet7 == soln);
	soln = {9, 3};
	bool opt3 = (answerSet7 == soln);
	assert(opt1 || opt2 || opt3);

	// Test 8 - Already sorted in descending order
	values = {100, 50, 25, 5, 1};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {100, 50, 25, 5, 1};
	set<int> answerSet8(ans.begin(), ans.end());
	assert(answerSet8 == soln);

	// Test 9 - Large numbers with multiple divisibility chains
	values = {90, 45, 30, 15, 10, 5, 3, 2};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet9(ans.begin(), ans.end());
	assert((answerSet9 == set<int>{90, 30, 10, 5}) || (answerSet9 == set<int>{90, 45, 15, 5}));

	cout << "All tests passed!" << endl;

	return 0;
}

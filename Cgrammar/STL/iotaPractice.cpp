// FILE : iotaPractice.cpp
// PROGRAMMER : Kevin Park
// DATE		  : 2017 / 8 / 13
// Description: To know what iota function is, I made this cpp file. 
// iota fills an iterator range in order as incremented numbers. 

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

template <typename T>
void showFuc(T vec) {
	for (auto it : vec) {
		std::cout << it << ' ';
	}
}
template <typename T>
void showFuc2(T something) {
	for (auto i : something) {
		std::cout << *i << ' ';
	}
}

int main() {
	std::vector<int> kev(10);
	std::iota(kev.begin(), kev.end(), 10);
	showFuc(kev);

	std::vector<std::vector<int>::iterator> kev2(kev.size());
	std::iota(kev2.begin(), kev2.end(), kev.begin());
	std::shuffle(kev2.begin(), kev2.end(), std::mt19937{ std::random_device{}() });

	std::cout << std::endl;
	std::cout << "After Shuffled " << std::endl;
	showFuc2(kev2);

	return 0;
}

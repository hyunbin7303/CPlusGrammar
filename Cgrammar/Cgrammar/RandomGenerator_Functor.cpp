#include <algorithm> // Used for std::generate
#include <iostream>
#include <vector>
#include <cstdlib>

int RandomGenerator() {
	return (std::rand() % 50);
}

template<class Kevin>
class RandomNumGenerator
{
	Kevin num;
public:
	RandomNumGenerator() : num(0.0) {}
	Kevin operator()() {
		return (std::rand() % 100);
	}
};
class something {
private:
	int num;
public:
	something() : num(0) {}
	int operator()() {
		return (std::rand() % 100);
	}
};

template<typename T>
void printOut(std::vector<T> inputVec) {
	for (auto it : inputVec) {
		std::cout << it << " ";
	}
}

int main() {
	std::vector<int> vec(10);
	std::generate(vec.begin(), vec.end(), std::rand);
	printOut(vec);


	std::cout << std::endl  << " ======================================= " << std::endl;
	std::generate(vec.begin(), vec.end(), RandomGenerator); // Third parameter should be function pointer or function object.
	printOut(vec);

	std::cout << std::endl << " ======================================= " << std::endl;
	std::generate(vec.begin(), vec.end(), something());
	printOut(vec);

	std::vector<double> vecDouble(10);
	std::cout << std::endl << " ======================================= " << std::endl;
	std::generate(vecDouble.begin(), vecDouble.end(), RandomNumGenerator<double>());
	printOut(vecDouble);

	
	return 0;
}



#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	queue <string> names;
	names.push("Ben");
	names.push("Erin");
	names.push("Dan");

	cout << "Welcome to US Coney and Cone! " << endl << endl;
	cout << "Now serving : " << names.front() << endl << endl;
	names.pop();
	cout << "There are currently " << names.size() << " people in the queue. "
		<< " People in the queue. "
		<< "The next person in the queue is "
		<< names.front() << "." << endl << endl
		<< names.back() << " is the last person in the queue. " << endl;

	cin.get();
	return 0;
}
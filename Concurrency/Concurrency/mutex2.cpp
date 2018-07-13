#include <iostream>
#include <mutex>
#include <string>
#include <fstream>
using namespace std;
mutex mux;



class LogFile
{
	mutex my_mux;
	ofstream f;

public:
	LogFile() {
		f.open("kevin.txt");
	}

	void shared_PRINT(string id, int value) {
		lock_guard<mutex> locker(mux);
		f << "FROM " << id << " : " << value << endl; 
	}

};


class stack {
private:
	int* _data;
	mutex _mux;


public:
	void pop(); // pops off the item on top of the stack.
	int& top(); // Returns the item on top
	//


};



void func1(stack& st)
{
	int value = st.top();
	st.pop();
	process(value); 
}


int main()
{
	LogFile log;
	thread t1(func1, ref(log));
	for (int i = 0; i < 100; i++)
	{
		log.shared_PRINT("FROM MAIN", i);
	}
	t1.join();
	system("pause");
}

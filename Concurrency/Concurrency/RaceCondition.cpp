#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>
using namespace std;

class KevinAccount
{
	int myMoney;
	mutex mux;
public:
	KevinAccount() : myMoney(0) {};
	void addMoney(int money)
	{
		mux.lock();
		for (int i = 0; i < money; i++)
		{
			myMoney++;
		}
		mux.unlock();
	}
	int getMoney()
	{
		return myMoney;
	}
};

int TestMyMoney(int numThread)
{
	KevinAccount kAccount;
	vector<thread> v_thread;
	for (int i = 0; i < numThread; i++)
	{
		v_thread.push_back(thread(&KevinAccount::addMoney, &kAccount, 1000));
	}
	for (int i = 0; i < v_thread.size(); i++)
	{
		v_thread.at(i).join();
	}
	return kAccount.getMoney();
}





int main()
{

	int value = 0;
	for (int k = 0; k < 1000; k++)
	{
		if ((value =TestMyMoney(5)) != 5000)
		{
			std::cout << "Error at count = " << k << "  Money in Wallet = " << value << std::endl;
			//break;
		}
	}
	system("pause");
	return 0;

}
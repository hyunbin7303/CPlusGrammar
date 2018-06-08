// File       : VectorSortingDifferentWay.cpp
// Programmer : Kevin Park
// Date       : 2017 / 7 / 25
// Description: When user excute this program, it automatically sorted by name(default setting).
//              Secondly, it shows sorting-by-damage, and then it shows sorted by HP.
//              I made this file to understand ostream and sorting properly. 



#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;
class LeagueChamp
{
private:
	string champName;
	int champDamage;
	int champHp;
public:

  
  // Constructor 
	LeagueChamp(string champName, int champDamage, int champHp) : champName(champName), champDamage(champDamage), champHp(champHp){}

  // Accessor
	string getName() { return champName; }
	int getDamage() { return champDamage; }
	int getHp() { return champHp; }

  // Default sorting by name
	bool operator < (const LeagueChamp& league)const
	{
		return champName < league.champName;
	}
	
	

	friend ostream& operator <<(ostream& os, const LeagueChamp& league);
};

ostream& operator << (ostream& out, const LeagueChamp& league)
{
	out << league.champName << "--- " << league.champDamage << "--- " << league.champHp;
	return out;
}

// Function : CompareDamage
// Purpose  : This function sort by damage of all league champions.
bool CompareDamage(LeagueChamp& l, LeagueChamp& r)
{
	return l.getDamage() < r.getDamage();
}
bool CompareHp(LeagueChamp& l, LeagueChamp& r)
{
	return l.getHp() < r.getHp();
}

template <typename Iter>
void print(Iter begin, Iter end)
{
	while (begin != end)
	{
		cout << "[ " << *begin << "] " << endl;
		begin++;
	}
}


int main()
{
	vector<LeagueChamp> vec;
	vec.push_back(LeagueChamp("kevin", 40, 51));
	vec.push_back(LeagueChamp("rammus", 20, 52));
	vec.push_back(LeagueChamp("lulu", 30, 53));
	vec.push_back(LeagueChamp("kyle", 45, 54));
	vec.push_back(LeagueChamp("garen", 55, 55));
	vec.push_back(LeagueChamp("nami", 56, 56));
	vec.push_back(LeagueChamp("ahri", 46, 57));

	// default Sorting
	sort(vec.begin(), vec.end());
	print(vec.begin(), vec.end());
	cout << endl << endl;


	//Sorted by Damage of champion
	sort(vec.begin(), vec.end(), CompareDamage);
	print(vec.begin(), vec.end());
	cout << endl << endl;


	// Sorted by Hp of champion
	sort(vec.begin(), vec.end(), CompareHp);
	print(vec.begin(), vec.end());
	cout << endl << endl;

	
	return 0;
}

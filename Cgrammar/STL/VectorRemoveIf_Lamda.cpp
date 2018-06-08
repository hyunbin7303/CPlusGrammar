// File       : VectorRemoveIf_Lamda.cpp
// Programmer : Kevin Park
// Date       : 2017 / 7 / 25
// Description: Erasing information in the vector container.
//              There are several different ways of doing this. 




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


	LeagueChamp() {}; // Default Constructor
	LeagueChamp(string champName, int champDamage, int champHp) : champName(champName), champDamage(champDamage), champHp(champHp){}

	bool operator < (const LeagueChamp& league)const
	{
		return champName < league.champName;
	}
	friend ostream& operator <<(ostream& os, const LeagueChamp& league);
	
	string getName() { return champName; }
	int getDamage() { return champDamage; }
	int getHp() { return champHp; }

};

ostream& operator << (ostream& out, const LeagueChamp& league)
{
	out << league.champName << "--- " << league.champDamage << "--- " << league.champHp;
	return out;
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


bool DamageBiggerThan(LeagueChamp & o)
{
	return (o.getDamage() > 45);
}

struct DamageBigger
{
	bool operator()(LeagueChamp & a)
	{
		return (a.getDamage() > 45);
	}
};



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
	vector<LeagueChamp> vec2, vec3;
	vec2 = vec;
	vec3 = vec;
  
	// default Sorting
	sort(vec.begin(), vec.end());
	print(vec.begin(), vec.end());
	cout << endl << endl;


	vec.erase(remove_if(vec.begin(), vec.end(), DamageBigger()), vec.end());
	//vec.erase(remove_if(vec.begin(), vec.end(), DamageBiggerThan), vec.end());
	print(vec.begin(), vec.end());
	cout << endl << endl;


	// Using LamDa Expression.
	vec2.erase(remove_if(vec2.begin(), vec2.end(), [](LeagueChamp & o)->bool {return (o.getDamage() > 45); }), vec2.end());
	print(vec2.begin(), vec2.end());
	cout << endl << endl;


	// using Lamda Expression effectively.
	int maximum2 = 0;
	vec3.erase(remove_if(vec3.begin(), vec3.end(), [&maximum2](LeagueChamp & o) 
	{
		if (maximum2 >= 2) return false;
		else if (o.getDamage() > 45)
		{
			maximum2++;
			return true;
		}
		return false;

	}), vec3.end());
	print(vec3.begin(), vec3.end());
	return 0;
}

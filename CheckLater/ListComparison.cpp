

#include <iostream>
#include <list>
#include <string>
#include <cctype>

bool compare_nocase(const std::string& first, const std::string& second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i]))
		{
			return true;
		}
		else if (tolower(first[i]) > tolower(second[i]))
		{
			return false;
		}
		++i;
	}
	return (first.length() < second.length());
}

int main(void)
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back("bne");
	mylist.push_back("awo");
	mylist.push_back("chree");

	mylist.sort();

	std::cout << "mylist contains: ";
	for (it = mylist.begin(); it != mylist.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
	mylist.sort(compare_nocase);
	std::cout << "mylist contains: ";

	for (it = mylist.begin(); it != mylist.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
	return 0;
}
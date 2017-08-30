

#include <iostream>
#include <vector>
template <typename _T>
class babo
{
public:
	void Draw(void)
	{
		std::cout << sizeof(p) << "of capacity class  " << std::endl;
	}
private:
	_T *p;
public:

	typename _T::iterator muhaha;
};



int main()
{
	babo<std::vector<int>> Test;
	Test.Draw();
	return 0;
}

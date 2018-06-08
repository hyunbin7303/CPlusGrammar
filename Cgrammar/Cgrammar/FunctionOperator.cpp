
#include <iostream>
using namespace std;
class MyScore
{
private:
	int math;
	int english; 
public:
	// Required constructor
	MyScore() // Default constructor 
	{
		math = 0;
		english = 0;
	}
	MyScore(int Math, int Eng)
	{
		if (Math == 0 && Eng == 0)
		{
			cout << "Score is 0 due to the fact that user didn't take test. " << endl;
		}
		english = Eng;
		math = Math;
	}


	// Overload function call
	MyScore operator()(int MidExam, int FinalExam, int Extra)
	{
		MyScore MathTotal;
		MathTotal.math = (MidExam + FinalExam + Extra) / 3;
		return MathTotal;
	}
	MyScore operator()(int MidExam, int FinalExam, int Extra, int Communication)
	{
		MyScore EngTotal;
		EngTotal.english = (MidExam + FinalExam + Extra + Communication) / 4;
		return EngTotal;
	}

	// method to display distance 
	void showEng()
	{
		cout <<"English : " << english << endl;
	}
	void showMath()
	{
		cout << "Math : " << math << endl;
	}
};


int main()
{
	MyScore OverallScore(60, 60), mathScore, engScore;

	mathScore = OverallScore(70, 80, 90);
	cout << "Math Total Average : " << endl;
	mathScore.showMath();
	
	engScore = OverallScore(80, 90, 50, 30);
	cout << "English Total Average : " << endl;
	engScore.showEng();


	return 0;
}



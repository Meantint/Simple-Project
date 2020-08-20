#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

class BullsAndCows {
private:
	int answerNumber[3];
	int ball[3];	// inputNumberÀÇ °¢ ÀÚ¸´¼ö
	int myInning = 0;
	int inputNumber = 0;
	int resultInning[9][3] = { 0 }; // column 0 idx : count strike, 
					// column 1 idx : count ball
	bool isEnd = false;

	void Start();
	void PrintInning();
	void InputNumber();
	bool IsCorrectNumber();
	bool CheckNumber();
	bool AskRestart();
	bool CheckInning();
public:
	BullsAndCows();
	~BullsAndCows();
	bool StartClass();
};
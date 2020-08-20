#include "bulls_and_cows.h"

BullsAndCows::BullsAndCows() {
	// answerNumber 결정
	srand((unsigned int)time(NULL));

	ball[0] = rand() % 9 + 1;

	ball[1] = rand() % 9 + 1;
	while (ball[0] == ball[1]) {
		ball[1] = rand() % 9 + 1;
	}

	ball[2] = rand() % 9 + 1;
	while (ball[2] == ball[0] || ball[2] == ball[1]) {
		ball[2] = rand() % 9 + 1;
	}

	for (int i = 0; i < 3; ++i) {
		answerNumber[i] = ball[i];
	}
}

BullsAndCows::~BullsAndCows() {
	cout << "Call Destructor\n";
}

void BullsAndCows::Start() {
	cout << "숫자 야구를 시작하겠습니다!" << "\n\n";
}

void BullsAndCows::PrintInning() {
	/*
	for (int i = 0; i < myInning; ++i) {
		if (resultInning[i][0] == 3) {
			cout << "Homerun!!! "
				<< "정답입니다!\n";
			return;
		}
		else
			cout << i + 1 << "회 --> "
			<< resultInning[i][2] << ','
			<< resultInning[i][0] << " 스트라이크, "
			<< resultInning[i][1] << " 볼\n\n";
	}
	*/
	for (int i = 0; i < myInning; ++i) {
		cout << i + 1 << "회 --> "
			<< resultInning[i][2] << ','
			<< resultInning[i][0] << " 스트라이크, "
			<< resultInning[i][1] << " 볼\n\n";
		if (resultInning[i][0] == 3) {
			cout << "Homerun!!! "
				<< "정답입니다!\n";
			return;
		}
	}
}

void BullsAndCows::InputNumber() {
	cout << "숫자를 입력하세요 : ";
	cin >> inputNumber;
	while (!IsCorrectNumber()) {
		cout << inputNumber << "는 잘못된 숫자입니다.\n"
			<< "다시 입력하세요 : ";
		cin >> inputNumber;
	}
}

bool BullsAndCows::IsCorrectNumber() {
	int number = inputNumber;
	if (number < 100 || number > 999) return false;

	ball[2] = number % 10;
	number /= 10;

	ball[1] = number % 10;
	if (ball[1] == ball[2])	return false;
	number /= 10;

	ball[0] = number % 10;
	if (ball[0] == ball[1] || ball[0] == ball[2]) return false;

	return true;
}

bool BullsAndCows::CheckNumber() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (ball[i] == answerNumber[j]) {
				if (i == j) {
					++resultInning[myInning][0];
				}
				else
					++resultInning[myInning][1];
				break;
			}
		}
	}
	resultInning[myInning][2] = inputNumber;
	++myInning;

	if (resultInning[myInning - 1][0] == 3) return true;
	return false;
}

bool BullsAndCows::AskRestart() {
	string restart = "";
	cout << "게임을 한 번 더 하시겠습니까? (Yes/No) : ";
	cin >> restart;
	if (restart == "Yes" || restart == "yes") {
		cout << "게임을 다시 시작합니다.\n\n";
		system("cls");
		return true;
	}
	else if (restart == "No" || restart == "no") {
		cout << "게임을 종료합니다......\n\n";
		return false;
	}
	else {
		cout << "알 수 없는 입력으로 인하여 게임을 종료합니다.\n\n";
		return false;
	}
}

bool BullsAndCows::CheckInning() {
	if (myInning == 9) {
		cout << "모든 이닝이 종료되었습니다.\n";
		cout << "정답은 "
			<< answerNumber[0] * 100 + answerNumber[1] * 10 + answerNumber[2] << "였습니다!\n";
		return false;
	}
	return true;
}

bool BullsAndCows::StartClass() {
	bool isHomerun = false;
	Start();
	Sleep(5000);
	while (!isHomerun) {
		InputNumber(); system("cls");
		isHomerun = CheckNumber();
		PrintInning();
		if (CheckInning() == false) break;
	}
	return AskRestart();
}
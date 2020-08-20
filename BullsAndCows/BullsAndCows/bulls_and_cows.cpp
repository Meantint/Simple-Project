#include "bulls_and_cows.h"

BullsAndCows::BullsAndCows() {
	// answerNumber ����
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
	cout << "���� �߱��� �����ϰڽ��ϴ�!" << "\n\n";
}

void BullsAndCows::PrintInning() {
	/*
	for (int i = 0; i < myInning; ++i) {
		if (resultInning[i][0] == 3) {
			cout << "Homerun!!! "
				<< "�����Դϴ�!\n";
			return;
		}
		else
			cout << i + 1 << "ȸ --> "
			<< resultInning[i][2] << ','
			<< resultInning[i][0] << " ��Ʈ����ũ, "
			<< resultInning[i][1] << " ��\n\n";
	}
	*/
	for (int i = 0; i < myInning; ++i) {
		cout << i + 1 << "ȸ --> "
			<< resultInning[i][2] << ','
			<< resultInning[i][0] << " ��Ʈ����ũ, "
			<< resultInning[i][1] << " ��\n\n";
		if (resultInning[i][0] == 3) {
			cout << "Homerun!!! "
				<< "�����Դϴ�!\n";
			return;
		}
	}
}

void BullsAndCows::InputNumber() {
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> inputNumber;
	while (!IsCorrectNumber()) {
		cout << inputNumber << "�� �߸��� �����Դϴ�.\n"
			<< "�ٽ� �Է��ϼ��� : ";
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
	cout << "������ �� �� �� �Ͻðڽ��ϱ�? (Yes/No) : ";
	cin >> restart;
	if (restart == "Yes" || restart == "yes") {
		cout << "������ �ٽ� �����մϴ�.\n\n";
		system("cls");
		return true;
	}
	else if (restart == "No" || restart == "no") {
		cout << "������ �����մϴ�......\n\n";
		return false;
	}
	else {
		cout << "�� �� ���� �Է����� ���Ͽ� ������ �����մϴ�.\n\n";
		return false;
	}
}

bool BullsAndCows::CheckInning() {
	if (myInning == 9) {
		cout << "��� �̴��� ����Ǿ����ϴ�.\n";
		cout << "������ "
			<< answerNumber[0] * 100 + answerNumber[1] * 10 + answerNumber[2] << "�����ϴ�!\n";
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
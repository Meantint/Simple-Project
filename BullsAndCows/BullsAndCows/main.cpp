#include "bulls_and_cows.h"

int main()
{
	bool isRestart = true;

	while (isRestart) {
		BullsAndCows bac;
		isRestart = bac.StartClass();
	}

	return 0;
}
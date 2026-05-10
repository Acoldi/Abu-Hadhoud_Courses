#include "clsDate.h"
int main() {
	clsDate date = clsDate("10/10/2020");

	date.AddDaysToDate(30);

	date.PrintDate();

}
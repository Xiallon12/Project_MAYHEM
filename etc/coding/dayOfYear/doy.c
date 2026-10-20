

int day_of_year(int day, int month, int year) {
	int dayNum = 0;
	int monthSize[] = {31, year%4==0?29:28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 0; i < month-1; i++)
		dayNum += monthSize[i];
	dayNum += day;
	return dayNum;
}

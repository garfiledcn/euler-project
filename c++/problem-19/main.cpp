#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				return true;
			else 
				return false;
		} else {
			return true;
		}
	}
	return false;
}


int sumDay(int y, int m, int d) {
	int mds[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (isLeapYear(y))
	    mds[1] = 29;
	    
	assert(y >= 1900);
	assert(m>=1 && m<=12);
	assert(d>=1 && d<=mds[m-1]);
	
	int sumd = 0;
	
	for (int year = 1900; year < y; ++ year) {
		if (isLeapYear(year))
			sumd += 366;
		else 
			sumd += 365;
	}
	for (int month = 1; month < m; ++month) {
		sumd += mds[month-1];
	}
	sumd += d;
	
	return sumd;
}

int main(int argc, char** argv) {
	int sumSanday = 0;
	for (int i = 1901; i<= 2000; ++i) {	
		for (int j = 1; j <= 12; ++j) {
			int d = sumDay(i, j, 1);
			if (d%7 == 0)
				sumSanday ++;
		}
	}
	printf("%d sandays\n", sumSanday);
	return 0;
}

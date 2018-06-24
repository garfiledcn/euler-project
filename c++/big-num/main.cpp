#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool isDigital(char* str, int* num) {
	if (str) {
		int len = strlen(str);
		for (int i=0; i<len; ++i) {
			if (str[i]>='0' && str[i]<='9') {
				num[i] = str[i] - '0';
			} else {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

const int MAX_NUM_LEN = 1024;

char bnl [MAX_NUM_LEN] = {0};
char bnr [MAX_NUM_LEN] = {0};

int num1[MAX_NUM_LEN] = {0};
int num2[MAX_NUM_LEN] = {0};
int result[MAX_NUM_LEN*2] = {0};

int getDigital(int &ll, int &lr) {
	FILE* fp = fopen("./digitalnum", "r");
	if (fp) {
		fgets(bnl, MAX_NUM_LEN, fp);
		fgets(bnr, MAX_NUM_LEN, fp);
		
		char* s = strstr(bnl, "\n");
		if (s) {
			*s='\0';
		}
		s = strstr(bnr, "\n");
		if (s) {
			*s = '\0';
		}
		printf("get numl:%s numr:%s\n", bnl, bnr);
		ll = strlen(bnl);
		lr = strlen(bnr);
		
		if (isDigital(bnl, num1) && isDigital(bnr, num2)) {
			return 0;
		} else {
			return EINVAL;
		}
	} else {
		return ENOENT;
	}
}
int main(int argc, char** argv) {
	int ll, lr;
	if (getDigital(ll, lr)) {
		printf("get digital num failed, just return\n");
	}
	
	printf("ll=%d lr=%d\n", ll, lr);
	for (int i=0; i<ll; ++i) {
		for (int j=0; j<lr; ++j) {
			result[i+j+1] += num1[i]*num2[j];
		}
	}
	for (int i=0; i<ll+lr; ++i) {
		printf("%d", result[i]);
	}
	printf("\n");
	for (int i=ll+lr-1; i>0; --i) {
		result[i-1] += result[i]/10;
		result[i] = result[i]%10;
	}
	for (int i=0; i<ll+lr; ++i) {
		printf("%d", result[i]);
	}
	
	return 0;
}

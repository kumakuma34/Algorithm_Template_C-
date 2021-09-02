#include <stdio.h>
#include <iostream>

using namespace std;

int atoi(char* cstr) {
	int sign = 1, data = 0;

	if (*cstr == '-') {
		sign = -1;
		cstr++;
	}
	while (*cstr) {
		if(*cstr >= '0' && *cstr <= '9')
			data = data * 10 + *cstr - '0';
		cstr++;
	}

	return data * sign;
}

void itoa(int num, char* str) {
	int len = 0;
	if (num >0) {
		while (num) {
			str[len++] = num % 10 + '0';
			num /= 10;
		}
		str[len] = '\0';

		for (int i = 0; i < len / 2; i++) {
			swap(str[i], str[len - 1 - i]);
		}
	}
	else if (num == 0) {
		str[len++] = '0';
		str[len] = '\0';
	}
	else {
		num *= -1;
		while (num) {
			str[len++] = num % 10 + '0';
			num /= 10;
		}
		str[len] = '\0';
		for (int i = 0; i < len / 2; i++) {
			swap(str[i], str[len -  i -1]);
		}
		char* tmp = new char[100];
		for (int i = 0; i < len; i++)
			tmp[i] = str[i];
		str[0] = '-';
		str[len + 1] = '\0';
		for (int i = 0; i <len; i++)
			str[i+1] = tmp[i];
	}
	
}
int main() {
	char* cstr = new char[100];
	char* cstr1 = new char[100];
	int number;

	printf("%s\n", "������ ��ȯ�� ���ڿ��� �Է��ϼ���");
	scanf("%s", cstr, 100);
	printf("%d\n", atoi(cstr));
	printf("%s\n", "���ڿ��� ��ȯ�� ������ �Է��ϼ���");
	scanf("%d", &number);
	itoa(number, cstr1);
	printf("%s\n", cstr1);
}
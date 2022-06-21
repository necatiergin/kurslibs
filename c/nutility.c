#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static int icmp(const void* vp1, const void* vp2)
{
	return *(const int*)vp1 - *(const int*)vp2;
}
//--------------------------------------------------
//--------------------------------------------------
int isprime(int val)
{
	if (val == 0 || val == 1)
		return 0;

	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return 0;

	return 1;
}
//--------------------------------------------------
//--------------------------------------------------
int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val) {
		++digit_count;
		val /= 10;
	}

	return digit_count;
}
//--------------------------------------------------
//--------------------------------------------------
void delay(double sec)
{
	clock_t start = clock();

	while (((double)clock() - start) / CLOCKS_PER_SEC < sec)
		;
}
//--------------------------------------------------
//--------------------------------------------------
void sl()
{
	printf("\n*******************************************************************************\n");
}
//--------------------------------------------------
//--------------------------------------------------
void randomize(void)
{
	srand((unsigned)time(0));
}
//--------------------------------------------------
//--------------------------------------------------
char* sgets(char* p)
{
	char* ptr = p;
	int c;

	while ((c = getchar()) != '\n') {
		*p++ = (char)c;
	}

	*p = '\0';

	return ptr;
}
//--------------------------------------------------
//--------------------------------------------------
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
//--------------------------------------------------
//--------------------------------------------------
void print_array(const int* ptr, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		if (i && i % 20 == 0) {
			printf("\n");
		}
		printf("%3d ", ptr[i]);
	}
	sl();
}
//--------------------------------------------------
//--------------------------------------------------
void set_random_array(int* ptr, size_t size)
{
	while (size--) {
		*ptr = rand() % 1000;
		++ptr;
	}
}
//--------------------------------------------------
//--------------------------------------------------
void bubble_sort(int* p, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t k = 0; k < size - 1 - i; ++k) {
			if (p[k] > p[k + 1])
				swap(p + k, p + k + 1);
		}
	}
}
//--------------------------------------------------
//--------------------------------------------------
void quicksort(int* p, size_t size)
{
	qsort(p, size, sizeof(int), &icmp);
}
//--------------------------------------------------
//--------------------------------------------------
int* search_array(const int* p, size_t size, int key)
{
	while (size--) {
		if (*p == key)
			return (int*)p;
		++p;
	}

	return NULL;
}
//--------------------------------------------------
//--------------------------------------------------
void gswap(void* vp1, void* vp2, size_t n)
{
	char* p1 = (char*)vp1;
	char* p2 = (char*)vp2;

	while (n--) {
		char temp = *p1;
		*p1++ = *p2;
		*p2++ = temp;
	}
}
//--------------------------------------------------
//--------------------------------------------------
int day_of_the_week(int d, int m, int y)
{
	static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

	if (m < 3)
		y -= 1;

	return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}
//--------------------------------------------------
//--------------------------------------------------
void bprint(int val)
{
	static char str[40];

	_itoa(val, str, 2);
	printf("%032s\n", str);
}
//--------------------------------------------------
//--------------------------------------------------
void print_binary(int val)
{
	unsigned int mask = ~(~0u >> 1);
	while (mask) {
		putchar(mask & val ? '1' : '0');
		mask >>= 1;
	}
	putchar('\n');
}

#ifndef  NUTILITY_INCLUDED
#define  NUTILITY_INCLUDED

#include <stddef.h>

#define   isleap(y)				((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define   asize(a)				(sizeof(a) / sizeof(a[0]))
#define   random_elem(a)		(a[rand() % asize(a)])
#define   clear_s(x)			(memset(&x, 0, sizeof(x)))

int isprime(int);
int ndigit(int);
int  day_of_the_week(int d, int m, int y);
void delay(double sec);
void sl(void);
void randomize(void);
char* sgets(char* p);
void swap(int* p1, int* p2);
void print_array(const int* ptr, size_t size);
void set_random_array(int* ptr, size_t size);
void bubble_sort(int* p, size_t size);
void quicksort(int* p, size_t size);
int* search_array(const int* p, size_t size, int key);
void gswap(void* vp1, void* vp2, size_t n);
void bprint(int);
void print_binary(int);

#endif

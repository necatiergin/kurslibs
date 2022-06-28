#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define   PRIVATE				static
#define   PUBLIC
#define   YEARBASE				1900
#define   RANDOM_YEAR_MIN		1940
#define   RANDOM_YEAR_MAX		2021

#define   isleap(y)				 ((y) % 4 == 0 && ((y) % 100 || y % 400 == 0))
#define   mon_days(y, m)		 (daytabs[isleap(y)][m])

PRIVATE const int daytabs[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

PRIVATE int is_valid_date(int d, int m, int y);
PRIVATE Date* set(Date *p, int d, int m, int y);
PRIVATE int	day_of_week(int d, int m, int y);
PRIVATE int totaldays(const Date* p);
PRIVATE Date* to_date(Date* p, int tdays);

// PUBLC FUNCTION DEFINITIONS

PUBLIC Date* set_date(Date* p, int d, int m, int y)
{
	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* set_date_today(Date* p)
{
	time_t timer;
	time(&timer);
	struct tm* tptr = localtime(&timer);
	
	return set(p, tptr->tm_mday, tptr->tm_mon + 1, tptr->tm_year + 1900);	
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* set_date_str(Date* p, const char* pstr)
{
	int d = atoi(pstr);
	int m = atoi(pstr + 3);
	int y = atoi(pstr + 6);

	return set(p, d, m, y);
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* set_date_random(Date* p)
{
	int y = rand() % (RANDOM_YEAR_MAX - RANDOM_YEAR_MIN + 1) + RANDOM_YEAR_MIN;
	int m = rand() % 12 + 1;
	int d = rand() % mon_days(y, m) + 1;

	return set(p, d, m, y);
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC Date* set_month_day(Date* p, int mday)
{
	return set(p, mday, p->m_m, p->m_y);
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* set_month(Date* p, int mon)
{
	return set(p, p->m_d, mon, p->m_y);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PUBLIC  Date* set_year(Date* p, int year)
{
	return set(p, p->m_d, p->m_m, year);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC int get_week_day(const Date* p)
{
	return day_of_week(p->m_d, p->m_m, p->m_y);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC int cmp_date(const Date* pa, const Date* pb)
{
	if (pa->m_y != pb->m_y)
		return pa->m_y - pb->m_y;

	if (pa->m_m != pb->m_m)
		return pa->m_m - pb->m_m;

	return pa->m_d - pb->m_d;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PUBLIC void print_date(const Date* p)
{
	static const char* const pmons[] = {
	"",
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};
	static const char* const pdays[] = {
	"Pazar",
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
	};

	printf("%02d %s %d %s\n", p->m_d, pmons[p->m_m], p->m_y, pdays[get_week_day(p)]);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PUBLIC Date* scan_date(Date* p)
{
	int day, mon, year;
	int retval = scanf("%d%d%d", &day, &mon, &year);
	if (retval != 3) {
		fprintf(stderr, "giris isleminde hata\n");
		exit(EXIT_FAILURE);
	}

	return set(p, day, mon, year);
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC int get_year(const Date* p)
{
	return p->m_y;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PUBLIC int get_month(const Date* p)
{
	return p->m_m;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC int get_month_day(const Date* p)
{
	return p->m_d;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PUBLIC int get_year_day(const Date* p)
{
	int sum = p->m_d;

	for (int i = 1; i < p->m_m; ++i) {
		sum += mon_days(p->m_y, i);
	}

	return sum;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PUBLIC int date_diff(const Date* p1, const Date* p2)
{
	return abs(totaldays(p1) - totaldays(p2));
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC Date* ndays_date(Date* pdest, const Date* psource, int n)
{
	return to_date(pdest, totaldays(psource) + n);
}

//PRIVATE FUNCTIONS

PRIVATE int is_valid_date(int d, int m, int y)
{
	return y >= YEARBASE && m > 0 && m <= 12 && d > 0 && d <= mon_days(y, m);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PRIVATE Date* set(Date* p, int d, int m, int y)
{
	if (!is_valid_date(d, m, y)) {
		fprintf(stderr, "gecersiz tarih olustu!\n");
		exit(EXIT_FAILURE);
	}

	p->m_d = d;
	p->m_m = m;
	p->m_y = y;

	return p;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PRIVATE int	day_of_week(int d, int m, int y)
{
	return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PRIVATE int totaldays(const Date* p)
{
	int sum = get_year_day(p);

	for (int i = YEARBASE; i < p->m_y; ++i) {
		sum += isleap(i) ? 366 : 365;
	}

	return sum;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


PRIVATE Date* to_date(Date* p, int totaldays)
{
	int y = YEARBASE;

	while (totaldays > (isleap(y) ? 366 : 365)) {
		totaldays -= isleap(y) ? 366 : 365;
		++y;
	}
	int m = 1;

	while (totaldays > mon_days(y, m)) {
		totaldays -= mon_days(y, m);
		++m;
	}

	int d = totaldays;

	return set(p, d, m, y);
}

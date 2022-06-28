#ifndef DATE_H
#define DATE_H

typedef struct {
	int m_d, m_m, m_y;
}Date;


Date* set_date(Date* p, int d, int m, int y);
Date* set_date_today(Date* pdate);
Date* set_date_str(Date* pdate, const char *pstr);
Date* set_date_random(Date* pdate);
Date* set_month(Date* pdate, int mon);
Date* set_year(Date* p, int y);
Date* set_month_day(Date* p, int mday);

//get functions - getters - accessors
int get_year(const Date* p);
int get_month(const Date* pdate);
int get_month_day(const Date* pdate);
int get_week_day(const Date* pdate); //0 pazar 1 pazartesi ...
int get_year_day(const Date* pdate);


//input-output function
void print_date(const Date* p);
Date* scan_date(Date* p);

//utility functions
int cmp_date(const Date*, const Date *);
int date_diff(const Date* p, const Date*);
Date* ndays_date(Date* pdest, const Date* psource, int n);

#endif

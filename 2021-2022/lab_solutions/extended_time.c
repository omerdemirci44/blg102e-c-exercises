// extended_time.c
// Week 12 — ExtendedTime with Date+Time structs, dynamic allocation, add/sub operations.
// Comments in English.

#include <stdio.h>
#include <stdlib.h>

typedef struct { int hour, minute, second; } Time;
typedef struct { int year, month, day; } Date;

typedef struct {
    Date *date;
    Time *time;
} ExtendedTime;

static Time* make_time(int h,int m,int s){ Time* t=(Time*)malloc(sizeof(Time)); t->hour=h; t->minute=m; t->second=s; return t; }
static Date* make_date(int y,int m,int d){ Date* t=(Date*)malloc(sizeof(Date)); t->year=y; t->month=m; t->day=d; return t; }
static ExtendedTime* make_extended(int y,int m,int d,int h,int mi,int s){
    ExtendedTime* e=(ExtendedTime*)malloc(sizeof(ExtendedTime));
    e->date=make_date(y,m,d); e->time=make_time(h,mi,s); return e;
}

static void normalize_time(Time* t){
    // normalize seconds and minutes, keep hours in [0..23], naive day carry returned as int
    int carry = 0;
    if (t->second >= 60) { carry = t->second/60; t->second %= 60; t->minute += carry; }
    if (t->second < 0) { int b = (-t->second+59)/60; t->second += 60*b; t->minute -= b; }
    carry = 0;
    if (t->minute >= 60) { carry = t->minute/60; t->minute %= 60; t->hour += carry; }
    if (t->minute < 0) { int b = (-t->minute+59)/60; t->minute += 60*b; t->hour -= b; }
    if (t->hour >= 24) { t->hour %= 24; /* day carry ignored for simplicity */ }
    if (t->hour < 0) { int b = (-t->hour+23)/24; t->hour += 24*b; /* day borrow ignored */ }
}

static void print_extended(const ExtendedTime* e){
    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
        e->date->year, e->date->month, e->date->day,
        e->time->hour, e->time->minute, e->time->second);
}

static ExtendedTime* add_time(const ExtendedTime* a,const Time* dt){
    ExtendedTime* r=make_extended(a->date->year,a->date->month,a->date->day,
                                  a->time->hour,a->time->minute,a->time->second);
    r->time->hour+=dt->hour; r->time->minute+=dt->minute; r->time->second+=dt->second;
    normalize_time(r->time);
    return r;
}

// For brevity, date addition is naive (no month-length, leap-year handling). Demonstrative only.
static void normalize_date(Date* d){
    while (d->day > 30) { d->day -= 30; d->month++; }
    while (d->day <= 0) { d->day += 30; d->month--; }
    while (d->month > 12) { d->month -= 12; d->year++; }
    while (d->month <= 0) { d->month += 12; d->year--; }
}

static ExtendedTime* add_date(const ExtendedTime* a,const Date* dd){
    ExtendedTime* r=make_extended(a->date->year,a->date->month,a->date->day,
                                  a->time->hour,a->time->minute,a->time->second);
    r->date->year += dd->year; r->date->month += dd->month; r->date->day += dd->day;
    normalize_date(r->date);
    return r;
}

int main(void){
    // Example I/O: 
    // y m d  h m s   then delta time (h m s) and delta date (y m d)
    int y,m,d,hh,mm,ss; if (scanf("%d %d %d %d %d %d",&y,&m,&d,&hh,&mm,&ss)!=6) return 0;
    int dh,dm,ds; if (scanf("%d %d %d",&dh,&dm,&ds)!=3) return 0;
    int dy,dmn,dd; if (scanf("%d %d %d",&dy,&dmn,&dd)!=3) return 0;

    ExtendedTime* t = make_extended(y,m,d,hh,mm,ss);
    Time dt = {dh,dm,ds}; Date ddv = {dy,dmn,dd};

    ExtendedTime* t_plus_time = add_time(t,&dt);
    ExtendedTime* t_plus_date = add_date(t,&ddv);

    print_extended(t);
    print_extended(t_plus_time);
    print_extended(t_plus_date);

    free(t->time); free(t->date); free(t);
    free(t_plus_time->time); free(t_plus_time->date); free(t_plus_time);
    free(t_plus_date->time); free(t_plus_date->date); free(t_plus_date);
    return 0;
}

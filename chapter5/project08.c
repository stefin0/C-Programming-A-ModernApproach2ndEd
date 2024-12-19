/*
The following table shows the daily flights from one city to another:
Departure time  Arrival time
8:00 a.m.       10:16 a.m.
9:43 a.m.       11:52 a.m.
11:19 a.m.      1:31 p.m.
12:47 p.m.      3:00 p.m.
2:00 p.ra.      4:08 p.m.
3:45 p.m.       5:55 p.m.
7:00 p.m.       9:20 p.m.
9:45 p.m.       11:58 p.m.
Write a program that asks user to enter a time (expressed in hours and minutes,
using the 24-hour clock). The program then displays the departure and arrival
times for the flight whose departure time is closest to that entered by the
user:
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int hour, min;

  printf("Departure time\tArrival\n");
  printf("8:00 am\t\t10:15 am\n");
  printf("9:43 am\t\t11:52 am\n");
  printf("11:19 am\t1:31 pm\n");
  printf("12:47 pm\t3:00 pm\n");
  printf("2:00 pm\t\t4:08 pm\n");
  printf("3:45 pm\t\t5:55 pm\n");
  printf("7:00 pm\t\t9:20 pm\n");
  printf("9:45 pm\t\t11:58 pm\n\n");

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);

  int minutes_since_midnight = hour * 60 + min;

  int _0800 = 8 * 60;
  int _0943 = 9 * 60 + 43;
  int _1119 = 11 * 60 + 19;
  int _1247 = 12 * 60 + 47;
  int _1400 = 14 * 60;
  int _1545 = 15 * 60 + 45;
  int _1900 = 19 * 60;
  int _2145 = 21 * 60 + 45;
  
  printf("Closest departure time is ");
  if (abs(_0800 - minutes_since_midnight) < abs(_0943 - minutes_since_midnight)) {
    printf("8:00 a.m., arriving at 10:16 a.m.\n");
  } else if (abs(_0943 - minutes_since_midnight) < abs(_1119 - minutes_since_midnight)) {
    printf("9:43 a.m., arriving at 11:52 a.m.\n");
  } else if (abs(_1119 - minutes_since_midnight) < abs(_1247 - minutes_since_midnight)) {
    printf("11:19 a.m., arriving at 1:31 p.m.\n");
  } else if (abs(_1247 - minutes_since_midnight) < abs(_1400 - minutes_since_midnight)) {
    printf("12:47 p.m., arriving at 3:00 p.m.\n");
  } else if (abs(_1400 - minutes_since_midnight) < abs(_1545 - minutes_since_midnight)) {
    printf("2:00 p.m., arriving at 4:08 p.m.\n");
  } else if (abs(_1545 - minutes_since_midnight) < abs(_1900 - minutes_since_midnight)) {
    printf("3:45 p.m., arriving at 5:55 p.m.\n");
  } else if (abs(_1900 - minutes_since_midnight) < abs(_2145 - minutes_since_midnight)) {
    printf("7:00 p.m., arriving at 9:20 p.m.\n");
  } else {
    printf("9:45 p.m., arriving at 11:58 p.m.\n");
  }
  
  return 0;
}

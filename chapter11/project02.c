/*
2. Modify Programming Project 8 from Chapter 5 so that it includes the following
function:
void find_closest_flight(int desired_time, int *departure_time, int
*arrival_time);
This function will find the flight whose departure time is
closest to desired time (expressed in minutes since midnight). It will store the
departure and arrival times of this llight (also expressed in minutes since
midnight) in the variables pointed to by departure_time and arrival_time.
respectively.
*/
#include <stdio.h>
#include <stdlib.h>

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);

int main(void) {
  int hour, min;
  int departure_time, arrival_time;
  char meridiem_departure, meridiem_arrival;

  printf("Departure time\tArrival\n");
  printf("8:00 am\t\t10:16 am\n");
  printf("9:43 am\t\t11:52 am\n");
  printf("11:19 am\t1:31 pm\n");
  printf("12:47 pm\t3:00 pm\n");
  printf("2:00 pm\t\t4:08 pm\n");
  printf("3:45 pm\t\t5:55 pm\n");
  printf("7:00 pm\t\t9:20 pm\n");
  printf("9:45 pm\t\t11:58 pm\n\n");

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hour, &min);

  int desired_time = hour * 60 + min;

  find_closest_flight(desired_time, &departure_time, &arrival_time);

  if (departure_time >= 720) {
    meridiem_departure = 'p';
  } else {
    meridiem_departure = 'a';
  }

  if (arrival_time >= 720) {
    meridiem_arrival = 'p';
  } else {
    meridiem_arrival = 'a';
  }

  printf(
      "\nClosest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
      (departure_time / 60) % 12 == 0 ? 12 : (departure_time / 60) % 12,
      departure_time % 60, meridiem_departure,
      (arrival_time / 60) % 12 == 0 ? 12 : (arrival_time / 60) % 12,
      arrival_time % 60, meridiem_arrival);

  return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time) {
  int _0800 = 8 * 60;
  int _0943 = 9 * 60 + 43;
  int _1016 = 10 * 60 + 16;
  int _1119 = 11 * 60 + 19;
  int _1152 = 11 * 60 + 52;
  int _1247 = 12 * 60 + 47;
  int _1331 = 13 * 60 + 31;
  int _1400 = 14 * 60;
  int _1500 = 15 * 60;
  int _1545 = 15 * 60 + 45;
  int _1608 = 16 * 60 + 8;
  int _1755 = 17 * 60 + 55;
  int _1900 = 19 * 60;
  int _2120 = 21 * 60 + 20;
  int _2145 = 21 * 60 + 45;
  int _2358 = 23 * 60 + 58;

  if (abs(_0800 - desired_time) < abs(_0943 - desired_time)) {
    *departure_time = _0800;
    *arrival_time = _1016;
  } else if (abs(_0943 - desired_time) < abs(_1119 - desired_time)) {
    *departure_time = _0943;
    *arrival_time = _1152;
  } else if (abs(_1119 - desired_time) < abs(_1247 - desired_time)) {
    *departure_time = _1119;
    *arrival_time = _1331;
  } else if (abs(_1247 - desired_time) < abs(_1400 - desired_time)) {
    *departure_time = _1247;
    *arrival_time = _1500;
  } else if (abs(_1400 - desired_time) < abs(_1545 - desired_time)) {
    *departure_time = _1400;
    *arrival_time = _1608;
  } else if (abs(_1545 - desired_time) < abs(_1900 - desired_time)) {
    *departure_time = _1545;
    *arrival_time = _1755;
  } else if (abs(_1900 - desired_time) < abs(_2145 - desired_time)) {
    *departure_time = _1900;
    *arrival_time = _2120;
  } else {
    *departure_time = _2145;
    *arrival_time = _2358;
  }
}

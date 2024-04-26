#ifndef TIMECONVERT_H
#define TIMECONVERT_H

#include <stdio.h>
#include <time.h>

long getSecDuration(struct timespec beg_time, struct timespec end_time);

long getMillsecDuration(struct timespec beg_time, struct timespec end_time);

void durationOutput(struct timespec beg_time, struct timespec end_time);

#endif // TIMECONVERT_H
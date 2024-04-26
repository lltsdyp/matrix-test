#include "timeconvert.h"

long getSecDuration(struct timespec beg_time, struct timespec end_time)
{
    return end_time.tv_sec - beg_time.tv_sec;
}

long getMillsecDuration(struct timespec beg_time, struct timespec end_time)
{
    long sec_duration = getSecDuration(beg_time, end_time);
    long nsec_duration = end_time.tv_nsec - beg_time.tv_nsec;
    return sec_duration * 1000 + nsec_duration / 1000000;
}

void durationOutput(struct timespec beg_time, struct timespec end_time)
{
    printf("Time: %ld secs, %ld msecs\n", getSecDuration(beg_time, end_time), getMillsecDuration(beg_time, end_time));
}

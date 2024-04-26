/***************************************
 * Optimize: + Loop Reordering
 ***************************************
 * Optimize: + '-O2' option
 */
#include "matrix.h"
#include <stdio.h>
#include <time.h>
#include "timeconvert.h"

long long outputMatrix[SIZE][SIZE];

int main()
{
    struct timespec beg_time, end_time;
    clock_gettime(CLOCK_REALTIME, &beg_time);
    for (int i = 0; i < SIZE; ++i)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                outputMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printf("%lld %lld\n", outputMatrix[0][0], outputMatrix[1024][152]);
    clock_gettime(CLOCK_REALTIME, &end_time);
    durationOutput(beg_time, end_time);
    return 0;
}

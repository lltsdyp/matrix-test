/***************************
 * Optimize: Loop unrolling
 */

#include "matrix.h"
#include "timeconvert.h"
#include <stdio.h>
#include <time.h>

long long outputMatrix[SIZE][SIZE];

// Experimental
#define BLOCK_SIZE 128
#define BLOCK_NUM SIZE / BLOCK_SIZE

int main()
{
    struct timespec beg_time, end_time;
    clock_gettime(CLOCK_REALTIME, &beg_time);
    for (int i_base = 0; i_base < BLOCK_NUM; ++i_base)
        for (int j_base = 0; j_base < BLOCK_NUM; ++j_base)
            for (int k_base = 0; k_base < BLOCK_NUM; ++k_base)
                for (int i_offset = 0; i_offset < BLOCK_SIZE; ++i_offset)
                    for (int k_offset = 0; k_offset < BLOCK_SIZE; ++k_offset)
                        for (int j_offset = 0; j_offset < BLOCK_SIZE; j_offset += 4)
                        {
                            outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset] +=
                                matrixA[i_base * BLOCK_SIZE + i_offset][k_base * BLOCK_SIZE + k_offset] *
                                matrixB[k_base * BLOCK_SIZE + k_offset][j_base * BLOCK_SIZE + j_offset];
                            outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset + 1] +=
                                matrixA[i_base * BLOCK_SIZE + i_offset][k_base * BLOCK_SIZE + k_offset] *
                                matrixB[k_base * BLOCK_SIZE + k_offset][j_base * BLOCK_SIZE + j_offset + 1];
                            outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset + 2] +=
                                matrixA[i_base * BLOCK_SIZE + i_offset][k_base * BLOCK_SIZE + k_offset] *
                                matrixB[k_base * BLOCK_SIZE + k_offset][j_base * BLOCK_SIZE + j_offset + 2];
                            outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset + 3] +=
                                matrixA[i_base * BLOCK_SIZE + i_offset][k_base * BLOCK_SIZE + k_offset] *
                                matrixB[k_base * BLOCK_SIZE + k_offset][j_base * BLOCK_SIZE + j_offset + 3];
                        }
    printf("%lld %lld\n", outputMatrix[0][0], outputMatrix[1024][152]);
    clock_gettime(CLOCK_REALTIME, &end_time);
    durationOutput(beg_time, end_time);
    return 0;
}

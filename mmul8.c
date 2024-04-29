#include "matrix.h"
#include "timeconvert.h"
#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <immintrin.h>

long long outputMatrix[SIZE][SIZE];

#define BLOCK_SIZE 128
#define BLOCK_NUM SIZE / BLOCK_SIZE

int main()
{
    struct timespec beg_time, end_time;
    clock_gettime(CLOCK_REALTIME, &beg_time);
#pragma omp parallel for num_threads(4)
    for (int i_base = 0; i_base < BLOCK_NUM; ++i_base)
        for (int j_base = 0; j_base < BLOCK_NUM; ++j_base)
            for (int k_base = 0; k_base < BLOCK_NUM; ++k_base)
                for (int i_offset = 0; i_offset < BLOCK_SIZE; ++i_offset)
                    for (int k_offset = 0; k_offset < BLOCK_SIZE; ++k_offset)
                        for (int j_offset = 0; j_offset < BLOCK_SIZE; j_offset += 8)
                        {
                            __m256i vector_a = _mm256_set1_epi64x(matrixA[i_base * BLOCK_SIZE + i_offset][k_base * BLOCK_SIZE + k_offset]);
                            __m256i vector_b1 = _mm256_load_epi64((void *)&matrixB[k_base * BLOCK_SIZE + k_offset][j_base * BLOCK_SIZE + j_offset]),
                                    vector_b2 = _mm256_load_epi64((void *)&matrixB[k_base * BLOCK_SIZE + k_offset][j_base * BLOCK_SIZE + j_offset + 4]);
                            __m256i outputVector1 = _mm256_load_epi64((void *)&outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset]),
                                    outputVector2 = _mm256_load_epi64((void *)&outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset + 4]);
                            __m256i product1 = _mm256_mullo_epi64(vector_a, vector_b1),
                                    product2 = _mm256_mullo_epi64(vector_a, vector_b2);
                            outputVector1 = _mm256_add_epi64(outputVector1, product1);
                            outputVector2 = _mm256_add_epi64(outputVector2, product2);
                            _mm256_store_epi64((void *)&outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset], outputVector1);
                            _mm256_store_epi64((void *)&outputMatrix[i_base * BLOCK_SIZE + i_offset][j_base * BLOCK_SIZE + j_offset + 4], outputVector2);
                        }
    printf("%lld %lld\n", outputMatrix[0][0], outputMatrix[1024][152]);
    clock_gettime(CLOCK_REALTIME, &end_time);
    durationOutput(beg_time, end_time);
    return 0;
}

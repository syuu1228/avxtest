#include <immintrin.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int a[] __attribute__((aligned(32))) = {3, 4, 5, 6}; 
    int b[] __attribute__((aligned(32))) = {1, 2, 3, 4}; 
    __m128i a_; 
    __m128i b_; 
    __m128i z_; 
    int z[4];
    int i;

    a_ = _mm_set_epi32(a[0], a[1], a[2], a[3]);
    b_ = _mm_set_epi32(b[0], b[1], b[2], b[3]);
    z_ = _mm_add_epi32(a_, b_);

    z[3] = _mm_extract_epi32(z_, 0); 
    z[2] = _mm_extract_epi32(z_, 1); 
    z[1] = _mm_extract_epi32(z_, 2); 
    z[0] = _mm_extract_epi32(z_, 3); 

    for (i = 0; i < 4; i++) {
        printf("z[%i]: %i\n", i, z[3-i]);
    };  
    return 0;
}


/* This file is fully designed and created by Christopher Xu
 * See README at root directory for details
 */
 
#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define fp_t int
#define SHFT 14
#define FRACTION 1<<(SHFT)

#define INT_ADD(x, n) (x) + (n) * (FRACTION)
#define INT_SUB(x, n) (x) - (n) * (FRACTION)
#define CONVERT_TO_FP(x) (x) * (FRACTION)
#define CONVERT_TO_INT_ZERO(x) (x) / (FRACTION)
#define CONVERT_TO_INT_NEAR(x) ((x) >= 0 ? ((x) + (FRACTION) / 2) / (FRACTION) : ((x) - (FRACTION) / 2) / (FRACTION))
#define FP_MUL(x, y) ((int64_t)(x)) * (y) / (FRACTION)
#define FP_DIV(x, y) ((int64_t)(x)) * (FRACTION) / (y)

#endif /* threads/fixed_point.h */
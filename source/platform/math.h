#pragma once

#ifdef __cplusplus
extern "C" {
#endif

double sin(double);
inline float sinf(float x) { return (float)sin(x); }

double cos(double);
inline float cosf(float x) { return (float)cos(x); }

double tan(double);
inline float tanf(float x) { return (float)tan(x); }

double sqrt(double);
inline float sqrtf(float x) { return (float)sqrt(x); }

double acos(double);
inline float acosf(float x) { return (float)acos(x); }

double frexp(double x, int* eptr);
double ldexp(double x, int exp);

double pow(double x, double y);

double copysign(double x, double y);

int __fpclassifyf(float);
int __fpclassifyd(double);
int __signbitd(double);

#ifdef __cplusplus
} // extern "C"
#endif

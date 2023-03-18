#include "../../include/other/Other.h"

long long time_in_milli()
{
    struct timeval curr_t{};
    gettimeofday(&curr_t, nullptr);
    long long milliseconds = curr_t.tv_sec * 1000LL + curr_t.tv_usec / 1000;
    return milliseconds;
}
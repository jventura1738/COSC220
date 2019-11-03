#include "timer.h"
#include <iomanip>

Timer::Timer()
{
    start_time = 0;
    end_time = 0;
}

void Timer::start_timer()
{
    start_time = clock();
}

void Timer::end_timer()
{
    end_time = clock();
}

double Timer::get_time()
{
    return 1000*(double(end_time - start_time) / (CLOCKS_PER_SEC));
}
void Timer::reset_time()
{
    start_time = 0;
    end_time = 0;
}

void Timer::display_time()
{
    std::cout << "\nTime elapsed: " << std::setprecision(2)
              << std::fixed << get_time() << "ms, "
              << get_time()/1000 << "s\n";
}

#include <ctime>
#include "timer.hpp"

Timer::Timer(): running(false),accumulated(0),start_time(0) {}
void Timer::start() {
   if (!running) {
      running = true;
      start_time = time(nullptr);  // record current time in seconds
   }
}
void Timer::stop() {
   if (running) {
      time_t const now = time(nullptr);
      accumulated += static_cast<long>(now - start_time);
      running = false;
   }
}
long Timer::elapsed() const {
   if (running) {
      time_t const now = time(nullptr);
      return accumulated + static_cast<long>(now - start_time);
   }
   return accumulated;
}
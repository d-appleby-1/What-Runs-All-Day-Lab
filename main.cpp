#include <iostream>
#include "src/timer.hpp"
#include <iostream>
#include <ctime>
#include <thread>

using std::cout;
using std::endl;

int main() {
  time_t sys_start = time(nullptr);
  Timer t;
  t.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  t.stop();
  time_t sys_end = time(nullptr);
  long sys_elapsed = static_cast<long>(sys_end - sys_start);
  cout << "Timer elapsed: " << t.elapsed() << " seconds"<<endl;
  cout << "System elapsed: " << sys_elapsed << " seconds"<<endl;
  long timer_elapsed = t.elapsed();
  cout << "Difference: " << timer_elapsed - sys_elapsed << " seconds"<<endl;
}
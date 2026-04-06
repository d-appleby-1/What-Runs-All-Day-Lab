#pragma once
class Timer {
private:
    bool running;
    long accumulated;
    time_t start_time;
public:
    Timer();
    void start();
    void stop();
    long elapsed() const;
};

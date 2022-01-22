//
// Created by xiehaitao on 2022/1/22.
//
#include "Poco/Timer.h"
#include "Poco/Thread.h"
#include "Poco/Stopwatch.h"
#include <iostream>


using Poco::Timer;
using Poco::TimerCallback;
using Poco::Thread;
using Poco::Stopwatch;
class TimerExample
{
public:
    TimerExample(){
        sw_.start();
    };

    void onTimer(Timer& timer){
        std::cout << "Callback called after " << sw_.elapsed()/1000 << " milliseconds." << std::endl;
    }
private:
    Stopwatch sw_;
};

int main(int argc, char** argv)
{
    TimerExample example;
    Timer timer(100,500);
    timer.start(TimerCallback<TimerExample>(example,&TimerExample::onTimer));

    Thread::sleep(5000);

    timer.stop();

    return 0;
}
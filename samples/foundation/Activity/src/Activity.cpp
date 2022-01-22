//
// Created by xiehaitao on 2022/1/22.
//
#include "Poco/Activity.h"
#include "Poco/Thread.h"
#include <iostream>


using Poco::Activity;
using Poco::Thread;

class ActivityExample
{
public:
    ActivityExample() : activity_(this,&ActivityExample::runActivity)
    {

    }

    void start()
    {
        activity_.start();
    }

    void stop()
    {
        activity_.stop();
        activity_.wait();
    }

protected:
    void runActivity()
    {
        while(!activity_.isStopped())
        {
            std::cout << "Activity running." << std::endl;
            Thread::sleep(250);
        }
        std::cout << "Activity stopped." << std::endl;
    }
private:
    Activity<ActivityExample> activity_;
};

int main(int argc, char** argv)
{
    ActivityExample example;
    example.start();
    Thread::sleep(2000);

    example.stop();

    example.start();
    example.stop();
    return 0;
}

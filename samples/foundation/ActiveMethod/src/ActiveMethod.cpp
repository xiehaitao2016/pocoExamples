//
// Created by xiehaitao on 2022/1/22.
//
#include "Poco/ActiveMethod.h"
#include "Poco/ActiveResult.h"
#include "Poco/Stopwatch.h"
#include <iostream>


using Poco::ActiveMethod;
using Poco::ActiveResult;
using Poco::Stopwatch;

class ActiveMethodExample
{
public:
    struct AddArgs
    {
        int a;
        int b;
    };
    ActiveMethodExample() : activeAdd(this,&ActiveMethodExample::activeAddImp)
    {
        sw_.start();
    }

    ActiveMethod<int,AddArgs,ActiveMethodExample> activeAdd;

private:
    int activeAddImp(const AddArgs& args)
    {
        Poco::Thread::sleep(1000*5);
        std::cout << "activeAddImp called after " << sw_.elapsed()/1000 << " milliseconds." << std::endl;
        return args.a + args.b;
    }

    Stopwatch sw_;

};

int main(int argc, char** argv)
{
    ActiveMethodExample example;
    ActiveMethodExample::AddArgs args = {1,2};
    ActiveResult<int> result = example.activeAdd(args);

    //do something else.
//    Poco::Thread::sleep(1000*8);
    int i = 0;
    while (!result.available()){
        Poco::Thread::sleep(1000*1);
        i++;
    }
    printf("sleep for %d second\n",i);

    result.wait();
    std::cout << result.data() << std::endl;
    return 0;
}

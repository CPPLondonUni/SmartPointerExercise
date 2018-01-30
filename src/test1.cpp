#include "exercise1.h"
#include "LoggerImpl.h"

#include <thread>
#include <memory>


std::unique_ptr<SuperImportantClass> naiceClass;
std::unique_ptr<SuperImportantClass> evenNaicerClass;

void CreateSuperClass(ILogger& log)
{
    
}

void Setup()
{
    LoggerImpl log{"log.txt"};
    naiceClass = std::make_unique<SuperImportantClass>(log);
   // evenNaicerClass = std::make_unique<SuperImportantClass>(log);// First one doesnt even work :(
    
}

int main()
{
    Setup();
    std::thread t1 {[] {naiceClass->run();}};
  //  std::thread t2 {[] {evenNaicerClass->run();}};//First one doesnt even work :(
    t1.join();
//    t2.join();
	return 0;
}

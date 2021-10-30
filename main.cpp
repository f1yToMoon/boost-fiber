#include <iostream>
#include <boost/fiber/all.hpp>

using namespace std;

void fn1( boost::fibers::barrier & b)
{
    boost::fibers::fiber::id id = boost::this_fiber::get_id();
    std::cout << "fiber " << id << ": fn1 entered" << std::endl;

    ++value1;
    std::cout << "fiber " << id << ": incremented value1: " << value1 << std::endl;
    boost::this_fiber::yield();

    std::cout << "fiber " << id << ": waits for barrier" << std::endl;
    b.wait();
    std::cout << "fiber " << id << ": passed barrier" << std::endl;

    ++value1;
    std::cout << "fiber " << id << ": incremented value1: " << value1 << std::endl;
    boost::this_fiber::yield();

    ++value1;
    std::cout << "fiber " << id << ": incremented value1: " << value1 << std::endl;
    boost::this_fiber::yield();

    ++value1;
    std::cout << "fiber " << id << ": incremented value1: " << value1 << std::endl;
    boost::this_fiber::yield();

    std::cout << "fiber " << id << ": fn1 returns" << std::endl;
}

void fn2( boost::fibers::barrier & b)
{
    boost::fibers::fiber::id id = boost::this_fiber::get_id();
    std::cout << "fiber " << id << ": fn2 entered" << std::endl;

    ++value2;
    std::cout << "fiber " << id << ": incremented value2: " << value2 << std::endl;
    boost::this_fiber::yield();

    ++value2;
    std::cout << "fiber " << id << ": incremented value2: " << value2 << std::endl;
    boost::this_fiber::yield();

    ++value2;
    std::cout << "fiber " << id << ": incremented value2: " << value2 << std::endl;
    boost::this_fiber::yield();

    std::cout << "fiber " << id << ": waits for barrier" << std::endl;
    b.wait();
    std::cout << "fiber " << id << ": passed barrier" << std::endl;

    ++value2;
    std::cout << "fiber " << id << ": incremented value2: " << value2 << std::endl;
    boost::this_fiber::yield();

    std::cout << "fiber " << id << ": fn2 returns" << std::endl;
}

int main()
{
        int value1 = 0;
        int value2 = 0;
    
        boost::fibers::barrier fb( 2);

        boost::fibers::fiber f1( & fn1, std::ref( fb) );
        boost::fibers::fiber f2( & fn2, std::ref( fb) );

        f1.join();
        f2.join();

        return 0;

}

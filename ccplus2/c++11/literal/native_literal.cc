#include <iostream>
#include <string>

using namespace std;


int	main(int argc, char **argv)
{
    cout << R"(hello,\n
     world)" << endl;   

    string str = R"(hello \4  \r 
    abc, mike
    hello\n)";
    cout << str << endl;
    return 0;
}


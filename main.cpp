#include <iostream>

using namespace std;

int main()
{

    int** r = nullptr;
    if(!r)
        std::cerr << " r is nullptr";

    r = new int*[10];

    for (int i = 0; i < 10; ++i) {
        std::cout << r[i] <<std::endl;
    }

    cout << "Hello World!" << endl;
    return 0;
}

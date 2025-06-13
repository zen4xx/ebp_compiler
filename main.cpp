#include "parser.h"

int main()
{
    for(auto s : file_to_vector("test"))
        std::cout << s << std::endl;
    return 0;
}

#include "../puddo.hpp"

int main (void)
{
    Matrix <std::string> matrix(2, 1);
    matrix.write();
    std::string tmp = "";
    matrix.set(0, 0, "123456789");
    tmp = matrix.get(0, 0);
    std::cout << tmp << std::endl;
    return(0);
}
#include <iostream>
#include "overload.hpp"

int main(void) {

    using clx = complex_number<double>;
    clx c1(1.5, 2.3);
    clx c2(3.3, 1.0);

    std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;
    clx c3 = c1+c2;
    std::cout << "The conjugate of " << c3 << " is " << conj(c3) << "; ";
    std::cout << "its real part is " << Re(c3)<< ", and its imaginary part is " << Im(c3) << std::endl; 
    
    //

    clx c5 = clx(3.4,4.2) + 2.2;
    std::cout << "(3.4 + 4.2i) + 2.2 = " << c5 << std::endl;
    clx c6 = 3.1 + clx(5.3,8.7);
    std::cout << "3.1 + (5.3 + 8.7i) = " << c6 << std::endl;
    
    return 0;
}

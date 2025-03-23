#pragma once

template<typename I>
class complex_number{
    I rl, clx;

public:
    complex_number(): rl(1), clx(1) {

    }

    explicit complex_number(I r): rl(r), clx(0) {
        std::cout << "converting constructor called (real->complex)" << std::endl;
    }

    complex_number(I r, I c): rl(r), clx(c) {
        std::cout << "building complex number" << std::endl;
    }

    















};

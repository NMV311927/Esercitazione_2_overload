#pragma once
#include <ostream>

template<typename I>
class complex_number{
    I a, b;

public:
    complex_number(): a(0), b(0) {}

    explicit complex_number(I r): a(r), b(0) {
        std::cout << "(converting constructor called (real->complex))" << std::endl;
    }

    complex_number(I r, I c): a(r), b(c) {
        std::cout << "(building complex number)" << std::endl;
    }

    I rl(void) const{
        return a;
    }

    I im(void) const{
        return b;
    }

    //

    complex_number& operator+=(const complex_number& other) {
        I c = a;
        I d = b;
        I e = other.a;
        I f = other.b;
        a = c + e;
        b = d + f;
        return *this;
	}

    complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    complex_number& operator+=(const I& other) {
        a += other;
        return *this;
	}

	complex_number operator+(const I& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    //

    complex_number& operator*=(const complex_number& other){
        I c = a;
        I d = b;
        I e = other.a;
        I f = other.b;
        a = c*e - d*f;
        b = d*e + c*f;
        return *this;
    }

    complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }

    complex_number& operator*=(const I& other) {
        complex_number mol(other);
        a *= mol;
        return *this;
	}

	complex_number operator*(const I& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

template<typename I>
complex_number<I> conj(const complex_number<I>& r){
    return complex_number<I>(r.rl(), -r.im());
}

template<typename I>
complex_number<I> Re(const complex_number<I>& r){
    return complex_number<I>(r.rl(), 0);
}

template<typename I>
complex_number<I> Im(const complex_number<I>& r){
    return complex_number<I>(0, r.im());
}

// 

template<typename I>
complex_number<I> operator+(const I& i, const complex_number<I>& r)
{
    return r + i;
}

template<typename I>
complex_number<I> operator*(const I& i, const complex_number<I>& r)
{
    return r * i;
}

//

template<typename I>
std::ostream& operator<<(std::ostream& os, const complex_number<I>& r) {
    if (r.im() < 0)
        os << r.rl() << " - " << -r.im() << "i";
    else 
        os << r.rl() << " + " << r.im() << "i";

    return os;
}
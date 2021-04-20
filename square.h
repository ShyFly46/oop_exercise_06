#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

template<class T>
struct square{
    std::pair<T, T> a, b, c, d;

    square(T size = 1){
        setsize(size);
    }
	
	void setsize(T size){
		b.first = size;
		c.second = size;
		d.first = size;
		d.second = size;
	}
};

template<class T>
std::istream &operator>>(std::istream &in, square<T> &q) {
	T size;
    in >> size;
	q.setsize(size);
	return in;
}

template<class T>
std::ostream &operator<<(std::ostream &out, square<T> &q) {
    out << "Square size "
		<< q.b.first;
	return out;
}

#endif 

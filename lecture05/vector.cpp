#include <iostream>

// -------------- Interface

class Array {
  size_t _size;
  double *_elem;
public:
  Array( size_t theSize );
  Array( const Array& );
  Array& operator=( const Array& );
  ~Array();
  Array& getSelf() {
    return *this;
  }
  bool amIthis( Array *other );

  //void resize( size_t newSize );

  inline size_t size() const { return _size; };

  double& operator[]( size_t i ) const;
  //double operator[] ( size_t i ) const;
  void print() const;
};

// -------------- Implementation
Array::Array( size_t theSize )
  :   _size{theSize},
      _elem{new double[theSize]} {
  for( size_t i = 0; i < _size; ++i ) {
    _elem[i] = 0;
  }
}

Array::Array( const Array &rhs ) 
  : _size{rhs._size}, _elem{nullptr} {

    _elem = new double[_size];
    for( size_t i = 0; i < _size; ++i ) {
      _elem[i] = rhs._elem[i];
    }
}
// if we're doing Array a2 = oldArray;
//                            ^rhs
// what if we write:
// oldArray = oldArray;
Array& Array::operator=( const Array &rhs ) {
  // NOT if( *this != rhs ) {
  if( this != &rhs ) {
    _size = rhs._size;
    _elem = new double[_size];
    for( size_t i = 0; i < _size; ++i ) {
      _elem[i] = rhs._elem[i];
    }
  }
  return *this;
}

bool Array::amIthis( Array *other ) {
  return this == other;
}

Array::~Array() {
  delete [] _elem;
}

double& Array::operator[]( size_t i ) const {
  return _elem[i];
}

/*double Array::operator[]( size_t i ) const {
  return _elem[i];
}*/

void Array::print() const {
  std::cout << "[ ";

  for( size_t i = 0; i < _size; ++i ) {
    std::cout << _elem[i] << " ";
  }

  std::cout << "]\n";
}


int main() {
  Array array{ 10 };
  array = array;

  std::cout << array.amIthis( &array ) << "\n";

  array.print();
//  array2.print();
  return 0;
}

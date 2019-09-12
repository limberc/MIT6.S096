#include <iostream>
#include <stdexcept>
#include <iomanip>

class IndexingScheme {
public:
  virtual size_t idx( size_t r, size_t c ) = 0;
  virtual ~IndexingScheme() {}
};
// IndexingScheme *scheme = new RowMajor{ 5, 5 };
// scheme->idx( 3, 3 );
// Derived *derived = new Base{};

class RowMajor : public IndexingScheme {
  size_t _nCols;
  RowMajor() = delete;
public:
  RowMajor( size_t, size_t numCols ) :
    _nCols{numCols} {}
  size_t idx( size_t r, size_t c ) {
    return c + r * _nCols;
  }
};

class ColMajor : public IndexingScheme {
  size_t _nRows;
  ColMajor() = delete;
public:
  ColMajor( size_t numRows, size_t ) :
    _nRows{numRows} {}
  size_t idx( size_t r, size_t c ) { 
    return r + c * _nRows;
  }
};

template<typename Scheme_T>
class Matrix {
  size_t _nRows, _nCols;
  double *_data;
  IndexingScheme *_scheme;
  Matrix() = delete;
  Matrix( const Matrix& matrix ) = delete;
  Matrix& operator=( const Matrix& matrix ) = delete;
public:
  //enum Scheme { ROW_MAJOR, COL_MAJOR };

  /*Matrix( size_t R, size_t C, Scheme type ) : 
    _nRows{R}, 
    _nCols{C}, 
    _data{ new double[R*C] },
    _scheme{ nullptr } {
      if( type == ROW_MAJOR ) {
        _scheme = new RowMajor{ R, C };
      } else if( type == COL_MAJOR ) {
        _scheme = new ColMajor{ R, C };
      } else {
        throw std::runtime_error( "Unknown indexing scheme" );
      }
    }*/
  Matrix( size_t R, size_t C ) : 
    _nRows{R}, 
    _nCols{C}, 
    _data{ new double[R*C] },
    _scheme{ new Scheme_T{ R, C } } {}

  ~Matrix() {
    delete [] _data;
    delete _scheme;
  }

  // matrix.data( 1, 1 ) = 5.0;
  double& data( size_t r, size_t c ) {
    return _data[_scheme->idx( r, c )];
  }

  // if( matrix.data( 1, 1 ) < 10.0 )
  double data( size_t r, size_t c ) const {
    return _data[_scheme->idx( r, c )];
  }

  double& data( size_t i ) { return _data[i]; }
  double data( size_t i ) const { return _data[i]; }

  inline size_t nRows() const { return _nRows; }
  inline size_t nCols() const { return _nCols; }
};

template<typename Scheme_T>
void print2d( const Matrix<Scheme_T>& matrix ) {
  for( size_t r = 0; r < matrix.nRows(); ++r ) {
    for( size_t c = 0; c < matrix.nCols(); ++c ) {
      std::cout << std::setw( 2 ) << matrix.data( r, c ) << " ";
    }
    std::cout << '\n';
  }
}

int main() {
  size_t R = 5, C = 5;
  //Matrix matrix{ R, C, Matrix::ROW_MAJOR };
  //Matrix matrix{ R, C, Matrix::COL_MAJOR };
  Matrix<ColMajor> matrix{ R, C };
  int idx = 0;
  for( size_t r = 0; r < R; ++r ) {
    for( size_t c = 0; c < C; ++c ) {
      matrix.data( r, c ) = ++idx;
    }
  }
  std::cout << "As 2d:\n";
  print2d( matrix );
  std::cout << "\nAs a flat array:\n";
  for( size_t i = 0; i < R * C; ++i ) {
      std::cout << matrix.data( i ) << " ";
  }
  std::cout << '\n';
}

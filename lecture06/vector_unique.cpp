#include <vector>
#include <memory>

class Object {
  int _id;
  double _foo;
  Object() = delete;
public:
  Object( int theId ) : _id{theId}, _foo{0.0} {}
};

int main() {
  std::vector< std::unique_ptr<Object> > objectPtrs;

  for( int i = 0; i < 10; ++i ) {
    objectPtrs.push_back( std::unique_ptr<Object>( new Object{i} ) );
  }
}

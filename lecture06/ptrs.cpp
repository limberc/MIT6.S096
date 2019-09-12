#include <iostream>
#include <vector>
#include <memory>

typedef std::shared_ptr<int> intPtr;

int main() {
  std::vector<intPtr> intPtrs;
  for( int i = 0; i < 100; ++i ) {
    intPtrs.push_back( intPtr{ new int{5} } );
  }
  std::cout << intPtrs[0] << '\n';
}

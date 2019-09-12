#include <vector>
#include <iostream>

int main() {
  std::vector<int> intArray;

  for( int i = 0; i < 10; ++i ) {
    intArray.push_back( i * i );
  }

  // for val in list:
  // use auto &val if you want
  // to modify that position
  for( auto &val : intArray ) {
    std::cout << val << " ";
    val = 5;
  }
  std::cout << "\n";

  // use plain auto val if you want
  // to just access the value
  for( auto val : intArray ) {
    std::cout << val << " ";
  }
  std::cout << "\n";
  return 0;
}

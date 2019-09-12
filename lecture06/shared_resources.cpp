#include <memory>
#include <iostream>
//#define SHARED

int main() {
#ifdef SHARED
  auto aPtr = std::shared_ptr<int>( new int );
#else
  auto aPtr = std::unique_ptr<int>( new int );
#endif //SHARED

  *aPtr = 5;
  std::cout << *aPtr << "\n";

  return 0;
}

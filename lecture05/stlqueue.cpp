#include <queue>
#include <stack>
#include <iostream>

int main() {
  std::queue<float> floatQueue;
  std::stack<float> floatStack;

  for( int i = 0; i < 10; ++i ) {
    floatQueue.push( (float) i );
    floatStack.push( (float) i );
  }

  std::cout << "Stack FILO: ";
  while( !floatStack.empty() ) {
    std::cout << floatStack.top() << " ";
    floatStack.pop();
  }
  std::cout << "\n";

  std::cout << "Queue FIFO: ";
  while( !floatQueue.empty() ) {
    std::cout << floatQueue.front() << " ";
    floatQueue.pop();
  }
  std::cout << "\n";

  return 0;
}

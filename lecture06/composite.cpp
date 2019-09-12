#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include "composite.h"

void Directory::ls() const {
  lsIndented( 0 );
}

void Directory::lsIndented( int indent ) const {
  for( int i = 0; i < indent; ++i ) {
    std::cout << '\t';
  }
  std::cout << _name << '\n';
  for( const auto &child : _children ) {
    child->lsIndented( indent + 1 );
  }
}

void File::lsIndented( int indent ) const {
  for( int i = 0; i < indent; ++i ) {
    std::cout << '\t';
  }
  std::cout << _name << '\n';
}

void File::ls() const {
  lsIndented( 0 );
}

NodePtr Directory::create( const std::string &dirname ) {
  return NodePtr( new Directory{ dirname } );
}

NodePtr File::create( const std::string &filename ) {
  return NodePtr( new File{ filename } );
}

int main() {
  auto projectDir = 
    Directory::create( "project" );
  auto srcDir = Directory::create( "src" );
  auto includeDir = 
    Directory::create( "include" );

  auto dirPtr = projectDir->getDirectory();
  if( dirPtr != nullptr ) {
    dirPtr->add( File::create( "Makefile" ) );
    dirPtr->add( File::create( "GRADER_INFO.txt" ) );
    dirPtr->add( srcDir );
    dirPtr->add( includeDir );
  }

  dirPtr = srcDir->getDirectory();
  if( dirPtr != nullptr ) {
    dirPtr->add( File::create( "list.c" ) );
    dirPtr->add( File::create( "test.c" ) );
  }

  dirPtr = includeDir->getDirectory();
  if( dirPtr != nullptr ) {
    dirPtr->add( File::create( "list.h" ) );
  }

  projectDir->ls();
  return 0;
}

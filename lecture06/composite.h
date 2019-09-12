#ifndef _COMPOSTE_H
#define _COMPOSTE_H

// composite.h:
// Example of composite design pattern

// Forward declarations
class Directory;
class Node;
typedef std::shared_ptr<Node> NodePtr;

// GoF "Component" class
class Node {
public:
  virtual ~Node() {}
  virtual void ls() const = 0;
  virtual void lsIndented( int indent ) const = 0;
  virtual Directory* getDirectory() { return nullptr; }
};

// GoF "Composite" class
class Directory : public Node {
  std::string _name;
  std::vector<NodePtr> _children;
  void lsIndented( int indent ) const;
public:
  Directory() : _name{ "/" }, _children{} {}
  Directory( const std::string &dirname ) : 
    _name{dirname + "/"}, 
    _children{} {}

  void add( NodePtr item ) { _children.push_back( item ); }
  void ls() const;
  virtual Directory* getDirectory() { return this; }

  static NodePtr create( const std::string &dirname );
};

// GoF "Leaf" class
class File : public Node {
  std::string _name;
  File() = delete;
  void lsIndented( int indent ) const;
public:
  File( std::string filename ) : _name(filename) {}
  void ls() const;

  static NodePtr create( const std::string &filename );
};

// Could be used as an overall container
class Filesystem {
  NodePtr _root;
public:
  Filesystem() : _root{ Directory::create( "" ) } {}
};

#endif // _COMPOSTE_H

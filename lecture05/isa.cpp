class Bird {
};

class FlyingBird : public Bird {
public:
  virtual void fly() = 0;
}

class Penguin : public Bird {
  // penguins are birds
  // but they shouldn't fly!
};

class AfricanSwallow : public FlyingBird {
  void fly() { /*... */ }
}
class EuropeanSwallow : public FlyingBird {
  void fly() { /*... */ }
}

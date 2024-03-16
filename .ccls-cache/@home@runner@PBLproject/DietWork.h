#include "Gym.h"
#include <iostream>
using namespace std;

struct Meal {
  public:
    virtual void meal() = 0; 
};

class Veg {
  public:
    void meal() {
      
    }
};
class Non_veg {
  public:
    void meal() {
      
    }
};
class Diet : protected Veg, protected Non_veg {};
class Work_out {};
class Wt_loss : protected Diet, protected Work_out {};
class Wt_gain : protected Diet, protected Work_out {};
class Wt_maintain : protected Diet, protected Work_out {};

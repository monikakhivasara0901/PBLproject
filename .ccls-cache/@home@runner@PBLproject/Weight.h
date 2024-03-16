#include "Gym.h"

struct Meal {
  
};

class Veg {
  
};
class Non_veg {
  
};
class Diet : protected Veg, protected Non_veg {};
class Work_out {};
class Wt_loss : protected Diet, protected Work_out {};
class Wt_gain : protected Diet, protected Work_out {};
class Wt_maintain : protected Diet, protected Work_out {};

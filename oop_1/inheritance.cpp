#include <iostream>
#include <string>

using namespace std;

class Robot {
public:
  Robot(const std::string &name) { this->name = name; }
  void boot() { cout << name << " sedang booting\n"; }
  virtual void move() { // ditambah virtual
    cout << name << " gerak cui\n";
  }

protected: // private diganti protected
  std::string name;
};

class MobileRobot : public Robot {
public:
  MobileRobot(const std::string &name) : Robot(name) {}
  void move() override { cout << name << " bergerak dengan sangat cepat\n"; }
};

class ArmRobot : public Robot {
public:
  ArmRobot(const std::string &name) : Robot(name) {}
  void move() override { cout << name << " bergerak dan mengambil box\n"; }
};

int main() {

  MobileRobot robot1("Triceratop");
  ArmRobot robot2("Rex");

  robot1.boot();
  robot1.move();

  robot2.boot();
  robot2.move();
  return 0;
}
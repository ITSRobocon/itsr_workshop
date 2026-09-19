#include <iostream>
#include <string>

using namespace std;

class Robot {
public:
  Robot(const std::string &name) { this->name = name; }
  void boot() { cout << name << " sedang booting\n"; }
  void move() { cout << name << " gerak cui\n"; }

private:
  std::string name;
};

int main() {

  Robot robotKu("Triceratop");
  robotKu.boot();
  robotKu.move();

  return 0;
} 
#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;

class FlagsComponent : public Component {
protected:
  vector<string> _flagStatuses;

public:
  void update(double dt) override;
  void render() override {}
  void addFlag(string status);
  void changeFlagStatus(int number, string status);
  string getFlagStatus(int number);
  explicit FlagsComponent(Entity* p);
  FlagsComponent() = delete;
};

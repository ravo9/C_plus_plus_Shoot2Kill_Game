#pragma once

#include "engine.h"

class MenuScene : public Scene {
protected:
  int _chosenValue;
  int _clickFreezer;

public:
  MenuScene() = default;
  ~MenuScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};

#pragma once

#include "engine.h"

class MenuAboutScene : public Scene {
protected:
  int _clickFreezer;

public:
  MenuAboutScene() = default;
  ~MenuAboutScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};

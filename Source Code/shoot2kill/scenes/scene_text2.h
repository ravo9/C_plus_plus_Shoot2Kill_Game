#pragma once

#include "engine.h"

class Text2Scene : public Scene {
public:
  Text2Scene() = default;
  ~Text2Scene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};

#pragma once

#include "engine.h"

class Text1Scene : public Scene {
public:
  Text1Scene() = default;
  ~Text1Scene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};

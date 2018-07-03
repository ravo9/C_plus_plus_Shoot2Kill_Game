#pragma once

#include "engine.h"

class LevelSceneFinal : public Scene {
protected:
  int _cannonFreezer;
  int _enemiesAttackFreezer;

public:
  void Load() override;

  void UnLoad() override;

  void Update(const double& dt) override;

  void Render() override;

};

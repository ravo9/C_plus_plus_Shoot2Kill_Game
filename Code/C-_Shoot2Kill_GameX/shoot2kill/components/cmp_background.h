#pragma once
#include <SFML/Graphics.hpp>

class BackgroundComponent : public Component {
protected:
  sf::Texture _backgroundTexture;

public:
  void update(double dt) override;
  void render() override {}
  explicit BackgroundComponent(Entity* p, std::string source);
  BackgroundComponent() = delete;
};

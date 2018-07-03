#include <engine.h>
#include "../components/cmp_background.h"
#include "../components/cmp_sprite.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void BackgroundComponent::update(double dt) {}

BackgroundComponent::BackgroundComponent(Entity* p, std::string source)
    : Component(p) {

	_parent->setPosition(Vector2f(0, 0));

	if (!_backgroundTexture.loadFromFile(source))
		cerr << "Failed to load background spritesheet!" << endl;
	else
		cout << "Background texture loaded!";

	auto b1 = _parent->addComponent<SpriteComponent>();
	b1->getSprite().setTexture(_backgroundTexture);
	b1->getSprite().setTextureRect(IntRect(0, 0, 1366, 768));
}

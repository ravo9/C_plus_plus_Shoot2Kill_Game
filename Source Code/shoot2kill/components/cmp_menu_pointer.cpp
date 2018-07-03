#include "cmp_menu_pointer.h"
#include "../components/cmp_sprite.h"
#include "../components/components_controls.h"
#include <engine.h>

using namespace std;
using namespace sf;

void MenuPointerComponent::update(double dt) {

	if (Keyboard::isKeyPressed(keyUp) && _choosingFreezer == 0) {
		_currentValue--;
		_choosingFreezer = 150;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && _choosingFreezer == 0){
		_currentValue++;
		_choosingFreezer = 150;
	}
	
	if (_currentValue == getPositionsAmount())
		_currentValue = 0;
	else if (_currentValue == -1)
		_currentValue = getPositionsAmount()-1;

	_parent->setPosition(getPosition(_currentValue));

	if (_choosingFreezer > 0)
		_choosingFreezer--;
}

MenuPointerComponent::MenuPointerComponent(Entity* p)
	: Component(p) {

	_spritesheet.loadFromFile("res/img/pointer.png");
	auto s1 = _parent->addComponent<SpriteComponent>();
	s1->getSprite().setTexture(_spritesheet);

	_currentValue = 0;
	_choosingFreezer = 0;
}

void MenuPointerComponent::addPosition(sf::Vector2f pos) {
	_positions.push_back(pos);
}

sf::Vector2f MenuPointerComponent::getPosition(int number) {
	return _positions[number];
}

int MenuPointerComponent::getCurrentPosition() {
	return _currentValue;
}

int MenuPointerComponent::getPositionsAmount() {
	return _positions.size();
}
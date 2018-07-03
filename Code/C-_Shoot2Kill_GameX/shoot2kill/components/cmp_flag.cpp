#include "cmp_flag.h"
#include "../components/cmp_sprite.h"
#include "../components/cmp_character_attributes.h"
#include <engine.h>

using namespace std;
using namespace sf;

void FlagsComponent::update(double dt) {}

FlagsComponent::FlagsComponent(Entity* p)
	: Component(p) {}

void FlagsComponent::addFlag(string status) {
	_flagStatuses.push_back(status);
}

void FlagsComponent::changeFlagStatus(int number, string status) {
	_flagStatuses.at(number) = status;
}

string FlagsComponent::getFlagStatus(int number) {
	return _flagStatuses.at(number);
}

#include "cmp_player_attributes.h"
#include "../components/cmp_text.h"

using namespace std;
using namespace sf;

PlayerAttributesComponent::PlayerAttributesComponent(Entity* p) : Component(p), _hp(100) {}

int PlayerAttributesComponent::getHpValue() { return _hp; }

void PlayerAttributesComponent::update(double dt) {}
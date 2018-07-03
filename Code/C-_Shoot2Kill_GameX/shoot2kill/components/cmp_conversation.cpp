#include "cmp_conversation.h"
#include "cmp_sprite.h"
#include "cmp_text.h"
#include "cmp_flag.h"
#include "cmp_enemy.h"
#include "cmp_enemy_ai.h"
#include <ecm.h>
#include <engine.h>

using namespace std;
using namespace sf;

DialogElement::DialogElement(int side, string source, string character) {
	_side = side;
	_source = source;
	_character = character;
}

int DialogElement::getSide() { return _side; }

string DialogElement::getSource() { return _source; }

string DialogElement::getCharacter() { return _character; }

void ConversationComponent::update(double dt) {

	if (_finished == false) {

		if (Keyboard::isKeyPressed(Keyboard::Space)) {

			if (_dialogFreezer <= 0) {
				loadNextDialog();
				_dialogFreezer = 100;
			}

			if (_dialogFreezer >= 0)
				_dialogFreezer--;
		}
	}
	else if (_postDialogueAction == "Final") {
		
		if (_parent->scene->ents.list[5]->GetCompatibleComponent<FlagsComponent>()[0]->getFlagStatus(0) != "closed")
			_parent->scene->ents.list[5]->GetCompatibleComponent<FlagsComponent>()[0]->changeFlagStatus(0, "activateNow");

		hideConversationComponent();
	}
}

ConversationComponent::ConversationComponent(Entity* p)
	: Component(p), _dialogFreezer(0), _finished(false) {

	auto infoText = _parent->addComponent<TextComponent>("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                    Press SPACE to follow the dialogue");
	infoText->SetColor(sf::Color(36, 255, 20, 255));
}

void ConversationComponent::addLeftSidePhrase(string source, string character) {

	addPhrase(-1, source, character);
}

void ConversationComponent::addRightSidePhrase(string source, string character) {

	addPhrase(1, source, character);
}

void ConversationComponent::addPhrase(int side, string source, string character) {

	_stack.push_back(DialogElement(side, source, character));
}

void ConversationComponent::setPostDialogueAction(string action) {

	_postDialogueAction = action;
}

void ConversationComponent::loadNextDialog() {

	if (!_stack.empty()) {

		DialogElement e = _stack.front();

		_spritesheet.loadFromFile(e.getSource());

		Vector2f characterPos = _parent->scene->ents.find(e.getCharacter())[0]->getPosition();

		float width = _spritesheet.getSize().x;
		float height = _spritesheet.getSize().y;

		if (e.getSide() == 1) // Right side
			_parent->setPosition(Vector2f(characterPos.x + 20.f, characterPos.y - height - 70.f));
		else // Left side
			_parent->setPosition(Vector2f(characterPos.x - width - 20.f, characterPos.y - height - 70.f));

		auto s2 = _parent->addComponent<SpriteComponent>();
		s2->getSprite().setTexture(_spritesheet);

		_stack.pop_front();
	}
	else {
		
		_finished = true;
	}
}

void ConversationComponent::hideConversationComponent() { 

	_parent->setPosition(Vector2f(-1000.f, -1000.f)); 
	_parent->GetCompatibleComponent<TextComponent>()[0]->SetText("");
}
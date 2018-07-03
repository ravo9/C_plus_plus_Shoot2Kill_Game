#pragma once
#include <ecm.h>
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;

class DialogElement {
protected:
	int _side;
	string _source;
	string _character;
	
public:
	DialogElement(int side, string _source, string _character);
	int getSide();
	string getSource();
	string getCharacter();
};

class ConversationComponent : public Component {
protected:
  bool _finished;
  int _dialogFreezer; 
  string _postDialogueAction;
  sf::Texture _spritesheet;
  std::list<DialogElement> _stack;
  void addPhrase(int side, string source, string character);

public:
  void update(double dt) override;
  void render() override {};
  void addLeftSidePhrase(string source, string character);
  void addRightSidePhrase(string source, string character);
  void setPostDialogueAction(string action);
  void loadNextDialog();
  void hideConversationComponent();
  explicit ConversationComponent(Entity* p);
  ConversationComponent() = delete;
};

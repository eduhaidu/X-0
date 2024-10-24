#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace JoculMeu
{
	class InterState : public State
	{
	public:
		InterState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _1pButton;
		sf::Sprite _2pButton;
		sf::Sprite _homeButton;
	};
}

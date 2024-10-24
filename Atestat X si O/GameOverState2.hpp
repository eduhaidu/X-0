#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace JoculMeu
{
	class GameOverState2 : public State
	{
	public:
		GameOverState2(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;

		sf::Sprite _homeButton;
	};
}

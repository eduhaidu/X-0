#include <sstream>
#include "InterState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "GameState2.hpp"

namespace JoculMeu
{
	InterState::InterState(GameDataRef data) : _data(data)
	{

	}

	void InterState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);
		this->_data->assets.LoadTexture("P1 Button", P1_BUTTON);
		this->_data->assets.LoadTexture("P2 Button", P2_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_1pButton.setTexture(this->_data->assets.GetTexture("P1 Button"));
		this->_2pButton.setTexture(this->_data->assets.GetTexture("P2 Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_homeButton.setPosition(this->_data->window.getSize().x - _homeButton.getGlobalBounds().width, _homeButton.getPosition().y);
		this->_1pButton.setPosition((this->_data->window.getSize().x / 2) - (this->_1pButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y / 3) - (this->_1pButton.getLocalBounds().height / 2));
		this->_2pButton.setPosition((this->_data->window.getSize().x / 2) - (this->_2pButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y / 3*2) - (this->_2pButton.getLocalBounds().height / 2));

	}

	void InterState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_1pButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_2pButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState2(_data)), true);
			}
		}
	}

	void InterState::Update(float dt)
	{

	}

	void InterState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_1pButton);
		this->_data->window.draw(this->_2pButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}
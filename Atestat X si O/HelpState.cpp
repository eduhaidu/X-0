#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "HelpState.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"

namespace JoculMeu
{
	HelpState::HelpState(GameDataRef data) : _data(data)
	{

	}

	void HelpState::Init()
	{
		this->_data->assets.LoadTexture("Help Text", HELP_TEXT);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_helpText.setTexture(this->_data->assets.GetTexture("Help Text"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_helpText.setPosition((SCREEN_WIDTH / 2) - (this->_helpText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_helpText.getGlobalBounds().height / 2));
		this->_homeButton.setPosition(this->_data->window.getSize().x - _homeButton.getGlobalBounds().width, _homeButton.getPosition().y);
	}

	void HelpState::HandleInput()
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
		}
	}

	void HelpState::Update(float dt)
	{

	}

	void HelpState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_helpText);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display();
	}
}
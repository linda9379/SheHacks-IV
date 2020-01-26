#include "TextRenderComponent.h"

using namespace GameEngine;

TextRenderComponent::TextRenderComponent()
{
	std::string filePath;
	filePath.append("Resources/img/");
	filePath.append("arial.ttf");
	if (!m_font.loadFromFile(filePath))
	{
		// error...
	}
}


TextRenderComponent::~TextRenderComponent()
{
}

void TextRenderComponent::Render(sf::RenderTarget* target)
{
	//__super::Render(target);

	sf::Text text;

	// select the font
	text.setFont(m_font); // font is a sf::Font

						// set the string to display
	text.setString(m_newText);

	// set the character size
	text.setCharacterSize(72); // in pixels, not points!

							   // set the color
	text.setFillColor(sf::Color::Black);

	// set the text style
	text.setStyle(sf::Text::Bold);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(m_new_pos_x, m_new_pos_y));

	target->draw(text);
}
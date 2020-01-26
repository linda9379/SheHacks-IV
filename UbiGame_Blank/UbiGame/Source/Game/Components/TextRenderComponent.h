#pragma once
#include "GameEngine\EntitySystem\Components\RenderComponent.h"

namespace GameEngine
{
	class TextRenderComponent : public RenderComponent
	{
	public:
		TextRenderComponent();
		~TextRenderComponent();
		virtual void Render(sf::RenderTarget* target) override;
		void setText(std::string t) { m_newText = t; }
		void setPos(int x, int y) { m_new_pos_x = x; m_new_pos_y = y; }
	private:
		std::string m_newText;
		sf::Font m_font;
		int m_new_pos_x;
		int m_new_pos_y;
	};
}
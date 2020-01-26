#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			FalseButton,
			TrueButton,
			Q1,
			Q2,
			Q3,
			Q4,
			Q5,
			Q6,
			Q7,
			Q8,
			Q9,
			Q10,
			BG,
			QUIT,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
			case eTexture::FalseButton: return "FalseBtn.png";
			case eTexture::TrueButton: return "TrueBtn.png";
			case eTexture::Q1: return "Q1.png";
			case eTexture::Q2: return "Q2.png";
			case eTexture::Q3: return "Q3.png";
			case eTexture::Q4: return "Q4.png";
			case eTexture::Q5: return "Q5.png";
			case eTexture::Q6: return "Q6.png";
			case eTexture::Q7: return "Q7.png";
			case eTexture::Q8: return "Q8.png";
			case eTexture::Q9: return "Q9.png";
			case eTexture::Q10: return "Q10.png";
			case eTexture::BG: return "bg.png";
			case eTexture::QUIT: return "quit.png";

		}

		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	static sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		return sf::Vector2f(-1.f, -1.f);
	}
}


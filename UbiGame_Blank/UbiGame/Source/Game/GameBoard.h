#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine/Util/TextureManager.h"
#include "Game/Components/TextRenderComponent.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard 
	{
	public:
		GameBoard();
		virtual ~GameBoard();


		void Update();
		void CheckResponse(bool response);
		bool IsGameOver() { return false; }

	private:
		void createText();
		void createCount();
		void CreatePlayer();
		void CreateLeftButton();
		void UpdateQuestion();
		void CreateRightButton();
		void CreateBG();
		void CreateQuit();
		void CreateObstacle();
		bool questions[10];
		int score;
		int cur_question;
		float timer;
		GameEngine::eTexture::type photos[10];
		GameEngine::Entity* m_player;
		GameEngine::Entity* left_btn;
		GameEngine::Entity* bg;
		GameEngine::Entity* right_btn;
		GameEngine::Entity* question;
		GameEngine::Entity* text;
		GameEngine::Entity* count;
		GameEngine::Entity* quit;
		bool flag;
		bool left_down;
		bool right_down;
		bool game_over;
	};
}


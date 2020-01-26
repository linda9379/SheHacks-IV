#include "GameBoard.h"
#include "GameEngine\GameEngineMain.h"
#include "Components\TextRenderComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Components/Button.h"

using namespace Game;

GameBoard::GameBoard()
	: text(nullptr)
	, count(nullptr)
	, questions{ false, true, true, true, false, true, false, false, true, true }
	, score(0)
	, photos{
		GameEngine::eTexture::Q1,
		GameEngine::eTexture::Q2,
		GameEngine::eTexture::Q3,
		GameEngine::eTexture::Q4,
		GameEngine::eTexture::Q5,
		GameEngine::eTexture::Q6,
		GameEngine::eTexture::Q7,
		GameEngine::eTexture::Q8,
		GameEngine::eTexture::Q9,
		GameEngine::eTexture::Q10
	}
	, cur_question(0)
	, flag(false)
	, game_over (false)
	, right_down(false)
	, left_down(false)
	, timer(60.f)
{
	createText();
	createCount();
	CreateLeftButton();
	CreateRightButton();
	UpdateQuestion();
	CreateBG();
}

void GameBoard::CreateLeftButton() {
	left_btn = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_btn);

	left_btn->SetPos(sf::Vector2f(270.f, 740.f));
	left_btn->SetSize(sf::Vector2f(310.f, 230.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(left_btn->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::TrueButton);
}

void GameBoard::CreateRightButton() {
	right_btn = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_btn);

	right_btn->SetPos(sf::Vector2f(730.f, 740.f));
	right_btn->SetSize(sf::Vector2f(310.f, 230.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(right_btn->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::FalseButton);

}

void GameBoard::UpdateQuestion() {
	if (question) {
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(question);
	}
	question = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(question);

	question->SetPos(sf::Vector2f(500.f, 350.f));
	question->SetSize(sf::Vector2f(837.f, 462.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(question->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(photos[cur_question]);
}

void GameBoard::CreateBG() {
	bg = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

	bg->SetPos(sf::Vector2f(0.f, 0.f));
	bg->SetSize(sf::Vector2f(2000.f, 2000.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(bg->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::BG);
	spriteRender->SetZLevel(-1);
}

void GameBoard::CreateQuit() {
	quit = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(quit);

	quit->SetPos(sf::Vector2f(500.f,500.f));
	quit->SetSize(sf::Vector2f(1000.f, 1000.f));

	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(quit->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::QUIT);
}

void GameBoard::createText() {
	text = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(text);

	GameEngine::TextRenderComponent* textRender = static_cast<GameEngine::TextRenderComponent*>(text->AddComponent<GameEngine::TextRenderComponent>());

}

void GameBoard::createCount() {
	count = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(count);

	GameEngine::TextRenderComponent* countRender = static_cast<GameEngine::TextRenderComponent*>(count->AddComponent<GameEngine::TextRenderComponent>());

}

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	//time since last frame
	float deltaTime = GameEngine::GameEngineMain::GetTimeDelta();
	timer -= deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !left_down) {
			CheckResponse(true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !right_down) {
			CheckResponse(false);
		}
		left_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		right_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	if (text)
	{
		GameEngine::TextRenderComponent* textRender = text->GetComponent<GameEngine::TextRenderComponent>();
		textRender->setText(std::to_string(timer));
		textRender->setPos(270.f, 50.f);
	
		GameEngine::TextRenderComponent* countRender = count->GetComponent<GameEngine::TextRenderComponent>();
		countRender->setText(std::to_string(score));
		countRender->setPos(770.f, 50.f);
		
	}
	
	if (timer <= 0.f|| cur_question==10)
	{
		game_over = true;
		CreateQuit();
		if (game_over) {
			left_down = true;
			right_down = true;
		}
		GameEngine::TextRenderComponent* countRender = count->GetComponent<GameEngine::TextRenderComponent>();
		countRender->setText(std::to_string(score));
		countRender->setPos(600.f, 475.f);
		countRender->SetZLevel(100);
	}

}

void GameBoard::CheckResponse(bool response)
{
	printf("Pressed button\n");
	//flag = true;
	if (questions[cur_question] == response) {
		++score;
	}
	++cur_question;
	UpdateQuestion();
	//flag = false;
}

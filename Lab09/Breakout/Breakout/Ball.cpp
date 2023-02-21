/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Player* p) 
{
	player = p;

	sprite = new Sprite("Resources/Ball.png");

	velX = 0.0f;
	velY = 0.0f;

	MoveTo(player->x, player->y - 30);
}

Ball::~Ball()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
	// delsoca a bola
	//Translate(velX * gameTime, velY * gameTime);
	MoveTo(player->x, player->y - 10);

	// mantem a bola dentro da janela
	if (x < 0)
		velX = -velX;
	if (x + sprite->Width() > window->Width())
		velX = -velX;

	if (y < 0)
		velY = -velY;
	if (y + sprite->Height() > window->Height())
		velY = -velY;
}

void Ball::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------
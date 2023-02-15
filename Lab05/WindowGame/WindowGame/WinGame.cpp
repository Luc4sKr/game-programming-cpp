/**********************************************************************************
// WinGame 
// 
//
// Descrição:   Um jogo para Windows é uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os métodos Init, 
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	HDC hdc;
	int lineXinitial, lineXfinal, lineYinitial, lineYfinal;
	int velXi, velYi;
	int velXf, velYf;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init() 
{
	hdc = GetDC(window->Id());

	lineXinitial = 10;
	lineYinitial = 10;
	lineXfinal = 100;
	lineYfinal = 100;

	velXi = 10;
	velXf = 7;
	velYi = 11;
	velYf = 8;
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		window->Close();

	lineXinitial += velXi;
	lineYinitial += velYi;
	lineXfinal += velXf;
	lineYfinal += velYf;

	// Init
	if (lineXinitial > window->Width())
	{
		velXi = -velXi;
	}

	if (lineYinitial > window->Height())
	{
		velYi = -velYi;
	}

	if (lineXinitial < 0)
	{
		velXi = -velXi;
	}

	if (lineYinitial < 0)
	{
		velYi = -velYi;
	}

	// Final
	if (lineXfinal > window->Width())
	{
		velXf = -velXf;
	}

	if (lineYfinal > window->Height())
	{
		velYf = -velYf;
	}

	if (lineXfinal < 0)
	{
		velXf = -velXf;
	}

	if (lineYfinal < 0)
	{
		velYf = -velYf;
	}

	MoveToEx(hdc, lineXinitial, lineYinitial, NULL);
} 

// ------------------------------------------------------------------------------

void WinGame::Draw()
{	
	LineTo(hdc, lineXfinal, lineYfinal);
} 

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}	


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine * engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------


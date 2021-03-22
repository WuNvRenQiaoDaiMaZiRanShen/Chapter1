#pragma once

#include "SDL.h"
class GAME			
{
public:				//������ʼ�� ѭ�� �˳���������
	bool init();
	void runloop();
	void shutdown();

private:				//������������������������Ϸ���£����� ���� ���
	//loop�Ĺ�������
	void input();
	void update();
	void output();
	//input�ĸ�������
	void quitgame();

//��Ա������
	bool isrunning;
	SDL_Window* mwindow;
	SDL_Renderer* mrenderer;
};




bool GAME::init()
{
	mrenderer = SDL_CreateRenderer(mwindow,-1,0);								//
	if (SDL_Init(SDL_INIT_VIDEO) != 0||mrenderer==NULL)
	{
		std::cout << "unable to initiate";
		return false;
	}
	else return true;
}

void GAME::runloop()
{
	while (isrunning)		//��isrunning��Ϊ1��ʱ�򣬻����loop��Ϸ��
	{
		GAME::input();
		GAME::update();
		GAME::output();
	}
}

void GAME::shutdown()
{
	SDL_DestroyWindow(mwindow);
	SDL_DestroyRenderer(mrenderer);
	SDL_Quit();
}

void GAME::input()
{
	quitgame();


}
void GAME::quitgame()
{
	//����ر���Ϸ
	SDL_Event mevent;
	while (SDL_PollEvent(&mevent))
	{
		if (mevent.type == SDL_QUIT)
		{
			isrunning = false;
		}
	}
	//��exc���˳���Ϸ
	const Uint8* keyboardstate = SDL_GetKeyboardState(NULL);
	if (keyboardstate[SDL_SCANCODE_ESCAPE])
	{
		isrunning = false;
	}
}
void GAME::update()
{




}
void GAME::output()
{
	SDL_SetRenderDrawColor(mrenderer, 0, 0, 255, 255);
	SDL_RenderPresent(mrenderer);
	//SDL_RenderPresent(mrenderer);


}
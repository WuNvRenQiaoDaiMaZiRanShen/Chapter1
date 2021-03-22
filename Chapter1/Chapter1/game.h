#pragma once

#include "SDL.h"
class GAME			
{
public:				//包括初始化 循环 退出三个函数
	bool init();
	void runloop();
	void shutdown();

private:				//包括三个辅助函数来进行游戏更新：输入 更新 输出
	//loop的骨骼函数
	void input();
	void update();
	void output();
	//input的辅助函数
	void quitgame();

//成员变量：
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
	while (isrunning)		//当isrunning置为1的时候，会继续loop游戏。
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
	//点×关闭游戏
	SDL_Event mevent;
	while (SDL_PollEvent(&mevent))
	{
		if (mevent.type == SDL_QUIT)
		{
			isrunning = false;
		}
	}
	//用exc键退出游戏
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
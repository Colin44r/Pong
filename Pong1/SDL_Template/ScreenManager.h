#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"

class ScreenManager {
private:
	static ScreenManager * sInstance;

	enum Screens { Start, Play };
	Screens mCurrentScreen;

	InputManager * mInput;

	StartScreen * mStartScreen;
	PlayScreen * mPlayScreen;
	bool mGameOverReset;

public:
	static ScreenManager * Instance();
	static void Release();
	bool GetmGameOverReset();
	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};
#endif
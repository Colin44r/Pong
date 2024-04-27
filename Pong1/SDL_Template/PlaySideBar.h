#ifndef __PLAYSIDEBAR_H
#define __PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"

class PlaySideBar : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	//Texture * mBackground;

	/*Texture * mTitle;*/
	Scoreboard* mPlayer1;
	Scoreboard* mPlayer2;

private:

public:
	PlaySideBar();
	~PlaySideBar();

	void Update() override;
	void Render() override;
};
#endif
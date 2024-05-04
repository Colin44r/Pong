#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
//#include "Level.h"
#include "PlaySideBar.h"
#include "Player.h"
#include "tinyxml2.h"
#include "Ball.h"

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	PlaySideBar * mSideBar;

	GameEntity* mPlayerModes;

	Player* mLeftPaddle;
	Player* mRightPaddle;
	Texture* mMiddleLine;
	Texture* mScorePlayer1;
	Texture* mScorePlayer2;
	Ball* mBall;

	//Texture * mStartLabel;

	//float mLevelStartTimer;
	//float mLevelStartDelay;

	bool mGameStarted;
	bool mPlayerHit;
	bool mPlayer2Hit;
	//Level * mLevel;
	bool mLevelStarted;
	int mCurrentStage;

	//Player * mPlayer;

private:
	void StartNextLevel();
	void HandleCollisions();

public:
	PlayScreen();
	~PlayScreen();

	void StartNewGame();

	bool GameOver();

	void Update() override;
	void Render() override;
};
#endif
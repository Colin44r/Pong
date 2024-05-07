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
	Texture* mGameOverScreen;
	Texture* mGameOverBlackScreen;

	Ball* mBall;

	Scoreboard* mScorePlayer1;
	Scoreboard* mScorePlayer2;

	//Texture * mStartLabel;

	//float mLevelStartTimer;
	//float mLevelStartDelay;

	bool mGameStarted;
	bool mPlayerHit;
	bool mPlayer2Hit;
	//Level * mLevel;
	bool mLevelStarted;
	int mCurrentStage;
	int mPlayer1Score;
	int mPlayer2Score;
	//Player * mPlayer;

private:
	void StartNextLevel();
	void HandleCollisions();
	bool mGameOver;
	float mGameOverTimer;
	float mTimerDuration;
	bool mDisplayGameOverScreen;

public:
	PlayScreen();
	~PlayScreen();

	void StartNewGame();

	bool GameOver();

	void Update() override;
	void Render() override;
};
#endif
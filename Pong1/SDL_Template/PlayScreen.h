#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
//#include "Level.h"
#include "PlaySideBar.h"
#include "Player.h"
#include "tinyxml2.h"
class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	PlaySideBar * mSideBar;

	GameEntity* mPlayerModes;

	Player* mLeftPaddle;
	Player* mRightPaddle;
	Texture* mMiddleLine;
	Scoreboard* mScorePlayer1;
	Scoreboard* mScorePlayer2;
	Texture* mBall;

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

public:
	PlayScreen();
	~PlayScreen();

	void StartNewGame();

	bool GameOver();

	void Update() override;
	void Render() override;
};
#endif
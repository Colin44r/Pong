#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "PlaySideBar.h"
#include "Player.h"
#include "tinyxml2.h"
#include "Ball.h"
#include "GoalPosts.h"

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;
	PlaySideBar * mSideBar;
	GameEntity* mPlayerModes;
	Player* mLeftPaddle;
	Player* mRightPaddle;
	Texture* mMiddleLine;
	Texture* mMiddleLine1;
	Texture* mMiddleLine2;
	Texture* mMiddleLine3;
	Texture* mMiddleLine4;
	Texture* mMiddleLine5;
	Texture* mMiddleLine6;
	Texture* mMiddleLine7;
	Texture* mMiddleLine8;
	Texture* mGameOverScreen;
	Texture* mGameOverBlackScreen;
	GoalPosts* mGoalPosts;
	GoalPosts* mGoalPosts2;
	Ball* mBall;
	Ball* mBall2;

	Ball* mBall3;

	Scoreboard* mScorePlayer1;
	Scoreboard* mScorePlayer2;

	bool mGameStarted;
	bool mPlayerHit;
	bool mPlayer2Hit;
	bool mLevelStarted;
	int mCurrentStage;
	int mSelectedMode;
	int mMiddleLineChange;
	float mCannotBeHitColour;
	float mFlashingLightsTimer;
	bool mColourChange;
	int mSelectedColor;
	int mSelectedColor2;
	float mTimerColorLoop;
	float mTimerColorLoop2;

private:
	void StartNextLevel();
	void HandleCollisions();
	bool mGameOver;
	bool mSpawnBalls;
	float mGameOverTimer;
	float mTimerDuration;
	bool mDisplayGameOverScreen;
	float mCanBeHit;
	float mCannotBeHit;
public:
	PlayScreen();
	~PlayScreen();
	void StartNewGame();
	bool GameOver();
	void SetSelectedMode(int change);
	void Update() override;
	void Render() override;
};
#endif
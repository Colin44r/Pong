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
	Texture* mGameOverScreen;
	Texture* mGameOverBlackScreen;
	GoalPosts* mGoalPosts;
	GoalPosts* mGoalPosts2;
	Ball* mBall;
	Ball* mBall2;
	Scoreboard* mScorePlayer1;
	Scoreboard* mScorePlayer2;

	bool mGameStarted;
	bool mPlayerHit;
	bool mPlayer2Hit;
	bool mLevelStarted;
	int mCurrentStage;
	int mSelectedMode;
	

private:
	void StartNextLevel();
	void HandleCollisions();
	bool mGameOver;
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
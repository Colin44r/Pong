#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "PlaySideBar.h"
#include "AnimatedGLTexture.h";
#include "GLTexture.h";

using namespace SDLFramework;

class StartScreen : public GameEntity {
private:
	Timer* mTimer;
	InputManager* mInputManager;

	GameEntity* mTopBar;
	/*GLTexture* mPlayerOne;
	GLTexture* mPlayerTwo;
	GLTexture* mScore;
	GLTexture* mHigh;*/
	//GLTexture* m1or2Players;
	//GLTexture* m5000Display;
	//GLTexture* m0Display;
	//Texture* mRound;

	Scoreboard* mPlayerOneScore;
	Scoreboard* mPlayerTwoScore;
	Scoreboard* mTopScore;


	GameEntity* mPlayerModes;
	GLTexture* mLeftPaddle;
	GLTexture* mRightPaddle;
	GLTexture* mCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	//int GetSelectedMode();

	GameEntity* mBottomBar;
	GLTexture* mPlayWhiteBox;
	GLTexture* mPongTitle;
	GLTexture* mPlayButton;


	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;
	//bool mSelectedMode;



public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);


	void ResetAnimation();

	void Update() override;
	void Render() override;
};
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
	GameEntity* mBottomBar;
	GLTexture* mWhiteRectangle;
	GLTexture* mWhiteRectangle2;
	GLTexture* mWhiteRectangle3;
	GLTexture* mFirstMode;
	GLTexture* mSecondMode;
	GLTexture* mPongTitle;
	GLTexture* mThirdMode;
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);
	void ResetAnimation();

	void Update() override;
	void Render() override;
};
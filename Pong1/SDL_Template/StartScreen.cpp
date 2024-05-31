#include "StartScreen.h"



StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mPongTitle = new GLTexture("           PONG", "emulogic.ttf", 100, { 255, 255, 255 });
	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mLeftPaddle = new GLTexture("PongSpriteSheet.png", 365, 4, 66, 530);
	mRightPaddle = new GLTexture("PongSpriteSheet.png", 445, 4, 66, 530);
	mFirstMode = new GLTexture("Normal ", "emulogic.ttf", 40, { 0, 0, 0 });
	mSecondMode = new GLTexture("RainBow ", "emulogic.ttf", 40, { 0, 0, 0 });
	mThirdMode = new GLTexture("Insanity ", "emulogic.ttf", 40, { 0, 0, 0 });
	mWhiteRectangle = new GLTexture("PongSpriteSheet.png", 360, 94, 64, 227);
	mWhiteRectangle2 = new GLTexture("PongSpriteSheet.png", 360, 94, 64, 227);
	mWhiteRectangle3 = new GLTexture("PongSpriteSheet.png", 360, 94, 64, 227);
	mCursor = new GLTexture("Cursor.png", 0,0,31,28 );

	mBottomBar->Parent(this);
	mPongTitle->Parent(mBottomBar);
	

	mWhiteRectangle->Rotate(90);
	mWhiteRectangle2->Rotate(90);
	mWhiteRectangle3->Rotate(90);
	mTopBar->Parent(this);
	mPlayerModes->Parent(this);
	mLeftPaddle->Parent(mPlayerModes);
	mRightPaddle->Parent(mPlayerModes);
	mFirstMode->Parent(mPlayerModes);
	mSecondMode->Parent(mPlayerModes);
	mThirdMode->Parent(mPlayerModes);
	mWhiteRectangle -> Parent(mPlayerModes);
	mWhiteRectangle2->Parent(mPlayerModes);
	mWhiteRectangle3->Parent(mPlayerModes);
	mCursor->Parent(mPlayerModes);

	mCursor->Position(-245.0, -50.0f);
	mWhiteRectangle->Position(-18.0f, -50.0f);
	mWhiteRectangle2->Position(-5.0f, 40.0f);
	mWhiteRectangle3->Position(0.0f, 130.0f);
	mFirstMode->Position(0.0f, -50.0f);
	mSecondMode->Position(15.0f, 40.0f);
	mThirdMode->Position(15.0f, 130.0f);
	mLeftPaddle->Position(-450.0f, -50.0f);
	mRightPaddle->Position(450.0f, -50.0f);
	mPongTitle->Position(-825.0f, -350.0f);

	mCursor->Scale(Vector2(1.5f, 1.5f));
	mPongTitle->Scale(Vector2(1.5f, 1.0f));
	mRightPaddle->Scale(Vector2(0.25f, 0.15f));
	mLeftPaddle->Scale(Vector2(0.25f, 0.15f));
	mWhiteRectangle->Scale(Vector2(1.0f, 1.1f));
	mWhiteRectangle2->Scale(Vector2(1.0f, 1.28f));
	mWhiteRectangle3->Scale(Vector2(1.0f, 1.42f));

	mCursorStartPos = mCursor->Position(Local);
	mCursorOffset = Vector2(0, 90);
}

StartScreen::~StartScreen() {
	delete mTopBar;
	mTopBar = nullptr;
	delete mPlayerModes;
	mPlayerModes = nullptr;
	delete mLeftPaddle;
	mLeftPaddle = nullptr;
	delete mRightPaddle;
	mRightPaddle = nullptr;
	delete mPongTitle;
	mPongTitle = nullptr;
	delete mThirdMode;
	mThirdMode = nullptr;
	mTimer = nullptr;
	mInputManager = nullptr;
	mTimer = nullptr;
	mInputManager = nullptr;
	delete mFirstMode;
	mFirstMode = nullptr;
	delete mSecondMode;
	mSecondMode = nullptr;
	delete mWhiteRectangle;
	mWhiteRectangle = nullptr;
	delete 	mWhiteRectangle2;
	mWhiteRectangle2 = nullptr;
	delete 	mWhiteRectangle3;
	mWhiteRectangle3 = nullptr;
	delete mCursor;
	mCursor = nullptr;

}

void StartScreen::ResetAnimation() {

}



void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 2;
	}
	else if (mSelectedMode > 2) {
		mSelectedMode = 0;
	}
	
	// First make a "getter" for mselected mode and send it to screenmanger line 91-93 in player.cpp 
	// create a setter in playscreen grabing the value from screen manger of the getter. 
	// Refer to player.h and .cpp "GetScore" and GetLives
	// 
	// 0 = firstmode
	// 1 = second mode
	// 2 = thrid mode
	mCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

int StartScreen::GetSelectedMode() {
	return mSelectedMode;
}

void StartScreen::Update() {


	if (mInputManager->KeyPressed(SDL_SCANCODE_DOWN)) {
		ChangeSelectedMode(1);
	}
	else if (mInputManager->KeyPressed(SDL_SCANCODE_UP)) {
		ChangeSelectedMode(-1);
	}
}

void StartScreen::Render() {
	
	mWhiteRectangle->Render();
	mWhiteRectangle2->Render();
	mWhiteRectangle3->Render();
	mFirstMode->Render();
	mSecondMode->Render();
	mLeftPaddle->Render();
	mRightPaddle->Render();
	mThirdMode->Render();
	mPongTitle->Render();
	mCursor->Render();
}


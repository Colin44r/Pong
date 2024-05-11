#include "StartScreen.h"



StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	mPongTitle = new GLTexture("           PONG", "emulogic.ttf", 100, { 255, 255, 255 });
	mPlayButton = new GLTexture("PLAY", "emulogic.ttf", 40, { 0, 0, 0 });
	mPlayWhiteBox = new GLTexture("PongSpriteSheet.png", 360, 94, 64, 227);
	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mLeftPaddle = new GLTexture("PongSpriteSheet.png", 365, 4, 66, 530);
	mRightPaddle = new GLTexture("PongSpriteSheet.png", 445, 4, 66, 530);

	mBottomBar->Parent(this);
	mPlayWhiteBox->Parent(mBottomBar);
	mPongTitle->Parent(mBottomBar);
	mPlayButton->Parent(mBottomBar);

	mPlayWhiteBox->Rotate(90);
	mTopBar->Parent(this);
	mPlayerModes->Parent(this);
	mLeftPaddle->Parent(mPlayerModes);
	mRightPaddle->Parent(mPlayerModes);

	mLeftPaddle->Position(-450.0f, -50.0f);
	mRightPaddle->Position(450.0f, -50.0f);
	mPongTitle->Position(-825.0f, -350.0f);
	mPlayButton->Position(0.0f, -190.0f);
	mPlayWhiteBox->Position(0.0f, -185.0f);

	mPlayWhiteBox->Scale(Vector2(1.0f, 1.0f));
	mPongTitle->Scale(Vector2(1.5f, 1.0f));
	mRightPaddle->Scale(Vector2(0.25f, 0.15f));
	mLeftPaddle->Scale(Vector2(0.25f, 0.15f));
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
	delete mPlayWhiteBox;
	mPlayWhiteBox = nullptr;
	delete mPongTitle;
	mPongTitle = nullptr;
	delete mPlayButton;
	mPlayButton = nullptr;
	mTimer = nullptr;
	mInputManager = nullptr;
	mTimer = nullptr;
	mInputManager = nullptr;
}

void StartScreen::ResetAnimation() {

}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}
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
	mLeftPaddle->Render();
	mRightPaddle->Render();
	mPlayWhiteBox->Render();
	mPlayButton->Render();
	mPongTitle->Render();
}


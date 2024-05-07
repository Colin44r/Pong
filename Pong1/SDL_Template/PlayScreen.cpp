#include "PlayScreen.h"

void PlayScreen::StartNextLevel() {
	mCurrentStage += 1;
	//mLevelStartTimer = 0.0f;
	mLevelStarted = true;
	
	//delete mLevel;
	//mLevel = new Level(mCurrentStage, mSideBar, mPlayer);
}

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mGameOver = false;
	mDisplayGameOverScreen = false;
	mGameOverTimer = 0;
	mTimerDuration = 3;

	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mLeftPaddle = new Player(false);
	mRightPaddle = new Player(true);
	mScorePlayer1 = new Scoreboard();
	mScorePlayer2 = new Scoreboard();
	mMiddleLine = new GLTexture("PongSpriteSheet.png", 288, 0, 39, 1029);
	mBall = new Ball(400);
	mGameOverScreen = new GLTexture("GameOverScreen.png");
	mGameOverBlackScreen = new GLTexture("BlackScreen.png", 0, 0, 1267, 705);

	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Position(Graphics::SCREEN_WIDTH * 0.87f, Graphics::SCREEN_HEIGHT * 0.05f);

	mPlayer1Score = 0;
	mPlayer2Score = 0;


	mPlayerModes->Parent(this);
	mRightPaddle->Parent(mPlayerModes);
	mLeftPaddle->Parent(mPlayerModes);
	mScorePlayer1->Parent(mPlayerModes);
	mScorePlayer2->Parent(mPlayerModes);
	mMiddleLine->Parent(mPlayerModes);
	mBall->Parent(mPlayerModes);
	mGameOverScreen->Parent(mPlayerModes);
	mGameOverBlackScreen->Parent(mPlayerModes);

	mLeftPaddle->Position(-450.0f, -50.0f);
	mRightPaddle->Position(450.0f, -50.0f);
	mScorePlayer1->Position(-130.0f, -350.0f);
	mScorePlayer2->Position(130.0f, -350.0f);
	mMiddleLine->Position(0.0f, -50.0f);
	mBall->Position(75.0f, -50.0f);
	mGameOverScreen->Position(0.0f, -50.0f);
	mGameOverBlackScreen->Position(0.0f, -50.0f);

	mGameOverScreen->Scale(Vector2(0.40f, 0.40f));
	mGameOverBlackScreen->Scale(Vector2(2.40f, 2.40f));
	//mBall->Scale(Vector2(0.40f, 0.40f));
	//mScorePlayer1->Scale(Vector2(1.7f, 2.50f));
	//mScorePlayer2->Scale(Vector2(1.7f, 2.50f));
	




	//mStartLabel = new GLTexture("START", "emulogic.ttf", 32, { 150, 0, 0 });
	//mStartLabel->Parent(this);
	//mStartLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	//mLevel = nullptr;
	//mLevelStartDelay = 1.0f;
	mLevelStarted = false;

	//mPlayer = nullptr;
}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mPlayerModes;
	mPlayerModes = nullptr;
	delete mLeftPaddle;
	mLeftPaddle = nullptr;
	delete mRightPaddle;
	mRightPaddle = nullptr;
	delete mSideBar;
	mSideBar = nullptr;
	delete mRightPaddle;
	mRightPaddle = nullptr;
	delete mSideBar;
	mSideBar = nullptr;
	delete mScorePlayer1;
	mScorePlayer1 = nullptr;
	delete mScorePlayer2;
	mScorePlayer2 = nullptr;
	delete mMiddleLine;
	mMiddleLine = nullptr;
	delete mBall;
	mBall = nullptr;
	delete mGameOverScreen;
	mGameOverScreen = nullptr;
	delete mGameOverBlackScreen;
	mGameOverBlackScreen = nullptr;

	
	


	//delete mStartLabel;
	//mStartLabel = nullptr;

	//delete mLevel;
	//mLevel = nullptr;

	//delete mPlayer;
	//mPlayer = nullptr;
}

void PlayScreen::StartNewGame() {
	//delete mPlayer;
	//mPlayer = new Player();
	//mPlayer->Parent(this);
	//mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	//mPlayer->Active(false);
	
	//This is how to build player you WILL NEED this^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


	//mSideBar->SetHighScore(30000);
	//mSideBar->SetShips(mPlayer->Lives());
	//mSideBar->SetPlayerScore(mPlayer->Score());
	//mSideBar->SetLevel(0);

	mGameStarted = false;
	mLevelStarted = false;
	//mLevelStartTimer = 0.0f;
	mCurrentStage = 0;
}

bool PlayScreen::GameOver() {
	return mGameOver;
}

void PlayScreen::HandleCollisions() {
	if (!mPlayerHit) {
		if (mRightPaddle ->WasHit()) {
			mPlayerHit = true;
			
		}
	}
	if (!mPlayer2Hit) {
		if (mLeftPaddle->WasHit()) {
			mPlayerHit = true;

		}
	}
}

void PlayScreen::Update() {


	if (mPlayer2Score < 11 && mPlayer1Score <11){
		mBall->Update();
		mLeftPaddle->Update();
		mRightPaddle->Update();
	}

	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_H)) {
		mPlayer1Score++;
		if (mPlayer1Score >= 11) {
			mPlayer1Score = 11;
			mDisplayGameOverScreen = true;
			if (mGameOverTimer >= mTimerDuration) {
				mGameOver = true; 
			}
			else {
				mGameOverTimer += mTimer->DeltaTime();

			}
		}
		mScorePlayer1->Score(mPlayer1Score);

	}

	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_G)) {
		mPlayer2Score++;
		if (mPlayer2Score >= 11) { 
			mPlayer2Score = 11;
			mDisplayGameOverScreen = true;
			if (mGameOverTimer >= mTimerDuration) {
				mGameOver = true;
			
			}
			else {
				mGameOverTimer += mTimer->DeltaTime();
			}
			
		}
		mScorePlayer2->Score(mPlayer2Score);
	}

	if (mGameStarted) {
		
		
		
		//Setting StartNextLevel to a Debug key because every game will want to call this differently
		//if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_L)) {
		//	StartNextLevel();
		//}
		//else {
		//	if (mLevel == nullptr) {
		//		StartNextLevel();
		//	}
		//	mLevel->Update();
		//	if (mLevel->State() == Level::Finished) {
		//		mLevelStarted = false;
		//	}
		//}

		////if (mCurrentStage > 0) {
		////	mSideBar->Update();
		////}

		////mPlayer->Update();
		//
		//
		//mSideBar->SetPlayerScore(mPlayer->Score());
	}
	else {
		if (!Mix_PlayingMusic()) {
			mGameStarted = true;
		}
	}
}

void PlayScreen::Render() {
	//if (!mGameStarted) {
	//	mStartLabel->Render();
	//}
	
	mMiddleLine->Render();
	mBall->Render();
	mSideBar->Render();
	mLeftPaddle->Render();
	mRightPaddle->Render();
	mScorePlayer1->Render();
	mScorePlayer2->Render();
	
	if (mDisplayGameOverScreen == true) {
		mGameOverBlackScreen->Render();
		mGameOverScreen->Render();
		
	}
	
	


	if (mGameStarted) {

		if (mLevelStarted) {
			//mLevel->Render();
		}

		//mPlayer->Render();
	}

	





}

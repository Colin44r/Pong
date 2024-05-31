#include "PlayScreen.h"

void PlayScreen::StartNextLevel() {
	mCurrentStage += 1;
	mLevelStarted = true;
	
}
PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mGameOver = false;
	mDisplayGameOverScreen = false;
	mGameOverTimer = 0;
	mTimerDuration = 3;
	mCanBeHit = 0;
	mCannotBeHit = 0.50;
	mFlashingLightsTimer = 0.0;
	mCannotBeHitColour = 0.25;
	//mTimerColorLoop = 1.0;
	//mTimerColorLoop2 = 0.0;

	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mLeftPaddle = new Player(false);
	mRightPaddle = new Player(true);
	mScorePlayer1 = new Scoreboard();
	mScorePlayer2 = new Scoreboard();

	mBall = new Ball(450, "Ball1");
	mBall2 = new Ball(550, "Ball2");
	mBall3 = new Ball(350, "Ball3"); // Ball speeds
	mGoalPosts = new GoalPosts(mLeftPaddle, mRightPaddle, mBall, mBall2, mBall3);
	mGoalPosts2 = new GoalPosts(mLeftPaddle, mRightPaddle, mBall, mBall2, mBall3);

	mGameOverScreen = new GLTexture("GameOverScreen.png");
	mGameOverBlackScreen = new GLTexture("BlackScreen.png", 0, 0, 1267, 705);

	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Position(Graphics::SCREEN_WIDTH * 0.87f, Graphics::SCREEN_HEIGHT * 0.05f);

	mPlayerModes->Parent(this);
	mRightPaddle->Parent(mPlayerModes);
	mLeftPaddle->Parent(mPlayerModes);
	mScorePlayer1->Parent(mPlayerModes);
	mScorePlayer2->Parent(mPlayerModes);
	mBall->Parent(mPlayerModes);
	mBall2->Parent(mPlayerModes);
	mBall3->Parent(mPlayerModes);
	mGameOverScreen->Parent(mPlayerModes);
	mGameOverBlackScreen->Parent(mPlayerModes);

	mLeftPaddle->Position(-450.0f, -50.0f);
	mRightPaddle->Position(450.0f, -50.0f);
	mScorePlayer1->Position(-130.0f, -350.0f);
	mScorePlayer2->Position(130.0f, -350.0f);

	mBall->Position(75.0f, -50.0f);
	mBall2->Position(90.0f, -10.0f);
	mBall3->Position(85.0f, -20.0f); // Change numbers for new balls to change direction

	mGameOverScreen->Position(0.0f, -50.0f);
	mGameOverBlackScreen->Position(0.0f, -50.0f);
	mGoalPosts->Position(0.0f, 425.0f);
	mGoalPosts2->Position(1024.0f, 425.0f);

	mGameOverScreen->Scale(Vector2(0.40f, 0.40f));
	mGameOverBlackScreen->Scale(Vector2(2.40f, 2.40f));
	mLevelStarted = false;


	mMiddleLine = new GLTexture("PongSpriteSheet.png", 288, 0, 39, 1029);
	mMiddleLine->Parent(mPlayerModes);
	mMiddleLine->Position(0.0f, -50.0f);
	mMiddleLine1 = new GLTexture("WallPongSpriteSheet.png", 0, 0, 40, 1029);
	mMiddleLine1->Parent(mPlayerModes);
	mMiddleLine1->Position(0.0f, -50.0f);
	mMiddleLine2 = new GLTexture("WallPongSpriteSheet.png", 0, 31, 40, 1029);
	mMiddleLine2->Parent(mPlayerModes);
	mMiddleLine2->Position(0.0f, -50.0f);
	mMiddleLine3 = new GLTexture("WallPongSpriteSheet.png", 0, 66, 40, 1029);
	mMiddleLine3->Parent(mPlayerModes);
	mMiddleLine3->Position(0.0f, -50.0f);
	mMiddleLine4 = new GLTexture("WallPongSpriteSheet.png", 0, 103, 40, 1029);
	mMiddleLine4->Parent(mPlayerModes);
	mMiddleLine4->Position(0.0f, -50.0f);
	mMiddleLine5 = new GLTexture("WallPongSpriteSheet.png", 0, 141, 40, 1029);
	mMiddleLine5->Parent(mPlayerModes);
	mMiddleLine5->Position(0.0f, -50.0f);
	mMiddleLine6 = new GLTexture("WallPongSpriteSheet.png", 0, 178, 40, 1029);
	mMiddleLine6->Parent(mPlayerModes);
	mMiddleLine6->Position(0.0f, -50.0f);
	mMiddleLine7 = new GLTexture("WallPongSpriteSheet.png", 0, 215, 40, 1029);
	mMiddleLine7->Parent(mPlayerModes);
	mMiddleLine7->Position(0.0f, -50.0f);
	mMiddleLine8 = new GLTexture("WallPongSpriteSheet.png", 0, 250, 40, 1029);
	mMiddleLine8->Parent(mPlayerModes);
	mMiddleLine8->Position(0.0f, -50.0f);

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
	delete mBall2;
	mBall2 = nullptr;
	delete mBall3;
	mBall3 = nullptr;
	delete mGameOverScreen;
	mGameOverScreen = nullptr;
	delete mGameOverBlackScreen;
	mGameOverBlackScreen = nullptr;
	delete mGoalPosts;
	mGoalPosts = nullptr;
	delete mGoalPosts2;
	mGoalPosts2 = nullptr;
	delete mBall2;
	mBall2 = nullptr;
	delete mMiddleLine1;
	mMiddleLine1 = nullptr;
	delete mMiddleLine2;
	mMiddleLine2 = nullptr;
	delete mMiddleLine3;
	mMiddleLine3 = nullptr;
	delete mMiddleLine4;
	mMiddleLine4 = nullptr;
	delete mMiddleLine5;
	mMiddleLine5 = nullptr;
	delete mMiddleLine6;
	mMiddleLine6 = nullptr;
	delete mMiddleLine7;
	mMiddleLine7 = nullptr;
	delete mMiddleLine8;
	mMiddleLine8 = nullptr;

}

void PlayScreen::StartNewGame() {
	mGameOver = false;
	mDisplayGameOverScreen = false;
	mLeftPaddle->SetScore(0);
	mRightPaddle->SetScore(0);
	mGameOverTimer = 0;
	mTimerDuration = 3;
	mCanBeHit = 0;
	mCannotBeHit = 0.50;
	mGameStarted = false;
	mLevelStarted = false;
	mCurrentStage = 0;
	mLeftPaddle->Position(-450.0f, -50.0f);
	mRightPaddle->Position(450.0f, -50.0f);
}

bool PlayScreen::GameOver() {
	return mGameOver;
	
}

void PlayScreen::HandleCollisions() {
	
}

void PlayScreen::SetSelectedMode(int change) {
	mSelectedMode = change;
	std::cout << "Mode Selected " <<mSelectedMode << std::endl;
}

void PlayScreen::Update() {
	
	mRightPaddle->SetSelectedMode(mSelectedMode);
	mLeftPaddle->SetSelectedMode(mSelectedMode);
	mBall->SetSelectedMode(mSelectedMode);

	if (mLeftPaddle->GetScore() < 11 && mRightPaddle->GetScore() <11){
		mBall->Update();
		mLeftPaddle->Update();
		mRightPaddle->Update();
	}

	if (mLeftPaddle->GetScore() >= 11) {
			mLeftPaddle->SetScore(11);
			mDisplayGameOverScreen = true;
			
		if (mGameOverTimer >= mTimerDuration) {
				mGameOver = true; 
			
				
		}
		else {
				mGameOverTimer += mTimer->DeltaTime();
				
		}
	}
		mScorePlayer1->Score(mLeftPaddle->GetScore());

	if (mRightPaddle->GetScore() >= 11) {
		mRightPaddle->SetScore(11);
		mDisplayGameOverScreen = true;
		
		if (mGameOverTimer >= mTimerDuration) {
				mGameOver = true;
	
		}
		else {
			mGameOverTimer += mTimer->DeltaTime();

		}
			
	}
		mScorePlayer2->Score(mRightPaddle->GetScore());


		if (mSelectedMode == 0) {

		}

		else if (mSelectedMode == 1) {
			
			
			//if (mTimerColorLoop >= mTimerColorLoop2) {


				//mSelectedColor = Random::Instance()->RandomRange(1, 10);
				//mSelectedColor2 = Random::Instance()->RandomRange(1, 10);

				if (mFlashingLightsTimer >= mCannotBeHitColour) {
					mSelectedColor += 1;
					if (mSelectedColor > 7) {
						mSelectedColor = 1;

					}

					mFlashingLightsTimer = 0;
				}
				else {
					mFlashingLightsTimer += mTimer->DeltaTime();
				}


			//}
			




		}

		else if (mSelectedMode == 2) {
			//if (mSpawnBalls = true);
			mBall2->Update();
			mBall3->Update();
			mLeftPaddle->SetMoveSpeed(750);
			mRightPaddle->SetMoveSpeed(750); // Paddle speeds

		}


	if (mGameStarted) {
	}
	else {
		if (!Mix_PlayingMusic()) {
			mGameStarted = true;
		}
	}
}

void PlayScreen::Render() {
	
	mBall->Render();
	mSideBar->Render();
	mLeftPaddle->Render();
	mRightPaddle->Render();
	mScorePlayer1->Render();
	mScorePlayer2->Render();
	mGoalPosts->Render();
	mGoalPosts2->Render();

	if (mGameStarted) {
		if (mLevelStarted) {
		}
	}




	if (mSelectedMode == 0) {
		mMiddleLine->Render();
	}

	
	else if (mSelectedMode == 1) {
		
		if (mSelectedColor == 1) {
			mMiddleLine1->Render();
		}
		else if (mSelectedColor == 2) {
			mMiddleLine2->Render();
		}
		else if (mSelectedColor == 3) {
			mMiddleLine3->Render();
		}
		else if (mSelectedColor == 4) {
			mMiddleLine4->Render();
		}
		else if (mSelectedColor == 5) {
			mMiddleLine5->Render();
		}
		else if (mSelectedColor == 6) {
			mMiddleLine6->Render();
		}
		else if (mSelectedColor == 7) {
			mMiddleLine7->Render();
		}
		else if (mSelectedColor == 8) {
			mMiddleLine8->Render();
		}
		

		


	}

	else if (mSelectedMode == 2) {
		mBall2->Render();
		mMiddleLine->Render();
	}
	



	

	else if (mSelectedMode == 1) {



	}

	else if (mSelectedMode == 2) {
		//if (mSpawnBalls = true);
		mBall2->Render();
		mBall3->Render();

	}

	if (mDisplayGameOverScreen == true) {
		mGameOverBlackScreen->Render();
		mGameOverScreen->Render();
	}

}

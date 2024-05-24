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

	mPlayerModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mLeftPaddle = new Player(false);
	mRightPaddle = new Player(true);
	mScorePlayer1 = new Scoreboard();
	mScorePlayer2 = new Scoreboard();
	mMiddleLine = new GLTexture("PongSpriteSheet.png", 288, 0, 39, 1029, {255, 0, 255});
	mBall = new Ball(450);
	mBall2 = new Ball(450);
	mGoalPosts = new GoalPosts(mLeftPaddle, mRightPaddle, mBall);
	mGoalPosts2 = new GoalPosts(mLeftPaddle, mRightPaddle, mBall);
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
	mMiddleLine->Parent(mPlayerModes);
	mBall->Parent(mPlayerModes);
	mBall2->Parent(mPlayerModes);
	mGameOverScreen->Parent(mPlayerModes);
	mGameOverBlackScreen->Parent(mPlayerModes);

	mLeftPaddle->Position(-450.0f, -50.0f);
	mRightPaddle->Position(450.0f, -50.0f);
	mScorePlayer1->Position(-130.0f, -350.0f);
	mScorePlayer2->Position(130.0f, -350.0f);
	mMiddleLine->Position(0.0f, -50.0f);
	mBall->Position(75.0f, -50.0f);
	mBall2->Position(45.0f, -50.0f);
	mGameOverScreen->Position(0.0f, -50.0f);
	mGameOverBlackScreen->Position(0.0f, -50.0f);
	mGoalPosts->Position(0.0f, 425.0f);
	mGoalPosts2 ->Position(1024.0f, 425.0f);

	mGameOverScreen->Scale(Vector2(0.40f, 0.40f));
	mGameOverBlackScreen->Scale(Vector2(2.40f, 2.40f));
	mLevelStarted = false;

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
	delete mGoalPosts;
	mGoalPosts = nullptr;
	delete mGoalPosts2;
	mGoalPosts2 = nullptr;
	delete mBall2;
	mBall2 = nullptr;

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
		/*	
				if (mWasHit == true) {
					return;
				}
				mWasHit = true;*/

				



			


		}

		else if (mSelectedMode == 2) {
			mBall2->Update();
			
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
	mMiddleLine->Render();
	mBall->Render();
	mSideBar->Render();
	mLeftPaddle->Render();
	mRightPaddle->Render();
	mScorePlayer1->Render();
	mScorePlayer2->Render();
	mGoalPosts->Render();
	mGoalPosts2->Render();

	if (mDisplayGameOverScreen == true) {
		mGameOverBlackScreen->Render();
		mGameOverScreen->Render();
	}

	if (mGameStarted) {
		if (mLevelStarted) {
		}
	}



	if (mSelectedMode == 0) {

	}

	else if (mSelectedMode == 1) {
		


	}

	else if (mSelectedMode == 2) {
		mBall2->Render();

	}
	





}

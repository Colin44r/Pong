#include "Player.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"


void Player::HandleMovement() {



	if (mIsPlayer1) {
		if (mInput->KeyDown(SDL_SCANCODE_DOWN)) {
			Translate(-Vec2_Down * mMoveSpeed * mTimer->DeltaTime(), World);
			
		}
		 if (mInput->KeyDown(SDL_SCANCODE_UP)) {
			Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		}
	}

	else{
		if (mInput->KeyDown(SDL_SCANCODE_S)) {
			Translate(-Vec2_Down * mMoveSpeed * mTimer->DeltaTime(), World);
		}
		 if (mInput->KeyDown(SDL_SCANCODE_W)) {
			Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		}
	}

	Vector2 pos = Position(Local);
	if (pos.y < mMoveBounds.x) {
		pos.y = mMoveBounds.x;
	}
	else if (pos.y > mMoveBounds.y) {
		pos.y= mMoveBounds.y;
	}

	Position(pos);
}


Player::Player(bool mPlayer1) {
	mIsPlayer1 = mPlayer1;
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();
	mName = "Player";

	mVisible = false;
	mWasHit = false;
	mCanBeHit = 0;
	mCannotBeHit = 0.50;
	mScore = 0;
	mLives = 2;
	
	if (mIsPlayer1) {
		mRightPaddle = new GLTexture("PongSpriteSheet.png", 445, 4, 66, 530);
		mRightPaddle->Parent(this);
		mRightPaddle->Position(Vec2_Zero);
		mRightPaddle->Scale(Vector2(0.25f, 0.15f));
		mRightPaddlePink = new GLTexture("PlayerPongSpriteSheet.png", 777, 539, 66, 530);
		mRightPaddlePink->Parent(this);
		mRightPaddlePink->Position(Vec2_Zero);
		mRightPaddlePink->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleRed = new GLTexture("PlayerPongSpriteSheet.png", 94, 0, 66, 530);
		mRightPaddleRed->Parent(this);
		mRightPaddleRed->Position(Vec2_Zero);
		mRightPaddleRed->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleBlue = new GLTexture("PlayerPongSpriteSheet.png", 265, 0, 66, 530);
		mRightPaddleBlue ->Parent(this);
		mRightPaddleBlue ->Position(Vec2_Zero);
		mRightPaddleBlue ->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleGreen = new GLTexture("PlayerPongSpriteSheet.png", 433, 0, 66, 530);
		mRightPaddleGreen->Parent(this);
		mRightPaddleGreen->Position(Vec2_Zero);
		mRightPaddleGreen->Scale(Vector2(0.25f, 0.15f));
		mRightPaddlePurple = new GLTexture("PlayerPongSpriteSheet.png", 609, 0, 66, 530);
		mRightPaddlePurple->Parent(this);
		mRightPaddlePurple->Position(Vec2_Zero);
		mRightPaddlePurple->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleOrange = new GLTexture("PlayerPongSpriteSheet.png", 778, 0, 66, 530);
		mRightPaddleOrange->Parent(this);
		mRightPaddleOrange->Position(Vec2_Zero);
		mRightPaddleOrange->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleCyan = new GLTexture("PlayerPongSpriteSheet.png", 96, 539, 66, 530);
		mRightPaddleCyan->Parent(this);
		mRightPaddleCyan->Position(Vec2_Zero);
		mRightPaddleCyan->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleYellow = new GLTexture("PlayerPongSpriteSheet.png", 265, 541, 66, 530);
		mRightPaddleYellow->Parent(this);
		mRightPaddleYellow->Position(Vec2_Zero);
		mRightPaddleYellow->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleMaroon = new GLTexture("PlayerPongSpriteSheet.png", 435, 542, 66, 530);
		mRightPaddleMaroon->Parent(this);
		mRightPaddleMaroon->Position(Vec2_Zero);
		mRightPaddleMaroon->Scale(Vector2(0.25f, 0.15f));
		mRightPaddleNeonGreen = new GLTexture("PlayerPongSpriteSheet.png", 606, 544, 66, 530);
		mRightPaddleNeonGreen->Parent(this);
		mRightPaddleNeonGreen->Position(Vec2_Zero);
		mRightPaddleNeonGreen->Scale(Vector2(0.25f, 0.15f));
	 

	}
	else {
		mLeftPaddle = new GLTexture("PongSpriteSheet.png", 365, 4, 66, 530);
		mLeftPaddle->Parent(this);
		mLeftPaddle->Position(Vec2_Zero);
		mLeftPaddle->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddlePink = new GLTexture("PlayerPongSpriteSheet.png", 684, 539, 66, 530);
		mLeftPaddlePink->Parent(this);
		mLeftPaddlePink->Position(Vec2_Zero);
		mLeftPaddlePink->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleRed = new GLTexture("PlayerPongSpriteSheet.png", 0, 0, 66, 530);
		mLeftPaddleRed->Parent(this);
		mLeftPaddleRed->Position(Vec2_Zero);
		mLeftPaddleRed->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleBlue = new GLTexture("PlayerPongSpriteSheet.png", 171, 0, 66, 530);
		mLeftPaddleBlue->Parent(this);
		mLeftPaddleBlue->Position(Vec2_Zero);
		mLeftPaddleBlue->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleGreen = new GLTexture("PlayerPongSpriteSheet.png", 342, 0, 66, 530);
		mLeftPaddleGreen->Parent(this);
		mLeftPaddleGreen->Position(Vec2_Zero);
		mLeftPaddleGreen->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddlePurple = new GLTexture("PlayerPongSpriteSheet.png", 514, 0, 66, 530);
		mLeftPaddlePurple->Parent(this);
		mLeftPaddlePurple->Position(Vec2_Zero);
		mLeftPaddlePurple->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleOrange = new GLTexture("PlayerPongSpriteSheet.png", 684, 0, 66, 530);
		mLeftPaddleOrange->Parent(this);
		mLeftPaddleOrange->Position(Vec2_Zero);
		mLeftPaddleOrange->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleCyan = new GLTexture("PlayerPongSpriteSheet.png", 0, 539, 66, 530);
		mLeftPaddleCyan->Parent(this);
		mLeftPaddleCyan->Position(Vec2_Zero);
		mLeftPaddleCyan->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleYellow = new GLTexture("PlayerPongSpriteSheet.png", 169, 542, 66, 530);
		mLeftPaddleYellow->Parent(this);
		mLeftPaddleYellow->Position(Vec2_Zero);
		mLeftPaddleYellow->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleMaroon = new GLTexture("PlayerPongSpriteSheet.png", 340, 542, 66, 530);
		mLeftPaddleMaroon->Parent(this);
		mLeftPaddleMaroon->Position(Vec2_Zero);
		mLeftPaddleMaroon->Scale(Vector2(0.25f, 0.15f));
		mLeftPaddleNeonGreen = new GLTexture("PlayerPongSpriteSheet.png", 511, 545, 66, 530);
		mLeftPaddleNeonGreen->Parent(this);
		mLeftPaddleNeonGreen->Position(Vec2_Zero);
		mLeftPaddleNeonGreen->Scale(Vector2(0.25f, 0.15f));

	}



	mMoveSpeed = 450.0f;
	mMoveBounds = Vector2(-451.0f, 361.0f);
	AddCollider(new BoxCollider(Vector2(16.0f, 84.0f)));
	

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);
}

Player::~Player() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;
	delete mRightPaddle;
	mRightPaddle = nullptr;
	delete mLeftPaddle;
	mLeftPaddle = nullptr;
	delete mRightPaddlePink;
	mRightPaddlePink = nullptr;
	delete mRightPaddleRed;
	mRightPaddleRed = nullptr;
	delete mRightPaddleBlue;
	mRightPaddleBlue = nullptr;
	delete mRightPaddleGreen;
	mRightPaddleGreen = nullptr;
	delete mRightPaddlePurple;
	mRightPaddlePurple = nullptr;
	delete mRightPaddleOrange;
	mRightPaddleOrange = nullptr;
	delete mRightPaddleCyan;
	mRightPaddleCyan = nullptr;
	delete mRightPaddleYellow;
	mRightPaddleYellow = nullptr;
	delete mRightPaddleMaroon;
	mRightPaddleMaroon = nullptr;
	delete mRightPaddleNeonGreen;
	mRightPaddleNeonGreen = nullptr;
	delete mLeftPaddlePink;
	mLeftPaddlePink = nullptr;
	delete mLeftPaddleRed;
	mLeftPaddleRed = nullptr;
	delete mLeftPaddleBlue;
	mLeftPaddleBlue = nullptr;
	delete mLeftPaddleGreen;
	mLeftPaddleGreen = nullptr;
	delete mLeftPaddlePurple;
	mLeftPaddlePurple = nullptr;
	delete mLeftPaddleOrange;
	mLeftPaddleOrange = nullptr;
	delete mLeftPaddleCyan;
	mLeftPaddleCyan = nullptr;
	delete mLeftPaddleYellow;
	mLeftPaddleYellow = nullptr;
	delete mLeftPaddleMaroon;
	mLeftPaddleMaroon = nullptr;
	delete mLeftPaddleNeonGreen;
	mLeftPaddleNeonGreen = nullptr;
}

void Player::Visible(bool visible) {
	mVisible = visible;
}

int Player::GetScore() {
	return mScore;
}

int Player::GetLives() {
	return mLives;
}

void Player::AddScore(int change) {
	mScore += change;
}

void Player::SetScore(int change) {
	mScore = change;
}

void Player::Hit(PhysEntity * other) {
	if(mWasHit == true){
		return;
    }

	mSelectedColor = Random::Instance()->RandomRange(0, 10);
	mSelectedColor2 = Random::Instance()->RandomRange(0, 10);
	mLives -= 1;
	mAudio->PlaySFX("SFX/PongHitNoise.mp3");
	mWasHit = true;

}

bool Player::WasHit() {
	if (!mWasHit) {
		return mWasHit;
	}
	
}

void Player::Update() {
	HandleMovement();
	if (mWasHit) {
		

		if (mCanBeHit >= mCannotBeHit) {
				mWasHit = false;
				mCanBeHit = 0;
		}
		else {
				mCanBeHit += mTimer->DeltaTime();

		}
		
	}
}

void Player::Render() {

	if (mIsPlayer1) {
		
		if (mSelectedColor == 0) {
			mRightPaddle->Render();

		}
		else if (mSelectedColor == 1) {
			mRightPaddlePink->Render();
		}
		else if (mSelectedColor == 2) {
			mRightPaddleRed->Render();
		}
		else if (mSelectedColor == 3) {
			mRightPaddleBlue->Render();
		}
		else if (mSelectedColor == 4) {
			mRightPaddleGreen->Render();
		}
		else if (mSelectedColor == 5) {
			mRightPaddlePurple->Render();
		}
		else if (mSelectedColor == 6) {
			mRightPaddleOrange->Render();
		}
		else if (mSelectedColor == 7) {
			mRightPaddleCyan->Render();
		}
		else if (mSelectedColor == 8) {
			mRightPaddleYellow->Render();
		}
		else if (mSelectedColor == 9) {
			mRightPaddleMaroon->Render();
		}
		else if (mSelectedColor == 10) {
			mRightPaddleNeonGreen->Render();
		}

	}
	else{
		if (mSelectedColor2 == 0) {
			mLeftPaddle->Render();

		}
		else if (mSelectedColor2 == 1) {
			std::cout << "lpink" << std::endl;
			mLeftPaddlePink->Render();
			
		}
		else if (mSelectedColor2 == 2) {
			std::cout << "lred" << std::endl;
			mLeftPaddleRed->Render();
		}
		else if (mSelectedColor2 == 3) {
			std::cout << "lblue" << std::endl;
			mLeftPaddleBlue->Render();
		}
		else if (mSelectedColor2 == 4) {
			std::cout << "lgreen" << std::endl;
			mLeftPaddleGreen->Render();
		}
		else if (mSelectedColor2 == 5) {
			std::cout << "lpruple" << std::endl;
			mLeftPaddlePurple->Render();
		}
		else if (mSelectedColor2 == 6) {
			std::cout << "lorange" << std::endl;
			mLeftPaddleOrange->Render();
		}
		else if (mSelectedColor2 == 7) {
			std::cout << "lcyan" << std::endl;
			mLeftPaddleCyan->Render();
		}
		else if (mSelectedColor2 == 8) {
			std::cout << "lYellow" << std::endl;
			mLeftPaddleYellow->Render();
		}
		else if (mSelectedColor2 == 9) {
			std::cout << "lMaroon" << std::endl;
			mLeftPaddleMaroon->Render();
		}
		else if (mSelectedColor2 == 10) {
			std::cout << "lNeonGreen" << std::endl;
			mLeftPaddleNeonGreen->Render();
		}
		
	}
	PhysEntity::Render();
}

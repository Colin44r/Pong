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
		
	}
	else {
		mLeftPaddle = new GLTexture("PongSpriteSheet.png", 365, 4, 66, 530);
		mLeftPaddle->Parent(this);
		mLeftPaddle->Position(Vec2_Zero);
		mLeftPaddle->Scale(Vector2(0.25f, 0.15f));
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
}

void Player::Visible(bool visible) {
	mVisible = visible;
}

int Player::Score() {
	return mScore;
}

int Player::Lives() {
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
		mRightPaddle->Render();
	}
	else{
		mLeftPaddle->Render();
	}
	PhysEntity::Render();
}

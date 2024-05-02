#include "Player.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"

void Player::HandleMovement() {



	if (mIsPlayer1) {
		if (mInput->KeyDown(SDL_SCANCODE_DOWN)) {
			Translate(-Vec2_Down * mMoveSpeed * mTimer->DeltaTime(), World);
		}
		else if (mInput->KeyDown(SDL_SCANCODE_UP)) {
			Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		}
	}

	else{
		if (mInput->KeyDown(SDL_SCANCODE_S)) {
			Translate(-Vec2_Down * mMoveSpeed * mTimer->DeltaTime(), World);
		}
		else if (mInput->KeyDown(SDL_SCANCODE_W)) {
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

//void Player::HandleFiring() {
//	if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
//		for (int i = 0; i < MAX_BULLETS; ++i) {
//			if (!mBullets[i]->Active()) {
//				mBullets[i]->Fire(Position());
//				mAudio->PlaySFX("SFX/Fire.wav");
//				break;
//			}
//		}
//	}
//}

Player::Player(bool mPlayer1) {
	mIsPlayer1 = mPlayer1;
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();
	

	mVisible = false;
//	mAnimating = false;
	mWasHit = false;

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



	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(-451.0f, 361.0f);

	//mDeathAnimation = new AnimatedGLTexture("PlayerExplosion.png", 0, 0, 128, 128, 4, 1.0f, Animation::Layouts::Horizontal);
	//mDeathAnimation->Parent(this);
	//mDeathAnimation->Position(Vec2_Zero);
	//mDeathAnimation->SetWrapMode(Animation::WrapModes::Once);

	/*for (int i = 0; i < MAX_BULLETS; ++i) {
		mBullets[i] = new Bullet(true);
	}*/

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
//	delete mDeathAnimation;
	//mDeathAnimation = nullptr;

	/*for (auto b : mBullets) {
		delete b;
	}*/
}

void Player::Visible(bool visible) {
	mVisible = visible;
}
//
//bool Player::IsAnimating() {
//	return mAnimating;
//}

int Player::Score() {
	return mScore;
}

int Player::Lives() {
	return mLives;
}

void Player::AddScore(int change) {
	mScore += change;
}

//bool Player::IgnoreCollisions()
//{
//	return !mVisible || mAnimating;
//}

void Player::Hit(PhysEntity * other) {
	mLives -= 1;
	//mAnimating = true;
	//mDeathAnimation->ResetAnimation();
	mAudio->PlaySFX("SFX/PlayerExplosion.wav");
	mWasHit = true;
	//TODO CHange audio file to pong hit
}

bool Player::WasHit() {
	return mWasHit;
}

void Player::Update() {
	HandleMovement();

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

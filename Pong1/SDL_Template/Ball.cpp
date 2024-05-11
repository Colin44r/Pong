#include "Ball.h"

float Ball::GetYVelocity() {
	return mYVelocity;


}

float Ball::GetXVelocity() {
	return mXVelocity;


}

void Ball::Hit(PhysEntity* other) {
	if (mWasHit == true) {
		return;
	}
	mWasHit = true;

	if (other->GetName()=="Player") {
	
		if (mXVelocity == 1) {
			mXVelocity = -1;

		}

		else if (mXVelocity == -1) {
			mXVelocity = 1;

		}
	}
	
	

	}

void Ball::SetXVelocity(float change) {
	mXVelocity = change;
}

void Ball::SetYVelocity(float change) {
	mYVelocity = change;
}

Ball::Ball(float movespeed) {
	
	mCanBeHit = 0;
	mCannotBeHit = 0.50;

	mAudioBallHit = AudioManager::Instance();
	AddCollider(new BoxCollider(Vector2(25.0F, 25.0F)));
	mWasHit = false;
	mTimer = Timer::Instance();
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);
		mBall = new GLTexture("PongSpriteSheet.png", 398, 577, 83, 82);
		mBall->Parent(this);
		mBall->Position(0.0f, 0.0f);
		mBall->Scale(Vector2(0.40f, 0.40f));
		mName = "Ball";
	mMoveSpeed = movespeed;
	mMoveBounds = Vector2(-480.0f, 380.0f);
}
	void Ball::HandleMovement() {

		Vector2 pos = Position(Local);
		if (pos.y <= mMoveBounds.x) {
			mYVelocity = 1.2;
			mAudioBallHit->PlaySFX("SFX/PongHitNoise.mp3");
		}
		 if (pos.y >= mMoveBounds.y) {
			mYVelocity = -1.2;
			mAudioBallHit->PlaySFX("SFX/PongHitNoise.mp3");
		}

		Translate(Vector2(mXVelocity, mYVelocity) * mMoveSpeed * mTimer->DeltaTime(), World);
	}
	void Ball::HandleCollisions() {

	}
		Ball::~Ball() {

			delete mBall;
			mBall = nullptr;
		}
		void Ball::Update() {
			mBall->Update();
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
		void Ball::Render() {

			mBall->Render();
			PhysEntity::Render();
		}




	

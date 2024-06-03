#include "Ball.h"
#include "ScreenManager.h"

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
	mColourChange = true;

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

Ball::Ball(float movespeed, std:: string name) {
	mColourChange = false;
	mCanBeHit = 0;
	mCannotBeHit = 0.50;
	mCannotBeHitColour = 0.20;
	mFlashingLightsTimer = 0.0;
	mSelectedMode = 0;

	mAudioBallHit = AudioManager::Instance();
	AddCollider(new BoxCollider(Vector2(25.0F, 25.0F)));
	mWasHit = false;
	mTimer = Timer::Instance();
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);
		mBall = new GLTexture("PongSpriteSheet.png", 398, 577, 83, 82);
		mBall->Parent(this);
		mBall->Position(0.0f, 0.0f);
		mBall->Scale(Vector2(0.40f, 0.40f));
		mName = name;
	mMoveSpeed = movespeed;
	mMoveBounds = Vector2(-480.0f, 380.0f);
	mBall1 = new GLTexture("BallPongSpriteSheet.png", 0, 0, 78, 80);//red
	mBall1->Parent(this);
	mBall1->Position(Vec2_Zero);
	mBall1->Scale(Vector2(0.40f, 0.40f));
	mBall2 = new GLTexture("BallPongSpriteSheet.png", 78, 0, 78, 80);//blue
	mBall2->Parent(this);
	mBall2->Position(Vec2_Zero);
	mBall2->Scale(Vector2(0.40f, 0.40f));
	mBall3 = new GLTexture("BallPongSpriteSheet.png", 156, 0, 78, 80);//green
	mBall3->Parent(this);
	mBall3->Position(Vec2_Zero);
	mBall3->Scale(Vector2(0.40f, 0.40f));
	mBall4 = new GLTexture("BallPongSpriteSheet.png", 235, 0, 78, 80);//purple
	mBall4->Parent(this);
	mBall4->Position(Vec2_Zero);
	mBall4->Scale(Vector2(0.40f, 0.40f));
	mBall5 = new GLTexture("BallPongSpriteSheet.png", 312, 0, 78, 80);//orange
	mBall5->Parent(this);
	mBall5->Position(Vec2_Zero);
	mBall5->Scale(Vector2(0.40f, 0.40f));
	mBall6 = new GLTexture("BallPongSpriteSheet.png", 0, 78, 78, 80);//cyan
	mBall6->Parent(this);
	mBall6->Position(Vec2_Zero);
	mBall6->Scale(Vector2(0.40f, 0.40f));
	mBall7 = new GLTexture("BallPongSpriteSheet.png", 78, 78, 78, 80);//yellow
	mBall7->Parent(this);
	mBall7->Position(Vec2_Zero);
	mBall7->Scale(Vector2(0.40f, 0.40f));
	mBall8 = new GLTexture("BallPongSpriteSheet.png", 156, 78, 78, 80);//maroon
	mBall8->Parent(this);
	mBall8->Position(Vec2_Zero);
	mBall8->Scale(Vector2(0.40f, 0.40f));
	mBall9 = new GLTexture("BallPongSpriteSheet.png", 235, 78, 78, 80);//neon green
	mBall9->Parent(this);
	mBall9->Position(Vec2_Zero);
	mBall9->Scale(Vector2(0.40f, 0.40f));
	mBall10 = new GLTexture("BallPongSpriteSheet.png", 312, 78, 78, 80);//pink
	mBall10->Parent(this);
	mBall10->Position(Vec2_Zero);
	mBall10->Scale(Vector2(0.40f, 0.40f));

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
	void Ball::SetSelectedMode(int change) {
		mSelectedMode = change;

	}
		Ball::~Ball() {

			delete mBall;
			mBall = nullptr;
			delete mBall1;
			mBall1 = nullptr;
			delete mBall2;
			mBall2 = nullptr;
			delete mBall3;
			mBall3 = nullptr;
			delete mBall4;
			mBall4 = nullptr;
			delete mBall5;
			mBall5 = nullptr;
			delete mBall6;
			mBall6 = nullptr;
			delete mBall7;
			mBall7 = nullptr;
			delete mBall8;
			mBall8 = nullptr;
			delete mBall9;
			mBall9 = nullptr;
			delete mBall10;
			mBall10 = nullptr;
		}
		void Ball::Update() {
			mBall->Update();
			HandleMovement();
			if (ScreenManager::Instance()->GetmGameOverReset() == true) {
				mSelectedColor = 0;

			}
			if (mWasHit) {

				if (mCanBeHit >= mCannotBeHit) {
					mWasHit = false;
					mCanBeHit = 0;
				}
				else {
					mCanBeHit += mTimer->DeltaTime();
				}
				mColourChange = true;
			}

			if (mSelectedMode == 1) {
				if (mColourChange) {

					mSelectedColor = Random::Instance()->RandomRange(1, 10);
					mSelectedColor2 = Random::Instance()->RandomRange(1, 10);

					if (mFlashingLightsTimer >= mCannotBeHitColour) {
						mColourChange = false;
						mFlashingLightsTimer = 0;

					}
					else {
						mFlashingLightsTimer += mTimer->DeltaTime();

					}


				}
			}

		}
		void Ball::Render() {

			if (mSelectedColor == 0) {
				mBall->Render();
			}
			PhysEntity::Render();


			if (mSelectedMode == 1) {

				if (mSelectedColor == 1) {
					mBall1->Render();
				}
				else if (mSelectedColor == 2) {
					mBall2->Render();
				}
				else if (mSelectedColor == 3) {
					mBall3->Render();
				}
				else if (mSelectedColor == 4) {
					mBall4->Render();
				}
				else if (mSelectedColor == 5) {
					mBall5->Render();
				}
				else if (mSelectedColor == 6) {
					mBall6->Render();
				}
				else if (mSelectedColor == 7) {
					mBall7->Render();
				}
				else if (mSelectedColor == 8) {
					mBall8->Render();
				}
				else if (mSelectedColor == 9) {
					mBall9->Render();
				}
				else if (mSelectedColor == 10) {
					mBall10->Render();
				}
			}
		}




	

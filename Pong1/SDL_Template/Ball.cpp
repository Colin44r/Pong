#include "Ball.h"

float Ball::GetYVelocity() {
	return mYVelocity;


}

float Ball::GetXVelocity() {
	return mXVelocity;


}

void Ball::Hit(PhysEntity* other) {
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
	//TODO  no matter what numbers i put this was the closest i got to the box of the game... Ask calem for help
}


	void Ball::HandleMovement() {

		
		//Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);

		Vector2 pos = Position(Local);
		if (pos.y <= mMoveBounds.x) {
			mYVelocity = 1;
		}
		 if (pos.y >= mMoveBounds.y) {
			mYVelocity = -1;
		}
		/*if (pos.x <= mMoveBounds.x) {
			XVelocity = 1;
		}*/
		//else if (pos.x >= mMoveBounds.y) {
		//	XVelocity = -1;
		//}
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
			
			


		}


		void Ball::Render() {

			mBall->Render();
			PhysEntity::Render();



		}




	

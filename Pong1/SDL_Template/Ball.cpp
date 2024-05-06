#include "Ball.h"

Ball::Ball(float movespeed) {
	


	mWasHit = false;
	mTimer = Timer::Instance();


	
		mBall = new GLTexture("PongSpriteSheet.png", 398, 577, 83, 82);
		mBall->Parent(this);
		mBall->Position(0.0f, 0.0f);
		mBall->Scale(Vector2(0.40f, 0.40f));
	
	

	
	
	mMoveSpeed = movespeed;
	mMoveBounds = Vector2(-480.0f, 380.0f);
	//TODO  no matter what numbers i put this was the closest i got to the box of the game... Ask calem for help
}


	void Ball::HandleMovement() {

		
		//Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);

		Vector2 pos = Position(Local);
		if (pos.y <= mMoveBounds.x) {
			YVelocity = 1;
		}
		else if (pos.y >= mMoveBounds.y) {
			YVelocity = -1;
		}
		if (pos.x <= mMoveBounds.x) {
			XVelocity = 1;
		}
		else if (pos.x >= mMoveBounds.y) {
			XVelocity = -1;
		}
		Translate(Vector2(XVelocity, YVelocity) * mMoveSpeed * mTimer->DeltaTime(), World);

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




		}




	

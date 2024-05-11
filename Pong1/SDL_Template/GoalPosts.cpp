#include "GoalPosts.h"




void GoalPosts::Hit(PhysEntity* other) {
	/*if (mWasHit == true) {
		return;
	}*/

	if (mBall -> GetXVelocity() == 1) {
			mLeftPaddle -> AddScore(1);
			mBall->Position(0.0f, 0.0f);
			mBall->SetXVelocity(-1);
			mWasHit = true;
	}

	else if (mBall -> GetXVelocity() == -1) {
			mRightPaddle->AddScore(1);
			mBall->Position(0.0f, 0.0f);
			mBall->SetXVelocity(1);
			mWasHit = true;
	}
	
}

GoalPosts::GoalPosts(Player* mLeftPlayer, Player* mRightPlayer, Ball* Ball) {
	mTimer = Timer::Instance();
	mCanBeHit = 0;
	mCannotBeHit = 2.0;
	mWasHit = false;
	AddCollider(new BoxCollider(Vector2(25.0F, 1000.0F)));
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);
	mLeftPaddle = mLeftPlayer;
	mRightPaddle = mRightPlayer;
	mBall = Ball;


	mName = "GoalPosts";


};


void GoalPosts::Render() {
	PhysEntity::Render();
}


//Tried to add timer to ball spawn in but ran out of time 
void GoalPosts::Update() {
//	if (mWasHit) {
//
//		if (mCanBeHit >= mCannotBeHit) {
//			mWasHit = false;
//			mCanBeHit = 0;
//			if (mBall->GetXVelocity() == 1) {
//				
//			}
//			else if (mBall->GetXVelocity() == -1) {
//				
//			}
//		}
//		else {
//			mCanBeHit += mTimer->DeltaTime();
//
//		}
//
//	}
}


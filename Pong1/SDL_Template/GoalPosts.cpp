#include "GoalPosts.h"




void GoalPosts::Hit(PhysEntity* other) {
//mRightPaddle Score();

	mBall->GetXVelocity();
	mBall->GetYVelocity();


		if (mBall -> GetXVelocity() == 1) {
			mLeftPaddle -> AddScore(1);
			mBall->Position(0.0f, 0.0f);
			mBall->SetXVelocity(-1);
		}

		else if (mBall -> GetXVelocity() == -1) {
			mRightPaddle->AddScore(1);
			mBall->Position(0.0f, 0.0f);
			mBall->SetXVelocity(1);
		}
	



}

GoalPosts::GoalPosts(Player* mLeftPlayer, Player* mRightPlayer, Ball* Ball) {
	
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



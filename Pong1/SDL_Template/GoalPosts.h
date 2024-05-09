#pragma once
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "BoxCollider.h"
#include "Player.h"
#include "Ball.h"

using namespace SDLFramework;

class GoalPosts : public PhysEntity {
	
	Player* mLeftPaddle;
	Player* mRightPaddle;
	Ball* mBall;


public:

	GoalPosts(Player* mLeftPlayer, Player* mRightPlayer, Ball* Ball);
	void Hit(PhysEntity* other) override;

	void Render() override;

};
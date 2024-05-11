#pragma once
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "BoxCollider.h"
#include "Player.h"
#include "Ball.h"

using namespace SDLFramework;

class GoalPosts : public PhysEntity {
	Timer* mTimer;
	Player* mLeftPaddle;
	Player* mRightPaddle;
	Ball* mBall;
	bool mWasHit;
	float mCanBeHit;
	float mCannotBeHit;

public:

	GoalPosts(Player* mLeftPlayer, Player* mRightPlayer, Ball* Ball);
	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;

};
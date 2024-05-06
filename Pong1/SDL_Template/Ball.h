#pragma once
#include "PhysEntity.h"
#include "PhysicsHelper.h"
#include "PhysicsManager.h"
#include "Timer.h"

class Ball : public PhysEntity {
private:
	
	Timer* mTimer;
	GLTexture* mBall;

	float XVelocity = 1.0;
	float YVelocity = 1.0;

	bool mWasHit;
	float mMoveSpeed;

	Vector2 mMoveBounds;
	void HandleCollisions();
	void HandleMovement();


public:

	Ball(float movespeed);
	~Ball();



	void Update() override;
	void Render() override;







};
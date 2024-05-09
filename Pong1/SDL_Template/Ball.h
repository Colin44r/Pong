#pragma once
#include "PhysEntity.h"
#include "PhysicsHelper.h"
#include "PhysicsManager.h"
#include "Timer.h"

class Ball : public PhysEntity {
private:
	
	Timer* mTimer;
	GLTexture* mBall;

	float mXVelocity = 1.0;
	float mYVelocity = 1.0;

	bool mWasHit;
	float mMoveSpeed;

	Vector2 mMoveBounds;
	void HandleCollisions();
	void HandleMovement();
	

public:


	void SetXVelocity(float change);
	void SetYVelocity(float change);

	float GetXVelocity();
	float GetYVelocity();

	Ball(float movespeed);
	~Ball();

	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;







};
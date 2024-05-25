#pragma once
#include "PhysEntity.h"
#include "PhysicsHelper.h"
#include "PhysicsManager.h"
#include "Timer.h"
#include "AudioManager.h"

class Ball : public PhysEntity {
private:
	
	AudioManager* mAudioBallHit;
	Timer* mTimer;
	GLTexture* mBall;
	float mCanBeHit;
	float mCannotBeHit;

	float mXVelocity = 1.0;
	float mYVelocity = 1.0;

	bool mWasHit;
	float mMoveSpeed;
	bool CanBeHit;

	Vector2 mMoveBounds;
	void HandleCollisions();
	void HandleMovement();
	

public:


	void SetXVelocity(float change);
	void SetYVelocity(float change);

	float GetXVelocity();
	float GetYVelocity();

	Ball(float movespeed, std::string name);
	~Ball();

	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;







};
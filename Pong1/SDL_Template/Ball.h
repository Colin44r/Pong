#pragma once
#include "PhysEntity.h"
#include "PhysicsHelper.h"
#include "PhysicsManager.h"
#include "Timer.h"
#include "AudioManager.h"
#include "Random.h"

class Ball : public PhysEntity {
private:
	
	AudioManager* mAudioBallHit;
	Timer* mTimer;
	GLTexture* mBall;
	GLTexture* mBall1;
	GLTexture* mBall2;
	GLTexture* mBall3;
	GLTexture* mBall4;
	GLTexture* mBall5;
	GLTexture* mBall6;
	GLTexture* mBall7;
	GLTexture* mBall8;
	GLTexture* mBall9;
	GLTexture* mBall10;
	float mCanBeHit;
	float mCannotBeHit;

	float mXVelocity = 1.0;
	float mYVelocity = 1.0;

	bool mWasHit;
	float mMoveSpeed;
	bool mColourChange;
	float mCannotBeHitColour;
	float mFlashingLightsTimer;
	int mSelectedColor;
	int mSelectedColor2;
	int mSelectedMode;
	

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
	void SetSelectedMode(int change);






};
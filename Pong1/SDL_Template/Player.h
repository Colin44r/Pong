#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Bullet.h"

using namespace SDLFramework;

class Player : public PhysEntity {
private:
	Timer * mTimer;
	InputManager * mInput;
	AudioManager * mAudio;

	bool mVisible;
	bool mWasHit;
	float mCanBeHit;
	float mCannotBeHit;

	int mScore;
	int mLives;

	Texture * mRightPaddle;
	Texture* mLeftPaddle;
	
	float mMoveSpeed;
	Vector2 mMoveBounds;

private:
	void HandleMovement();
	bool mIsPlayer1;

public:
	Player(bool mPlayer1);
	~Player();

	void Visible(bool visible);
	bool IsAnimating();
	int GetScore();
	int GetLives();
	void SetScore(int change);
	void AddScore(int change);
	void Hit(PhysEntity * other) override;
	bool WasHit();
	void Update() override;
	void Render() override;
	void SetMoveSpeed(float change);
};
#endif
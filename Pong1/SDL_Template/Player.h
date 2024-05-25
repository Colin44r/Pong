#ifndef __PLAYER_H
#define __PLAYER_H
#include "AnimatedGLTexture.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Random.h"

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
	int mSelectedColor;
	int mSelectedColor2;

	Texture * mRightPaddle;
	Texture* mLeftPaddle;
	Texture* mRightPaddleRed;
	Texture* mRightPaddleBlue;
	Texture* mRightPaddleGreen;
	Texture* mRightPaddlePurple;
	Texture* mRightPaddleOrange;
	Texture* mRightPaddleCyan;
	Texture* mRightPaddleYellow;
	Texture* mRightPaddleMaroon;
	Texture* mRightPaddleNeonGreen;
	Texture* mRightPaddlePink;
	Texture* mLeftPaddleRed;
	Texture* mLeftPaddleBlue;
	Texture* mLeftPaddleGreen;
	Texture* mLeftPaddlePurple;
	Texture* mLeftPaddleOrange;
	Texture* mLeftPaddleCyan;
	Texture* mLeftPaddleYellow;
	Texture* mLeftPaddleMaroon;
	Texture* mLeftPaddleNeonGreen;
	Texture* mLeftPaddlePink;

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
};
#endif
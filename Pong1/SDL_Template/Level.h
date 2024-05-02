//#ifndef __LEVEL_H
//#define __LEVEL_H
//#include "PlaySideBar.h"
//#include "Player.h"
//#include "tinyxml2.h"
//
//using namespace tinyxml2;
//
//class Level : public GameEntity {
//public:
//	enum LevelStates { Running, Finished, GameOver };
//
//private:
//	Timer * mTimer;
//	PlaySideBar * mSideBar;
//
//	int mStage;
//	bool mStageStarted;
//
//	//float mLabelTimer;
//
//	//Texture * mStageLabel;
//	//Scoreboard * mStageNumber;
//	//float mStageLabelOnScreen;
//	//float mStageLabelOffScreen;
//
//	//Texture * mReadyLabel;
//	//float mReadyLabelOnScreen;
//	//float mReadyLabelOffScreen;
//
//	Player * mPlayer;
//	bool mPlayerHit;
//	float mRespawnDelay;
//	float mRespawnTimer;
//	float mRespawnLabelOnScreen;
//
//	Texture * mGameOverLabel;
//	float mGameOverDelay;
//	float mGameOverTimer;
//	float mGameOverLabelOnScreen;
//
//	LevelStates mCurrentState;
//
//private:
//	void StartStage();
//	void HandleStartLabels();
//	void HandleCollisions();
//	void HandlePlayerDeath();
//
//public:
//	Level(int stage, PlaySideBar * sideBar, Player * player);
//	~Level();
//
//	LevelStates State();
//
//	void Update() override;
//	void Render() override;
//};
//#endif
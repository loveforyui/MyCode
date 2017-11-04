#pragma once

class CSoundMgr
{
	DECLARE_SINGLETON(CSoundMgr)
public:
	enum CHANNEL_ID { CHANNEL_BGM, CHANNEL_PLAYER, CHANNEL_MONSTER, CHANNEL_EFFECT, CHANNEL_END };

private:
	CSoundMgr();
	~CSoundMgr();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void LoadSoundFile();
	void PlaySound(const TCHAR* pSoundKey, CHANNEL_ID eID);
	void PlayBGM(const TCHAR* pSoundKey);
	void StopSound(CHANNEL_ID eID);
	void StopSoundAll();

private:
	FMOD_SYSTEM*	m_pSystem;	// 사운드 시스템 총괄 관리자
	FMOD_CHANNEL*	m_pChannelArr[CHANNEL_END]; // 사운드를 재생하기 위한 채널 배열

	// FMOD_SOUND:사운드 리소스 정보를 갖는 사운드 타입
	map<const TCHAR*, FMOD_SOUND*>	m_MapSound; 
};


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
	FMOD_SYSTEM*	m_pSystem;	// ���� �ý��� �Ѱ� ������
	FMOD_CHANNEL*	m_pChannelArr[CHANNEL_END]; // ���带 ����ϱ� ���� ä�� �迭

	// FMOD_SOUND:���� ���ҽ� ������ ���� ���� Ÿ��
	map<const TCHAR*, FMOD_SOUND*>	m_MapSound; 
};


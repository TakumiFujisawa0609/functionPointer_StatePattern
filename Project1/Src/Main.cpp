#include <DxLib.h>

#include "Enemy/EnemyManager/EnemyManager.h"
#include "Enemy/Enemy1/Enemy1.h"
#include "Enemy/Enemy2/Enemy2.h"

// �萔
static constexpr int SCREEN_SIZE_X = 1024;
static constexpr int SCREEN_SIZE_Y = 768;

// WinMain�֐�
//---------------------------------
int WINAPI WinMain(
    _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �E�B���h�E�T�C�Y
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
	ChangeWindowMode(true);

	// DxLib�̏�����
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �`��X�N���[���̐ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	// �����E������
	EnemyManager::CreateInstance();

	// �G�̒ǉ�
	EnemyManager::GetInstance()->AddEnemy(std::make_unique<Enemy1>());
	EnemyManager::GetInstance()->AddEnemy(std::make_unique<Enemy2>());

	// ������
	EnemyManager::GetInstance()->Init();

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �G�l�~�[�X�V
		EnemyManager::GetInstance()->Update();

		// �`��X�N���[����������
		ClearDrawScreen();

		// �G�l�~�[�`��
		EnemyManager::GetInstance()->Draw();

		DrawFormatString(0, 0, 0xFFFFFF, "1,2,3 �L�[ �ŏ�ԑJ��");

		// �`��X�N���[���̐ؑ�
		ScreenFlip();
	}

	// �G�l�~�[�폜�E�}�l�[�W���[�폜
	EnemyManager::GetInstance()->Delete();
	EnemyManager::DeleteInstance();

	// DxLib�̌�n��
	if (DxLib_End() == -1)
	{
		return -1;
	}

	return 0;
}

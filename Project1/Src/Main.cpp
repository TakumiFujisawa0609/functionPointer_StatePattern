#include <DxLib.h>

#include "Enemy/EnemyManager/EnemyManager.h"
#include "Enemy/Enemy1/Enemy1.h"
#include "Enemy/Enemy2/Enemy2.h"

// 定数
static constexpr int SCREEN_SIZE_X = 1024;
static constexpr int SCREEN_SIZE_Y = 768;

// WinMain関数
//---------------------------------
int WINAPI WinMain(
    _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウサイズ
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
	ChangeWindowMode(true);

	// DxLibの初期化
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// 描画スクリーンの設定
	SetDrawScreen(DX_SCREEN_BACK);

	// 生成・初期化
	EnemyManager::CreateInstance();

	// 敵の追加
	EnemyManager::GetInstance()->AddEnemy(std::make_unique<Enemy1>());
	EnemyManager::GetInstance()->AddEnemy(std::make_unique<Enemy2>());

	// 初期化
	EnemyManager::GetInstance()->Init();

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// エネミー更新
		EnemyManager::GetInstance()->Update();

		// 描画スクリーンを初期化
		ClearDrawScreen();

		// エネミー描画
		EnemyManager::GetInstance()->Draw();

		DrawFormatString(0, 0, 0xFFFFFF, "1,2,3 キー で状態遷移");

		// 描画スクリーンの切替
		ScreenFlip();
	}

	// エネミー削除・マネージャー削除
	EnemyManager::GetInstance()->Delete();
	EnemyManager::DeleteInstance();

	// DxLibの後始末
	if (DxLib_End() == -1)
	{
		return -1;
	}

	return 0;
}

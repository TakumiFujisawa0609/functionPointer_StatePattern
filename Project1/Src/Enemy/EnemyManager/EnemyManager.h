#pragma once

#include "../EnemyBase.h"

#include <memory>
#include <vector>

class EnemyManager {
public:
    // シングルトン（生成・取得・削除）
    static void CreateInstance(void) { if (instance_ == nullptr) { instance_ = new EnemyManager(); } };
    static EnemyManager* GetInstance(void) { return instance_; };
    static void DeleteInstance(void) { if (instance_ != nullptr) { delete instance_; instance_ = nullptr; } }

public:
    // 敵の追加
    void AddEnemy(std::unique_ptr<EnemyBase> enemy);

    void Init();    // 初期化
    void Update();  // 更新
    void Draw();    // 描画
    void Delete();  // 削除

private:
    // デフォルトコンストラクタをprivateにして、外部から生成できない様にする
    EnemyManager(void);
    // デストラクタも同様
    ~EnemyManager(void);

    // コピー・ムーブ操作を禁止
    EnemyManager(const EnemyManager&) = delete;
    EnemyManager& operator=(const EnemyManager&) = delete;
    EnemyManager(EnemyManager&&) = delete;
    EnemyManager& operator=(EnemyManager&&) = delete;
    
    // 下記をコンパイルエラーさせるため 上記を追加
    // EnemyManager copy = *EnemyManager::GetInstance();
    // EnemyManager copied(*EznemyManager::GetInstance());
    // EnemyManager moved = std::move(*EnemyManager::GetInstance());

private:
    // 静的インスタンス
    static EnemyManager* instance_;

    std::vector<std::unique_ptr<EnemyBase>> enemies;
};
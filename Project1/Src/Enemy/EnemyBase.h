#pragma once
#include <DxLib.h>

#include "EnemyState.h"

class EnemyBase {
public:
    EnemyBase();   

    virtual ~EnemyBase() = default;

    virtual void Init() = 0;    // 初期化
    virtual void Draw() = 0;    // 描画
    virtual void Delete() = 0;  // 削除

    virtual void Update();      // 更新

    // 状態遷移
    void SetState(EnemyState newState);

    // 状態を返却
    EnemyState GetState() const;

    // 座標を返却
    VECTOR GetPos() const;

protected:
    // 現在の状態
    EnemyState currentState_;

    // 状態のテーブル（派生クラスでセットする）
    EnemyStateFunction stateTable_[ENEMY_STATE_MAX];

    // 座標
    VECTOR pos_;
};

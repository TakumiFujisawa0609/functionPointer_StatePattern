#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
    // 状態テーブルは派生クラスで初期化する
    currentState_ = STATE_IDLE;
}

void EnemyBase::Update()
{
    // nullチェック
    if (stateTable_[currentState_]) 
    {
        stateTable_[currentState_](*this);
    }
}

void EnemyBase::SetState(EnemyState newState) 
{
    currentState_ = newState;
}

EnemyState EnemyBase::GetState() const 
{
    return currentState_;
}

VECTOR EnemyBase::GetPos() const
{
    return pos_;
}

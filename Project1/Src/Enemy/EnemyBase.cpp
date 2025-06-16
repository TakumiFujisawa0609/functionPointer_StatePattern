#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
    // ��ԃe�[�u���͔h���N���X�ŏ���������
    currentState_ = STATE_IDLE;
}

void EnemyBase::Update()
{
    // null�`�F�b�N
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

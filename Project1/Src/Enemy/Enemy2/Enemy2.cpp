#include "Enemy2.h"
#include <iostream>

Enemy2::Enemy2() : EnemyBase()
{
    // ��Ԃ̓o�^
    // �S�����Ƃ߂�ǂ��̂łƂ肠����3��
    stateTable_[STATE_IDLE] = Idle;
    stateTable_[STATE_ATTACK] = Attack;
    stateTable_[STATE_DEAD] = Dead;
    // ��ԕʂŃN���X����Ă�����
}

void Enemy2::Init()
{
}

void Enemy2::Draw()
{
    // �K���ɕ������o���Ă܂��B
    DrawFormatString(100, 100, 0xFF0000, "���� Enemy2 �ł��B");

    switch (currentState_)
    {
    case STATE_IDLE:
        DrawFormatString(100, 120, 0xFF0000, "���݂̏�Ԃ� �ҋ@ �ł��B");
        break;
    case STATE_ATTACK:
        DrawFormatString(100, 120, 0xFF0000, "���݂̏�Ԃ� �U�� �ł��B");
        break;
    case STATE_DEAD:
        DrawFormatString(100, 120, 0xFF0000, "���݂̏�Ԃ� ���S �ł��B");
        break;
    case ENEMY_STATE_MAX:
    default:
        DrawFormatString(100, 100, 0xFF0000, "�G���[");
        break;
    }
}

void Enemy2::Delete()
{
}

void Enemy2::Idle(EnemyBase& enemy)
{
    if (CheckHitKey(KEY_INPUT_1))
    {
        // ���̏�Ԃ�
        enemy.SetState(STATE_ATTACK);
    }
}

void Enemy2::Attack(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_2))
    {
        // ���̏�Ԃ�
        enemy.SetState(STATE_DEAD);
    }
}

void Enemy2::Dead(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_3))
    {
        // ���̏�Ԃ�
        enemy.SetState(STATE_IDLE);
    }
}

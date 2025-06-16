#include "Enemy1.h"

Enemy1::Enemy1() : EnemyBase() 
{
    // ��Ԃ̓o�^
    // �S�����Ƃ߂�ǂ��̂łƂ肠����3��
    stateTable_[STATE_IDLE] = Idle;
    stateTable_[STATE_ATTACK] = Attack;
    stateTable_[STATE_RETREAT] = Retreat;
    // ��ԕʂŃN���X����Ă�����
}

void Enemy1::Init()
{
}

void Enemy1::Draw()
{
    // �K���ɕ������o���Ă܂��B
    DrawFormatString(500, 100, 0x00FF00, "���� Enemy1 �ł��B");

    switch (currentState_)
    {
    case STATE_IDLE:
        DrawFormatString(500, 120, 0x00FF00, "���݂̏�Ԃ� �ҋ@ �ł��B");
        break;
    case STATE_ATTACK:
        DrawFormatString(500, 120, 0x00FF00, "���݂̏�Ԃ� �U�� �ł��B");
        break;
    case STATE_RETREAT:
        DrawFormatString(500, 120, 0x00FF00, "���݂̏�Ԃ� ��� �ł��B");
        break;
    case ENEMY_STATE_MAX:
    default:
        DrawFormatString(500, 120, 0x00FF00, "�G���[");
        break;
    }
}

void Enemy1::Delete()
{
}

void Enemy1::Idle(EnemyBase& enemy)
{
    if (CheckHitKey(KEY_INPUT_1))
    {
        // ���̏�Ԃ�
        enemy.SetState(STATE_ATTACK);
    }
}

void Enemy1::Attack(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_2))
    {
        // ���̏�Ԃ�
        enemy.SetState(STATE_RETREAT);
    }
}

void Enemy1::Retreat(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_3))
    {
        // ���̏�Ԃ�
        enemy.SetState(STATE_IDLE);
    }
}

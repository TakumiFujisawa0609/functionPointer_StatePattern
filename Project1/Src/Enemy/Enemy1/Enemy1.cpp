#include "Enemy1.h"

Enemy1::Enemy1() : EnemyBase() 
{
    // 状態の登録
    // 全部やるとめんどいのでとりあえず3個
    stateTable_[STATE_IDLE] = Idle;
    stateTable_[STATE_ATTACK] = Attack;
    stateTable_[STATE_RETREAT] = Retreat;
    // 状態別でクラス作ってもいい
}

void Enemy1::Init()
{
}

void Enemy1::Draw()
{
    // 適当に文字を出してます。
    DrawFormatString(500, 100, 0x00FF00, "私は Enemy1 です。");

    switch (currentState_)
    {
    case STATE_IDLE:
        DrawFormatString(500, 120, 0x00FF00, "現在の状態は 待機 です。");
        break;
    case STATE_ATTACK:
        DrawFormatString(500, 120, 0x00FF00, "現在の状態は 攻撃 です。");
        break;
    case STATE_RETREAT:
        DrawFormatString(500, 120, 0x00FF00, "現在の状態は 後退 です。");
        break;
    case ENEMY_STATE_MAX:
    default:
        DrawFormatString(500, 120, 0x00FF00, "エラー");
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
        // 次の状態へ
        enemy.SetState(STATE_ATTACK);
    }
}

void Enemy1::Attack(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_2))
    {
        // 次の状態へ
        enemy.SetState(STATE_RETREAT);
    }
}

void Enemy1::Retreat(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_3))
    {
        // 次の状態へ
        enemy.SetState(STATE_IDLE);
    }
}

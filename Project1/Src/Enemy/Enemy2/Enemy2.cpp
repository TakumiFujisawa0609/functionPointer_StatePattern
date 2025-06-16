#include "Enemy2.h"
#include <iostream>

Enemy2::Enemy2() : EnemyBase()
{
    // 状態の登録
    // 全部やるとめんどいのでとりあえず3個
    stateTable_[STATE_IDLE] = Idle;
    stateTable_[STATE_ATTACK] = Attack;
    stateTable_[STATE_DEAD] = Dead;
    // 状態別でクラス作ってもいい
}

void Enemy2::Init()
{
}

void Enemy2::Draw()
{
    // 適当に文字を出してます。
    DrawFormatString(100, 100, 0xFF0000, "私は Enemy2 です。");

    switch (currentState_)
    {
    case STATE_IDLE:
        DrawFormatString(100, 120, 0xFF0000, "現在の状態は 待機 です。");
        break;
    case STATE_ATTACK:
        DrawFormatString(100, 120, 0xFF0000, "現在の状態は 攻撃 です。");
        break;
    case STATE_DEAD:
        DrawFormatString(100, 120, 0xFF0000, "現在の状態は 死亡 です。");
        break;
    case ENEMY_STATE_MAX:
    default:
        DrawFormatString(100, 100, 0xFF0000, "エラー");
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
        // 次の状態へ
        enemy.SetState(STATE_ATTACK);
    }
}

void Enemy2::Attack(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_2))
    {
        // 次の状態へ
        enemy.SetState(STATE_DEAD);
    }
}

void Enemy2::Dead(EnemyBase& enemy) 
{
    if (CheckHitKey(KEY_INPUT_3))
    {
        // 次の状態へ
        enemy.SetState(STATE_IDLE);
    }
}

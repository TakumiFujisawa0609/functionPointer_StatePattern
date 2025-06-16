#pragma once

#include "../EnemyBase.h"

class Enemy2 : public EnemyBase 
{
public:
    Enemy2();

    void Init() override;
    void Draw() override;
    void Delete() override;

private:
    static void Idle(EnemyBase& enemy);
    static void Attack(EnemyBase& enemy);
    static void Dead(EnemyBase& enemy);
};

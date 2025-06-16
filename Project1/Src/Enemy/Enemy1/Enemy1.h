#pragma once

#include "../EnemyBase.h"

class Enemy1 : public EnemyBase 
{
public:
    Enemy1();

    void Init() override;
    void Draw() override;
    void Delete() override;

private:
    static void Idle(EnemyBase& enemy);
    static void Attack(EnemyBase& enemy);
    static void Retreat(EnemyBase& enemy);
};
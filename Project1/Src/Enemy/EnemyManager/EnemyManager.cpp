#include "EnemyManager.h"

EnemyManager* EnemyManager::instance_ = nullptr;

EnemyManager::EnemyManager(void){}
EnemyManager::~EnemyManager(void){}

void EnemyManager::AddEnemy(std::unique_ptr<EnemyBase> enemy) 
{
    enemies.emplace_back(std::move(enemy));
}

void EnemyManager::Init()
{
    for (auto& enemy : enemies) 
    {
        enemy->Init();
    }
}

void EnemyManager::Update() 
{
    for (auto& enemy : enemies)
    {
        enemy->Update();
    }
}

void EnemyManager::Draw() 
{
    for (auto& enemy : enemies) 
    {
        enemy->Draw();
    }
}

void EnemyManager::Delete()
{
    for (auto& enemy : enemies)
    {
        enemy->Delete();
    }

    enemies.clear();
}

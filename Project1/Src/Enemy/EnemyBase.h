#pragma once
#include <DxLib.h>

#include "EnemyState.h"

class EnemyBase {
public:
    EnemyBase();   

    virtual ~EnemyBase() = default;

    virtual void Init() = 0;    // ������
    virtual void Draw() = 0;    // �`��
    virtual void Delete() = 0;  // �폜

    virtual void Update();      // �X�V

    // ��ԑJ��
    void SetState(EnemyState newState);

    // ��Ԃ�ԋp
    EnemyState GetState() const;

    // ���W��ԋp
    VECTOR GetPos() const;

protected:
    // ���݂̏��
    EnemyState currentState_;

    // ��Ԃ̃e�[�u���i�h���N���X�ŃZ�b�g����j
    EnemyStateFunction stateTable_[ENEMY_STATE_MAX];

    // ���W
    VECTOR pos_;
};

#pragma once

class EnemyBase; // �O���錾

// ��Ԋ֐��^
typedef void (*EnemyStateFunction)(EnemyBase&);

// �G�̏�ԁi���ʁj
enum EnemyState 
{
    STATE_IDLE,         // �ҋ@
    STATE_SEARCH,       // ���G
    STATE_CHASE,        // �ǐ�
    STATE_ATTACK,       // �U��
    STATE_RETREAT,      // ���
    STATE_RETURN,       // �߂�
    STATE_DEAD,         // ���S

    ENEMY_STATE_MAX,    // �G�̑S���
};

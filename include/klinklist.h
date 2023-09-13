#ifndef _KLINK_LIST
#define _KLINK_LIST
/****************************************************************************
* @file        : incl/klinklist.h
* @brief       : 通用链表
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-03-02 16:29:52 创建文件
*      2023-03-05 15:11:19 实现初始化、头插法。
****************************************************************************/

#include <stdint.h>
#include <stddef.h>

/**
 * @brief 通用头节点
 */
struct klist_head{
    struct klist_head *prev;
    struct klist_head *next;
};

/**
 * @brief: 通用链表初始化
 * @param1: l，链表头
 *
 * 前驱和后继都指向自己。
 *
 */
inline void klist_init(struct klist_head *head)
{
    head->next = head;
    head->prev = head;
}

/**
 * @brief: 头插法插入节点
 * @param1: new，要插入的节点
 * @param2: l，要插入的链表
 *
 * @return: -1，插入失败
 *           0，插入成功
 *
 */
int32_t klist_add(struct klist_head *new,struct klist_head *head);

/**
 * @brief: 删除节点。
 * @param1: head，待删除的节点。
 *
 * 删除链表上的节点，只是从链表中删除，不会释放空间。
 *
 * @return: -1 失败
 *           0 成功
 */
int32_t klist_del(struct klist_head *head);

#endif //  _KLINK_LIST

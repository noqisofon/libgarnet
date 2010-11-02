/**
 * @file glinkedlist.h
 * @since 2010-10-13T09:31:23+0900
 */
#ifndef garnet_glinkedlist_h
#define garnet_glinkedlist_h

#include "_garnet.h"


/**
 * �����N���X�g�̃m�[�h�ł��B
 */
typedef struct g_linkedlist_t {
    struct g_linkedlist_t*      head;
    VALUE                       value;
    struct g_linkedlist_t*      tail;
} GList;


/**
 * ���X�g�̖����� item ����ꂽ�m�[�h��ǉ����܂��B
 */
GList*  g_list_add(GList* self, VALUE item);


/**
 * ���X�g�̐擪�� item ��ǉ����܂��B
 */
GList*  g_list_add_front(GList* self, VALUE item);


/**
 * ���X�g�� position �Ԗڂ� item ��}�����܂��B
 */
GList*  g_list_insert(GList* self, VALUE item, gint position);


/**
 * �w�肳�ꂽ���X�g�̐擪�̃m�[�h��Ԃ��܂��B
 */
GList*  g_list_front(GList* self);


/**
 * �w�肳�ꂽ���X�g�̖����̃m�[�h��Ԃ��܂��B
 */
GList*  g_list_behind(GList* self);


/**
 * �w�肳�ꂽ���X�g�̃T�C�Y��Ԃ��܂��B
 */
size_t  g_list_length(GList* self);


/**
 * ���X�g�� position �Ԗڂ̃m�[�h��Ԃ��܂��B
 */
GList*  g_list_advance(GList* self, gint distance);


/**
 * ���X�g����w�肳�ꂽ�l�������Ă���m�[�h���������܂��B
 */
GList*  g_list_find(GList* self, VALUE found);


/**
 * �w�肳�ꂽ���X�g���g���Ă��郁������S�ĊJ�����܂��B
 */
void    g_list_free(GList* self);


#endif  /* garnet_glinkedlist_h */

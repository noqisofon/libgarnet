/**
 * @file glinkedlist.h
 * @since 2010-10-13T09:31:23+0900
 */
#ifndef garnet_glinkedlist_h
#define garnet_glinkedlist_h

#ifndef GARNET_DEFINE_GARNET_API
#   define     GARNET_API      __stdcall
#endif  /* ndef GARNET_DEFINE_GARNET_API */

#ifndef GARNET_DEFINE_VALUE
typedef     void*       VALUE;
#   define      GARNET_DEFINE_VALUE
#endif  /* GARNET_DEFINE_VALUE */

#ifndef GARNET_DEFINE_GINT
typedef     int32_t       gint;
#   define      GARNET_DEFINE_GINT
#endif  /* GARNET_DEFINE_GINT */


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
GList* GARNET_API  g_list_add(GList* self, VALUE item);


/**
 * ���X�g�̐擪�� item ��ǉ����܂��B
 */
GList* GARNET_API  g_list_add_front(GList* self, VALUE item);


/**
 * ���X�g�� position �Ԗڂ� item ��}�����܂��B
 */
GList* GARNET_API  g_list_insert(GList* self, VALUE item, gint position);


/**
 * �w�肳�ꂽ���X�g�̐擪�̃m�[�h��Ԃ��܂��B
 */
GList* GARNET_API  g_list_front(GList* self);


/**
 * �w�肳�ꂽ���X�g�̖����̃m�[�h��Ԃ��܂��B
 */
GList* GARNET_API  g_list_behind(GList* self);


/**
 * �w�肳�ꂽ���X�g�̃T�C�Y��Ԃ��܂��B
 */
size_t GARNET_API  g_list_length(GList* self);


/**
 * ���X�g�� position �Ԗڂ̃m�[�h��Ԃ��܂��B
 */
GList* GARNET_API  g_list_advance(GList* self, gint distance);


/**
 * ���X�g����w�肳�ꂽ�l�������Ă���m�[�h���������܂��B
 */
GList* GARNET_API  g_list_find(GList* self, VALUE found);


/**
 * �w�肳�ꂽ���X�g���g���Ă��郁������S�ĊJ�����܂��B
 */
void GARNET_API    g_list_free(GList* self);


#endif  /* garnet_glinkedlist_h */

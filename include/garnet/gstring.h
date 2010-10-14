#ifndef garnet_gstring_h
#define garnet_gstring_h

#include "_garnet.h"


#if 0
/**
 * �w�肳�ꂽ������̒�����Ԃ��܂��B
 */
size_t g_strlen(const gchar* self);
#else
#   define     g_strlen        strlen
#endif
#define     g_strcpy        strcpy
#define     g_strncpy       strncpy
#define     g_strcat        strcat
#define     g_strncat       strncat
#define     g_strcmp        strcmp


/**
 * �w�肳�ꂽ������̕�����Ԃ��܂��B
 */
gchar* g_strdup(const gchar* self);


/**
 * �w�肳�ꂽ������� n byte �ڂ܂ł̕�����Ԃ��܂��B
 */
gchar* g_strndup(const gchar* self, size_t _N);


/**
 * �w�肳�ꂽ������ n �����ō\�����ꂽ�������Ԃ��܂��B
 */
gchar* g_strnfill(size_t _N, gchar filled_ch);


/**
 * self �� other �����蓖�Ă܂��B
 */
gchar* g_str_assign(gchar* self, const gchar* other);


/**
 *
 */
const gchar* g_str_find(const gchar* self, size_t n, gchar found_ch);


/**
 *
 */
const gchar* g_str_rfind(const gchar* self, size_t _N, gchar found_ch);


/**
 * left �� right ���������e���ǂ������ʂ��܂��B
 */
gboolean g_str_equal(const gchar* left, const gchar* right);
/**
 * left �� right ���������e���ǂ������ʂ��܂��B
 */
gboolean g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len);


/**
 *
 */
gboolean g_str_startswith(const gchar* self, const gchar* prefix);


/**
 * self �� appendee ��t�������܂��B
 */
gchar* g_str_append(gchar* self, const gchar* appendee);


/**
 * self �� appendee ��t�������܂��B
 */
gchar* g_str_appendch(gchar* self, gchar appendee);


/**
 * self �� right �����������V�����������Ԃ��܂��B
 */
gchar* g_str_concat(const gchar* self, const gchar* right);


/**
 * self �� n �����ڂ�Ԃ��܂��B
 */
int32_t g_str_slice(const gchar* self, int32_t n);


/**
 * self �Ɋ܂܂�� sub_string �� replacement �Œu��������̐V�����������Ԃ���
 * ���B
 */
gchar* g_str_replace( const gchar*  self,
                      const gchar*  sub_string,
                      const gchar*  replacement
                      );


/**
 * self �Ɋ܂܂�� sub_string �� replacement �ł��ׂĒu��������̐V�����������
 * �Ԃ��܂��B
 */
gchar* g_str_replace_all( const gchar*  self,
                          const gchar*  sub_string,
                          const gchar*  replacement
                          );


#endif  /* garnet_gstring_h */

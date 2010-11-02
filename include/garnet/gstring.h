/**
 * @file    gstring.h
 * @brief   ������p�֐����W���[���B
 * @since   2010-07-27T08:41:24
 */
#ifndef garnet_gstring_h
#define garnet_gstring_h

#include <garnet/_garnet.h>


#if 0
/**
 * �w�肳�ꂽ������̒�����Ԃ��܂��B
 */
size_t g_strlen(const gchar* self);
#else
/**
 * @def g_strlen
 * �w�肳�ꂽ������̒�����Ԃ��܂��B
 */
#   define     g_strlen        strlen
#endif
#define     g_strcpy        strcpy
#define     g_strncpy       strncpy
#define     g_strcat        strcat
#define     g_strncat       strncat
#define     g_strcmp        strcmp


/**
 * �w�肳�ꂽ������̕�����Ԃ��܂��B
 *  @param [in] self    �������镶����B
 *
 *  @return �������ꂽ������B
 *
 *  @note �������ꂽ������͎g���I������� g_free �֐��ŊJ�����Ă��������B
 */
gchar* g_strdup(const gchar* self);


/**
 * �w�肳�ꂽ������� n �����ڂ܂ł̕�����Ԃ��܂��B
 *  @param [in] self    �������镶����B
 *  @param [in] n       �������镶�����B
 *
 *  @retuen �������ꂽ������B
 *
 *  @note �������ꂽ������͎g���I������� g_free �֐��ŊJ�����Ă��������B
 */
gchar* g_strndup(const gchar* self, size_t n);


/**
 * �w�肳�ꂽ������ n �����ō\�����ꂽ�������Ԃ��܂��B
 *  @param [in] n           ������̒����B
 *  @param [in] filled_ch   �\�����镶����B
 *
 *  @return �w�肵�������� n �����ō\�����ꂽ������
 *
 * @note
 *      �Ԃ��ꂽ������͎g���I������� g_free �֐��ŊJ�����Ă��������B
 */
gchar* g_strnfill(size_t n, gchar filled_ch);


/**
 * self �� other �����蓖�Ă܂��B
 *  @param [in,out] self    ���蓖�Ă���������B
 *  @param [in]     other   ���蓖�Ă镶����B
 *
 *  @return ���蓖�Ă�ꂽ���Ƃ� self�B
 *
 *  @note
 *      other �� self ��蒷���ꍇ�A�Ԃ��ꂽ self �������A�h���X�ł͂���܂���B
 */
gchar* g_str_assign(gchar* self, const gchar* other);


/**
 * �w�肳�ꂽ�����񂩂當�����������A���̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] n           �������镶����̒����B
 *  @param [in] found_ch    ���������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* g_strchr(const gchar* self, size_t n, gchar found_ch);


/**
 * �w�肳�ꂽ�����񂩂當�����t�������猟�����A���̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] n           �������镶����̒����B
 *  @param [in] found_ch    ���������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* g_strrchr(const gchar* self, size_t n, gchar found_ch);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̍ŏ��̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* g_str_find(const gchar* self, const gchar* search_text);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̍Ō�̈ʒu���|�C���^�ŕԂ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̃|�C���^�B
 */
const gchar* g_str_find_last_of(const gchar* self, const gchar* search_text);


/**
 * �w�肳�ꂽ������� search_text ���܂܂�Ă����炻�̈ʒu��Ԃ��܂��B
 *  @param [in] self        �������镶����B
 *  @param [in] search_text ����������������B
 *
 *  @return self ���̈ʒu�B
 */
gint g_str_index_of(const gchar* self, const gchar* search_text);


/**
 * left �� right ���������e���ǂ������ʂ��܂��B
 *  @param [in] left    ���ʂ��镶���񍶕ӁB
 *  @param [in] right   ���ʂ��镶����E�ӁB
 *
 *  @return �����Ȃ�^�B
 */
gboolean g_str_equal(const gchar* left, const gchar* right);
/**
 * left �� right ���������e���ǂ������ʂ��܂��B
 *  @param [in] left        ���ʂ��镶���񍶕ӁB
 *  @param [in] left_len    left �̕�����̒����B
 *  @param [in] right       ���ʂ��镶����E�ӁB
 *  @param [in] right_len   right �̕�����̒����B
 *
 *  @return �����Ȃ�^�B
 */
gboolean g_str_equal_len(const gchar* left, size_t left_len, const gchar* right, size_t right_len);


/**
 * �w�肳�ꂽ������̐擪�� prefix ���܂܂�Ă�����ǂ����𔻕ʂ��܂��B
 *  @param [in] self    ���ʂ��镶����B
 *  @param [in] prefix  ���ׂ镶����B
 *
 *  @return �܂܂�Ă�����^�B
 */
gboolean g_str_startswith(const gchar* self, const gchar* prefix);


/**
 * self �� appendee ��t�������܂��B
 *  @param  [in,out]    self    �t��������镶����B
 *  @param  [in]        apendee �t������������B
 *
 *  @return �t�������ꂽ���Ƃ� self�B
 *
 *  @note
 *      ���蓖�Ă�ꂽ�o�b�t�@��蒷���Ȃ�ꍇ�A�o�b�t�@��L�΂����Ƃ͂���Ă��܂���B
 */
gchar* g_str_append(gchar* self, const gchar* appendee);


/**
 * self �� appendee ��t�������܂��B
 *  @param  [in,out]    self    �t��������镶����B
 *  @param  [in]        apendee �t�����������B
 *
 *  @return �t�������ꂽ���Ƃ� self�B
 *
 *  @note
 *      ���蓖�Ă�ꂽ�o�b�t�@��蒷���Ȃ�ꍇ�A�o�b�t�@��L�΂����Ƃ͂���Ă��܂���B
 */
gchar* g_str_appendch(gchar* self, gchar appendee);


/**
 * self �� right �����������V�����������Ԃ��܂��B
 *  @param  [in]    self    �������镶���񍶕ӁB
 *  @param  [in]    right   �������镶����E�ӁB
 *
 *  @return self �� right �����������V����������B
 */
gchar* g_str_concat(const gchar* self, const gchar* right);


/**
 * self �� n �����ڂ�Ԃ��܂��B
 */
gint g_str_char_at(const gchar* self, gint n);


/**
 * self �� n �����ڂ��� m �����ڂ܂ł�Ԃ��܂��B
 */
gchar* g_str_slice(const gchar* self, gint n, gint m);


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

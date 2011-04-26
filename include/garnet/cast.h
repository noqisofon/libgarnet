/**
 * \file    cast.h
 * @breif   C++ ���̃L���X�g�� C ���̃L���X�g�ƃX�C�b�`�ł���G�N�X�e���V����
 */
#if !defined(__CSTYLE_CAST)
////////////////////////////////////////////////////////////////////////////////
// 
// C �X�^�C���̃L���X�g���s���֐��^�v���v���Z�b�T�B
// 
#   define     __CSTYLE_CAST(_type_, _expression_)      ((_type_)_expression_)


#   ifdef __cplusplus
/* 
 * _SPAG_NON_STANDALONE_MODULE ����`����Ă��Ȃ�������A�f�t�H���g�Ƃ���
 * _SPAG_USE_CPPSTYLE_CAST ���`���܂��B
 */
#       if !defined(_SPAG_NON_STANDALONE_MODULE)
#           define          _SPAG_USE_CPPSTYLE_CAST
#       else
/* 
 * ��`����Ă���A_USE_CPPSTYLE_CAST ����`����Ă�����
 * _SPAG_USE_CPPSTYLE_CAST ���`���܂��B
 */
#           if defined(_USE_CPPSTYLE_CAST)
#               define      _SPAG_USE_CPPSTYLE_CAST
#           endif  /* defined(_USE_CPPSTYLE_CAST) */

#       endif  /* !defined(_SPAG_NON_STANDALONE_MODULE) */
#   endif  /* def __cplusplus */


////////////////////////////////////////////////////////////////////////////////
// 
// C++ �X�^�C���̃L���X�g���s���֐��^�v���v���Z�b�T�B
// 
#   if defined(_SPAG_USE_CPPSTYLE_CAST)
#       define      __DYNAMIC_CAST(_type_, _expression_)                  dynamic_cast<_type_>(_expression_)
#       define      __STATIC_CAST(_type_, _expression_)                    static_cast<_type_>(_expression_)
#       define      __REINTERPRET_CAST(_type_, _expression_)          reinterpret_cast<_type_>(_expression_)
#       define      __CONST_CAST(_type_, _expression_)                      const_cast<_type_>(_expression_)
#   else
#       define      __DYNAMIC_CAST(_type_, _expression_)                 __CSTYLE_CAST(_type_, _expression_)
#       define      __STATIC_CAST(_type_, _expression_)                  __CSTYLE_CAST(_type_, _expression_)
#       define      __REINTERPRET_CAST(_type_, _expression_)             __CSTYLE_CAST(_type_, _expression_)
#       define      __CONST_CAST(_type_, _expression_)                   __CSTYLE_CAST(_type_, _expression_)
#   endif  /* defined(_SPAG_USE_CPPSTYLE_CAST) */


#endif  /* !defined(__CSTYLE_CAST) */
// Local Variables:
//   coding: shift_jis
// End:
// cast.h ends here

#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.files"), aligned (8)))
#else
# define SECTION
#endif

static const SECTION union { const guint8 data[965]; const double alignment; void * const ptr;}  files_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\344\000\000\000\000\000\000\050\007\000\000\000"
  "\000\000\000\000\001\000\000\000\002\000\000\000\003\000\000\000"
  "\004\000\000\000\005\000\000\000\006\000\000\000\240\342\141\216"
  "\001\000\000\000\344\000\000\000\013\000\114\000\360\000\000\000"
  "\364\000\000\000\173\242\170\174\002\000\000\000\364\000\000\000"
  "\003\000\114\000\370\000\000\000\374\000\000\000\324\265\002\000"
  "\377\377\377\377\374\000\000\000\001\000\114\000\000\001\000\000"
  "\004\001\000\000\152\134\374\354\006\000\000\000\004\001\000\000"
  "\023\000\166\000\030\001\000\000\041\002\000\000\073\227\074\147"
  "\006\000\000\000\041\002\000\000\020\000\166\000\070\002\000\000"
  "\372\002\000\000\064\276\140\351\006\000\000\000\372\002\000\000"
  "\017\000\166\000\020\003\000\000\260\003\000\000\102\215\300\016"
  "\000\000\000\000\260\003\000\000\006\000\114\000\270\003\000\000"
  "\304\003\000\000\145\154\145\155\145\156\164\141\162\171\057\000"
  "\006\000\000\000\151\157\057\000\000\000\000\000\057\000\000\000"
  "\001\000\000\000\123\151\144\145\142\141\162\105\170\160\141\156"
  "\144\145\162\056\143\163\163\000\014\002\000\000\001\000\000\000"
  "\170\332\225\220\321\116\303\060\014\105\337\373\025\326\236\312"
  "\264\144\351\140\010\262\257\111\023\323\106\155\342\052\115\131"
  "\007\342\337\011\055\260\122\136\300\362\113\256\235\173\217\314"
  "\161\354\224\067\030\340\065\203\124\245\322\115\025\150\360\106"
  "\102\014\312\367\235\012\350\343\151\036\122\110\233\022\074\171"
  "\374\122\106\326\327\312\320\171\251\166\312\030\353\053\011\002"
  "\004\077\076\334\116\025\320\235\140\277\115\332\175\067\302\166"
  "\237\275\145\031\377\116\347\052\004\072\177\102\050\157\235\212"
  "\226\374\322\164\242\261\263\252\332\026\016\102\270\036\364\120"
  "\132\315\112\174\261\030\162\301\357\166\040\122\363\303\016\212"
  "\233\371\037\165\112\333\170\111\060\363\233\125\261\141\126\223"
  "\147\075\015\101\243\274\052\261\106\207\371\046\041\061\364\206"
  "\365\027\127\122\153\365\046\071\055\141\245\256\121\067\150\176"
  "\102\377\342\073\376\215\357\312\063\071\074\121\160\022\002\105"
  "\025\061\177\024\006\253\165\172\115\317\353\203\255\263\213\377"
  "\336\246\370\310\170\007\131\064\236\127\000\050\165\165\141\171"
  "\051\104\151\163\153\122\145\156\144\145\162\145\162\056\143\163"
  "\163\000\000\000\000\000\000\000\134\001\000\000\001\000\000\000"
  "\170\332\215\216\101\016\202\060\020\105\367\075\305\054\025\241"
  "\020\115\134\340\306\033\170\004\123\332\261\064\024\332\264\005"
  "\061\306\273\213\105\023\067\032\146\367\223\377\336\174\352\225"
  "\300\212\071\250\372\020\114\107\125\313\044\146\163\200\073\201"
  "\351\054\023\102\165\262\204\342\100\036\204\320\017\241\161\100"
  "\035\121\155\170\363\056\267\252\313\152\124\262\016\045\354\354"
  "\030\211\074\201\323\200\316\115\034\204\032\301\367\234\243\367"
  "\300\215\066\016\222\374\227\222\136\224\326\050\250\066\327\331"
  "\136\061\336\110\147\372\116\224\300\264\255\031\254\216\001\307"
  "\160\216\246\024\012\272\137\377\333\370\055\334\000\305\326\206"
  "\133\272\240\134\276\036\013\147\354\322\031\333\070\343\011\350"
  "\212\164\022\000\050\165\165\141\171\051\103\157\154\157\162\102"
  "\165\164\164\157\156\056\143\163\163\000\000\000\000\000\000\000"
  "\315\000\000\000\001\000\000\000\170\332\115\215\301\012\203\060"
  "\020\104\357\176\305\342\311\202\221\026\332\113\172\361\117\304"
  "\254\213\011\232\154\061\033\232\122\372\357\025\075\350\234\206"
  "\067\017\246\101\236\171\121\046\211\160\150\002\007\002\264\204"
  "\023\174\013\130\143\172\234\306\205\123\030\064\264\246\217\324"
  "\155\376\163\033\267\252\301\273\014\125\053\224\145\037\353\263"
  "\131\303\265\171\134\166\337\273\240\054\271\321\212\206\333\375"
  "\225\017\372\166\203\330\063\124\243\114\312\041\007\025\071\055"
  "\110\372\040\142\311\123\125\342\314\221\124\374\170\303\263\303"
  "\162\275\370\025\177\333\276\101\352\000\050\165\165\141\171\051"
  "\146\151\154\145\163\057\000\000\005\000\000\000\004\000\000\000"
  "\003\000\000\000" };

static GStaticResource static_resource = { files_resource_data.data, sizeof (files_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };

G_GNUC_INTERNAL
GResource *files_get_resource (void);
GResource *files_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __G_CONSTRUCTOR_H__
#define __G_CONSTRUCTOR_H__

/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a usable way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

/*
 * Only try to include gslist.h if not already included via glib.h,
 * so that items using gconstructor.h outside of GLib (such as
 * GResources) continue to build properly.
 */
#ifndef __G_LIB_H__
#include "gslist.h"
#endif

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for x86 and x64/ARM/ARM64 programs, as symbols on x86 are prefixed
 * with an underscore but symbols on x64/ARM/ARM64 are not.
 */
#ifdef _M_IX86
#define G_MSVC_SYMBOL_PREFIX "_"
#else
#define G_MSVC_SYMBOL_PREFIX ""
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */
#endif /* __G_CONSTRUCTOR_H__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(filesresource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(filesresource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(filesresource_destructor)
#endif
G_DEFINE_DESTRUCTOR(filesresource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void filesresource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void filesresource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}

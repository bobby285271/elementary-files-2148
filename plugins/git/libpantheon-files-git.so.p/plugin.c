/* plugin.c generated by valac 0.56.3, the Vala compiler
 * generated from plugin.vala, do not modify */

#include "pantheon-files-git.h"
#include <libgit2-glib/ggit.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>
#include "pantheon-files-core.h"
#include <gtk/gtk.h>
#include <gio/gio.h>

#define FILES_PLUGINS_GIT_EXCLUDED_FS_TYPES "fuse"

enum  {
	FILES_GIT_REPO_INFO_0_PROPERTY,
	FILES_GIT_REPO_INFO_REPO_PROPERTY,
	FILES_GIT_REPO_INFO_STATUS_MAP_PROPERTY,
	FILES_GIT_REPO_INFO_NUM_PROPERTIES
};
static GParamSpec* files_git_repo_info_properties[FILES_GIT_REPO_INFO_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Block1Data Block1Data;
#define __vala_GgitStatusOptions_free0(var) ((var == NULL) ? NULL : (var = (_vala_GgitStatusOptions_free (var), NULL)))
#define _files_git_repo_child_info_free0(var) ((var == NULL) ? NULL : (var = (files_git_repo_child_info_free (var), NULL)))

struct _FilesGitRepoInfoPrivate {
	GgitRepository* _repo;
	GHashTable* _status_map;
};

struct _Block1Data {
	int _ref_count_;
	FilesGitRepoInfo* self;
	GgitStatusFlags _result_;
	gchar* path;
};

struct _FilesPluginsGitPrivate {
	GHashTable* repo_map;
	GHashTable* child_map;
};

static gint FilesGitRepoInfo_private_offset;
static gpointer files_git_repo_info_parent_class = NULL;
static GgitStatusOptions* files_git_repo_info_status_options;
static GgitStatusOptions* files_git_repo_info_status_options = NULL;
static gint FilesPluginsGit_private_offset;
static gpointer files_plugins_git_parent_class = NULL;

static gint ___lambda4_ (FilesGitRepoInfo* self,
                  const gchar* path,
                  GgitStatusFlags status_flags);
static gint ____lambda4__ggit_status_callback (const gchar* path,
                                        GgitStatusFlags status_flags,
                                        gpointer self);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void __lambda5_ (Block1Data* _data1_,
                 const gchar* k,
                 GgitStatusFlags v);
static void ___lambda5__gh_func (gconstpointer key,
                          gconstpointer value,
                          gpointer self);
static GgitStatusFlags* _ggit_status_flags_dup (GgitStatusFlags* self);
static GObject * files_git_repo_info_constructor (GType type,
                                           guint n_construct_properties,
                                           GObjectConstructParam * construct_properties);
static void _g_free0_ (gpointer var);
static void _vala_GgitStatusOptions_free (GgitStatusOptions* self);
static void files_git_repo_info_finalize (GObject * obj);
static GType files_git_repo_info_get_type_once (void);
static void _vala_files_git_repo_info_get_property (GObject * object,
                                             guint property_id,
                                             GValue * value,
                                             GParamSpec * pspec);
static void _vala_files_git_repo_info_set_property (GObject * object,
                                             guint property_id,
                                             const GValue * value,
                                             GParamSpec * pspec);
static void _g_object_unref0_ (gpointer var);
static void _files_git_repo_child_info_free0_ (gpointer var);
static void files_plugins_git_real_directory_loaded (FilesPluginsBase* base,
                                              GtkApplicationWindow* window,
                                              FilesAbstractSlot* view,
                                              FilesFile* directory);
static void files_plugins_git_real_update_file_info (FilesPluginsBase* base,
                                              FilesFile* gof);
static void files_plugins_git_finalize (FilesPluginsBase * obj);
static GType files_plugins_git_get_type_once (void);
static void _vala_array_destroy (gpointer array,
                          gssize array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gssize array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
files_git_repo_info_get_instance_private (FilesGitRepoInfo* self)
{
	return G_STRUCT_MEMBER_P (self, FilesGitRepoInfo_private_offset);
}

FilesGitRepoInfo*
files_git_repo_info_construct (GType object_type,
                               GgitRepository* _repo)
{
	FilesGitRepoInfo * self = NULL;
	g_return_val_if_fail (_repo != NULL, NULL);
	self = (FilesGitRepoInfo*) g_object_new (object_type, "repo", _repo, NULL);
	return self;
}

FilesGitRepoInfo*
files_git_repo_info_new (GgitRepository* _repo)
{
	return files_git_repo_info_construct (FILES_TYPE_GIT_REPO_INFO, _repo);
}

static gint
___lambda4_ (FilesGitRepoInfo* self,
             const gchar* path,
             GgitStatusFlags status_flags)
{
	GHashTable* _tmp0_;
	gchar* _tmp1_;
	gint result;
	g_return_val_if_fail (path != NULL, 0);
	_tmp0_ = self->priv->_status_map;
	_tmp1_ = g_strdup (path);
	g_hash_table_insert (_tmp0_, _tmp1_, (gpointer) ((gintptr) status_flags));
	result = 0;
	return result;
}

static gint
____lambda4__ggit_status_callback (const gchar* path,
                                   GgitStatusFlags status_flags,
                                   gpointer self)
{
	gint result;
	result = ___lambda4_ ((FilesGitRepoInfo*) self, path, status_flags);
	return result;
}

gboolean
files_git_repo_info_get_status_list (FilesGitRepoInfo* self)
{
	GHashTable* _tmp0_;
	GError* _inner_error0_ = NULL;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_status_map;
	g_hash_table_remove_all (_tmp0_);
	{
		GgitRepository* _tmp1_;
		GgitStatusOptions* _tmp2_;
		_tmp1_ = self->priv->_repo;
		_tmp2_ = files_git_repo_info_status_options;
		ggit_repository_file_status_foreach (_tmp1_, _tmp2_, ____lambda4__ggit_status_callback, self, &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp3_;
		const gchar* _tmp4_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp3_ = e;
		_tmp4_ = _tmp3_->message;
		g_warning ("plugin.vala:51: Error getting status: %s", _tmp4_);
		result = FALSE;
		_g_error_free0 (e);
		return result;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		gboolean _tmp5_ = FALSE;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return _tmp5_;
	}
	result = TRUE;
	return result;
}

static Block1Data*
block1_data_ref (Block1Data* _data1_)
{
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}

static void
block1_data_unref (void * _userdata_)
{
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		FilesGitRepoInfo* self;
		self = _data1_->self;
		_g_free0 (_data1_->path);
		_g_object_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}

static void
__lambda5_ (Block1Data* _data1_,
            const gchar* k,
            GgitStatusFlags v)
{
	FilesGitRepoInfo* self;
	self = _data1_->self;
	g_return_if_fail (k != NULL);
	if (g_str_has_prefix (k, _data1_->path)) {
		_data1_->_result_ = v;
	}
}

static void
___lambda5__gh_func (gconstpointer key,
                     gconstpointer value,
                     gpointer self)
{
	__lambda5_ (self, (const gchar*) key, (GgitStatusFlags) ((gintptr) value));
}

static GgitStatusFlags*
_ggit_status_flags_dup (GgitStatusFlags* self)
{
	GgitStatusFlags* dup;
	dup = g_new0 (GgitStatusFlags, 1);
	memcpy (dup, self, sizeof (GgitStatusFlags));
	return dup;
}

static gpointer
__ggit_status_flags_dup0 (gpointer self)
{
	return self ? _ggit_status_flags_dup (self) : NULL;
}

GgitStatusFlags*
files_git_repo_info_lookup_status (FilesGitRepoInfo* self,
                                   const gchar* path)
{
	Block1Data* _data1_;
	gchar* _tmp0_;
	GHashTable* _tmp1_;
	GgitStatusFlags* _tmp2_;
	GgitStatusFlags* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->self = g_object_ref (self);
	_tmp0_ = g_strdup (path);
	_g_free0 (_data1_->path);
	_data1_->path = _tmp0_;
	_data1_->_result_ = GGIT_STATUS_CURRENT;
	_tmp1_ = self->priv->_status_map;
	g_hash_table_foreach (_tmp1_, ___lambda5__gh_func, _data1_);
	_tmp2_ = __ggit_status_flags_dup0 (&_data1_->_result_);
	result = _tmp2_;
	block1_data_unref (_data1_);
	_data1_ = NULL;
	return result;
}

GgitRepository*
files_git_repo_info_get_repo (FilesGitRepoInfo* self)
{
	GgitRepository* result;
	GgitRepository* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_repo;
	result = _tmp0_;
	return result;
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
files_git_repo_info_set_repo (FilesGitRepoInfo* self,
                              GgitRepository* value)
{
	GgitRepository* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_git_repo_info_get_repo (self);
	if (old_value != value) {
		GgitRepository* _tmp0_;
		_tmp0_ = _g_object_ref0 (value);
		_g_object_unref0 (self->priv->_repo);
		self->priv->_repo = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_git_repo_info_properties[FILES_GIT_REPO_INFO_REPO_PROPERTY]);
	}
}

GHashTable*
files_git_repo_info_get_status_map (FilesGitRepoInfo* self)
{
	GHashTable* result;
	GHashTable* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_status_map;
	result = _tmp0_;
	return result;
}

static gpointer
_g_hash_table_ref0 (gpointer self)
{
	return self ? g_hash_table_ref (self) : NULL;
}

static void
files_git_repo_info_set_status_map (FilesGitRepoInfo* self,
                                    GHashTable* value)
{
	GHashTable* old_value;
	g_return_if_fail (self != NULL);
	old_value = files_git_repo_info_get_status_map (self);
	if (old_value != value) {
		GHashTable* _tmp0_;
		_tmp0_ = _g_hash_table_ref0 (value);
		_g_hash_table_unref0 (self->priv->_status_map);
		self->priv->_status_map = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, files_git_repo_info_properties[FILES_GIT_REPO_INFO_STATUS_MAP_PROPERTY]);
	}
}

static void
_g_free0_ (gpointer var)
{
	var = (g_free (var), NULL);
}

static GObject *
files_git_repo_info_constructor (GType type,
                                 guint n_construct_properties,
                                 GObjectConstructParam * construct_properties)
{
	GObject * obj;
	GObjectClass * parent_class;
	FilesGitRepoInfo * self;
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	GHashTable* _tmp2_;
	GHashTable* _tmp3_;
	parent_class = G_OBJECT_CLASS (files_git_repo_info_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_TYPE_GIT_REPO_INFO, FilesGitRepoInfo);
	_tmp0_ = g_str_hash;
	_tmp1_ = g_str_equal;
	_tmp2_ = g_hash_table_new_full (_tmp0_, _tmp1_, _g_free0_, NULL);
	_tmp3_ = _tmp2_;
	files_git_repo_info_set_status_map (self, _tmp3_);
	_g_hash_table_unref0 (_tmp3_);
	files_git_repo_info_get_status_list (self);
	return obj;
}

static void
_vala_GgitStatusOptions_free (GgitStatusOptions* self)
{
	g_boxed_free (ggit_status_options_get_type (), self);
}

static void
files_git_repo_info_class_init (FilesGitRepoInfoClass * klass,
                                gpointer klass_data)
{
	gchar** _tmp0_;
	gchar** _tmp1_;
	gint _tmp1__length1;
	GgitStatusOptions* _tmp2_;
	files_git_repo_info_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &FilesGitRepoInfo_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_files_git_repo_info_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_files_git_repo_info_set_property;
	G_OBJECT_CLASS (klass)->constructor = files_git_repo_info_constructor;
	G_OBJECT_CLASS (klass)->finalize = files_git_repo_info_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_GIT_REPO_INFO_REPO_PROPERTY, files_git_repo_info_properties[FILES_GIT_REPO_INFO_REPO_PROPERTY] = g_param_spec_object ("repo", "repo", "repo", ggit_repository_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), FILES_GIT_REPO_INFO_STATUS_MAP_PROPERTY, files_git_repo_info_properties[FILES_GIT_REPO_INFO_STATUS_MAP_PROPERTY] = g_param_spec_boxed ("status-map", "status-map", "status-map", G_TYPE_HASH_TABLE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	_tmp1_ = _tmp0_;
	_tmp1__length1 = 0;
	_tmp2_ = ggit_status_options_new (GGIT_STATUS_OPTION_DEFAULT, GGIT_STATUS_SHOW_INDEX_AND_WORKDIR, _tmp1_);
	__vala_GgitStatusOptions_free0 (files_git_repo_info_status_options);
	files_git_repo_info_status_options = _tmp2_;
	_tmp1_ = (_vala_array_free (_tmp1_, _tmp1__length1, (GDestroyNotify) g_free), NULL);
}

static void
files_git_repo_info_instance_init (FilesGitRepoInfo * self,
                                   gpointer klass)
{
	self->priv = files_git_repo_info_get_instance_private (self);
}

static void
files_git_repo_info_finalize (GObject * obj)
{
	FilesGitRepoInfo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_TYPE_GIT_REPO_INFO, FilesGitRepoInfo);
	_g_object_unref0 (self->priv->_repo);
	_g_hash_table_unref0 (self->priv->_status_map);
	G_OBJECT_CLASS (files_git_repo_info_parent_class)->finalize (obj);
}

/***
    Copyright (c) 2019 elementary LLC <https://elementary.io>

    This program is free software: you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License version 3, as published
    by the Free Software Foundation.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranties of
    MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
    PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.

    Authors : Jeremy Wootten <jeremy@elementaryos.org>
***/
static GType
files_git_repo_info_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesGitRepoInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_git_repo_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesGitRepoInfo), 0, (GInstanceInitFunc) files_git_repo_info_instance_init, NULL };
	GType files_git_repo_info_type_id;
	files_git_repo_info_type_id = g_type_register_static (G_TYPE_OBJECT, "FilesGitRepoInfo", &g_define_type_info, 0);
	FilesGitRepoInfo_private_offset = g_type_add_instance_private (files_git_repo_info_type_id, sizeof (FilesGitRepoInfoPrivate));
	return files_git_repo_info_type_id;
}

GType
files_git_repo_info_get_type (void)
{
	static volatile gsize files_git_repo_info_type_id__once = 0;
	if (g_once_init_enter (&files_git_repo_info_type_id__once)) {
		GType files_git_repo_info_type_id;
		files_git_repo_info_type_id = files_git_repo_info_get_type_once ();
		g_once_init_leave (&files_git_repo_info_type_id__once, files_git_repo_info_type_id);
	}
	return files_git_repo_info_type_id__once;
}

static void
_vala_files_git_repo_info_get_property (GObject * object,
                                        guint property_id,
                                        GValue * value,
                                        GParamSpec * pspec)
{
	FilesGitRepoInfo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, FILES_TYPE_GIT_REPO_INFO, FilesGitRepoInfo);
	switch (property_id) {
		case FILES_GIT_REPO_INFO_REPO_PROPERTY:
		g_value_set_object (value, files_git_repo_info_get_repo (self));
		break;
		case FILES_GIT_REPO_INFO_STATUS_MAP_PROPERTY:
		g_value_set_boxed (value, files_git_repo_info_get_status_map (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_files_git_repo_info_set_property (GObject * object,
                                        guint property_id,
                                        const GValue * value,
                                        GParamSpec * pspec)
{
	FilesGitRepoInfo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, FILES_TYPE_GIT_REPO_INFO, FilesGitRepoInfo);
	switch (property_id) {
		case FILES_GIT_REPO_INFO_REPO_PROPERTY:
		files_git_repo_info_set_repo (self, g_value_get_object (value));
		break;
		case FILES_GIT_REPO_INFO_STATUS_MAP_PROPERTY:
		files_git_repo_info_set_status_map (self, g_value_get_boxed (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

void
files_git_repo_child_info_copy (const FilesGitRepoChildInfo* self,
                                FilesGitRepoChildInfo* dest)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	_tmp0_ = (*self).repo_uri;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 ((*dest).repo_uri);
	(*dest).repo_uri = _tmp1_;
	_tmp2_ = (*self).rel_path;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 ((*dest).rel_path);
	(*dest).rel_path = _tmp3_;
}

void
files_git_repo_child_info_destroy (FilesGitRepoChildInfo* self)
{
	_g_free0 ((*self).repo_uri);
	_g_free0 ((*self).rel_path);
}

FilesGitRepoChildInfo*
files_git_repo_child_info_dup (const FilesGitRepoChildInfo* self)
{
	FilesGitRepoChildInfo* dup;
	dup = g_new0 (FilesGitRepoChildInfo, 1);
	files_git_repo_child_info_copy (self, dup);
	return dup;
}

void
files_git_repo_child_info_free (FilesGitRepoChildInfo* self)
{
	files_git_repo_child_info_destroy (self);
	g_free (self);
}

static GType
files_git_repo_child_info_get_type_once (void)
{
	GType files_git_repo_child_info_type_id;
	files_git_repo_child_info_type_id = g_boxed_type_register_static ("FilesGitRepoChildInfo", (GBoxedCopyFunc) files_git_repo_child_info_dup, (GBoxedFreeFunc) files_git_repo_child_info_free);
	return files_git_repo_child_info_type_id;
}

GType
files_git_repo_child_info_get_type (void)
{
	static volatile gsize files_git_repo_child_info_type_id__once = 0;
	if (g_once_init_enter (&files_git_repo_child_info_type_id__once)) {
		GType files_git_repo_child_info_type_id;
		files_git_repo_child_info_type_id = files_git_repo_child_info_get_type_once ();
		g_once_init_leave (&files_git_repo_child_info_type_id__once, files_git_repo_child_info_type_id);
	}
	return files_git_repo_child_info_type_id__once;
}

static inline gpointer
files_plugins_git_get_instance_private (FilesPluginsGit* self)
{
	return G_STRUCT_MEMBER_P (self, FilesPluginsGit_private_offset);
}

static void
_g_object_unref0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}

static void
_files_git_repo_child_info_free0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (files_git_repo_child_info_free (var), NULL));
}

FilesPluginsGit*
files_plugins_git_construct (GType object_type)
{
	FilesPluginsGit* self = NULL;
	GHashFunc _tmp0_;
	GEqualFunc _tmp1_;
	GHashTable* _tmp2_;
	GHashFunc _tmp3_;
	GEqualFunc _tmp4_;
	GHashTable* _tmp5_;
	self = (FilesPluginsGit*) files_plugins_base_construct (object_type);
	_tmp0_ = g_str_hash;
	_tmp1_ = g_str_equal;
	_tmp2_ = g_hash_table_new_full (_tmp0_, _tmp1_, _g_free0_, _g_object_unref0_);
	_g_hash_table_unref0 (self->priv->repo_map);
	self->priv->repo_map = _tmp2_;
	_tmp3_ = g_str_hash;
	_tmp4_ = g_str_equal;
	_tmp5_ = g_hash_table_new_full (_tmp3_, _tmp4_, _g_free0_, _files_git_repo_child_info_free0_);
	_g_hash_table_unref0 (self->priv->child_map);
	self->priv->child_map = _tmp5_;
	return self;
}

FilesPluginsGit*
files_plugins_git_new (void)
{
	return files_plugins_git_construct (FILES_PLUGINS_TYPE_GIT);
}

static gboolean
string_contains (const gchar* self,
                 const gchar* needle)
{
	gchar* _tmp0_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = strstr ((gchar*) self, (gchar*) needle);
	result = _tmp0_ != NULL;
	return result;
}

static gpointer
_files_git_repo_child_info_dup0 (gpointer self)
{
	return self ? files_git_repo_child_info_dup (self) : NULL;
}

static void
files_plugins_git_real_directory_loaded (FilesPluginsBase* base,
                                         GtkApplicationWindow* window,
                                         FilesAbstractSlot* view,
                                         FilesFile* directory)
{
	FilesPluginsGit * self;
	FilesDirectory* _tmp0_;
	FilesDirectory* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	GFileInfo* info = NULL;
	gboolean _tmp18_ = FALSE;
	GFileInfo* _tmp19_;
	const gchar* fs_type = NULL;
	GFileInfo* _tmp21_;
	const gchar* _tmp22_;
	const gchar* _tmp23_;
	gchar* dir_uri = NULL;
	const gchar* _tmp25_;
	const gchar* _tmp26_;
	gchar* _tmp27_;
	gchar* repo_uri = NULL;
	gchar* _tmp28_;
	GError* _inner_error0_ = NULL;
	self = (FilesPluginsGit*) base;
	g_return_if_fail (window != NULL);
	g_return_if_fail (view != NULL);
	g_return_if_fail (directory != NULL);
	_tmp0_ = files_abstract_slot_get_directory (view);
	_tmp1_ = _tmp0_;
	_tmp2_ = files_directory_get_is_local (_tmp1_);
	_tmp3_ = _tmp2_;
	if (!_tmp3_) {
		g_debug ("plugin.vala:89: Git plugin ignoring non-local folder");
		return;
	}
	{
		GFileInfo* _tmp4_ = NULL;
		GFile* _tmp5_;
		GFileInfo* _tmp6_;
		GFileInfo* _tmp7_;
		GFileInfo* _tmp8_;
		const gchar* fs_type = NULL;
		GFileInfo* _tmp9_;
		const gchar* _tmp10_;
		const gchar* _tmp11_;
		_tmp5_ = files_file_get_target_location (directory);
		_tmp6_ = g_file_query_filesystem_info (_tmp5_, G_FILE_ATTRIBUTE_FILESYSTEM_TYPE, NULL, &_inner_error0_);
		_tmp4_ = _tmp6_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
		_tmp7_ = _tmp4_;
		_tmp4_ = NULL;
		_g_object_unref0 (info);
		info = _tmp7_;
		_tmp8_ = info;
		if (!g_file_info_has_attribute (_tmp8_, G_FILE_ATTRIBUTE_FILESYSTEM_TYPE)) {
			g_debug ("plugin.vala:97: GIT PLUGIN: no filesystem type info - ignoring");
			_g_object_unref0 (_tmp4_);
			_g_object_unref0 (info);
			return;
		}
		_tmp9_ = info;
		_tmp10_ = g_file_info_get_attribute_string (_tmp9_, G_FILE_ATTRIBUTE_FILESYSTEM_TYPE);
		fs_type = _tmp10_;
		_tmp11_ = fs_type;
		if (string_contains (FILES_PLUGINS_GIT_EXCLUDED_FS_TYPES, _tmp11_)) {
			const gchar* _tmp12_;
			_tmp12_ = fs_type;
			g_warning ("plugin.vala:103: GIT PLUGIN: excluded filesystem type %s", _tmp12_);
			_g_object_unref0 (_tmp4_);
			_g_object_unref0 (info);
			return;
		}
		_g_object_unref0 (_tmp4_);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* _error_ = NULL;
		GError* _tmp13_;
		_error_ = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp13_ = _error_;
		if (!g_error_matches (_tmp13_, G_IO_ERROR, G_IO_ERROR_CANCELLED)) {
			const gchar* _tmp14_;
			const gchar* _tmp15_;
			GError* _tmp16_;
			const gchar* _tmp17_;
			_tmp14_ = files_file_get_uri (directory);
			_tmp15_ = _tmp14_;
			_tmp16_ = _error_;
			_tmp17_ = _tmp16_->message;
			g_warning ("plugin.vala:108: GIT PLUGIN: Error querying %s filesystem info: %s", _tmp15_, _tmp17_);
		}
		_g_error_free0 (_error_);
		_g_object_unref0 (info);
		return;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		_g_object_unref0 (info);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
	_tmp19_ = info;
	if (_tmp19_ == NULL) {
		_tmp18_ = TRUE;
	} else {
		GFileInfo* _tmp20_;
		_tmp20_ = info;
		_tmp18_ = !g_file_info_has_attribute (_tmp20_, G_FILE_ATTRIBUTE_FILESYSTEM_TYPE);
	}
	if (_tmp18_) {
		g_debug ("plugin.vala:115: GIT PLUGIN: no filesystem type info - ignoring");
		_g_object_unref0 (info);
		return;
	}
	_tmp21_ = info;
	_tmp22_ = g_file_info_get_attribute_string (_tmp21_, G_FILE_ATTRIBUTE_FILESYSTEM_TYPE);
	fs_type = _tmp22_;
	_tmp23_ = fs_type;
	if (string_contains (FILES_PLUGINS_GIT_EXCLUDED_FS_TYPES, _tmp23_)) {
		const gchar* _tmp24_;
		_tmp24_ = fs_type;
		g_warning ("plugin.vala:121: GIT PLUGIN: excluded filesystem type %s", _tmp24_);
		_g_object_unref0 (info);
		return;
	}
	_tmp25_ = files_file_get_uri (directory);
	_tmp26_ = _tmp25_;
	_tmp27_ = g_strdup (_tmp26_);
	dir_uri = _tmp27_;
	_tmp28_ = g_strdup ("");
	repo_uri = _tmp28_;
	{
		GFile* key = NULL;
		GFile* _tmp29_;
		GFile* _tmp30_;
		GFile* _tmp31_;
		GFile* _tmp32_;
		gchar* _tmp33_;
		gchar* _tmp34_;
		gboolean _tmp35_;
		GFile* gitdir = NULL;
		GFile* _tmp36_;
		GFile* _tmp37_;
		GFile* _tmp38_;
		_tmp29_ = files_file_get_location (directory);
		_tmp30_ = _tmp29_;
		_tmp31_ = _g_object_ref0 (_tmp30_);
		key = _tmp31_;
		_tmp32_ = key;
		_tmp33_ = g_file_get_path (_tmp32_);
		_tmp34_ = _tmp33_;
		_tmp35_ = _tmp34_ == NULL;
		_g_free0 (_tmp34_);
		if (_tmp35_) {
			_g_object_unref0 (key);
			_g_free0 (repo_uri);
			_g_free0 (dir_uri);
			_g_object_unref0 (info);
			return;
		}
		_tmp36_ = key;
		_tmp37_ = ggit_repository_discover (_tmp36_, &_inner_error0_);
		gitdir = _tmp37_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			_g_object_unref0 (key);
			goto __catch1_g_error;
		}
		_tmp38_ = gitdir;
		if (_tmp38_ != NULL) {
			GFile* _tmp39_;
			gchar* _tmp40_;
			FilesGitRepoInfo* repo_info = NULL;
			GHashTable* _tmp41_;
			const gchar* _tmp42_;
			gconstpointer _tmp43_;
			FilesGitRepoInfo* _tmp44_;
			FilesGitRepoInfo* _tmp45_;
			GHashTable* _tmp55_;
			const gchar* _tmp56_;
			_tmp39_ = gitdir;
			_tmp40_ = g_file_get_uri (_tmp39_);
			_g_free0 (repo_uri);
			repo_uri = _tmp40_;
			_tmp41_ = self->priv->repo_map;
			_tmp42_ = repo_uri;
			_tmp43_ = g_hash_table_lookup (_tmp41_, _tmp42_);
			_tmp44_ = _g_object_ref0 ((FilesGitRepoInfo*) _tmp43_);
			repo_info = _tmp44_;
			_tmp45_ = repo_info;
			if (_tmp45_ == NULL) {
				GgitRepository* git_repo = NULL;
				GFile* _tmp46_;
				GgitRepository* _tmp47_;
				GgitRepository* _tmp48_;
				FilesGitRepoInfo* _tmp49_;
				GHashTable* _tmp50_;
				const gchar* _tmp51_;
				gchar* _tmp52_;
				FilesGitRepoInfo* _tmp53_;
				FilesGitRepoInfo* _tmp54_;
				_tmp46_ = gitdir;
				_tmp47_ = ggit_repository_open (_tmp46_, &_inner_error0_);
				git_repo = _tmp47_;
				if (G_UNLIKELY (_inner_error0_ != NULL)) {
					_g_object_unref0 (repo_info);
					_g_object_unref0 (gitdir);
					_g_object_unref0 (key);
					goto __catch1_g_error;
				}
				_tmp48_ = git_repo;
				_tmp49_ = files_git_repo_info_new (_tmp48_);
				_g_object_unref0 (repo_info);
				repo_info = _tmp49_;
				_tmp50_ = self->priv->repo_map;
				_tmp51_ = repo_uri;
				_tmp52_ = g_strdup (_tmp51_);
				_tmp53_ = repo_info;
				_tmp54_ = _g_object_ref0 (_tmp53_);
				g_hash_table_insert (_tmp50_, _tmp52_, _tmp54_);
				_g_object_unref0 (git_repo);
			} else {
			}
			_tmp55_ = self->priv->child_map;
			_tmp56_ = dir_uri;
			if (!g_hash_table_contains (_tmp55_, _tmp56_)) {
				gchar* rel_path = NULL;
				FilesGitRepoInfo* _tmp57_;
				GgitRepository* _tmp58_;
				GgitRepository* _tmp59_;
				GFile* _tmp60_;
				GFile* _tmp61_;
				GFile* _tmp62_;
				GFile* _tmp63_;
				GFile* _tmp64_;
				GFile* _tmp65_;
				GFile* _tmp66_;
				gchar* _tmp67_;
				gchar* _tmp68_;
				const gchar* _tmp69_;
				FilesGitRepoChildInfo child_info = {0};
				const gchar* _tmp73_;
				gchar* _tmp74_;
				const gchar* _tmp75_;
				gchar* _tmp76_;
				FilesGitRepoChildInfo _tmp77_ = {0};
				GHashTable* _tmp78_;
				const gchar* _tmp79_;
				gchar* _tmp80_;
				FilesGitRepoChildInfo _tmp81_;
				FilesGitRepoChildInfo _tmp82_;
				FilesGitRepoChildInfo* _tmp83_;
				_tmp57_ = repo_info;
				_tmp58_ = files_git_repo_info_get_repo (_tmp57_);
				_tmp59_ = _tmp58_;
				_tmp60_ = ggit_repository_get_location (_tmp59_);
				_tmp61_ = _tmp60_;
				_tmp62_ = _tmp61_;
				_tmp63_ = g_file_get_parent (_tmp62_);
				_tmp64_ = _tmp63_;
				_tmp65_ = files_file_get_location (directory);
				_tmp66_ = _tmp65_;
				_tmp67_ = g_file_get_relative_path (_tmp64_, _tmp66_);
				_tmp68_ = _tmp67_;
				_g_object_unref0 (_tmp64_);
				_g_object_unref0 (_tmp62_);
				rel_path = _tmp68_;
				_tmp69_ = rel_path;
				if (_tmp69_ != NULL) {
					const gchar* _tmp70_;
					gchar* _tmp71_;
					_tmp70_ = rel_path;
					_tmp71_ = g_strconcat (_tmp70_, G_DIR_SEPARATOR_S, NULL);
					_g_free0 (rel_path);
					rel_path = _tmp71_;
				} else {
					gchar* _tmp72_;
					_tmp72_ = g_strdup ("");
					_g_free0 (rel_path);
					rel_path = _tmp72_;
				}
				_tmp73_ = repo_uri;
				_tmp74_ = g_strdup (_tmp73_);
				_tmp75_ = rel_path;
				_tmp76_ = g_strdup (_tmp75_);
				_g_free0 (_tmp77_.repo_uri);
				_tmp77_.repo_uri = _tmp74_;
				_g_free0 (_tmp77_.rel_path);
				_tmp77_.rel_path = _tmp76_;
				child_info = _tmp77_;
				_tmp78_ = self->priv->child_map;
				_tmp79_ = dir_uri;
				_tmp80_ = g_strdup (_tmp79_);
				_tmp81_ = child_info;
				_tmp82_ = _tmp81_;
				_tmp83_ = _files_git_repo_child_info_dup0 (&_tmp82_);
				g_hash_table_insert (_tmp78_, _tmp80_, _tmp83_);
				files_git_repo_child_info_destroy (&child_info);
				_g_free0 (rel_path);
			} else {
			}
			_g_object_unref0 (repo_info);
		}
		_g_object_unref0 (gitdir);
		_g_object_unref0 (key);
	}
	goto __finally1;
	__catch1_g_error:
	{
		GError* e = NULL;
		const gchar* _tmp84_;
		const gchar* _tmp85_;
		GError* _tmp86_;
		const gchar* _tmp87_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp84_ = files_file_get_uri (directory);
		_tmp85_ = _tmp84_;
		_tmp86_ = e;
		_tmp87_ = _tmp86_->message;
		g_debug ("plugin.vala:159: Error opening git repository at %s: %s", _tmp85_, _tmp87_);
		_g_error_free0 (e);
	}
	__finally1:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		_g_free0 (repo_uri);
		_g_free0 (dir_uri);
		_g_object_unref0 (info);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
	_g_free0 (repo_uri);
	_g_free0 (dir_uri);
	_g_object_unref0 (info);
}

static void
files_plugins_git_real_update_file_info (FilesPluginsBase* base,
                                         FilesFile* gof)
{
	FilesPluginsGit * self;
	gboolean _tmp0_ = FALSE;
	FilesGitRepoChildInfo* child_info = NULL;
	GHashTable* _tmp1_;
	GFile* _tmp2_;
	GFile* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gconstpointer _tmp6_;
	FilesGitRepoChildInfo* _tmp7_;
	FilesGitRepoChildInfo* _tmp8_;
	FilesGitRepoChildInfo* _tmp9_;
	FilesGitRepoInfo* repo_info = NULL;
	GHashTable* _tmp10_;
	FilesGitRepoChildInfo* _tmp11_;
	const gchar* _tmp12_;
	gconstpointer _tmp13_;
	FilesGitRepoInfo* _tmp14_;
	FilesGitRepoInfo* _tmp15_;
	self = (FilesPluginsGit*) base;
	g_return_if_fail (gof != NULL);
	if (gof->is_hidden) {
		_tmp0_ = gof->is_directory;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		return;
	}
	_tmp1_ = self->priv->child_map;
	_tmp2_ = files_file_get_directory (gof);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_file_get_uri (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = g_hash_table_lookup (_tmp1_, _tmp5_);
	_tmp7_ = _files_git_repo_child_info_dup0 ((FilesGitRepoChildInfo*) _tmp6_);
	_tmp8_ = _tmp7_;
	_g_free0 (_tmp5_);
	child_info = _tmp8_;
	_tmp9_ = child_info;
	if (_tmp9_ == NULL) {
		_files_git_repo_child_info_free0 (child_info);
		return;
	}
	_tmp10_ = self->priv->repo_map;
	_tmp11_ = child_info;
	_tmp12_ = (*_tmp11_).repo_uri;
	_tmp13_ = g_hash_table_lookup (_tmp10_, _tmp12_);
	_tmp14_ = _g_object_ref0 ((FilesGitRepoInfo*) _tmp13_);
	repo_info = _tmp14_;
	_tmp15_ = repo_info;
	if (_tmp15_ != NULL) {
		gchar* rel_path = NULL;
		FilesGitRepoChildInfo* _tmp16_;
		const gchar* _tmp17_;
		const gchar* _tmp18_;
		const gchar* _tmp19_;
		gchar* _tmp20_;
		const gchar* _tmp21_;
		_tmp16_ = child_info;
		_tmp17_ = (*_tmp16_).rel_path;
		_tmp18_ = files_file_get_basename (gof);
		_tmp19_ = _tmp18_;
		_tmp20_ = g_strconcat (_tmp17_, _tmp19_, NULL);
		rel_path = _tmp20_;
		_tmp21_ = rel_path;
		if (_tmp21_ != NULL) {
			GgitStatusFlags* git_status = NULL;
			FilesGitRepoInfo* _tmp22_;
			const gchar* _tmp23_;
			GgitStatusFlags* _tmp24_;
			GgitStatusFlags* _tmp25_;
			_tmp22_ = repo_info;
			_tmp23_ = rel_path;
			_tmp24_ = files_git_repo_info_lookup_status (_tmp22_, _tmp23_);
			git_status = _tmp24_;
			_tmp25_ = git_status;
			if (_tmp25_ != NULL) {
				GgitStatusFlags* _tmp26_;
				_tmp26_ = git_status;
				switch (*_tmp26_) {
					case GGIT_STATUS_CURRENT:
					{
						break;
					}
					case GGIT_STATUS_INDEX_MODIFIED:
					case GGIT_STATUS_WORKING_TREE_MODIFIED:
					{
						files_file_add_emblem (gof, "emblem-git-modified");
						break;
					}
					case GGIT_STATUS_WORKING_TREE_NEW:
					{
						files_file_add_emblem (gof, "emblem-git-new");
						break;
					}
					default:
					{
						break;
					}
				}
			}
			_g_free0 (git_status);
		} else {
			g_critical ("plugin.vala:199: Relative path is null");
		}
		_g_free0 (rel_path);
	}
	_g_object_unref0 (repo_info);
	_files_git_repo_child_info_free0 (child_info);
}

static void
files_plugins_git_class_init (FilesPluginsGitClass * klass,
                              gpointer klass_data)
{
	files_plugins_git_parent_class = g_type_class_peek_parent (klass);
	((FilesPluginsBaseClass *) klass)->finalize = files_plugins_git_finalize;
	g_type_class_adjust_private_offset (klass, &FilesPluginsGit_private_offset);
	((FilesPluginsBaseClass *) klass)->directory_loaded = (void (*) (FilesPluginsBase*, GtkApplicationWindow*, FilesAbstractSlot*, FilesFile*)) files_plugins_git_real_directory_loaded;
	((FilesPluginsBaseClass *) klass)->update_file_info = (void (*) (FilesPluginsBase*, FilesFile*)) files_plugins_git_real_update_file_info;
}

static void
files_plugins_git_instance_init (FilesPluginsGit * self,
                                 gpointer klass)
{
	self->priv = files_plugins_git_get_instance_private (self);
}

static void
files_plugins_git_finalize (FilesPluginsBase * obj)
{
	FilesPluginsGit * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_PLUGINS_TYPE_GIT, FilesPluginsGit);
	_g_hash_table_unref0 (self->priv->repo_map);
	_g_hash_table_unref0 (self->priv->child_map);
	FILES_PLUGINS_BASE_CLASS (files_plugins_git_parent_class)->finalize (obj);
}

static GType
files_plugins_git_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesPluginsGitClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_plugins_git_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesPluginsGit), 0, (GInstanceInitFunc) files_plugins_git_instance_init, NULL };
	GType files_plugins_git_type_id;
	files_plugins_git_type_id = g_type_register_static (FILES_PLUGINS_TYPE_BASE, "FilesPluginsGit", &g_define_type_info, 0);
	FilesPluginsGit_private_offset = g_type_add_instance_private (files_plugins_git_type_id, sizeof (FilesPluginsGitPrivate));
	return files_plugins_git_type_id;
}

GType
files_plugins_git_get_type (void)
{
	static volatile gsize files_plugins_git_type_id__once = 0;
	if (g_once_init_enter (&files_plugins_git_type_id__once)) {
		GType files_plugins_git_type_id;
		files_plugins_git_type_id = files_plugins_git_get_type_once ();
		g_once_init_leave (&files_plugins_git_type_id__once, files_plugins_git_type_id);
	}
	return files_plugins_git_type_id__once;
}

FilesPluginsBase*
module_init (void)
{
	FilesPluginsGit* plug = NULL;
	FilesPluginsGit* _tmp0_;
	FilesPluginsBase* result;
	ggit_init ();
	_tmp0_ = files_plugins_git_new ();
	plug = _tmp0_;
	result = (FilesPluginsBase*) plug;
	return result;
}

static void
_vala_array_destroy (gpointer array,
                     gssize array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		gssize i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}

static void
_vala_array_free (gpointer array,
                  gssize array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


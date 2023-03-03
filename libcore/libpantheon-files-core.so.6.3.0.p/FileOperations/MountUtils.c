/* MountUtils.c generated by valac 0.56.3, the Vala compiler
 * generated from MountUtils.vala, do not modify */

/* Copyright 2020 elementary LLC (https://elementary.io)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, Inc.,; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <gio/gio.h>
#include <gtk/gtk.h>
#include <glib.h>
#include "pantheon-files-core.h"
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>
#include <granite.h>
#include <unistd.h>
#include <glib-object.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _MarlinFileOperationsUnmountMountData MarlinFileOperationsUnmountMountData;
typedef struct _MarlinFileOperationsEjectMountData MarlinFileOperationsEjectMountData;
typedef struct _MarlinFileOperationsEjectDriveData MarlinFileOperationsEjectDriveData;
typedef struct _MarlinFileOperationsSafelyRemoveDriveData MarlinFileOperationsSafelyRemoveDriveData;
typedef struct _MarlinFileOperationsMountVolumeFullData MarlinFileOperationsMountVolumeFullData;
#define _marlin_file_operations_common_job_unref0(var) ((var == NULL) ? NULL : (var = (marlin_file_operations_common_job_unref (var), NULL)))

struct _MarlinFileOperationsUnmountMountData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	GMount* mount;
	GtkWindow* parent;
	gboolean result;
	GtkMountOperation* mount_op;
	GtkMountOperation* _tmp0_;
	GtkMountOperation* _tmp1_;
	GError* e;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	GError* _tmp6_;
	const gchar* _tmp7_;
	GraniteMessageDialog* _tmp8_;
	GraniteMessageDialog* _tmp9_;
	GError* _inner_error0_;
};

struct _MarlinFileOperationsEjectMountData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	GMount* mount;
	GtkWindow* parent;
	gboolean result;
	GtkMountOperation* mount_op;
	GtkMountOperation* _tmp0_;
	GtkMountOperation* _tmp1_;
	GError* e;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	GError* _tmp6_;
	const gchar* _tmp7_;
	GraniteMessageDialog* _tmp8_;
	GraniteMessageDialog* _tmp9_;
	GError* _inner_error0_;
};

struct _MarlinFileOperationsEjectDriveData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	GDrive* drive;
	GtkWindow* parent;
	GList* _tmp0_;
	GList* vol_collection;
	GList* vol_it;
	GVolume* _tmp1_;
	GVolume* vol;
	GMount* mount;
	GVolume* _tmp2_;
	GMount* _tmp3_;
	gboolean _tmp4_;
	GMount* _tmp5_;
	GMount* _tmp6_;
	GtkMountOperation* mount_op;
	GtkMountOperation* _tmp7_;
	GtkMountOperation* _tmp8_;
	GError* e;
	gchar* _tmp9_;
	gchar* _tmp10_;
	GError* _tmp11_;
	const gchar* _tmp12_;
	GError* _inner_error0_;
};

struct _MarlinFileOperationsSafelyRemoveDriveData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	GDrive* drive;
	GtkWindow* parent;
	GtkMountOperation* mount_op;
	GtkMountOperation* _tmp0_;
	GError* e;
	gchar* _tmp1_;
	gchar* _tmp2_;
	GError* _tmp3_;
	const gchar* _tmp4_;
	GError* _inner_error0_;
};

struct _MarlinFileOperationsMountVolumeFullData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	GVolume* volume;
	GtkWindow* parent_window;
	gboolean result;
	GtkMountOperation* mount_operation;
	GtkMountOperation* _tmp0_;
	GtkMountOperation* _tmp1_;
	GtkMountOperation* _tmp2_;
	GError* e;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	GError* _tmp7_;
	const gchar* _tmp8_;
	GraniteMessageDialog* _tmp9_;
	GraniteMessageDialog* _tmp10_;
	GError* _inner_error0_;
};

static void marlin_file_operations_unmount_mount_data_free (gpointer _data);
static gboolean marlin_file_operations_unmount_mount_co (MarlinFileOperationsUnmountMountData* _data_);
static void marlin_file_operations_unmount_mount_ready (GObject* source_object,
                                                 GAsyncResult* _res_,
                                                 gpointer _user_data_);
static void marlin_file_operations_eject_mount_data_free (gpointer _data);
static gboolean marlin_file_operations_eject_mount_co (MarlinFileOperationsEjectMountData* _data_);
static void marlin_file_operations_eject_mount_ready (GObject* source_object,
                                               GAsyncResult* _res_,
                                               gpointer _user_data_);
static void marlin_file_operations_eject_drive_data_free (gpointer _data);
static gboolean marlin_file_operations_eject_drive_co (MarlinFileOperationsEjectDriveData* _data_);
static void marlin_file_operations_eject_drive_ready (GObject* source_object,
                                               GAsyncResult* _res_,
                                               gpointer _user_data_);
static void _g_object_unref0_ (gpointer var);
static inline void _g_list_free__g_object_unref0_ (GList* self);
static void marlin_file_operations_safely_remove_drive_data_free (gpointer _data);
static gboolean marlin_file_operations_safely_remove_drive_co (MarlinFileOperationsSafelyRemoveDriveData* _data_);
static void marlin_file_operations_safely_remove_drive_ready (GObject* source_object,
                                                       GAsyncResult* _res_,
                                                       gpointer _user_data_);
static void marlin_file_operations_mount_volume_full_data_free (gpointer _data);
static gboolean marlin_file_operations_mount_volume_full_co (MarlinFileOperationsMountVolumeFullData* _data_);
static void marlin_file_operations_mount_volume_full_ready (GObject* source_object,
                                                     GAsyncResult* _res_,
                                                     gpointer _user_data_);
VALA_EXTERN gboolean marlin_file_operations_dir_has_files (GFile* dir);
static inline gpointer _vala_memdup2 (gconstpointer mem,
                        gsize byte_size);

static void
marlin_file_operations_unmount_mount_data_free (gpointer _data)
{
	MarlinFileOperationsUnmountMountData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->mount);
	_g_object_unref0 (_data_->parent);
	g_slice_free (MarlinFileOperationsUnmountMountData, _data_);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

void
marlin_file_operations_unmount_mount (GMount* mount,
                                      GtkWindow* parent,
                                      GAsyncReadyCallback _callback_,
                                      gpointer _user_data_)
{
	MarlinFileOperationsUnmountMountData* _data_;
	GMount* _tmp0_;
	GtkWindow* _tmp1_;
	g_return_if_fail (mount != NULL);
	_data_ = g_slice_new0 (MarlinFileOperationsUnmountMountData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, marlin_file_operations_unmount_mount_data_free);
	_tmp0_ = _g_object_ref0 (mount);
	_g_object_unref0 (_data_->mount);
	_data_->mount = _tmp0_;
	_tmp1_ = _g_object_ref0 (parent);
	_g_object_unref0 (_data_->parent);
	_data_->parent = _tmp1_;
	marlin_file_operations_unmount_mount_co (_data_);
}

gboolean
marlin_file_operations_unmount_mount_finish (GAsyncResult* _res_)
{
	gboolean result;
	MarlinFileOperationsUnmountMountData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
	result = _data_->result;
	return result;
}

static void
marlin_file_operations_unmount_mount_ready (GObject* source_object,
                                            GAsyncResult* _res_,
                                            gpointer _user_data_)
{
	MarlinFileOperationsUnmountMountData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	marlin_file_operations_unmount_mount_co (_data_);
}

static gboolean
marlin_file_operations_unmount_mount_co (MarlinFileOperationsUnmountMountData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	if (g_mount_can_unmount (_data_->mount)) {
		_data_->_tmp0_ = (GtkMountOperation*) gtk_mount_operation_new (_data_->parent);
		_data_->mount_op = _data_->_tmp0_;
		{
			_data_->_tmp1_ = _data_->mount_op;
			_data_->_state_ = 1;
			g_mount_unmount_with_operation (_data_->mount, G_MOUNT_UNMOUNT_NONE, (GMountOperation*) _data_->_tmp1_, NULL, marlin_file_operations_unmount_mount_ready, _data_);
			return FALSE;
			_state_1:
			g_mount_unmount_with_operation_finish (_data_->mount, _data_->_res_, &_data_->_inner_error0_);
			if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
				goto __catch0_g_error;
			}
			_data_->result = TRUE;
			_g_object_unref0 (_data_->mount_op);
			g_task_return_pointer (_data_->_async_result, _data_, NULL);
			if (_data_->_state_ != 0) {
				while (!g_task_get_completed (_data_->_async_result)) {
					g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
				}
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		}
		goto __finally0;
		__catch0_g_error:
		{
			_data_->e = _data_->_inner_error0_;
			_data_->_inner_error0_ = NULL;
			_data_->_tmp2_ = g_mount_get_name (_data_->mount);
			_data_->_tmp3_ = _data_->_tmp2_;
			_data_->_tmp4_ = g_strdup_printf (_ ("Unable to unmount '%s'"), _data_->_tmp3_);
			_data_->_tmp5_ = _data_->_tmp4_;
			_data_->_tmp6_ = _data_->e;
			_data_->_tmp7_ = _data_->_tmp6_->message;
			_data_->_tmp8_ = pf_dialogs_show_error_dialog (_data_->_tmp5_, _data_->_tmp7_, NULL);
			_data_->_tmp9_ = _data_->_tmp8_;
			_g_object_unref0 (_data_->_tmp9_);
			_g_free0 (_data_->_tmp5_);
			_g_free0 (_data_->_tmp3_);
			_data_->result = FALSE;
			_g_error_free0 (_data_->e);
			_g_object_unref0 (_data_->mount_op);
			g_task_return_pointer (_data_->_async_result, _data_, NULL);
			if (_data_->_state_ != 0) {
				while (!g_task_get_completed (_data_->_async_result)) {
					g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
				}
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		}
		__finally0:
		_g_object_unref0 (_data_->mount_op);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error0_->message, g_quark_to_string (_data_->_inner_error0_->domain), _data_->_inner_error0_->code);
		g_clear_error (&_data_->_inner_error0_);
		g_object_unref (_data_->_async_result);
		return FALSE;
	} else {
		_data_->_state_ = 2;
		marlin_file_operations_eject_mount (_data_->mount, _data_->parent, marlin_file_operations_unmount_mount_ready, _data_);
		return FALSE;
		_state_2:
		_data_->result = marlin_file_operations_eject_mount_finish (_data_->_res_);
		g_task_return_pointer (_data_->_async_result, _data_, NULL);
		if (_data_->_state_ != 0) {
			while (!g_task_get_completed (_data_->_async_result)) {
				g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
			}
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
}

static void
marlin_file_operations_eject_mount_data_free (gpointer _data)
{
	MarlinFileOperationsEjectMountData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->mount);
	_g_object_unref0 (_data_->parent);
	g_slice_free (MarlinFileOperationsEjectMountData, _data_);
}

void
marlin_file_operations_eject_mount (GMount* mount,
                                    GtkWindow* parent,
                                    GAsyncReadyCallback _callback_,
                                    gpointer _user_data_)
{
	MarlinFileOperationsEjectMountData* _data_;
	GMount* _tmp0_;
	GtkWindow* _tmp1_;
	g_return_if_fail (mount != NULL);
	_data_ = g_slice_new0 (MarlinFileOperationsEjectMountData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, marlin_file_operations_eject_mount_data_free);
	_tmp0_ = _g_object_ref0 (mount);
	_g_object_unref0 (_data_->mount);
	_data_->mount = _tmp0_;
	_tmp1_ = _g_object_ref0 (parent);
	_g_object_unref0 (_data_->parent);
	_data_->parent = _tmp1_;
	marlin_file_operations_eject_mount_co (_data_);
}

gboolean
marlin_file_operations_eject_mount_finish (GAsyncResult* _res_)
{
	gboolean result;
	MarlinFileOperationsEjectMountData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
	result = _data_->result;
	return result;
}

static void
marlin_file_operations_eject_mount_ready (GObject* source_object,
                                          GAsyncResult* _res_,
                                          gpointer _user_data_)
{
	MarlinFileOperationsEjectMountData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	marlin_file_operations_eject_mount_co (_data_);
}

static gboolean
marlin_file_operations_eject_mount_co (MarlinFileOperationsEjectMountData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	if (g_mount_can_eject (_data_->mount)) {
		_data_->_tmp0_ = (GtkMountOperation*) gtk_mount_operation_new (_data_->parent);
		_data_->mount_op = _data_->_tmp0_;
		{
			_data_->_tmp1_ = _data_->mount_op;
			_data_->_state_ = 1;
			g_mount_eject_with_operation (_data_->mount, G_MOUNT_UNMOUNT_NONE, (GMountOperation*) _data_->_tmp1_, NULL, marlin_file_operations_eject_mount_ready, _data_);
			return FALSE;
			_state_1:
			g_mount_eject_with_operation_finish (_data_->mount, _data_->_res_, &_data_->_inner_error0_);
			if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
				goto __catch0_g_error;
			}
			_data_->result = TRUE;
			_g_object_unref0 (_data_->mount_op);
			g_task_return_pointer (_data_->_async_result, _data_, NULL);
			if (_data_->_state_ != 0) {
				while (!g_task_get_completed (_data_->_async_result)) {
					g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
				}
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		}
		goto __finally0;
		__catch0_g_error:
		{
			_data_->e = _data_->_inner_error0_;
			_data_->_inner_error0_ = NULL;
			_data_->_tmp2_ = g_mount_get_name (_data_->mount);
			_data_->_tmp3_ = _data_->_tmp2_;
			_data_->_tmp4_ = g_strdup_printf (_ ("Unable to eject '%s'"), _data_->_tmp3_);
			_data_->_tmp5_ = _data_->_tmp4_;
			_data_->_tmp6_ = _data_->e;
			_data_->_tmp7_ = _data_->_tmp6_->message;
			_data_->_tmp8_ = pf_dialogs_show_error_dialog (_data_->_tmp5_, _data_->_tmp7_, NULL);
			_data_->_tmp9_ = _data_->_tmp8_;
			_g_object_unref0 (_data_->_tmp9_);
			_g_free0 (_data_->_tmp5_);
			_g_free0 (_data_->_tmp3_);
			_data_->result = FALSE;
			_g_error_free0 (_data_->e);
			_g_object_unref0 (_data_->mount_op);
			g_task_return_pointer (_data_->_async_result, _data_, NULL);
			if (_data_->_state_ != 0) {
				while (!g_task_get_completed (_data_->_async_result)) {
					g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
				}
			}
			g_object_unref (_data_->_async_result);
			return FALSE;
		}
		__finally0:
		_g_object_unref0 (_data_->mount_op);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error0_->message, g_quark_to_string (_data_->_inner_error0_->domain), _data_->_inner_error0_->code);
		g_clear_error (&_data_->_inner_error0_);
		g_object_unref (_data_->_async_result);
		return FALSE;
	} else {
		_data_->result = FALSE;
		g_task_return_pointer (_data_->_async_result, _data_, NULL);
		if (_data_->_state_ != 0) {
			while (!g_task_get_completed (_data_->_async_result)) {
				g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
			}
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
}

static void
marlin_file_operations_eject_drive_data_free (gpointer _data)
{
	MarlinFileOperationsEjectDriveData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->drive);
	_g_object_unref0 (_data_->parent);
	g_slice_free (MarlinFileOperationsEjectDriveData, _data_);
}

void
marlin_file_operations_eject_drive (GDrive* drive,
                                    GtkWindow* parent,
                                    GAsyncReadyCallback _callback_,
                                    gpointer _user_data_)
{
	MarlinFileOperationsEjectDriveData* _data_;
	GDrive* _tmp0_;
	GtkWindow* _tmp1_;
	g_return_if_fail (drive != NULL);
	_data_ = g_slice_new0 (MarlinFileOperationsEjectDriveData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, marlin_file_operations_eject_drive_data_free);
	_tmp0_ = _g_object_ref0 (drive);
	_g_object_unref0 (_data_->drive);
	_data_->drive = _tmp0_;
	_tmp1_ = _g_object_ref0 (parent);
	_g_object_unref0 (_data_->parent);
	_data_->parent = _tmp1_;
	marlin_file_operations_eject_drive_co (_data_);
}

void
marlin_file_operations_eject_drive_finish (GAsyncResult* _res_)
{
	MarlinFileOperationsEjectDriveData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
}

static void
marlin_file_operations_eject_drive_ready (GObject* source_object,
                                          GAsyncResult* _res_,
                                          gpointer _user_data_)
{
	MarlinFileOperationsEjectDriveData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	marlin_file_operations_eject_drive_co (_data_);
}

static void
_g_object_unref0_ (gpointer var)
{
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}

static inline void
_g_list_free__g_object_unref0_ (GList* self)
{
	g_list_free_full (self, (GDestroyNotify) _g_object_unref0_);
}

static gboolean
marlin_file_operations_eject_drive_co (MarlinFileOperationsEjectDriveData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = g_drive_get_volumes (_data_->drive);
	{
		_data_->vol_collection = _data_->_tmp0_;
		for (_data_->vol_it = _data_->vol_collection; _data_->vol_it != NULL; _data_->vol_it = _data_->vol_it->next) {
			_data_->_tmp1_ = _g_object_ref0 ((GVolume*) _data_->vol_it->data);
			_data_->vol = _data_->_tmp1_;
			{
				_data_->_tmp2_ = _data_->vol;
				_data_->_tmp3_ = g_volume_get_mount (_data_->_tmp2_);
				_data_->mount = _data_->_tmp3_;
				_data_->_tmp5_ = _data_->mount;
				if (_data_->_tmp5_ != NULL) {
					_data_->_tmp6_ = _data_->mount;
					_data_->_state_ = 1;
					marlin_file_operations_unmount_mount (_data_->_tmp6_, _data_->parent, marlin_file_operations_eject_drive_ready, _data_);
					return FALSE;
					_state_1:
					_data_->_tmp4_ = !marlin_file_operations_unmount_mount_finish (_data_->_res_);
				} else {
					_data_->_tmp4_ = FALSE;
				}
				if (_data_->_tmp4_) {
					_g_object_unref0 (_data_->mount);
					_g_object_unref0 (_data_->vol);
					(_data_->vol_collection == NULL) ? NULL : (_data_->vol_collection = (_g_list_free__g_object_unref0_ (_data_->vol_collection), NULL));
					g_task_return_pointer (_data_->_async_result, _data_, NULL);
					if (_data_->_state_ != 0) {
						while (!g_task_get_completed (_data_->_async_result)) {
							g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
						}
					}
					g_object_unref (_data_->_async_result);
					return FALSE;
				}
				_g_object_unref0 (_data_->mount);
				_g_object_unref0 (_data_->vol);
			}
		}
		(_data_->vol_collection == NULL) ? NULL : (_data_->vol_collection = (_g_list_free__g_object_unref0_ (_data_->vol_collection), NULL));
	}
	_data_->_tmp7_ = (GtkMountOperation*) gtk_mount_operation_new (_data_->parent);
	_data_->mount_op = _data_->_tmp7_;
	{
		_data_->_tmp8_ = _data_->mount_op;
		_data_->_state_ = 2;
		g_drive_eject_with_operation (_data_->drive, G_MOUNT_UNMOUNT_NONE, (GMountOperation*) _data_->_tmp8_, NULL, marlin_file_operations_eject_drive_ready, _data_);
		return FALSE;
		_state_2:
		g_drive_eject_with_operation_finish (_data_->drive, _data_->_res_, &_data_->_inner_error0_);
		if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->e = _data_->_inner_error0_;
		_data_->_inner_error0_ = NULL;
		_data_->_tmp9_ = g_drive_get_name (_data_->drive);
		_data_->_tmp10_ = _data_->_tmp9_;
		_data_->_tmp11_ = _data_->e;
		_data_->_tmp12_ = _data_->_tmp11_->message;
		g_warning ("MountUtils.vala:79: Unable to eject drive %s: %s", _data_->_tmp10_, _data_->_tmp12_);
		_g_free0 (_data_->_tmp10_);
		_g_error_free0 (_data_->e);
	}
	__finally0:
	if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
		_g_object_unref0 (_data_->mount_op);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error0_->message, g_quark_to_string (_data_->_inner_error0_->domain), _data_->_inner_error0_->code);
		g_clear_error (&_data_->_inner_error0_);
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_g_object_unref0 (_data_->mount_op);
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

static void
marlin_file_operations_safely_remove_drive_data_free (gpointer _data)
{
	MarlinFileOperationsSafelyRemoveDriveData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->drive);
	_g_object_unref0 (_data_->parent);
	g_slice_free (MarlinFileOperationsSafelyRemoveDriveData, _data_);
}

void
marlin_file_operations_safely_remove_drive (GDrive* drive,
                                            GtkWindow* parent,
                                            GAsyncReadyCallback _callback_,
                                            gpointer _user_data_)
{
	MarlinFileOperationsSafelyRemoveDriveData* _data_;
	GDrive* _tmp0_;
	GtkWindow* _tmp1_;
	g_return_if_fail (drive != NULL);
	_data_ = g_slice_new0 (MarlinFileOperationsSafelyRemoveDriveData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, marlin_file_operations_safely_remove_drive_data_free);
	_tmp0_ = _g_object_ref0 (drive);
	_g_object_unref0 (_data_->drive);
	_data_->drive = _tmp0_;
	_tmp1_ = _g_object_ref0 (parent);
	_g_object_unref0 (_data_->parent);
	_data_->parent = _tmp1_;
	marlin_file_operations_safely_remove_drive_co (_data_);
}

void
marlin_file_operations_safely_remove_drive_finish (GAsyncResult* _res_)
{
	MarlinFileOperationsSafelyRemoveDriveData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
}

static void
marlin_file_operations_safely_remove_drive_ready (GObject* source_object,
                                                  GAsyncResult* _res_,
                                                  gpointer _user_data_)
{
	MarlinFileOperationsSafelyRemoveDriveData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	marlin_file_operations_safely_remove_drive_co (_data_);
}

static gboolean
marlin_file_operations_safely_remove_drive_co (MarlinFileOperationsSafelyRemoveDriveData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_state_ = 1;
	marlin_file_operations_eject_drive (_data_->drive, _data_->parent, marlin_file_operations_safely_remove_drive_ready, _data_);
	return FALSE;
	_state_1:
	marlin_file_operations_eject_drive_finish (_data_->_res_);
	_data_->_tmp0_ = (GtkMountOperation*) gtk_mount_operation_new (_data_->parent);
	_data_->mount_op = _data_->_tmp0_;
	{
		_data_->_state_ = 2;
		g_drive_stop (_data_->drive, G_MOUNT_UNMOUNT_NONE, (GMountOperation*) _data_->mount_op, NULL, marlin_file_operations_safely_remove_drive_ready, _data_);
		return FALSE;
		_state_2:
		g_drive_stop_finish (_data_->drive, _data_->_res_, &_data_->_inner_error0_);
		if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->e = _data_->_inner_error0_;
		_data_->_inner_error0_ = NULL;
		_data_->_tmp1_ = g_drive_get_name (_data_->drive);
		_data_->_tmp2_ = _data_->_tmp1_;
		_data_->_tmp3_ = _data_->e;
		_data_->_tmp4_ = _data_->_tmp3_->message;
		g_warning ("MountUtils.vala:94: Unable to stop drive %s: %s", _data_->_tmp2_, _data_->_tmp4_);
		_g_free0 (_data_->_tmp2_);
		_g_error_free0 (_data_->e);
	}
	__finally0:
	if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
		_g_object_unref0 (_data_->mount_op);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error0_->message, g_quark_to_string (_data_->_inner_error0_->domain), _data_->_inner_error0_->code);
		g_clear_error (&_data_->_inner_error0_);
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_g_object_unref0 (_data_->mount_op);
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

static void
marlin_file_operations_mount_volume_full_data_free (gpointer _data)
{
	MarlinFileOperationsMountVolumeFullData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->volume);
	_g_object_unref0 (_data_->parent_window);
	g_slice_free (MarlinFileOperationsMountVolumeFullData, _data_);
}

void
marlin_file_operations_mount_volume_full (GVolume* volume,
                                          GtkWindow* parent_window,
                                          GAsyncReadyCallback _callback_,
                                          gpointer _user_data_)
{
	MarlinFileOperationsMountVolumeFullData* _data_;
	GVolume* _tmp0_;
	GtkWindow* _tmp1_;
	g_return_if_fail (volume != NULL);
	_data_ = g_slice_new0 (MarlinFileOperationsMountVolumeFullData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, marlin_file_operations_mount_volume_full_data_free);
	_tmp0_ = _g_object_ref0 (volume);
	_g_object_unref0 (_data_->volume);
	_data_->volume = _tmp0_;
	_tmp1_ = _g_object_ref0 (parent_window);
	_g_object_unref0 (_data_->parent_window);
	_data_->parent_window = _tmp1_;
	marlin_file_operations_mount_volume_full_co (_data_);
}

gboolean
marlin_file_operations_mount_volume_full_finish (GAsyncResult* _res_)
{
	gboolean result;
	MarlinFileOperationsMountVolumeFullData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
	result = _data_->result;
	return result;
}

static void
marlin_file_operations_mount_volume_full_ready (GObject* source_object,
                                                GAsyncResult* _res_,
                                                gpointer _user_data_)
{
	MarlinFileOperationsMountVolumeFullData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	marlin_file_operations_mount_volume_full_co (_data_);
}

static gboolean
marlin_file_operations_mount_volume_full_co (MarlinFileOperationsMountVolumeFullData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = (GtkMountOperation*) gtk_mount_operation_new (_data_->parent_window);
	_data_->mount_operation = _data_->_tmp0_;
	_data_->_tmp1_ = _data_->mount_operation;
	g_mount_operation_set_password_save ((GMountOperation*) _data_->_tmp1_, G_PASSWORD_SAVE_FOR_SESSION);
	{
		_data_->_tmp2_ = _data_->mount_operation;
		_data_->_state_ = 1;
		g_volume_mount (_data_->volume, G_MOUNT_MOUNT_NONE, (GMountOperation*) _data_->_tmp2_, NULL, marlin_file_operations_mount_volume_full_ready, _data_);
		return FALSE;
		_state_1:
		g_volume_mount_finish (_data_->volume, _data_->_res_, &_data_->_inner_error0_);
		if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		_data_->e = _data_->_inner_error0_;
		_data_->_inner_error0_ = NULL;
		_data_->_tmp3_ = g_volume_get_name (_data_->volume);
		_data_->_tmp4_ = _data_->_tmp3_;
		_data_->_tmp5_ = g_strdup_printf (_ ("Unable to mount '%s'"), _data_->_tmp4_);
		_data_->_tmp6_ = _data_->_tmp5_;
		_data_->_tmp7_ = _data_->e;
		_data_->_tmp8_ = _data_->_tmp7_->message;
		_data_->_tmp9_ = pf_dialogs_show_error_dialog (_data_->_tmp6_, _data_->_tmp8_, NULL);
		_data_->_tmp10_ = _data_->_tmp9_;
		_g_object_unref0 (_data_->_tmp10_);
		_g_free0 (_data_->_tmp6_);
		_g_free0 (_data_->_tmp4_);
		_data_->result = FALSE;
		_g_error_free0 (_data_->e);
		_g_object_unref0 (_data_->mount_operation);
		g_task_return_pointer (_data_->_async_result, _data_, NULL);
		if (_data_->_state_ != 0) {
			while (!g_task_get_completed (_data_->_async_result)) {
				g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
			}
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	__finally0:
	if (G_UNLIKELY (_data_->_inner_error0_ != NULL)) {
		_g_object_unref0 (_data_->mount_operation);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error0_->message, g_quark_to_string (_data_->_inner_error0_->domain), _data_->_inner_error0_->code);
		g_clear_error (&_data_->_inner_error0_);
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->result = TRUE;
	_g_object_unref0 (_data_->mount_operation);
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

void
marlin_file_operations_mount_volume (GVolume* volume,
                                     GtkWindow* parent_window)
{
	g_return_if_fail (volume != NULL);
	marlin_file_operations_mount_volume_full (volume, parent_window, NULL, NULL);
}

gboolean
marlin_file_operations_has_trash_files (GMount* mount)
{
	GList* dirs = NULL;
	GList* _tmp0_;
	GList* _tmp1_;
	gboolean result;
	if (mount == NULL) {
		result = FALSE;
		return result;
	}
	_tmp0_ = marlin_file_operations_get_trash_dirs_for_mount (mount);
	dirs = _tmp0_;
	_tmp1_ = dirs;
	{
		GList* dir_collection = NULL;
		GList* dir_it = NULL;
		dir_collection = _tmp1_;
		for (dir_it = dir_collection; dir_it != NULL; dir_it = dir_it->next) {
			GFile* dir = NULL;
			dir = (GFile*) dir_it->data;
			{
				GFile* _tmp2_;
				_tmp2_ = dir;
				if (marlin_file_operations_dir_has_files (_tmp2_)) {
					result = TRUE;
					(dirs == NULL) ? NULL : (dirs = (_g_list_free__g_object_unref0_ (dirs), NULL));
					return result;
				}
			}
		}
	}
	result = FALSE;
	(dirs == NULL) ? NULL : (dirs = (_g_list_free__g_object_unref0_ (dirs), NULL));
	return result;
}

gboolean
marlin_file_operations_mount_has_trash (GMount* mount)
{
	GFile* root = NULL;
	GFile* _tmp0_;
	GFile* _tmp1_;
	gboolean result;
	g_return_val_if_fail (mount != NULL, FALSE);
	_tmp0_ = g_mount_get_root (mount);
	root = _tmp0_;
	_tmp1_ = root;
	if (g_file_is_native (_tmp1_)) {
		gint uid = 0;
		gboolean _tmp2_ = FALSE;
		GFile* _tmp3_;
		gchar* _tmp4_;
		gchar* _tmp5_;
		GFile* _tmp6_;
		GFile* _tmp7_;
		gboolean _tmp8_;
		uid = (gint) getuid ();
		_tmp3_ = root;
		_tmp4_ = g_strdup_printf (".Trash/%d", uid);
		_tmp5_ = _tmp4_;
		_tmp6_ = g_file_resolve_relative_path (_tmp3_, _tmp5_);
		_tmp7_ = _tmp6_;
		_tmp8_ = _tmp7_ != NULL;
		_g_object_unref0 (_tmp7_);
		_g_free0 (_tmp5_);
		if (_tmp8_) {
			_tmp2_ = TRUE;
		} else {
			GFile* _tmp9_;
			gchar* _tmp10_;
			gchar* _tmp11_;
			GFile* _tmp12_;
			GFile* _tmp13_;
			_tmp9_ = root;
			_tmp10_ = g_strdup_printf (".Trash-%d", uid);
			_tmp11_ = _tmp10_;
			_tmp12_ = g_file_resolve_relative_path (_tmp9_, _tmp11_);
			_tmp13_ = _tmp12_;
			_tmp2_ = _tmp13_ != NULL;
			_g_object_unref0 (_tmp13_);
			_g_free0 (_tmp11_);
		}
		if (_tmp2_) {
			result = TRUE;
			_g_object_unref0 (root);
			return result;
		}
	}
	result = FALSE;
	_g_object_unref0 (root);
	return result;
}

GList*
marlin_file_operations_get_trash_dirs_for_mount (GMount* mount)
{
	GList* list = NULL;
	GFile* root = NULL;
	GFile* _tmp0_;
	GFile* _tmp1_;
	GList* result;
	g_return_val_if_fail (mount != NULL, NULL);
	list = NULL;
	_tmp0_ = g_mount_get_root (mount);
	root = _tmp0_;
	_tmp1_ = root;
	if (g_file_is_native (_tmp1_)) {
		gint uid = 0;
		GFile* trash = NULL;
		GFile* _tmp2_;
		gchar* _tmp3_;
		gchar* _tmp4_;
		GFile* _tmp5_;
		GFile* _tmp6_;
		GFile* _tmp7_;
		GFile* _tmp18_;
		gchar* _tmp19_;
		gchar* _tmp20_;
		GFile* _tmp21_;
		GFile* _tmp22_;
		uid = (gint) getuid ();
		_tmp2_ = root;
		_tmp3_ = g_strdup_printf (".Trash/%d", uid);
		_tmp4_ = _tmp3_;
		_tmp5_ = g_file_resolve_relative_path (_tmp2_, _tmp4_);
		_tmp6_ = _tmp5_;
		_g_free0 (_tmp4_);
		trash = _tmp6_;
		_tmp7_ = trash;
		if (_tmp7_ != NULL) {
			GFile* child = NULL;
			GFile* _tmp8_;
			GFile* _tmp9_;
			GFile* _tmp10_;
			GFile* _tmp13_;
			GFile* _tmp14_;
			GFile* _tmp15_;
			_tmp8_ = trash;
			_tmp9_ = g_file_get_child (_tmp8_, "files");
			child = _tmp9_;
			_tmp10_ = child;
			if (g_file_query_exists (_tmp10_, NULL)) {
				GFile* _tmp11_;
				GFile* _tmp12_;
				_tmp11_ = child;
				_tmp12_ = _g_object_ref0 (_tmp11_);
				list = g_list_prepend (list, _tmp12_);
			}
			_tmp13_ = trash;
			_tmp14_ = g_file_get_child (_tmp13_, "info");
			_g_object_unref0 (child);
			child = _tmp14_;
			_tmp15_ = child;
			if (g_file_query_exists (_tmp15_, NULL)) {
				GFile* _tmp16_;
				GFile* _tmp17_;
				_tmp16_ = child;
				_tmp17_ = _g_object_ref0 (_tmp16_);
				list = g_list_prepend (list, _tmp17_);
			}
			_g_object_unref0 (child);
		}
		_tmp18_ = root;
		_tmp19_ = g_strdup_printf (".Trash-%d", uid);
		_tmp20_ = _tmp19_;
		_tmp21_ = g_file_resolve_relative_path (_tmp18_, _tmp20_);
		_g_object_unref0 (trash);
		trash = _tmp21_;
		_g_free0 (_tmp20_);
		_tmp22_ = trash;
		if (_tmp22_ != NULL) {
			GFile* child = NULL;
			GFile* _tmp23_;
			GFile* _tmp24_;
			GFile* _tmp25_;
			GFile* _tmp28_;
			GFile* _tmp29_;
			GFile* _tmp30_;
			_tmp23_ = trash;
			_tmp24_ = g_file_get_child (_tmp23_, "files");
			child = _tmp24_;
			_tmp25_ = child;
			if (g_file_query_exists (_tmp25_, NULL)) {
				GFile* _tmp26_;
				GFile* _tmp27_;
				_tmp26_ = child;
				_tmp27_ = _g_object_ref0 (_tmp26_);
				list = g_list_prepend (list, _tmp27_);
			}
			_tmp28_ = trash;
			_tmp29_ = g_file_get_child (_tmp28_, "info");
			_g_object_unref0 (child);
			child = _tmp29_;
			_tmp30_ = child;
			if (g_file_query_exists (_tmp30_, NULL)) {
				GFile* _tmp31_;
				GFile* _tmp32_;
				_tmp31_ = child;
				_tmp32_ = _g_object_ref0 (_tmp31_);
				list = g_list_prepend (list, _tmp32_);
			}
			_g_object_unref0 (child);
		}
		_g_object_unref0 (trash);
	}
	result = list;
	_g_object_unref0 (root);
	return result;
}

void
marlin_file_operations_empty_trash_for_mount (GtkWidget* parent_view,
                                              GMount* mount)
{
	GList* dirs = NULL;
	GList* _tmp0_;
	GtkWindow* parent_window = NULL;
	FilesFileOperationsEmptyTrashJob* job = NULL;
	GtkWindow* _tmp2_;
	GList* _tmp3_;
	FilesFileOperationsEmptyTrashJob* _tmp4_;
	g_return_if_fail (mount != NULL);
	_tmp0_ = marlin_file_operations_get_trash_dirs_for_mount (mount);
	dirs = _tmp0_;
	parent_window = NULL;
	if (parent_view != NULL) {
		GtkWidget* _tmp1_;
		_tmp1_ = gtk_widget_get_ancestor (parent_view, gtk_window_get_type ());
		parent_window = G_TYPE_CHECK_INSTANCE_CAST (_tmp1_, gtk_window_get_type (), GtkWindow);
	}
	_tmp2_ = parent_window;
	_tmp3_ = dirs;
	dirs = NULL;
	_tmp4_ = marlin_file_operations_empty_trash_job_new (_tmp2_, _tmp3_);
	job = _tmp4_;
	marlin_file_operations_empty_trash_job_empty_trash (job, NULL, NULL);
	_marlin_file_operations_common_job_unref0 (job);
	(dirs == NULL) ? NULL : (dirs = (_g_list_free__g_object_unref0_ (dirs), NULL));
}

gboolean
marlin_file_operations_dir_has_files (GFile* dir)
{
	GError* _inner_error0_ = NULL;
	gboolean result;
	g_return_val_if_fail (dir != NULL, FALSE);
	{
		GFileEnumerator* enumerator = NULL;
		GFileEnumerator* _tmp0_;
		GFileInfo* _tmp1_ = NULL;
		GFileEnumerator* _tmp2_;
		GFileInfo* _tmp3_;
		_tmp0_ = g_file_enumerate_children (dir, G_FILE_ATTRIBUTE_STANDARD_NAME, G_FILE_QUERY_INFO_NONE, NULL, &_inner_error0_);
		enumerator = _tmp0_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			goto __catch0_g_error;
		}
		_tmp2_ = enumerator;
		_tmp3_ = g_file_enumerator_next_file (_tmp2_, NULL, &_inner_error0_);
		_tmp1_ = _tmp3_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			_g_object_unref0 (enumerator);
			goto __catch0_g_error;
		}
		if (_tmp1_ != NULL) {
			result = TRUE;
			_g_object_unref0 (_tmp1_);
			_g_object_unref0 (enumerator);
			return result;
		}
		_g_object_unref0 (_tmp1_);
		_g_object_unref0 (enumerator);
	}
	goto __finally0;
	__catch0_g_error:
	{
		g_clear_error (&_inner_error0_);
		result = FALSE;
		return result;
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		gboolean _tmp4_ = FALSE;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return _tmp4_;
	}
	result = FALSE;
	return result;
}

static inline gpointer
_vala_memdup2 (gconstpointer mem,
               gsize byte_size)
{
	gpointer new_mem;
	if (mem && byte_size != 0) {
		new_mem = g_malloc (byte_size);
		memcpy (new_mem, mem, byte_size);
	} else {
		new_mem = NULL;
	}
	return new_mem;
}


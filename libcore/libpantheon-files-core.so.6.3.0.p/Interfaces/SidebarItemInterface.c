/* SidebarItemInterface.c generated by valac 0.56.3, the Vala compiler
 * generated from SidebarItemInterface.vala, do not modify */

/*
 * SidebarItemInterface.vala
 *
 * Copyright 2020 elementary LLC. <https://elementary.io>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * Authors : Jeremy Wootten <jeremy@elementaryos.org>
 */

#include "pantheon-files-core.h"
#include <glib.h>
#include <gee.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <string.h>

guint32 sidebar_sidebar_item_interface_row_id = 0U;
GeeHashMap* sidebar_sidebar_item_interface_item_id_map = NULL;
GMutex sidebar_sidebar_item_interface_item_map_lock = {0};

static void sidebar_sidebar_item_interface_real_update_icon (SidebarSidebarItemInterface* self,
                                                      GIcon* icon);
static void sidebar_sidebar_item_interface_real_add_extra_menu_items (SidebarSidebarItemInterface* self,
                                                               PopupMenuBuilder* menu_builder);
static void sidebar_sidebar_item_interface_real_update_plugin_data (SidebarSidebarItemInterface* self,
                                                             FilesSidebarPluginItem* item);
static void sidebar_sidebar_item_interface_real_activated (SidebarSidebarItemInterface* self,
                                                    FilesOpenFlag flag);
static GType sidebar_sidebar_item_interface_get_type_once (void);
static inline gpointer _vala_memdup2 (gconstpointer mem,
                        gsize byte_size);

guint32
sidebar_sidebar_item_interface_get_next_item_id (void)
{
	guint32 _tmp0_;
	guint32 result;
	sidebar_sidebar_item_interface_row_id = sidebar_sidebar_item_interface_row_id + 1;
	_tmp0_ = sidebar_sidebar_item_interface_row_id;
	result = _tmp0_;
	return result;
}

SidebarSidebarItemInterface*
sidebar_sidebar_item_interface_get_item (guint32 id)
{
	SidebarSidebarItemInterface* item = NULL;
	GeeHashMap* _tmp0_;
	gpointer _tmp1_;
	SidebarSidebarItemInterface* result;
	if (id == ((guint32) 0)) {
		result = NULL;
		return result;
	}
	g_mutex_lock (&sidebar_sidebar_item_interface_item_map_lock);
	_tmp0_ = sidebar_sidebar_item_interface_item_id_map;
	_tmp1_ = gee_abstract_map_get ((GeeAbstractMap*) _tmp0_, (gpointer) ((guintptr) id));
	item = (SidebarSidebarItemInterface*) _tmp1_;
	g_mutex_unlock (&sidebar_sidebar_item_interface_item_map_lock);
	result = item;
	return result;
}

gint
sidebar_sidebar_item_interface_get_index (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, 0);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_index) {
		return _iface_->get_index (self);
	}
	return -1;
}

void
sidebar_sidebar_item_interface_destroy_bookmark (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->destroy_bookmark) {
		_iface_->destroy_bookmark (self);
	}
}

static void
sidebar_sidebar_item_interface_real_update_icon (SidebarSidebarItemInterface* self,
                                                 GIcon* icon)
{
	g_return_if_fail (icon != NULL);
	sidebar_sidebar_item_interface_set_gicon (self, icon);
}

void
sidebar_sidebar_item_interface_update_icon (SidebarSidebarItemInterface* self,
                                            GIcon* icon)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->update_icon) {
		_iface_->update_icon (self, icon);
	}
}

static void
sidebar_sidebar_item_interface_real_add_extra_menu_items (SidebarSidebarItemInterface* self,
                                                          PopupMenuBuilder* menu_builder)
{
	g_return_if_fail (menu_builder != NULL);
}

void
sidebar_sidebar_item_interface_add_extra_menu_items (SidebarSidebarItemInterface* self,
                                                     PopupMenuBuilder* menu_builder)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->add_extra_menu_items) {
		_iface_->add_extra_menu_items (self, menu_builder);
	}
}

static void
sidebar_sidebar_item_interface_real_update_plugin_data (SidebarSidebarItemInterface* self,
                                                        FilesSidebarPluginItem* item)
{
	g_return_if_fail (item != NULL);
}

void
sidebar_sidebar_item_interface_update_plugin_data (SidebarSidebarItemInterface* self,
                                                   FilesSidebarPluginItem* item)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->update_plugin_data) {
		_iface_->update_plugin_data (self, item);
	}
}

static void
sidebar_sidebar_item_interface_real_activated (SidebarSidebarItemInterface* self,
                                               FilesOpenFlag flag)
{
	SidebarSidebarListInterface* _tmp0_;
	SidebarSidebarListInterface* _tmp1_;
	_tmp0_ = sidebar_sidebar_item_interface_get_list (self);
	_tmp1_ = _tmp0_;
	sidebar_sidebar_list_interface_open_item (_tmp1_, self, flag);
}

void
sidebar_sidebar_item_interface_activated (SidebarSidebarItemInterface* self,
                                          FilesOpenFlag flag)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->activated) {
		_iface_->activated (self, flag);
	}
}

SidebarSidebarListInterface*
sidebar_sidebar_item_interface_get_list (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_list) {
		return _iface_->get_list (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_list (SidebarSidebarItemInterface* self,
                                         SidebarSidebarListInterface* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_list) {
		_iface_->set_list (self, value);
	}
}

guint32
sidebar_sidebar_item_interface_get_id (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, 0U);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_id) {
		return _iface_->get_id (self);
	}
	return 0U;
}

void
sidebar_sidebar_item_interface_set_id (SidebarSidebarItemInterface* self,
                                       guint32 value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_id) {
		_iface_->set_id (self, value);
	}
}

const gchar*
sidebar_sidebar_item_interface_get_uri (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_uri) {
		return _iface_->get_uri (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_uri (SidebarSidebarItemInterface* self,
                                        const gchar* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_uri) {
		_iface_->set_uri (self, value);
	}
}

const gchar*
sidebar_sidebar_item_interface_get_custom_name (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_custom_name) {
		return _iface_->get_custom_name (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_custom_name (SidebarSidebarItemInterface* self,
                                                const gchar* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_custom_name) {
		_iface_->set_custom_name (self, value);
	}
}

GIcon*
sidebar_sidebar_item_interface_get_gicon (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_gicon) {
		return _iface_->get_gicon (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_gicon (SidebarSidebarItemInterface* self,
                                          GIcon* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_gicon) {
		_iface_->set_gicon (self, value);
	}
}

gboolean
sidebar_sidebar_item_interface_get_pinned (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, FALSE);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_pinned) {
		return _iface_->get_pinned (self);
	}
	return FALSE;
}

void
sidebar_sidebar_item_interface_set_pinned (SidebarSidebarItemInterface* self,
                                           gboolean value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_pinned) {
		_iface_->set_pinned (self, value);
	}
}

gboolean
sidebar_sidebar_item_interface_get_permanent (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, FALSE);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_permanent) {
		return _iface_->get_permanent (self);
	}
	return FALSE;
}

void
sidebar_sidebar_item_interface_set_permanent (SidebarSidebarItemInterface* self,
                                              gboolean value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_permanent) {
		_iface_->set_permanent (self, value);
	}
}

gboolean
sidebar_sidebar_item_interface_get_can_insert_before (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, FALSE);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_can_insert_before) {
		return _iface_->get_can_insert_before (self);
	}
	return FALSE;
}

void
sidebar_sidebar_item_interface_set_can_insert_before (SidebarSidebarItemInterface* self,
                                                      gboolean value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_can_insert_before) {
		_iface_->set_can_insert_before (self, value);
	}
}

gboolean
sidebar_sidebar_item_interface_get_can_insert_after (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, FALSE);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_can_insert_after) {
		return _iface_->get_can_insert_after (self);
	}
	return FALSE;
}

void
sidebar_sidebar_item_interface_set_can_insert_after (SidebarSidebarItemInterface* self,
                                                     gboolean value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_can_insert_after) {
		_iface_->set_can_insert_after (self, value);
	}
}

GMenuModel*
sidebar_sidebar_item_interface_get_menu_model (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_menu_model) {
		return _iface_->get_menu_model (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_menu_model (SidebarSidebarItemInterface* self,
                                               GMenuModel* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_menu_model) {
		_iface_->set_menu_model (self, value);
	}
}

GActionGroup*
sidebar_sidebar_item_interface_get_action_group (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_action_group) {
		return _iface_->get_action_group (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_action_group (SidebarSidebarItemInterface* self,
                                                 GActionGroup* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_action_group) {
		_iface_->set_action_group (self, value);
	}
}

const gchar*
sidebar_sidebar_item_interface_get_action_group_namespace (SidebarSidebarItemInterface* self)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->get_action_group_namespace) {
		return _iface_->get_action_group_namespace (self);
	}
	return NULL;
}

void
sidebar_sidebar_item_interface_set_action_group_namespace (SidebarSidebarItemInterface* self,
                                                           const gchar* value)
{
	SidebarSidebarItemInterfaceIface* _iface_;
	g_return_if_fail (self != NULL);
	_iface_ = SIDEBAR_SIDEBAR_ITEM_INTERFACE_GET_INTERFACE (self);
	if (_iface_->set_action_group_namespace) {
		_iface_->set_action_group_namespace (self, value);
	}
}

static void
sidebar_sidebar_item_interface_default_init (SidebarSidebarItemInterfaceIface * iface,
                                             gpointer iface_data)
{
	g_object_interface_install_property (iface, g_param_spec_object ("list", "list", "list", SIDEBAR_TYPE_SIDEBAR_LIST_INTERFACE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_interface_install_property (iface, g_param_spec_uint ("id", "id", "id", 0, G_MAXUINT, 0U, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_interface_install_property (iface, g_param_spec_string ("uri", "uri", "uri", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_object_interface_install_property (iface, g_param_spec_string ("custom-name", "custom-name", "custom-name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_interface_install_property (iface, g_param_spec_object ("gicon", "gicon", "gicon", g_icon_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
	g_object_interface_install_property (iface, g_param_spec_boolean ("pinned", "pinned", "pinned", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_interface_install_property (iface, g_param_spec_boolean ("permanent", "permanent", "permanent", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_interface_install_property (iface, g_param_spec_boolean ("can-insert-before", "can-insert-before", "can-insert-before", TRUE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_interface_install_property (iface, g_param_spec_boolean ("can-insert-after", "can-insert-after", "can-insert-after", TRUE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_interface_install_property (iface, g_param_spec_object ("menu-model", "menu-model", "menu-model", g_menu_model_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_interface_install_property (iface, g_param_spec_object ("action-group", "action-group", "action-group", g_action_group_get_type (), G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_interface_install_property (iface, g_param_spec_string ("action-group-namespace", "action-group-namespace", "action-group-namespace", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	iface->update_icon = sidebar_sidebar_item_interface_real_update_icon;
	iface->add_extra_menu_items = sidebar_sidebar_item_interface_real_add_extra_menu_items;
	iface->update_plugin_data = sidebar_sidebar_item_interface_real_update_plugin_data;
	iface->activated = sidebar_sidebar_item_interface_real_activated;
}

static GType
sidebar_sidebar_item_interface_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (SidebarSidebarItemInterfaceIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sidebar_sidebar_item_interface_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType sidebar_sidebar_item_interface_type_id;
	sidebar_sidebar_item_interface_type_id = g_type_register_static (G_TYPE_INTERFACE, "SidebarSidebarItemInterface", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (sidebar_sidebar_item_interface_type_id, gtk_widget_get_type ());
	return sidebar_sidebar_item_interface_type_id;
}

GType
sidebar_sidebar_item_interface_get_type (void)
{
	static volatile gsize sidebar_sidebar_item_interface_type_id__once = 0;
	if (g_once_init_enter (&sidebar_sidebar_item_interface_type_id__once)) {
		GType sidebar_sidebar_item_interface_type_id;
		sidebar_sidebar_item_interface_type_id = sidebar_sidebar_item_interface_get_type_once ();
		g_once_init_leave (&sidebar_sidebar_item_interface_type_id__once, sidebar_sidebar_item_interface_type_id);
	}
	return sidebar_sidebar_item_interface_type_id__once;
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

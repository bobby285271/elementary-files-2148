/* pantheon-files-send-by-email.h generated by valac 0.56.3, the Vala compiler, do not modify */

#ifndef __PLUGINS_SEND_BY_EMAIL_PANTHEON_FILES_SEND_BY_EMAIL_H__
#define __PLUGINS_SEND_BY_EMAIL_PANTHEON_FILES_SEND_BY_EMAIL_H__

#include <gtk/gtk.h>
#include <glib-object.h>
#include <gio/gio.h>
#include "pantheon-files-core.h"
#include <stdlib.h>
#include <string.h>
#include <glib.h>

G_BEGIN_DECLS

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define FILES_PLUGINS_TYPE_SEND_BY_EMAIL_MENU_ITEM (files_plugins_send_by_email_menu_item_get_type ())
#define FILES_PLUGINS_SEND_BY_EMAIL_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_PLUGINS_TYPE_SEND_BY_EMAIL_MENU_ITEM, FilesPluginsSendByEmailMenuItem))
#define FILES_PLUGINS_SEND_BY_EMAIL_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_PLUGINS_TYPE_SEND_BY_EMAIL_MENU_ITEM, FilesPluginsSendByEmailMenuItemClass))
#define FILES_PLUGINS_IS_SEND_BY_EMAIL_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_PLUGINS_TYPE_SEND_BY_EMAIL_MENU_ITEM))
#define FILES_PLUGINS_IS_SEND_BY_EMAIL_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_PLUGINS_TYPE_SEND_BY_EMAIL_MENU_ITEM))
#define FILES_PLUGINS_SEND_BY_EMAIL_MENU_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_PLUGINS_TYPE_SEND_BY_EMAIL_MENU_ITEM, FilesPluginsSendByEmailMenuItemClass))

typedef struct _FilesPluginsSendByEmailMenuItem FilesPluginsSendByEmailMenuItem;
typedef struct _FilesPluginsSendByEmailMenuItemClass FilesPluginsSendByEmailMenuItemClass;
typedef struct _FilesPluginsSendByEmailMenuItemPrivate FilesPluginsSendByEmailMenuItemPrivate;

#define FILES_PLUGINS_TYPE_SEND_BY_EMAIL (files_plugins_send_by_email_get_type ())
#define FILES_PLUGINS_SEND_BY_EMAIL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_PLUGINS_TYPE_SEND_BY_EMAIL, FilesPluginsSendByEmail))
#define FILES_PLUGINS_SEND_BY_EMAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_PLUGINS_TYPE_SEND_BY_EMAIL, FilesPluginsSendByEmailClass))
#define FILES_PLUGINS_IS_SEND_BY_EMAIL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_PLUGINS_TYPE_SEND_BY_EMAIL))
#define FILES_PLUGINS_IS_SEND_BY_EMAIL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_PLUGINS_TYPE_SEND_BY_EMAIL))
#define FILES_PLUGINS_SEND_BY_EMAIL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_PLUGINS_TYPE_SEND_BY_EMAIL, FilesPluginsSendByEmailClass))

typedef struct _FilesPluginsSendByEmail FilesPluginsSendByEmail;
typedef struct _FilesPluginsSendByEmailClass FilesPluginsSendByEmailClass;
typedef struct _FilesPluginsSendByEmailPrivate FilesPluginsSendByEmailPrivate;

struct _FilesPluginsSendByEmailMenuItem {
	GtkMenuItem parent_instance;
	FilesPluginsSendByEmailMenuItemPrivate * priv;
};

struct _FilesPluginsSendByEmailMenuItemClass {
	GtkMenuItemClass parent_class;
};

struct _FilesPluginsSendByEmail {
	FilesPluginsBase parent_instance;
	FilesPluginsSendByEmailPrivate * priv;
};

struct _FilesPluginsSendByEmailClass {
	FilesPluginsBaseClass parent_class;
};

VALA_EXTERN GType files_plugins_send_by_email_menu_item_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesPluginsSendByEmailMenuItem, g_object_unref)
VALA_EXTERN FilesPluginsSendByEmailMenuItem* files_plugins_send_by_email_menu_item_new (GFile** files,
                                                                            gint files_length1);
VALA_EXTERN FilesPluginsSendByEmailMenuItem* files_plugins_send_by_email_menu_item_construct (GType object_type,
                                                                                  GFile** files,
                                                                                  gint files_length1);
VALA_EXTERN GType files_plugins_send_by_email_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesPluginsSendByEmail, files_plugins_base_unref)
VALA_EXTERN FilesPluginsSendByEmail* files_plugins_send_by_email_new (void);
VALA_EXTERN FilesPluginsSendByEmail* files_plugins_send_by_email_construct (GType object_type);
VALA_EXTERN FilesPluginsBase* module_init (void);
VALA_EXTERN gchar* portal_generate_token (void);

G_END_DECLS

#endif

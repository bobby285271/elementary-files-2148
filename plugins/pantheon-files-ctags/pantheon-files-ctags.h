/* pantheon-files-ctags.h generated by valac 0.56.3, the Vala compiler, do not modify */

#ifndef __PLUGINS_PANTHEON_FILES_CTAGS_PANTHEON_FILES_CTAGS_H__
#define __PLUGINS_PANTHEON_FILES_CTAGS_PANTHEON_FILES_CTAGS_H__

#include "pantheon-files-core.h"
#include <glib-object.h>
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

#define FILES_PLUGINS_TYPE_CTAGS (files_plugins_ctags_get_type ())
#define FILES_PLUGINS_CTAGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_PLUGINS_TYPE_CTAGS, FilesPluginsCTags))
#define FILES_PLUGINS_CTAGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_PLUGINS_TYPE_CTAGS, FilesPluginsCTagsClass))
#define FILES_PLUGINS_IS_CTAGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_PLUGINS_TYPE_CTAGS))
#define FILES_PLUGINS_IS_CTAGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_PLUGINS_TYPE_CTAGS))
#define FILES_PLUGINS_CTAGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_PLUGINS_TYPE_CTAGS, FilesPluginsCTagsClass))

typedef struct _FilesPluginsCTags FilesPluginsCTags;
typedef struct _FilesPluginsCTagsClass FilesPluginsCTagsClass;
typedef struct _FilesPluginsCTagsPrivate FilesPluginsCTagsPrivate;

struct _FilesPluginsCTags {
	FilesPluginsBase parent_instance;
	FilesPluginsCTagsPrivate * priv;
};

struct _FilesPluginsCTagsClass {
	FilesPluginsBaseClass parent_class;
};

VALA_EXTERN GType files_plugins_ctags_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesPluginsCTags, files_plugins_base_unref)
VALA_EXTERN FilesPluginsCTags* files_plugins_ctags_new (void);
VALA_EXTERN FilesPluginsCTags* files_plugins_ctags_construct (GType object_type);
VALA_EXTERN FilesPluginsBase* module_init (void);

G_END_DECLS

#endif
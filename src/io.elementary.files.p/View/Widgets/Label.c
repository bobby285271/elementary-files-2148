/* Label.c generated by valac 0.56.3, the Vala compiler
 * generated from Label.vala, do not modify */

/*
* Copyright (c) 2016-2018 elementary LLC. <https://elementary.io>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1335 USA.
*/

#include <gtk/gtk.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define TYPE_KEY_LABEL (key_label_get_type ())
#define KEY_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_KEY_LABEL, KeyLabel))
#define KEY_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_KEY_LABEL, KeyLabelClass))
#define IS_KEY_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_KEY_LABEL))
#define IS_KEY_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_KEY_LABEL))
#define KEY_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_KEY_LABEL, KeyLabelClass))

typedef struct _KeyLabel KeyLabel;
typedef struct _KeyLabelClass KeyLabelClass;
typedef struct _KeyLabelPrivate KeyLabelPrivate;
enum  {
	KEY_LABEL_0_PROPERTY,
	KEY_LABEL_NUM_PROPERTIES
};
static GParamSpec* key_label_properties[KEY_LABEL_NUM_PROPERTIES];

#define TYPE_VALUE_LABEL (value_label_get_type ())
#define VALUE_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_VALUE_LABEL, ValueLabel))
#define VALUE_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_VALUE_LABEL, ValueLabelClass))
#define IS_VALUE_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_VALUE_LABEL))
#define IS_VALUE_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_VALUE_LABEL))
#define VALUE_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_VALUE_LABEL, ValueLabelClass))

typedef struct _ValueLabel ValueLabel;
typedef struct _ValueLabelClass ValueLabelClass;
typedef struct _ValueLabelPrivate ValueLabelPrivate;
enum  {
	VALUE_LABEL_0_PROPERTY,
	VALUE_LABEL_NUM_PROPERTIES
};
static GParamSpec* value_label_properties[VALUE_LABEL_NUM_PROPERTIES];

struct _KeyLabel {
	GtkLabel parent_instance;
	KeyLabelPrivate * priv;
};

struct _KeyLabelClass {
	GtkLabelClass parent_class;
};

struct _ValueLabel {
	GtkLabel parent_instance;
	ValueLabelPrivate * priv;
};

struct _ValueLabelClass {
	GtkLabelClass parent_class;
};

static gpointer key_label_parent_class = NULL;
static gpointer value_label_parent_class = NULL;

VALA_EXTERN GType key_label_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (KeyLabel, g_object_unref)
VALA_EXTERN KeyLabel* key_label_new (const gchar* label);
VALA_EXTERN KeyLabel* key_label_construct (GType object_type,
                               const gchar* label);
static GType key_label_get_type_once (void);
VALA_EXTERN GType value_label_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (ValueLabel, g_object_unref)
VALA_EXTERN ValueLabel* value_label_new (const gchar* label);
VALA_EXTERN ValueLabel* value_label_construct (GType object_type,
                                   const gchar* label);
static GType value_label_get_type_once (void);

KeyLabel*
key_label_construct (GType object_type,
                     const gchar* label)
{
	KeyLabel * self = NULL;
	g_return_val_if_fail (label != NULL, NULL);
	self = (KeyLabel*) g_object_new (object_type, "halign", GTK_ALIGN_END, "label", label, "margin-start", 12, NULL);
	return self;
}

KeyLabel*
key_label_new (const gchar* label)
{
	return key_label_construct (TYPE_KEY_LABEL, label);
}

static void
key_label_class_init (KeyLabelClass * klass,
                      gpointer klass_data)
{
	key_label_parent_class = g_type_class_peek_parent (klass);
}

static void
key_label_instance_init (KeyLabel * self,
                         gpointer klass)
{
}

static GType
key_label_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (KeyLabelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) key_label_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (KeyLabel), 0, (GInstanceInitFunc) key_label_instance_init, NULL };
	GType key_label_type_id;
	key_label_type_id = g_type_register_static (gtk_label_get_type (), "KeyLabel", &g_define_type_info, 0);
	return key_label_type_id;
}

GType
key_label_get_type (void)
{
	static volatile gsize key_label_type_id__once = 0;
	if (g_once_init_enter (&key_label_type_id__once)) {
		GType key_label_type_id;
		key_label_type_id = key_label_get_type_once ();
		g_once_init_leave (&key_label_type_id__once, key_label_type_id);
	}
	return key_label_type_id__once;
}

ValueLabel*
value_label_construct (GType object_type,
                       const gchar* label)
{
	ValueLabel * self = NULL;
	g_return_val_if_fail (label != NULL, NULL);
	self = (ValueLabel*) g_object_new (object_type, "can-focus", TRUE, "halign", GTK_ALIGN_START, "label", label, "selectable", TRUE, "use-markup", TRUE, NULL);
	return self;
}

ValueLabel*
value_label_new (const gchar* label)
{
	return value_label_construct (TYPE_VALUE_LABEL, label);
}

static void
value_label_class_init (ValueLabelClass * klass,
                        gpointer klass_data)
{
	value_label_parent_class = g_type_class_peek_parent (klass);
}

static void
value_label_instance_init (ValueLabel * self,
                           gpointer klass)
{
}

static GType
value_label_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValueLabelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) value_label_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValueLabel), 0, (GInstanceInitFunc) value_label_instance_init, NULL };
	GType value_label_type_id;
	value_label_type_id = g_type_register_static (gtk_label_get_type (), "ValueLabel", &g_define_type_info, 0);
	return value_label_type_id;
}

GType
value_label_get_type (void)
{
	static volatile gsize value_label_type_id__once = 0;
	if (g_once_init_enter (&value_label_type_id__once)) {
		GType value_label_type_id;
		value_label_type_id = value_label_get_type_once ();
		g_once_init_leave (&value_label_type_id__once, value_label_type_id);
	}
	return value_label_type_id__once;
}


/* Browser.c generated by valac 0.56.3, the Vala compiler
 * generated from Browser.vala, do not modify */

#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <zeitgeist-datamodel.h>
#include <gee.h>
#include <gobject/gvaluecollector.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define FILES_VIEW_TYPE_BROWSER (files_view_browser_get_type ())
#define FILES_VIEW_BROWSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_VIEW_TYPE_BROWSER, FilesViewBrowser))
#define FILES_VIEW_BROWSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_VIEW_TYPE_BROWSER, FilesViewBrowserClass))
#define FILES_VIEW_IS_BROWSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_VIEW_TYPE_BROWSER))
#define FILES_VIEW_IS_BROWSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_VIEW_TYPE_BROWSER))
#define FILES_VIEW_BROWSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_VIEW_TYPE_BROWSER, FilesViewBrowserClass))

typedef struct _FilesViewBrowser FilesViewBrowser;
typedef struct _FilesViewBrowserClass FilesViewBrowserClass;
typedef struct _FilesViewBrowserPrivate FilesViewBrowserPrivate;

#define FILES_VIEW_TYPE_STACK (files_view_stack_get_type ())
#define FILES_VIEW_STACK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FILES_VIEW_TYPE_STACK, FilesViewStack))
#define FILES_VIEW_STACK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FILES_VIEW_TYPE_STACK, FilesViewStackClass))
#define FILES_VIEW_IS_STACK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FILES_VIEW_TYPE_STACK))
#define FILES_VIEW_IS_STACK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FILES_VIEW_TYPE_STACK))
#define FILES_VIEW_STACK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FILES_VIEW_TYPE_STACK, FilesViewStackClass))

typedef struct _FilesViewStack FilesViewStack;
typedef struct _FilesViewStackClass FilesViewStackClass;
enum  {
	FILES_VIEW_BROWSER_0_PROPERTY,
	FILES_VIEW_BROWSER_NUM_PROPERTIES
};
static GParamSpec* files_view_browser_properties[FILES_VIEW_BROWSER_NUM_PROPERTIES];
#define _files_view_stack_unref0(var) ((var == NULL) ? NULL : (var = (files_view_stack_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _FilesViewStackPrivate FilesViewStackPrivate;
typedef struct _FilesViewParamSpecStack FilesViewParamSpecStack;

struct _FilesViewBrowser {
	GObject parent_instance;
	FilesViewBrowserPrivate * priv;
	GtkMenu* back_menu;
	GtkMenu* forward_menu;
};

struct _FilesViewBrowserClass {
	GObjectClass parent_class;
};

struct _FilesViewBrowserPrivate {
	FilesViewStack* back_stack;
	FilesViewStack* forward_stack;
	gchar* current_uri;
	gint history_list_length;
};

struct _FilesViewStack {
	GTypeInstance parent_instance;
	volatile int ref_count;
	FilesViewStackPrivate * priv;
};

struct _FilesViewStackClass {
	GTypeClass parent_class;
	void (*finalize) (FilesViewStack *self);
};

struct _FilesViewStackPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	GeeLinkedList* list;
};

struct _FilesViewParamSpecStack {
	GParamSpec parent_instance;
};

static gint FilesViewBrowser_private_offset;
static gpointer files_view_browser_parent_class = NULL;
static gint FilesViewStack_private_offset;
static gpointer files_view_stack_parent_class = NULL;

VALA_EXTERN GType files_view_browser_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesViewBrowser, g_object_unref)
VALA_EXTERN gpointer files_view_stack_ref (gpointer instance);
VALA_EXTERN void files_view_stack_unref (gpointer instance);
VALA_EXTERN GParamSpec* files_view_param_spec_stack (const gchar* name,
                                         const gchar* nick,
                                         const gchar* blurb,
                                         GType object_type,
                                         GParamFlags flags);
VALA_EXTERN void files_view_value_set_stack (GValue* value,
                                 gpointer v_object);
VALA_EXTERN void files_view_value_take_stack (GValue* value,
                                  gpointer v_object);
VALA_EXTERN gpointer files_view_value_get_stack (const GValue* value);
VALA_EXTERN GType files_view_stack_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (FilesViewStack, files_view_stack_unref)
VALA_EXTERN FilesViewBrowser* files_view_browser_new (void);
VALA_EXTERN FilesViewBrowser* files_view_browser_construct (GType object_type);
VALA_EXTERN FilesViewStack* files_view_stack_new (GType g_type,
                                      GBoxedCopyFunc g_dup_func,
                                      GDestroyNotify g_destroy_func);
VALA_EXTERN FilesViewStack* files_view_stack_construct (GType object_type,
                                            GType g_type,
                                            GBoxedCopyFunc g_dup_func,
                                            GDestroyNotify g_destroy_func);
VALA_EXTERN void files_view_browser_record_uri (FilesViewBrowser* self,
                                    const gchar* uri);
VALA_EXTERN void files_view_stack_clear (FilesViewStack* self);
VALA_EXTERN FilesViewStack* files_view_stack_push (FilesViewStack* self,
                                       gconstpointer element);
VALA_EXTERN void files_zeitgeist_manager_report_event (const gchar* uri,
                                           const gchar* interpretation);
VALA_EXTERN GeeList* files_view_browser_go_back_list (FilesViewBrowser* self);
VALA_EXTERN GeeList* files_view_stack_slice_head (FilesViewStack* self,
                                      gint amount);
VALA_EXTERN GeeList* files_view_browser_go_forward_list (FilesViewBrowser* self);
VALA_EXTERN gchar* files_view_browser_go_back (FilesViewBrowser* self,
                                   guint n);
VALA_EXTERN gpointer files_view_stack_pop (FilesViewStack* self);
VALA_EXTERN gchar* files_view_browser_go_forward (FilesViewBrowser* self,
                                      guint n);
VALA_EXTERN gboolean files_view_browser_get_can_go_back (FilesViewBrowser* self);
VALA_EXTERN gboolean files_view_stack_is_empty (FilesViewStack* self);
VALA_EXTERN gboolean files_view_browser_get_can_go_forward (FilesViewBrowser* self);
static void files_view_browser_finalize (GObject * obj);
static GType files_view_browser_get_type_once (void);
VALA_EXTERN gpointer files_view_stack_peek (FilesViewStack* self);
VALA_EXTERN gint files_view_stack_size (FilesViewStack* self);
static void files_view_stack_finalize (FilesViewStack * obj);
static GType files_view_stack_get_type_once (void);

static inline gpointer
files_view_browser_get_instance_private (FilesViewBrowser* self)
{
	return G_STRUCT_MEMBER_P (self, FilesViewBrowser_private_offset);
}

FilesViewBrowser*
files_view_browser_construct (GType object_type)
{
	FilesViewBrowser * self = NULL;
	FilesViewStack* _tmp0_;
	FilesViewStack* _tmp1_;
	self = (FilesViewBrowser*) g_object_new (object_type, NULL);
	_tmp0_ = files_view_stack_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free);
	_files_view_stack_unref0 (self->priv->back_stack);
	self->priv->back_stack = _tmp0_;
	_tmp1_ = files_view_stack_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free);
	_files_view_stack_unref0 (self->priv->forward_stack);
	self->priv->forward_stack = _tmp1_;
	return self;
}

FilesViewBrowser*
files_view_browser_new (void)
{
	return files_view_browser_construct (FILES_VIEW_TYPE_BROWSER);
}

/**
         * Use this method to track an uri location in
         * the back/forward stacks
         */
void
files_view_browser_record_uri (FilesViewBrowser* self,
                               const gchar* uri)
{
	const gchar* _tmp0_;
	gchar* _tmp12_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->current_uri;
	if (_tmp0_ != NULL) {
		if (uri != NULL) {
			const gchar* _tmp1_;
			_tmp1_ = self->priv->current_uri;
			if (g_strcmp0 (_tmp1_, uri) != 0) {
				FilesViewStack* _tmp2_;
				FilesViewStack* _tmp3_;
				const gchar* _tmp4_;
				FilesViewStack* _tmp5_;
				FilesViewStack* _tmp6_;
				const gchar* _tmp7_;
				_tmp2_ = self->priv->forward_stack;
				files_view_stack_clear (_tmp2_);
				_tmp3_ = self->priv->back_stack;
				_tmp4_ = self->priv->current_uri;
				_tmp5_ = files_view_stack_push (_tmp3_, _tmp4_);
				_tmp6_ = _tmp5_;
				_files_view_stack_unref0 (_tmp6_);
				_tmp7_ = self->priv->current_uri;
				files_zeitgeist_manager_report_event (_tmp7_, ZEITGEIST_ZG_LEAVE_EVENT);
				files_zeitgeist_manager_report_event (uri, ZEITGEIST_ZG_ACCESS_EVENT);
			}
		} else {
			FilesViewStack* _tmp8_;
			const gchar* _tmp9_;
			FilesViewStack* _tmp10_;
			FilesViewStack* _tmp11_;
			_tmp8_ = self->priv->back_stack;
			_tmp9_ = self->priv->current_uri;
			_tmp10_ = files_view_stack_push (_tmp8_, _tmp9_);
			_tmp11_ = _tmp10_;
			_files_view_stack_unref0 (_tmp11_);
		}
	}
	_tmp12_ = g_strdup (uri);
	_g_free0 (self->priv->current_uri);
	self->priv->current_uri = _tmp12_;
}

GeeList*
files_view_browser_go_back_list (FilesViewBrowser* self)
{
	FilesViewStack* _tmp0_;
	GeeList* _tmp1_;
	GeeList* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->back_stack;
	_tmp1_ = files_view_stack_slice_head (_tmp0_, self->priv->history_list_length);
	result = _tmp1_;
	return result;
}

GeeList*
files_view_browser_go_forward_list (FilesViewBrowser* self)
{
	FilesViewStack* _tmp0_;
	GeeList* _tmp1_;
	GeeList* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->forward_stack;
	_tmp1_ = files_view_stack_slice_head (_tmp0_, self->priv->history_list_length);
	result = _tmp1_;
	return result;
}

gchar*
files_view_browser_go_back (FilesViewBrowser* self,
                            guint n)
{
	gchar* uri = NULL;
	FilesViewStack* _tmp0_;
	gpointer _tmp1_;
	const gchar* _tmp2_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_debug ("Browser.vala:74: [Browser] go back %i places", (gint) n);
	_tmp0_ = self->priv->back_stack;
	_tmp1_ = files_view_stack_pop (_tmp0_);
	uri = (gchar*) _tmp1_;
	_tmp2_ = uri;
	if (_tmp2_ != NULL) {
		const gchar* _tmp3_;
		_tmp3_ = self->priv->current_uri;
		if (_tmp3_ != NULL) {
			FilesViewStack* _tmp4_;
			const gchar* _tmp5_;
			FilesViewStack* _tmp6_;
			FilesViewStack* _tmp7_;
			const gchar* _tmp8_;
			gchar* _tmp9_;
			_tmp4_ = self->priv->forward_stack;
			_tmp5_ = self->priv->current_uri;
			_tmp6_ = files_view_stack_push (_tmp4_, _tmp5_);
			_tmp7_ = _tmp6_;
			_files_view_stack_unref0 (_tmp7_);
			_tmp8_ = uri;
			_tmp9_ = g_strdup (_tmp8_);
			_g_free0 (self->priv->current_uri);
			self->priv->current_uri = _tmp9_;
		}
	}
	if (n <= ((guint) 1)) {
		result = uri;
		return result;
	} else {
		gchar* _tmp10_;
		_tmp10_ = files_view_browser_go_back (self, n - 1);
		result = _tmp10_;
		_g_free0 (uri);
		return result;
	}
}

gchar*
files_view_browser_go_forward (FilesViewBrowser* self,
                               guint n)
{
	gchar* uri = NULL;
	FilesViewStack* _tmp0_;
	gpointer _tmp1_;
	const gchar* _tmp2_;
	gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	g_debug ("Browser.vala:91: [Browser] go forward %i places", (gint) n);
	_tmp0_ = self->priv->forward_stack;
	_tmp1_ = files_view_stack_pop (_tmp0_);
	uri = (gchar*) _tmp1_;
	_tmp2_ = uri;
	if (_tmp2_ != NULL) {
		const gchar* _tmp3_;
		_tmp3_ = self->priv->current_uri;
		if (_tmp3_ != NULL) {
			FilesViewStack* _tmp4_;
			const gchar* _tmp5_;
			FilesViewStack* _tmp6_;
			FilesViewStack* _tmp7_;
			const gchar* _tmp8_;
			gchar* _tmp9_;
			_tmp4_ = self->priv->back_stack;
			_tmp5_ = self->priv->current_uri;
			_tmp6_ = files_view_stack_push (_tmp4_, _tmp5_);
			_tmp7_ = _tmp6_;
			_files_view_stack_unref0 (_tmp7_);
			_tmp8_ = uri;
			_tmp9_ = g_strdup (_tmp8_);
			_g_free0 (self->priv->current_uri);
			self->priv->current_uri = _tmp9_;
		}
	}
	if (n <= ((guint) 1)) {
		result = uri;
		return result;
	} else {
		gchar* _tmp10_;
		_tmp10_ = files_view_browser_go_forward (self, n - 1);
		result = _tmp10_;
		_g_free0 (uri);
		return result;
	}
}

gboolean
files_view_browser_get_can_go_back (FilesViewBrowser* self)
{
	FilesViewStack* _tmp0_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->back_stack;
	result = !files_view_stack_is_empty (_tmp0_);
	return result;
}

gboolean
files_view_browser_get_can_go_forward (FilesViewBrowser* self)
{
	FilesViewStack* _tmp0_;
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->forward_stack;
	result = !files_view_stack_is_empty (_tmp0_);
	return result;
}

static void
files_view_browser_class_init (FilesViewBrowserClass * klass,
                               gpointer klass_data)
{
	files_view_browser_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &FilesViewBrowser_private_offset);
	G_OBJECT_CLASS (klass)->finalize = files_view_browser_finalize;
}

static void
files_view_browser_instance_init (FilesViewBrowser * self,
                                  gpointer klass)
{
	self->priv = files_view_browser_get_instance_private (self);
	self->priv->current_uri = NULL;
	self->priv->history_list_length = 10;
}

static void
files_view_browser_finalize (GObject * obj)
{
	FilesViewBrowser * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_VIEW_TYPE_BROWSER, FilesViewBrowser);
	_files_view_stack_unref0 (self->priv->back_stack);
	_files_view_stack_unref0 (self->priv->forward_stack);
	_g_free0 (self->priv->current_uri);
	_g_object_unref0 (self->back_menu);
	_g_object_unref0 (self->forward_menu);
	G_OBJECT_CLASS (files_view_browser_parent_class)->finalize (obj);
}

static GType
files_view_browser_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (FilesViewBrowserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_view_browser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesViewBrowser), 0, (GInstanceInitFunc) files_view_browser_instance_init, NULL };
	GType files_view_browser_type_id;
	files_view_browser_type_id = g_type_register_static (G_TYPE_OBJECT, "FilesViewBrowser", &g_define_type_info, 0);
	FilesViewBrowser_private_offset = g_type_add_instance_private (files_view_browser_type_id, sizeof (FilesViewBrowserPrivate));
	return files_view_browser_type_id;
}

GType
files_view_browser_get_type (void)
{
	static volatile gsize files_view_browser_type_id__once = 0;
	if (g_once_init_enter (&files_view_browser_type_id__once)) {
		GType files_view_browser_type_id;
		files_view_browser_type_id = files_view_browser_get_type_once ();
		g_once_init_leave (&files_view_browser_type_id__once, files_view_browser_type_id);
	}
	return files_view_browser_type_id__once;
}

static inline gpointer
files_view_stack_get_instance_private (FilesViewStack* self)
{
	return G_STRUCT_MEMBER_P (self, FilesViewStack_private_offset);
}

FilesViewStack*
files_view_stack_construct (GType object_type,
                            GType g_type,
                            GBoxedCopyFunc g_dup_func,
                            GDestroyNotify g_destroy_func)
{
	FilesViewStack* self = NULL;
	GeeLinkedList* _tmp0_;
	self = (FilesViewStack*) g_type_create_instance (object_type);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = gee_linked_list_new (g_type, (GBoxedCopyFunc) g_dup_func, (GDestroyNotify) g_destroy_func, NULL, NULL, NULL);
	_g_object_unref0 (self->priv->list);
	self->priv->list = _tmp0_;
	return self;
}

FilesViewStack*
files_view_stack_new (GType g_type,
                      GBoxedCopyFunc g_dup_func,
                      GDestroyNotify g_destroy_func)
{
	return files_view_stack_construct (FILES_VIEW_TYPE_STACK, g_type, g_dup_func, g_destroy_func);
}

static gpointer
_files_view_stack_ref0 (gpointer self)
{
	return self ? files_view_stack_ref (self) : NULL;
}

FilesViewStack*
files_view_stack_push (FilesViewStack* self,
                       gconstpointer element)
{
	GeeLinkedList* _tmp0_;
	FilesViewStack* _tmp1_;
	FilesViewStack* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->list;
	gee_deque_offer_head ((GeeDeque*) _tmp0_, element);
	_tmp1_ = _files_view_stack_ref0 (self);
	result = _tmp1_;
	return result;
}

gpointer
files_view_stack_pop (FilesViewStack* self)
{
	GeeLinkedList* _tmp0_;
	gpointer _tmp1_;
	gpointer result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->list;
	_tmp1_ = gee_deque_poll_head ((GeeDeque*) _tmp0_);
	result = _tmp1_;
	return result;
}

gpointer
files_view_stack_peek (FilesViewStack* self)
{
	GeeLinkedList* _tmp0_;
	gpointer _tmp1_;
	gpointer result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->list;
	_tmp1_ = gee_deque_peek_head ((GeeDeque*) _tmp0_);
	result = _tmp1_;
	return result;
}

gint
files_view_stack_size (FilesViewStack* self)
{
	GeeLinkedList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->list;
	_tmp1_ = gee_abstract_collection_get_size ((GeeAbstractCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}

void
files_view_stack_clear (FilesViewStack* self)
{
	GeeLinkedList* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->list;
	gee_abstract_collection_clear ((GeeAbstractCollection*) _tmp0_);
}

gboolean
files_view_stack_is_empty (FilesViewStack* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = files_view_stack_size (self) == 0;
	return result;
}

GeeList*
files_view_stack_slice_head (FilesViewStack* self,
                             gint amount)
{
	GeeLinkedList* _tmp0_;
	GeeList* _tmp1_;
	GeeList* result;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->list;
	_tmp1_ = gee_abstract_list_slice ((GeeAbstractList*) _tmp0_, 0, MIN (files_view_stack_size (self), amount));
	result = _tmp1_;
	return result;
}

static void
files_view_value_stack_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
files_view_value_stack_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		files_view_stack_unref (value->data[0].v_pointer);
	}
}

static void
files_view_value_stack_copy_value (const GValue* src_value,
                                   GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = files_view_stack_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
files_view_value_stack_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
files_view_value_stack_collect_value (GValue* value,
                                      guint n_collect_values,
                                      GTypeCValue* collect_values,
                                      guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		FilesViewStack * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = files_view_stack_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
files_view_value_stack_lcopy_value (const GValue* value,
                                    guint n_collect_values,
                                    GTypeCValue* collect_values,
                                    guint collect_flags)
{
	FilesViewStack ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = files_view_stack_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
files_view_param_spec_stack (const gchar* name,
                             const gchar* nick,
                             const gchar* blurb,
                             GType object_type,
                             GParamFlags flags)
{
	FilesViewParamSpecStack* spec;
	g_return_val_if_fail (g_type_is_a (object_type, FILES_VIEW_TYPE_STACK), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
files_view_value_get_stack (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FILES_VIEW_TYPE_STACK), NULL);
	return value->data[0].v_pointer;
}

void
files_view_value_set_stack (GValue* value,
                            gpointer v_object)
{
	FilesViewStack * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FILES_VIEW_TYPE_STACK));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FILES_VIEW_TYPE_STACK));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		files_view_stack_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		files_view_stack_unref (old);
	}
}

void
files_view_value_take_stack (GValue* value,
                             gpointer v_object)
{
	FilesViewStack * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, FILES_VIEW_TYPE_STACK));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, FILES_VIEW_TYPE_STACK));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		files_view_stack_unref (old);
	}
}

static void
files_view_stack_class_init (FilesViewStackClass * klass,
                             gpointer klass_data)
{
	files_view_stack_parent_class = g_type_class_peek_parent (klass);
	((FilesViewStackClass *) klass)->finalize = files_view_stack_finalize;
	g_type_class_adjust_private_offset (klass, &FilesViewStack_private_offset);
}

static void
files_view_stack_instance_init (FilesViewStack * self,
                                gpointer klass)
{
	self->priv = files_view_stack_get_instance_private (self);
	self->ref_count = 1;
}

static void
files_view_stack_finalize (FilesViewStack * obj)
{
	FilesViewStack * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, FILES_VIEW_TYPE_STACK, FilesViewStack);
	g_signal_handlers_destroy (self);
	_g_object_unref0 (self->priv->list);
}

/**
     * Stack api
     */
static GType
files_view_stack_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { files_view_value_stack_init, files_view_value_stack_free_value, files_view_value_stack_copy_value, files_view_value_stack_peek_pointer, "p", files_view_value_stack_collect_value, "p", files_view_value_stack_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (FilesViewStackClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_view_stack_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FilesViewStack), 0, (GInstanceInitFunc) files_view_stack_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType files_view_stack_type_id;
	files_view_stack_type_id = g_type_register_fundamental (g_type_fundamental_next (), "FilesViewStack", &g_define_type_info, &g_define_type_fundamental_info, 0);
	FilesViewStack_private_offset = g_type_add_instance_private (files_view_stack_type_id, sizeof (FilesViewStackPrivate));
	return files_view_stack_type_id;
}

GType
files_view_stack_get_type (void)
{
	static volatile gsize files_view_stack_type_id__once = 0;
	if (g_once_init_enter (&files_view_stack_type_id__once)) {
		GType files_view_stack_type_id;
		files_view_stack_type_id = files_view_stack_get_type_once ();
		g_once_init_leave (&files_view_stack_type_id__once, files_view_stack_type_id);
	}
	return files_view_stack_type_id__once;
}

gpointer
files_view_stack_ref (gpointer instance)
{
	FilesViewStack * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
files_view_stack_unref (gpointer instance)
{
	FilesViewStack * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		FILES_VIEW_STACK_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

/* godot-cpp example rewritten with usage of cppscript macros
 *
 * Read comments for syntax explanation
 *
 */
#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/tile_map.hpp>
#include <godot_cpp/classes/tile_set.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

//include this to use macros here
#include <cppscript.h>

using namespace godot;

class ExampleRef;

class Example : public Control {
	// Register your class
	// Possible class types:
	// basic class 		GCLASS(name, base_name)
	// virtual class 	GVIRTUAL_CLASS(name, base_name)
	// abstract class 	GABSTRACT_CLASS(name, base_name)
	GCLASS(Example, Control);

	// Signal declaration
	// provide signal name, list of (arg_type, arg_name)/arg_name
	GSIGNAL(custom_signal, String name, int value);
	GSIGNAL(example_signal, float typed_arg, untyped_arg);

protected:
	// This method is created automatically
	//static void _bind_methods();

	void _notification(int p_what);
	bool _set(const StringName &p_name, const Variant &p_value);
	bool _get(const StringName &p_name, Variant &r_ret) const;
	void _get_property_list(List<PropertyInfo> *p_list) const;
	bool _property_can_revert(const StringName &p_name) const;
	bool _property_get_revert(const StringName &p_name, Variant &r_property) const;

	String _to_string() const;

private:
	// Group/subgroup declarations
	// Affects all properties below it
	// Remove group with empty GGROUP()/GSUBGROUP() respectively
	GGROUP(Group);
	GSUBGROUP(Subgroup);

	// Property declaration
	// Provide setter and getter name
	// If member function with the same name is not declared,
	// it is created automatically
	// (it is a template, not a generated declaration,
	// so it is not assessible from a C++ code)
	GPROPERTY(set_custom_position, get_custom_position);

	Vector2 custom_position;
	

	// No custom set/get example
	GPROPERTY(set_float_auto, get_float_auto);
	float float_auto = 0;

private:
	Vector3 property_from_list;
	Vector2 dprop[3];
	int last_rpc_arg = 0;

public:
	// Enum declaration
	// Registered automatically when public
	enum Constants {
		FIRST,
		ANSWER_TO_EVERYTHING = 42,
	};

	// Bitfield declaration
	// Requires public access and GBITFIELD() macro
	GBITFIELD();
	enum Flags {
		FLAG_ONE = 1,
		FLAG_TWO = 2,
		FLAG_THREE = 4,
	};

	// Constants declaration
	// Registered automatically when public
	enum {
		CONSTANT_WITHOUT_ENUM = 314,
	};

	Example();
	~Example();

	// Methods declarations
	// Registered automatically when public

	void set_custom_position(const Vector2 &pos);
	Vector2 get_custom_position() const;

	virtual void _ready();
	void simple_func();
	void simple_const_func() const;
	int custom_ref_func(Ref<ExampleRef> p_ref);
	int custom_const_ref_func(const Ref<ExampleRef> &p_ref);
	String image_ref_func(Ref<Image> p_image);
	String image_const_ref_func(const Ref<Image> &p_image);
	String return_something(const String &base);
	Viewport *return_something_const() const;

	// Use GIGNORE() macro to not register
	// next method/enum/constant declaration
	GIGNORE();
	Ref<ExampleRef> return_ref() const;

	Ref<ExampleRef> return_empty_ref() const;
	ExampleRef *return_extended_ref() const;
	Ref<ExampleRef> extended_ref_checks(Ref<ExampleRef> p_ref) const;

	// Vararg method declaration
	// Provide list of (arg_type, arg_name)/arg_name (optional)
	// Manually provide correct function signature
	// Variant (*)(const Variant**, GDExtensionInt, GDExtensionCallError&);
	GVARARG(String some_argument);
	Variant varargs_func(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error);

	GVARARG(String some_argument);
	int varargs_func_nv(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error);

	GVARARG(String some_argument);
	void varargs_func_void(const Variant **args, GDExtensionInt arg_count, GDExtensionCallError &error);

	void emit_custom_signal(const String &name, int value);
	int def_args(int p_a = 100, int p_b = 200);

	Array test_array() const;
	int test_tarray_arg(const TypedArray<int64_t> &p_array);
	TypedArray<Vector2> test_tarray() const;
	Dictionary test_dictionary() const;
	Example *test_node_argument(Example *p_node) const;
	String test_string_ops() const;
	String test_str_utility() const;
	bool test_string_is_fourty_two(const String &p_str) const;
	int test_vector_ops() const;

	bool test_object_cast_to_node(Object *p_object) const;
	bool test_object_cast_to_control(Object *p_object) const;
	bool test_object_cast_to_example(Object *p_object) const;

	Vector2i test_variant_vector2i_conversion(const Variant &p_variant) const;
	int test_variant_int_conversion(const Variant &p_variant) const;
	float test_variant_float_conversion(const Variant &p_variant) const;

	void test_add_child(Node *p_node);
	void test_set_tileset(TileMap *p_tilemap, const Ref<TileSet> &p_tileset) const;
	
	BitField<Flags> test_bitfield(BitField<Flags> flags);

	// RPC method declaration
	// Same rules as in GDscript
	// To make use of RPC methods, you need to call
	// _rpc_config() generated method in _ready method
	// or on NOTIFICATION_READY notification
	GRPC(authority, reliable, call_local);
	void test_rpc(int p_value);

	void test_send_rpc(int p_value);
	int return_last_rpc_arg();

	Vector4 get_v4() const;

	// Static method declaration
	// Registered automatically if public
	static int test_static(int p_a, int p_b);
	static void test_static2();

	// Virtual functions are not registered
	virtual bool _has_point(const Vector2 &point) const override;
	virtual void _input(const Ref<InputEvent> &event) override;

	void print_vec();
};

/* Variant casts are generated in binds header
 *
VARIANT_ENUM_CAST(Example::Constants);
VARIANT_BITFIELD_CAST(Example::Flags);
*/

/* No enums outside of class for now
 *
enum EnumWithoutClass {
	OUTSIDE_OF_CLASS = 512
};
VARIANT_ENUM_CAST(EnumWithoutClass);
*/

class ExampleRef : public RefCounted {
	GCLASS(ExampleRef, RefCounted);

private:
	static int instance_count;
	static int last_id;

	GPROPERTY(set_id, get_id)
	int id;

protected:
	//static void _bind_methods();

public:
	ExampleRef();
	~ExampleRef();

	void set_id(int p_id);
	int get_id() const;
};

class ExampleMin : public Control {
	GCLASS(ExampleMin, Control);

};


class ExampleVirtual : public Object {
	GVIRTUAL_CLASS(ExampleVirtual, Object);
};

class ExampleAbstract : public Object {
	GABSTRACT_CLASS(ExampleAbstract, Object);
};

#endif // EXAMPLE_CLASS_H

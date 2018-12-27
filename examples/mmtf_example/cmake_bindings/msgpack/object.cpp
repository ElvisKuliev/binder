#include <iostream> // --trace
#include <msgpack/object.h> // msgpack_object
#include <msgpack/object.h> // msgpack_object_equal
#include <msgpack/object.h> // msgpack_object_kv
#include <msgpack/object.h> // msgpack_object_print
#include <msgpack/object.h> // msgpack_object_print_buffer
#include <sstream> // __str__
#include <stdio.h> // _IO_FILE

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <mmtf.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_msgpack_object(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	std::cout << "B187_[msgpack_object] ";
	{ // msgpack_object file:msgpack/object.h line:90
		pybind11::class_<msgpack_object, std::shared_ptr<msgpack_object>> cl(M(""), "msgpack_object", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new msgpack_object(); } ) );
		cl.def( pybind11::init( [](msgpack_object const &o){ return new msgpack_object(o); } ) );
		cl.def_readwrite("type", &msgpack_object::type);
		cl.def_readwrite("via", &msgpack_object::via);
	}
	std::cout << "B188_[msgpack_object_kv] ";
	std::cout << "B189_[void msgpack_object_print(struct _IO_FILE *, struct msgpack_object)] ";
	std::cout << "B190_[int msgpack_object_print_buffer(char *, unsigned long, struct msgpack_object)] ";
	std::cout << "B191_[bool msgpack_object_equal(const struct msgpack_object, const struct msgpack_object)] ";
}
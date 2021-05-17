/// <summary>
/// Internals of the bindings between native and .NET code.
/// Game code shouldn't go here.
/// </summary>
/// <author>
/// Jackson Dunstan, 2017, http://JacksonDunstan.com
/// </author>
/// <license>
/// MIT
/// </license>

// Game type definitions
#include "NativeScript.h"

// Type definitions
#include "Bindings.h"

// For assert()
#include <assert.h>

// For memset(), etc.
#include <string.h>

////////////////////////////////////////////////////////////////
// C# functions for C++ to call
////////////////////////////////////////////////////////////////

namespace Plugin
{
	void (*ReleaseObject)(int32_t handle);
	int32_t (*StringNew)(const char* chars);
	void (*SetException)(int32_t handle);
	int32_t (*ArrayGetLength)(int32_t handle);
	int32_t (*EnumerableGetEnumerator)(int32_t handle);
	
	/*BEGIN FUNCTION POINTERS*/
	void (*ReleaseSystemDecimal)(int32_t handle);
	int32_t (*SystemDecimalConstructorSystemDouble)(double value);
	int32_t (*SystemDecimalConstructorSystemUInt64)(uint64_t value);
	int32_t (*BoxDecimal)(int32_t valHandle);
	int32_t (*UnboxDecimal)(int32_t valHandle);
	UnityEngine::Vector3 (*UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle)(float x, float y, float z);
	UnityEngine::Vector3 (*UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3)(UnityEngine::Vector3& a, UnityEngine::Vector3& b);
	int32_t (*BoxVector3)(UnityEngine::Vector3& val);
	UnityEngine::Vector3 (*UnboxVector3)(int32_t valHandle);
	int32_t (*UnityEngineObjectPropertyGetName)(int32_t thisHandle);
	void (*UnityEngineObjectPropertySetName)(int32_t thisHandle, int32_t valueHandle);
	int32_t (*UnityEngineObjectMethodInstantiateUnityEngineObject)(int32_t originalHandle);
	int32_t (*UnityEngineComponentPropertyGetTransform)(int32_t thisHandle);
	UnityEngine::Vector3 (*UnityEngineTransformPropertyGetPosition)(int32_t thisHandle);
	void (*UnityEngineTransformPropertySetPosition)(int32_t thisHandle, UnityEngine::Vector3& value);
	int32_t (*SystemCollectionsIEnumeratorPropertyGetCurrent)(int32_t thisHandle);
	int32_t (*SystemCollectionsIEnumeratorMethodMoveNext)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectConstructor)();
	int32_t (*UnityEngineGameObjectMethodAddComponentNativeBaseNativeScript)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodAddComponentNativeBaseNativeEntityView)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodGetComponentNativeBaseNativeEntityView)(int32_t thisHandle);
	int32_t (*UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType)(UnityEngine::PrimitiveType type);
	void (*UnityEngineDebugMethodLogSystemObject)(int32_t messageHandle);
	int32_t (*UnityEngineMonoBehaviourPropertyGetTransform)(int32_t thisHandle);
	int32_t (*SystemExceptionConstructorSystemString)(int32_t messageHandle);
	int32_t (*BoxPrimitiveType)(UnityEngine::PrimitiveType val);
	UnityEngine::PrimitiveType (*UnboxPrimitiveType)(int32_t valHandle);
	void (*UnityEngineProfilingProfilerMethodBeginSampleSystemString)(int32_t nameHandle);
	void (*UnityEngineProfilingProfilerMethodEndSample)();
	float (*UnityEngineTimePropertyGetDeltaTime)();
	int32_t (*NativeEventHubConstructor)();
	void (*NativeEventHubMethodInvokeEntityDestroyedSystemUInt32)(int32_t thisHandle, uint32_t e);
	int32_t (*NativeAbstractBaseNativeScriptPropertyGetEvents)(int32_t thisHandle);
	void (*ReleaseBaseNativeScript)(int32_t handle);
	void (*BaseNativeScriptConstructor)(int32_t cppHandle, int32_t* handle);
	uint32_t (*NativeBaseNativeEntityViewPropertyGetEntityRef)(int32_t thisHandle);
	void (*NativeBaseNativeEntityViewPropertySetEntityRef)(int32_t thisHandle, uint32_t value);
	int32_t (*UnityEngineResourcesMethodLoadUnityEngineGameObjectSystemString)(int32_t pathHandle);
	int32_t (*NativeUnityTypeHelpersMethodDowncastUnityEngineGameObjectUnityEngineObject)(int32_t objHandle);
	int32_t (*BoxBoolean)(uint32_t val);
	int32_t (*UnboxBoolean)(int32_t valHandle);
	int32_t (*BoxSByte)(int8_t val);
	int8_t (*UnboxSByte)(int32_t valHandle);
	int32_t (*BoxByte)(uint8_t val);
	uint8_t (*UnboxByte)(int32_t valHandle);
	int32_t (*BoxInt16)(int16_t val);
	int16_t (*UnboxInt16)(int32_t valHandle);
	int32_t (*BoxUInt16)(uint16_t val);
	uint16_t (*UnboxUInt16)(int32_t valHandle);
	int32_t (*BoxInt32)(int32_t val);
	int32_t (*UnboxInt32)(int32_t valHandle);
	int32_t (*BoxUInt32)(uint32_t val);
	uint32_t (*UnboxUInt32)(int32_t valHandle);
	int32_t (*BoxInt64)(int64_t val);
	int64_t (*UnboxInt64)(int32_t valHandle);
	int32_t (*BoxUInt64)(uint64_t val);
	uint64_t (*UnboxUInt64)(int32_t valHandle);
	int32_t (*BoxChar)(uint16_t val);
	int16_t (*UnboxChar)(int32_t valHandle);
	int32_t (*BoxSingle)(float val);
	float (*UnboxSingle)(int32_t valHandle);
	int32_t (*BoxDouble)(double val);
	double (*UnboxDouble)(int32_t valHandle);
	/*END FUNCTION POINTERS*/
}

////////////////////////////////////////////////////////////////
// Global variables
////////////////////////////////////////////////////////////////

namespace Plugin
{
	System::String NullString(nullptr);
}

////////////////////////////////////////////////////////////////
// Plugin Types
////////////////////////////////////////////////////////////////

namespace Plugin
{
	ManagedType::ManagedType()
		: Handle(0)
	{
	}
	
	ManagedType::ManagedType(decltype(nullptr))
		: Handle(0)
	{
	}
	
	ManagedType::ManagedType(Plugin::InternalUse iu, int32_t handle)
		: Handle(handle)
	{
	}
}

////////////////////////////////////////////////////////////////
// C# Primitive Types
////////////////////////////////////////////////////////////////

namespace System
{
	Boolean::Boolean()
		: Value(0)
	{
	}
	
	Boolean::Boolean(bool value)
		: Value((int32_t)value)
	{
	}
	
	Boolean::Boolean(int32_t value)
		: Value(value)
	{
	}
	
	Boolean::Boolean(uint32_t value)
		: Value(value)
	{
	}
	
	Boolean::operator bool() const
	{
		return (bool)Value;
	}
	
	Boolean::operator int32_t() const
	{
		return Value;
	}
	
	Boolean::operator uint32_t() const
	{
		return Value;
	}
	
	Boolean::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IComparable_1<Boolean>() const
	{
		return IComparable_1<Boolean>(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Boolean::operator IEquatable_1<Boolean>() const
	{
		return IEquatable_1<Boolean>(Plugin::InternalUse::Only, Plugin::BoxBoolean(Value));
	}
	
	Char::Char()
		: Value(0)
	{
	}
	
	Char::Char(char value)
		: Value(value)
	{
	}
	
	Char::Char(int16_t value)
		: Value(value)
	{
	}
	
	Char::operator int16_t() const
	{
		return Value;
	}
	
	Char::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IComparable_1<Char>() const
	{
		return IComparable_1<Char>(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}
	
	Char::operator IEquatable_1<Char>() const
	{
		return IEquatable_1<Char>(Plugin::InternalUse::Only, Plugin::BoxChar(Value));
	}

	SByte::SByte()
		: Value(0)
	{
	}
	
	SByte::SByte(int8_t val)
		: Value(val)
	{
	}
	
	SByte::operator int8_t() const
	{
		return Value;
	}
	
	SByte::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IComparable_1<SByte>() const
	{
		return IComparable_1<SByte>(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}
	
	SByte::operator IEquatable_1<SByte>() const
	{
		return IEquatable_1<SByte>(Plugin::InternalUse::Only, Plugin::BoxSByte(Value));
	}

	Byte::Byte()
		: Value(0)
	{
	}
	
	Byte::Byte(uint8_t value)
		: Value(value)
	{
	}
	
	Byte::operator uint8_t() const
	{
		return Value;
	}
	
	Byte::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IComparable_1<Byte>() const
	{
		return IComparable_1<Byte>(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}
	
	Byte::operator IEquatable_1<Byte>() const
	{
		return IEquatable_1<Byte>(Plugin::InternalUse::Only, Plugin::BoxByte(Value));
	}

	Int16::Int16()
		: Value(0)
	{
	}
	
	Int16::Int16(int16_t value)
		: Value(value)
	{
	}
	
	Int16::operator int16_t() const
	{
		return Value;
	}
	
	Int16::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IComparable_1<Int16>() const
	{
		return IComparable_1<Int16>(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}
	
	Int16::operator IEquatable_1<Int16>() const
	{
		return IEquatable_1<Int16>(Plugin::InternalUse::Only, Plugin::BoxInt16(Value));
	}

	UInt16::UInt16()
		: Value(0)
	{
	}
	
	UInt16::UInt16(uint16_t value)
		: Value(value)
	{
	}
	
	UInt16::operator uint16_t() const
	{
		return Value;
	}
	
	UInt16::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IComparable_1<UInt16>() const
	{
		return IComparable_1<UInt16>(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}
	
	UInt16::operator IEquatable_1<UInt16>() const
	{
		return IEquatable_1<UInt16>(Plugin::InternalUse::Only, Plugin::BoxUInt16(Value));
	}

	Int32::Int32()
		: Value(0)
	{
	}
	
	Int32::Int32(int32_t value)
		: Value(value)
	{
	}
	
	Int32::operator int32_t() const
	{
		return Value;
	}
	
	Int32::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IComparable_1<Int32>() const
	{
		return IComparable_1<Int32>(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}
	
	Int32::operator IEquatable_1<Int32>() const
	{
		return IEquatable_1<Int32>(Plugin::InternalUse::Only, Plugin::BoxInt32(Value));
	}

	UInt32::UInt32()
		: Value(0)
	{
	}
	
	UInt32::UInt32(uint32_t value)
		: Value(value)
	{
	}
	
	UInt32::operator uint32_t() const
	{
		return Value;
	}
	
	UInt32::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IComparable_1<UInt32>() const
	{
		return IComparable_1<UInt32>(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}
	
	UInt32::operator IEquatable_1<UInt32>() const
	{
		return IEquatable_1<UInt32>(Plugin::InternalUse::Only, Plugin::BoxUInt32(Value));
	}

	Int64::Int64()
		: Value(0)
	{
	}
	
	Int64::Int64(int64_t value)
		: Value(value)
	{
	}
	
	Int64::operator int64_t() const
	{
		return Value;
	}
	
	Int64::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IComparable_1<Int64>() const
	{
		return IComparable_1<Int64>(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}
	
	Int64::operator IEquatable_1<Int64>() const
	{
		return IEquatable_1<Int64>(Plugin::InternalUse::Only, Plugin::BoxInt64(Value));
	}

	UInt64::UInt64()
		: Value(0)
	{
	}
	
	UInt64::UInt64(uint64_t value)
		: Value(value)
	{
	}
	
	UInt64::operator uint64_t() const
	{
		return Value;
	}
	
	UInt64::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IComparable_1<UInt64>() const
	{
		return IComparable_1<UInt64>(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}
	
	UInt64::operator IEquatable_1<UInt64>() const
	{
		return IEquatable_1<UInt64>(Plugin::InternalUse::Only, Plugin::BoxUInt64(Value));
	}

	Single::Single()
		: Value(0.0f)
	{
	}
	
	Single::Single(float value)
		: Value(value)
	{
	}
	
	Single::operator float() const
	{
		return Value;
	}
	
	Single::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IComparable_1<Single>() const
	{
		return IComparable_1<Single>(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}
	
	Single::operator IEquatable_1<Single>() const
	{
		return IEquatable_1<Single>(Plugin::InternalUse::Only, Plugin::BoxSingle(Value));
	}

	Double::Double()
		: Value(0.0)
	{
	}
	
	Double::Double(double value)
		: Value(value)
	{
	}
	
	Double::operator double() const
	{
		return Value;
	}
	
	Double::operator Object() const
	{
		return Object(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator ValueType() const
	{
		return ValueType(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IComparable() const
	{
		return IComparable(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IFormattable() const
	{
		return IFormattable(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IConvertible() const
	{
		return IConvertible(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IComparable_1<Double>() const
	{
		return IComparable_1<Double>(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
	
	Double::operator IEquatable_1<Double>() const
	{
		return IEquatable_1<Double>(Plugin::InternalUse::Only, Plugin::BoxDouble(Value));
	}
}

////////////////////////////////////////////////////////////////
// Support for using IEnumerable with range for loops
////////////////////////////////////////////////////////////////

namespace Plugin
{
	// End iterators are dummies full of null
	EnumerableIterator::EnumerableIterator(decltype(nullptr))
		: enumerator(nullptr)
		, hasMore(false)
	{
	}
	
	// Begin iterators keep track of an IEnumerator
	EnumerableIterator::EnumerableIterator(
		System::Collections::IEnumerable& enumerable)
		: enumerator(enumerable.GetEnumerator())
	{
		hasMore = enumerator.MoveNext();
	}
	
	EnumerableIterator& EnumerableIterator::operator++()
	{
		hasMore = enumerator.MoveNext();
		return *this;
	}
	
	bool EnumerableIterator::operator!=(const EnumerableIterator& other)
	{
		return hasMore;
	}
	
	System::Object EnumerableIterator::operator*()
	{
		return enumerator.GetCurrent();
	}
}

////////////////////////////////////////////////////////////////
// User-defined literals for creating decimals (System.Decimal)
////////////////////////////////////////////////////////////////

System::Decimal operator"" _m(long double x)
{
	return System::Decimal((System::Double)x);
}

System::Decimal operator"" _m(unsigned long long x)
{
	return System::Decimal((System::UInt64)x);
}

////////////////////////////////////////////////////////////////
// Reference counting of managed objects
////////////////////////////////////////////////////////////////

namespace Plugin
{
	int32_t RefCountsLenClass;
	int32_t* RefCountsClass;

	void ReferenceManagedClass(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenClass);
		if (handle != 0)
		{
			RefCountsClass[handle]++;
		}
	}

	void DereferenceManagedClass(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenClass);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsClass[handle];
			if (numRemain == 0)
			{
				ReleaseObject(handle);
			}
		}
	}
	
	bool DereferenceManagedClassNoRelease(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenClass);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsClass[handle];
			if (numRemain == 0)
			{
				return true;
			}
		}
		return false;
	}
	
	/*BEGIN GLOBAL STATE AND FUNCTIONS*/
	int32_t RefCountsLenSystemDecimal;
	int32_t* RefCountsSystemDecimal;
	
	void ReferenceManagedSystemDecimal(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenSystemDecimal);
		if (handle != 0)
		{
			RefCountsSystemDecimal[handle]++;
		}
	}
	
	void DereferenceManagedSystemDecimal(int32_t handle)
	{
		assert(handle >= 0 && handle < RefCountsLenSystemDecimal);
		if (handle != 0)
		{
			int32_t numRemain = --RefCountsSystemDecimal[handle];
			if (numRemain == 0)
			{
				ReleaseSystemDecimal(handle);
			}
		}
	}
	
	// Free list for Native::BaseNativeScript pointers
	
	int32_t BaseNativeScriptFreeListSize;
	Native::BaseNativeScript** BaseNativeScriptFreeList;
	Native::BaseNativeScript** NextFreeBaseNativeScript;
	
	int32_t StoreBaseNativeScript(Native::BaseNativeScript* del)
	{
		assert(NextFreeBaseNativeScript != nullptr);
		Native::BaseNativeScript** pNext = NextFreeBaseNativeScript;
		NextFreeBaseNativeScript = (Native::BaseNativeScript**)*pNext;
		*pNext = del;
		return (int32_t)(pNext - BaseNativeScriptFreeList);
	}
	
	Native::BaseNativeScript* GetBaseNativeScript(int32_t handle)
	{
		assert(handle >= 0 && handle < BaseNativeScriptFreeListSize);
		return BaseNativeScriptFreeList[handle];
	}
	
	void RemoveBaseNativeScript(int32_t handle)
	{
		Native::BaseNativeScript** pRelease = BaseNativeScriptFreeList + handle;
		*pRelease = (Native::BaseNativeScript*)NextFreeBaseNativeScript;
		NextFreeBaseNativeScript = pRelease;
	}
	
	// Free list for whole Native::BaseNativeScript objects
	
	union BaseNativeScriptFreeWholeListEntry
	{
		BaseNativeScriptFreeWholeListEntry* Next;
		Native::BaseNativeScript Value;
	};
	int32_t BaseNativeScriptFreeWholeListSize;
	BaseNativeScriptFreeWholeListEntry* BaseNativeScriptFreeWholeList;
	BaseNativeScriptFreeWholeListEntry* NextFreeWholeBaseNativeScript;
	
	Native::BaseNativeScript* StoreWholeBaseNativeScript()
	{
		assert(NextFreeWholeBaseNativeScript != nullptr);
		BaseNativeScriptFreeWholeListEntry* pNext = NextFreeWholeBaseNativeScript;
		NextFreeWholeBaseNativeScript = pNext->Next;
		return &pNext->Value;
	}
	
	void RemoveWholeBaseNativeScript(Native::BaseNativeScript* instance)
	{
		BaseNativeScriptFreeWholeListEntry* pRelease = (BaseNativeScriptFreeWholeListEntry*)instance;
		if (pRelease >= BaseNativeScriptFreeWholeList && pRelease < BaseNativeScriptFreeWholeList + (BaseNativeScriptFreeWholeListSize - 1))
		{
			pRelease->Next = NextFreeWholeBaseNativeScript;
			NextFreeWholeBaseNativeScript = pRelease->Next;
		}
	}
	/*END GLOBAL STATE AND FUNCTIONS*/
}

namespace Plugin
{
	// An unhandled exception caused by C++ calling into C#
	System::Exception* unhandledCsharpException = nullptr;
}

////////////////////////////////////////////////////////////////
// Mirrors of C# types. These wrap the C# functions to present
// a similiar API as in C#.
////////////////////////////////////////////////////////////////

namespace System
{
	Object::Object()
		: Plugin::ManagedType(nullptr)
	{
	}
	
	Object::Object(Plugin::InternalUse iu, int32_t handle)
		: ManagedType(Plugin::InternalUse::Only, handle)
	{
	}
	
	Object::Object(decltype(nullptr))
		: ManagedType(nullptr)
	{
	}
	
	bool Object::operator==(decltype(nullptr)) const
	{
		return Handle == 0;
	}
	
	bool Object::operator!=(decltype(nullptr)) const
	{
		return Handle != 0;
	}
	
	void Object::ThrowReferenceToThis()
	{
		throw *this;
	}
	
	ValueType::ValueType(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
	{
	}
	
	ValueType::ValueType(decltype(nullptr))
		: Object(nullptr)
	{
	}
	
	Enum::Enum(Plugin::InternalUse iu, int32_t handle)
		: ValueType(iu, handle)
	{
	}
	
	Enum::Enum(decltype(nullptr))
		: ValueType(nullptr)
	{
	}
	
	String::String(decltype(nullptr))
		: Object(Plugin::InternalUse::Only, 0)
	{
	}
	
	String::String(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
	{
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	String::String(const String& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
	}
	
	String::String(String&& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	String::~String()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	String& String::operator=(const String& other)
	{
		if (Handle != other.Handle)
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
			}
			Handle = other.Handle;
			if (Handle)
			{
				Plugin::ReferenceManagedClass(Handle);
			}
		}
		return *this;
	}
	
	String& String::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	String& String::operator=(String&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	String::String(const char* chars)
		: Object(Plugin::InternalUse::Only, Plugin::StringNew(chars))
	{
		Plugin::ReferenceManagedClass(Handle);
	}
	
	ICloneable::ICloneable(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
	{
	}
	
	ICloneable::ICloneable(decltype(nullptr))
		: Object(nullptr)
	{
	}
	
	namespace Collections
	{
		IEnumerable::IEnumerable(Plugin::InternalUse iu, int32_t handle)
			: Object(iu, handle)
		{
		}
		
		IEnumerable::IEnumerable(decltype(nullptr))
			: Object(nullptr)
		{
		}
		
		IEnumerator IEnumerable::GetEnumerator()
		{
			return IEnumerator(
				Plugin::InternalUse::Only,
				Plugin::EnumerableGetEnumerator(Handle));
		}
		
		Plugin::EnumerableIterator begin(
			System::Collections::IEnumerable& enumerable)
		{
			return Plugin::EnumerableIterator(enumerable);
		}
		
		Plugin::EnumerableIterator end(
			System::Collections::IEnumerable& enumerable)
		{
			return Plugin::EnumerableIterator(nullptr);
		}
		
		ICollection::ICollection(Plugin::InternalUse iu, int32_t handle)
			: Object(iu, handle)
			, IEnumerable(nullptr)
		{
		}
		
		ICollection::ICollection(decltype(nullptr))
			: Object(nullptr)
			, IEnumerable(nullptr)
		{
		}
		
		IList::IList(Plugin::InternalUse iu, int32_t handle)
			: Object(iu, handle)
			, IEnumerable(nullptr)
			, ICollection(nullptr)
		{
		}
		
		IList::IList(decltype(nullptr))
			: Object(nullptr)
			, IEnumerable(nullptr)
			, ICollection(nullptr)
		{
		}
	}
	
	Array::Array(Plugin::InternalUse iu, int32_t handle)
		: Object(iu, handle)
		, ICloneable(nullptr)
		, Collections::IEnumerable(nullptr)
		, Collections::ICollection(nullptr)
		, Collections::IList(nullptr)
	{
	}
	
	Array::Array(decltype(nullptr))
		: Object(nullptr)
		, ICloneable(nullptr)
		, Collections::IEnumerable(nullptr)
		, Collections::ICollection(nullptr)
		, Collections::IList(nullptr)
	{
	}
	
	int32_t Array::GetLength()
	{
		return Plugin::ArrayGetLength(Handle);
	}
	
	int32_t Array::GetRank()
	{
		return 0;
	}
}

/*BEGIN METHOD DEFINITIONS*/
namespace System
{
	IFormattable::IFormattable(decltype(nullptr))
	{
	}
	
	IFormattable::IFormattable(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IFormattable::IFormattable(const IFormattable& other)
		: IFormattable(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IFormattable::IFormattable(IFormattable&& other)
		: IFormattable(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IFormattable::~IFormattable()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IFormattable& IFormattable::operator=(const IFormattable& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IFormattable& IFormattable::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IFormattable& IFormattable::operator=(IFormattable&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IFormattable::operator==(const IFormattable& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IFormattable::operator!=(const IFormattable& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IConvertible::IConvertible(decltype(nullptr))
	{
	}
	
	IConvertible::IConvertible(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IConvertible::IConvertible(const IConvertible& other)
		: IConvertible(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IConvertible::IConvertible(IConvertible&& other)
		: IConvertible(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IConvertible::~IConvertible()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IConvertible& IConvertible::operator=(const IConvertible& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IConvertible& IConvertible::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IConvertible& IConvertible::operator=(IConvertible&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IConvertible::operator==(const IConvertible& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IConvertible::operator!=(const IConvertible& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable::IComparable(decltype(nullptr))
	{
	}
	
	IComparable::IComparable(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable::IComparable(const IComparable& other)
		: IComparable(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable::IComparable(IComparable&& other)
		: IComparable(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable::~IComparable()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable& IComparable::operator=(const IComparable& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable& IComparable::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable& IComparable::operator=(IComparable&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable::operator==(const IComparable& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable::operator!=(const IComparable& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Boolean>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Boolean>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Boolean>::IEquatable_1(const IEquatable_1<System::Boolean>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Boolean>::IEquatable_1(IEquatable_1<System::Boolean>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Boolean>::~IEquatable_1<System::Boolean>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Boolean>& IEquatable_1<System::Boolean>::operator=(const IEquatable_1<System::Boolean>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Boolean>& IEquatable_1<System::Boolean>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Boolean>& IEquatable_1<System::Boolean>::operator=(IEquatable_1<System::Boolean>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Boolean>::operator==(const IEquatable_1<System::Boolean>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Boolean>::operator!=(const IEquatable_1<System::Boolean>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Char>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Char>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Char>::IEquatable_1(const IEquatable_1<System::Char>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Char>::IEquatable_1(IEquatable_1<System::Char>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Char>::~IEquatable_1<System::Char>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Char>& IEquatable_1<System::Char>::operator=(const IEquatable_1<System::Char>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Char>& IEquatable_1<System::Char>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Char>& IEquatable_1<System::Char>::operator=(IEquatable_1<System::Char>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Char>::operator==(const IEquatable_1<System::Char>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Char>::operator!=(const IEquatable_1<System::Char>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::SByte>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::SByte>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::SByte>::IEquatable_1(const IEquatable_1<System::SByte>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::SByte>::IEquatable_1(IEquatable_1<System::SByte>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::SByte>::~IEquatable_1<System::SByte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::SByte>& IEquatable_1<System::SByte>::operator=(const IEquatable_1<System::SByte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::SByte>& IEquatable_1<System::SByte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::SByte>& IEquatable_1<System::SByte>::operator=(IEquatable_1<System::SByte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::SByte>::operator==(const IEquatable_1<System::SByte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::SByte>::operator!=(const IEquatable_1<System::SByte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Byte>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Byte>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Byte>::IEquatable_1(const IEquatable_1<System::Byte>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Byte>::IEquatable_1(IEquatable_1<System::Byte>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Byte>::~IEquatable_1<System::Byte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Byte>& IEquatable_1<System::Byte>::operator=(const IEquatable_1<System::Byte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Byte>& IEquatable_1<System::Byte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Byte>& IEquatable_1<System::Byte>::operator=(IEquatable_1<System::Byte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Byte>::operator==(const IEquatable_1<System::Byte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Byte>::operator!=(const IEquatable_1<System::Byte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Int16>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Int16>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Int16>::IEquatable_1(const IEquatable_1<System::Int16>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Int16>::IEquatable_1(IEquatable_1<System::Int16>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Int16>::~IEquatable_1<System::Int16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Int16>& IEquatable_1<System::Int16>::operator=(const IEquatable_1<System::Int16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Int16>& IEquatable_1<System::Int16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Int16>& IEquatable_1<System::Int16>::operator=(IEquatable_1<System::Int16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Int16>::operator==(const IEquatable_1<System::Int16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Int16>::operator!=(const IEquatable_1<System::Int16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::UInt16>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::UInt16>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::UInt16>::IEquatable_1(const IEquatable_1<System::UInt16>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::UInt16>::IEquatable_1(IEquatable_1<System::UInt16>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::UInt16>::~IEquatable_1<System::UInt16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::UInt16>& IEquatable_1<System::UInt16>::operator=(const IEquatable_1<System::UInt16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::UInt16>& IEquatable_1<System::UInt16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::UInt16>& IEquatable_1<System::UInt16>::operator=(IEquatable_1<System::UInt16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::UInt16>::operator==(const IEquatable_1<System::UInt16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::UInt16>::operator!=(const IEquatable_1<System::UInt16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Int32>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Int32>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Int32>::IEquatable_1(const IEquatable_1<System::Int32>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Int32>::IEquatable_1(IEquatable_1<System::Int32>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Int32>::~IEquatable_1<System::Int32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Int32>& IEquatable_1<System::Int32>::operator=(const IEquatable_1<System::Int32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Int32>& IEquatable_1<System::Int32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Int32>& IEquatable_1<System::Int32>::operator=(IEquatable_1<System::Int32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Int32>::operator==(const IEquatable_1<System::Int32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Int32>::operator!=(const IEquatable_1<System::Int32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::UInt32>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::UInt32>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::UInt32>::IEquatable_1(const IEquatable_1<System::UInt32>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::UInt32>::IEquatable_1(IEquatable_1<System::UInt32>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::UInt32>::~IEquatable_1<System::UInt32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::UInt32>& IEquatable_1<System::UInt32>::operator=(const IEquatable_1<System::UInt32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::UInt32>& IEquatable_1<System::UInt32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::UInt32>& IEquatable_1<System::UInt32>::operator=(IEquatable_1<System::UInt32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::UInt32>::operator==(const IEquatable_1<System::UInt32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::UInt32>::operator!=(const IEquatable_1<System::UInt32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Int64>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Int64>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Int64>::IEquatable_1(const IEquatable_1<System::Int64>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Int64>::IEquatable_1(IEquatable_1<System::Int64>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Int64>::~IEquatable_1<System::Int64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Int64>& IEquatable_1<System::Int64>::operator=(const IEquatable_1<System::Int64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Int64>& IEquatable_1<System::Int64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Int64>& IEquatable_1<System::Int64>::operator=(IEquatable_1<System::Int64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Int64>::operator==(const IEquatable_1<System::Int64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Int64>::operator!=(const IEquatable_1<System::Int64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::UInt64>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::UInt64>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::UInt64>::IEquatable_1(const IEquatable_1<System::UInt64>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::UInt64>::IEquatable_1(IEquatable_1<System::UInt64>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::UInt64>::~IEquatable_1<System::UInt64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::UInt64>& IEquatable_1<System::UInt64>::operator=(const IEquatable_1<System::UInt64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::UInt64>& IEquatable_1<System::UInt64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::UInt64>& IEquatable_1<System::UInt64>::operator=(IEquatable_1<System::UInt64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::UInt64>::operator==(const IEquatable_1<System::UInt64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::UInt64>::operator!=(const IEquatable_1<System::UInt64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Single>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Single>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Single>::IEquatable_1(const IEquatable_1<System::Single>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Single>::IEquatable_1(IEquatable_1<System::Single>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Single>::~IEquatable_1<System::Single>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Single>& IEquatable_1<System::Single>::operator=(const IEquatable_1<System::Single>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Single>& IEquatable_1<System::Single>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Single>& IEquatable_1<System::Single>::operator=(IEquatable_1<System::Single>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Single>::operator==(const IEquatable_1<System::Single>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Single>::operator!=(const IEquatable_1<System::Single>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Double>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Double>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Double>::IEquatable_1(const IEquatable_1<System::Double>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Double>::IEquatable_1(IEquatable_1<System::Double>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Double>::~IEquatable_1<System::Double>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Double>& IEquatable_1<System::Double>::operator=(const IEquatable_1<System::Double>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Double>& IEquatable_1<System::Double>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Double>& IEquatable_1<System::Double>::operator=(IEquatable_1<System::Double>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Double>::operator==(const IEquatable_1<System::Double>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Double>::operator!=(const IEquatable_1<System::Double>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<System::Decimal>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<System::Decimal>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<System::Decimal>::IEquatable_1(const IEquatable_1<System::Decimal>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<System::Decimal>::IEquatable_1(IEquatable_1<System::Decimal>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<System::Decimal>::~IEquatable_1<System::Decimal>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<System::Decimal>& IEquatable_1<System::Decimal>::operator=(const IEquatable_1<System::Decimal>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<System::Decimal>& IEquatable_1<System::Decimal>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<System::Decimal>& IEquatable_1<System::Decimal>::operator=(IEquatable_1<System::Decimal>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<System::Decimal>::operator==(const IEquatable_1<System::Decimal>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<System::Decimal>::operator!=(const IEquatable_1<System::Decimal>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(decltype(nullptr))
	{
	}
	
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(const IEquatable_1<UnityEngine::Vector3>& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IEquatable_1<UnityEngine::Vector3>::IEquatable_1(IEquatable_1<UnityEngine::Vector3>&& other)
		: IEquatable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IEquatable_1<UnityEngine::Vector3>::~IEquatable_1<UnityEngine::Vector3>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IEquatable_1<UnityEngine::Vector3>& IEquatable_1<UnityEngine::Vector3>::operator=(const IEquatable_1<UnityEngine::Vector3>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IEquatable_1<UnityEngine::Vector3>& IEquatable_1<UnityEngine::Vector3>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IEquatable_1<UnityEngine::Vector3>& IEquatable_1<UnityEngine::Vector3>::operator=(IEquatable_1<UnityEngine::Vector3>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IEquatable_1<UnityEngine::Vector3>::operator==(const IEquatable_1<UnityEngine::Vector3>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IEquatable_1<UnityEngine::Vector3>::operator!=(const IEquatable_1<UnityEngine::Vector3>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Boolean>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Boolean>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Boolean>::IComparable_1(const IComparable_1<System::Boolean>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Boolean>::IComparable_1(IComparable_1<System::Boolean>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Boolean>::~IComparable_1<System::Boolean>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Boolean>& IComparable_1<System::Boolean>::operator=(const IComparable_1<System::Boolean>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Boolean>& IComparable_1<System::Boolean>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Boolean>& IComparable_1<System::Boolean>::operator=(IComparable_1<System::Boolean>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Boolean>::operator==(const IComparable_1<System::Boolean>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Boolean>::operator!=(const IComparable_1<System::Boolean>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Char>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Char>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Char>::IComparable_1(const IComparable_1<System::Char>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Char>::IComparable_1(IComparable_1<System::Char>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Char>::~IComparable_1<System::Char>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Char>& IComparable_1<System::Char>::operator=(const IComparable_1<System::Char>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Char>& IComparable_1<System::Char>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Char>& IComparable_1<System::Char>::operator=(IComparable_1<System::Char>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Char>::operator==(const IComparable_1<System::Char>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Char>::operator!=(const IComparable_1<System::Char>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::SByte>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::SByte>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::SByte>::IComparable_1(const IComparable_1<System::SByte>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::SByte>::IComparable_1(IComparable_1<System::SByte>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::SByte>::~IComparable_1<System::SByte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::SByte>& IComparable_1<System::SByte>::operator=(const IComparable_1<System::SByte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::SByte>& IComparable_1<System::SByte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::SByte>& IComparable_1<System::SByte>::operator=(IComparable_1<System::SByte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::SByte>::operator==(const IComparable_1<System::SByte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::SByte>::operator!=(const IComparable_1<System::SByte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Byte>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Byte>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Byte>::IComparable_1(const IComparable_1<System::Byte>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Byte>::IComparable_1(IComparable_1<System::Byte>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Byte>::~IComparable_1<System::Byte>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Byte>& IComparable_1<System::Byte>::operator=(const IComparable_1<System::Byte>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Byte>& IComparable_1<System::Byte>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Byte>& IComparable_1<System::Byte>::operator=(IComparable_1<System::Byte>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Byte>::operator==(const IComparable_1<System::Byte>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Byte>::operator!=(const IComparable_1<System::Byte>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Int16>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Int16>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Int16>::IComparable_1(const IComparable_1<System::Int16>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Int16>::IComparable_1(IComparable_1<System::Int16>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Int16>::~IComparable_1<System::Int16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Int16>& IComparable_1<System::Int16>::operator=(const IComparable_1<System::Int16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Int16>& IComparable_1<System::Int16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Int16>& IComparable_1<System::Int16>::operator=(IComparable_1<System::Int16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Int16>::operator==(const IComparable_1<System::Int16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Int16>::operator!=(const IComparable_1<System::Int16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::UInt16>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::UInt16>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::UInt16>::IComparable_1(const IComparable_1<System::UInt16>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::UInt16>::IComparable_1(IComparable_1<System::UInt16>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::UInt16>::~IComparable_1<System::UInt16>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::UInt16>& IComparable_1<System::UInt16>::operator=(const IComparable_1<System::UInt16>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::UInt16>& IComparable_1<System::UInt16>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::UInt16>& IComparable_1<System::UInt16>::operator=(IComparable_1<System::UInt16>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::UInt16>::operator==(const IComparable_1<System::UInt16>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::UInt16>::operator!=(const IComparable_1<System::UInt16>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Int32>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Int32>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Int32>::IComparable_1(const IComparable_1<System::Int32>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Int32>::IComparable_1(IComparable_1<System::Int32>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Int32>::~IComparable_1<System::Int32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Int32>& IComparable_1<System::Int32>::operator=(const IComparable_1<System::Int32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Int32>& IComparable_1<System::Int32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Int32>& IComparable_1<System::Int32>::operator=(IComparable_1<System::Int32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Int32>::operator==(const IComparable_1<System::Int32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Int32>::operator!=(const IComparable_1<System::Int32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::UInt32>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::UInt32>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::UInt32>::IComparable_1(const IComparable_1<System::UInt32>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::UInt32>::IComparable_1(IComparable_1<System::UInt32>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::UInt32>::~IComparable_1<System::UInt32>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::UInt32>& IComparable_1<System::UInt32>::operator=(const IComparable_1<System::UInt32>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::UInt32>& IComparable_1<System::UInt32>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::UInt32>& IComparable_1<System::UInt32>::operator=(IComparable_1<System::UInt32>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::UInt32>::operator==(const IComparable_1<System::UInt32>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::UInt32>::operator!=(const IComparable_1<System::UInt32>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Int64>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Int64>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Int64>::IComparable_1(const IComparable_1<System::Int64>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Int64>::IComparable_1(IComparable_1<System::Int64>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Int64>::~IComparable_1<System::Int64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Int64>& IComparable_1<System::Int64>::operator=(const IComparable_1<System::Int64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Int64>& IComparable_1<System::Int64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Int64>& IComparable_1<System::Int64>::operator=(IComparable_1<System::Int64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Int64>::operator==(const IComparable_1<System::Int64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Int64>::operator!=(const IComparable_1<System::Int64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::UInt64>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::UInt64>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::UInt64>::IComparable_1(const IComparable_1<System::UInt64>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::UInt64>::IComparable_1(IComparable_1<System::UInt64>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::UInt64>::~IComparable_1<System::UInt64>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::UInt64>& IComparable_1<System::UInt64>::operator=(const IComparable_1<System::UInt64>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::UInt64>& IComparable_1<System::UInt64>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::UInt64>& IComparable_1<System::UInt64>::operator=(IComparable_1<System::UInt64>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::UInt64>::operator==(const IComparable_1<System::UInt64>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::UInt64>::operator!=(const IComparable_1<System::UInt64>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Single>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Single>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Single>::IComparable_1(const IComparable_1<System::Single>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Single>::IComparable_1(IComparable_1<System::Single>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Single>::~IComparable_1<System::Single>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Single>& IComparable_1<System::Single>::operator=(const IComparable_1<System::Single>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Single>& IComparable_1<System::Single>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Single>& IComparable_1<System::Single>::operator=(IComparable_1<System::Single>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Single>::operator==(const IComparable_1<System::Single>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Single>::operator!=(const IComparable_1<System::Single>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Double>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Double>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Double>::IComparable_1(const IComparable_1<System::Double>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Double>::IComparable_1(IComparable_1<System::Double>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Double>::~IComparable_1<System::Double>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Double>& IComparable_1<System::Double>::operator=(const IComparable_1<System::Double>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Double>& IComparable_1<System::Double>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Double>& IComparable_1<System::Double>::operator=(IComparable_1<System::Double>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Double>::operator==(const IComparable_1<System::Double>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Double>::operator!=(const IComparable_1<System::Double>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	IComparable_1<System::Decimal>::IComparable_1(decltype(nullptr))
	{
	}
	
	IComparable_1<System::Decimal>::IComparable_1(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	IComparable_1<System::Decimal>::IComparable_1(const IComparable_1<System::Decimal>& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	IComparable_1<System::Decimal>::IComparable_1(IComparable_1<System::Decimal>&& other)
		: IComparable_1(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	IComparable_1<System::Decimal>::~IComparable_1<System::Decimal>()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	IComparable_1<System::Decimal>& IComparable_1<System::Decimal>::operator=(const IComparable_1<System::Decimal>& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	IComparable_1<System::Decimal>& IComparable_1<System::Decimal>::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	IComparable_1<System::Decimal>& IComparable_1<System::Decimal>::operator=(IComparable_1<System::Decimal>&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool IComparable_1<System::Decimal>::operator==(const IComparable_1<System::Decimal>& other) const
	{
		return Handle == other.Handle;
	}
	
	bool IComparable_1<System::Decimal>::operator!=(const IComparable_1<System::Decimal>& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	namespace Runtime
	{
		namespace Serialization
		{
			IDeserializationCallback::IDeserializationCallback(decltype(nullptr))
			{
			}
			
			IDeserializationCallback::IDeserializationCallback(Plugin::InternalUse, int32_t handle)
			{
				Handle = handle;
				if (handle)
				{
					Plugin::ReferenceManagedClass(handle);
				}
			}
			
			IDeserializationCallback::IDeserializationCallback(const IDeserializationCallback& other)
				: IDeserializationCallback(Plugin::InternalUse::Only, other.Handle)
			{
			}
			
			IDeserializationCallback::IDeserializationCallback(IDeserializationCallback&& other)
				: IDeserializationCallback(Plugin::InternalUse::Only, other.Handle)
			{
				other.Handle = 0;
			}
			
			IDeserializationCallback::~IDeserializationCallback()
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
			}
			
			IDeserializationCallback& IDeserializationCallback::operator=(const IDeserializationCallback& other)
			{
				if (this->Handle)
				{
					Plugin::DereferenceManagedClass(this->Handle);
				}
				this->Handle = other.Handle;
				if (this->Handle)
				{
					Plugin::ReferenceManagedClass(this->Handle);
				}
				return *this;
			}
			
			IDeserializationCallback& IDeserializationCallback::operator=(decltype(nullptr))
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
				return *this;
			}
			
			IDeserializationCallback& IDeserializationCallback::operator=(IDeserializationCallback&& other)
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
				}
				Handle = other.Handle;
				other.Handle = 0;
				return *this;
			}
			
			bool IDeserializationCallback::operator==(const IDeserializationCallback& other) const
			{
				return Handle == other.Handle;
			}
			
			bool IDeserializationCallback::operator!=(const IDeserializationCallback& other) const
			{
				return Handle != other.Handle;
			}
		}
	}
}

namespace System
{
	Decimal::Decimal(decltype(nullptr))
	{
	}
	
	Decimal::Decimal(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
	}
	
	Decimal::Decimal(const Decimal& other)
		: Decimal(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Decimal::Decimal(Decimal&& other)
		: Decimal(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Decimal::~Decimal()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
			Handle = 0;
		}
	}
	
	Decimal& Decimal::operator=(const Decimal& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
		return *this;
	}
	
	Decimal& Decimal::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Decimal& Decimal::operator=(Decimal&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedSystemDecimal(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Decimal::operator==(const Decimal& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Decimal::operator!=(const Decimal& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Decimal::Decimal(System::Double value)
	{
		auto returnValue = Plugin::SystemDecimalConstructorSystemDouble(value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
	}
	
	System::Decimal::Decimal(System::UInt64 value)
	{
		auto returnValue = Plugin::SystemDecimalConstructorSystemUInt64(value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedSystemDecimal(Handle);
		}
	}
	
	System::Decimal::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::Object()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IComparable()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IComparable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IComparable_1<System::Decimal>()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IComparable_1<System::Decimal>(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IConvertible()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IConvertible(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::Runtime::Serialization::IDeserializationCallback()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Runtime::Serialization::IDeserializationCallback(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IEquatable_1<System::Decimal>()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IEquatable_1<System::Decimal>(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	System::Decimal::operator System::IFormattable()
	{
		int32_t handle = Plugin::BoxDecimal(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IFormattable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
}

namespace System
{
	System::Object::operator System::Decimal()
	{
		System::Decimal returnVal(Plugin::InternalUse::Only, Plugin::UnboxDecimal(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	Vector3::Vector3()
	{
	}
	
	UnityEngine::Vector3::Vector3(System::Single x, System::Single y, System::Single z)
	{
		auto returnValue = Plugin::UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle(x, y, z);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		*this = returnValue;
	}
	
	UnityEngine::Vector3 UnityEngine::Vector3::operator+(UnityEngine::Vector3& a)
	{
		auto returnValue = Plugin::UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3(*this, a);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	UnityEngine::Vector3::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxVector3(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::Vector3::operator System::Object()
	{
		int32_t handle = Plugin::BoxVector3(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::Vector3::operator System::IEquatable_1<UnityEngine::Vector3>()
	{
		int32_t handle = Plugin::BoxVector3(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IEquatable_1<UnityEngine::Vector3>(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
}

namespace System
{
	System::Object::operator UnityEngine::Vector3()
	{
		UnityEngine::Vector3 returnVal(Plugin::UnboxVector3(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	Object::Object(decltype(nullptr))
	{
	}
	
	Object::Object(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Object::Object(const Object& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Object::Object(Object&& other)
		: Object(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Object::~Object()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Object& Object::operator=(const Object& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Object& Object::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Object& Object::operator=(Object&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Object::operator==(const Object& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Object::operator!=(const Object& other) const
	{
		return Handle != other.Handle;
	}
	
	System::String UnityEngine::Object::GetName()
	{
		auto returnValue = Plugin::UnityEngineObjectPropertyGetName(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return System::String(Plugin::InternalUse::Only, returnValue);
	}
	
	void UnityEngine::Object::SetName(System::String& value)
	{
		Plugin::UnityEngineObjectPropertySetName(Handle, value.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	UnityEngine::Object UnityEngine::Object::Instantiate(UnityEngine::Object& original)
	{
		auto returnValue = Plugin::UnityEngineObjectMethodInstantiateUnityEngineObject(original.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Object(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	Component::Component(decltype(nullptr))
		: UnityEngine::Object(nullptr)
	{
	}
	
	Component::Component(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Component::Component(const Component& other)
		: Component(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Component::Component(Component&& other)
		: Component(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Component::~Component()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Component& Component::operator=(const Component& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Component& Component::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Component& Component::operator=(Component&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Component::operator==(const Component& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Component::operator!=(const Component& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Transform UnityEngine::Component::GetTransform()
	{
		auto returnValue = Plugin::UnityEngineComponentPropertyGetTransform(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Transform(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	Transform::Transform(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, System::Collections::IEnumerable(nullptr)
	{
	}
	
	Transform::Transform(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, System::Collections::IEnumerable(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Transform::Transform(const Transform& other)
		: Transform(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Transform::Transform(Transform&& other)
		: Transform(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Transform::~Transform()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Transform& Transform::operator=(const Transform& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Transform& Transform::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Transform& Transform::operator=(Transform&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Transform::operator==(const Transform& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Transform::operator!=(const Transform& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Vector3 UnityEngine::Transform::GetPosition()
	{
		auto returnValue = Plugin::UnityEngineTransformPropertyGetPosition(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	void UnityEngine::Transform::SetPosition(UnityEngine::Vector3& value)
	{
		Plugin::UnityEngineTransformPropertySetPosition(Handle, value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace System
{
	namespace Collections
	{
		IEnumerator::IEnumerator(decltype(nullptr))
		{
		}
		
		IEnumerator::IEnumerator(Plugin::InternalUse, int32_t handle)
		{
			Handle = handle;
			if (handle)
			{
				Plugin::ReferenceManagedClass(handle);
			}
		}
		
		IEnumerator::IEnumerator(const IEnumerator& other)
			: IEnumerator(Plugin::InternalUse::Only, other.Handle)
		{
		}
		
		IEnumerator::IEnumerator(IEnumerator&& other)
			: IEnumerator(Plugin::InternalUse::Only, other.Handle)
		{
			other.Handle = 0;
		}
		
		IEnumerator::~IEnumerator()
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
				Handle = 0;
			}
		}
		
		IEnumerator& IEnumerator::operator=(const IEnumerator& other)
		{
			if (this->Handle)
			{
				Plugin::DereferenceManagedClass(this->Handle);
			}
			this->Handle = other.Handle;
			if (this->Handle)
			{
				Plugin::ReferenceManagedClass(this->Handle);
			}
			return *this;
		}
		
		IEnumerator& IEnumerator::operator=(decltype(nullptr))
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
				Handle = 0;
			}
			return *this;
		}
		
		IEnumerator& IEnumerator::operator=(IEnumerator&& other)
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
			}
			Handle = other.Handle;
			other.Handle = 0;
			return *this;
		}
		
		bool IEnumerator::operator==(const IEnumerator& other) const
		{
			return Handle == other.Handle;
		}
		
		bool IEnumerator::operator!=(const IEnumerator& other) const
		{
			return Handle != other.Handle;
		}
		
		System::Object System::Collections::IEnumerator::GetCurrent()
		{
			auto returnValue = Plugin::SystemCollectionsIEnumeratorPropertyGetCurrent(Handle);
			if (Plugin::unhandledCsharpException)
			{
				System::Exception* ex = Plugin::unhandledCsharpException;
				Plugin::unhandledCsharpException = nullptr;
				ex->ThrowReferenceToThis();
				delete ex;
			}
			return System::Object(Plugin::InternalUse::Only, returnValue);
		}
		
		System::Boolean System::Collections::IEnumerator::MoveNext()
		{
			auto returnValue = Plugin::SystemCollectionsIEnumeratorMethodMoveNext(Handle);
			if (Plugin::unhandledCsharpException)
			{
				System::Exception* ex = Plugin::unhandledCsharpException;
				Plugin::unhandledCsharpException = nullptr;
				ex->ThrowReferenceToThis();
				delete ex;
			}
			return returnValue;
		}
	}
}

namespace System
{
	namespace Runtime
	{
		namespace Serialization
		{
			ISerializable::ISerializable(decltype(nullptr))
			{
			}
			
			ISerializable::ISerializable(Plugin::InternalUse, int32_t handle)
			{
				Handle = handle;
				if (handle)
				{
					Plugin::ReferenceManagedClass(handle);
				}
			}
			
			ISerializable::ISerializable(const ISerializable& other)
				: ISerializable(Plugin::InternalUse::Only, other.Handle)
			{
			}
			
			ISerializable::ISerializable(ISerializable&& other)
				: ISerializable(Plugin::InternalUse::Only, other.Handle)
			{
				other.Handle = 0;
			}
			
			ISerializable::~ISerializable()
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
			}
			
			ISerializable& ISerializable::operator=(const ISerializable& other)
			{
				if (this->Handle)
				{
					Plugin::DereferenceManagedClass(this->Handle);
				}
				this->Handle = other.Handle;
				if (this->Handle)
				{
					Plugin::ReferenceManagedClass(this->Handle);
				}
				return *this;
			}
			
			ISerializable& ISerializable::operator=(decltype(nullptr))
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
				return *this;
			}
			
			ISerializable& ISerializable::operator=(ISerializable&& other)
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
				}
				Handle = other.Handle;
				other.Handle = 0;
				return *this;
			}
			
			bool ISerializable::operator==(const ISerializable& other) const
			{
				return Handle == other.Handle;
			}
			
			bool ISerializable::operator!=(const ISerializable& other) const
			{
				return Handle != other.Handle;
			}
		}
	}
}

namespace System
{
	namespace Runtime
	{
		namespace InteropServices
		{
			_Exception::_Exception(decltype(nullptr))
			{
			}
			
			_Exception::_Exception(Plugin::InternalUse, int32_t handle)
			{
				Handle = handle;
				if (handle)
				{
					Plugin::ReferenceManagedClass(handle);
				}
			}
			
			_Exception::_Exception(const _Exception& other)
				: _Exception(Plugin::InternalUse::Only, other.Handle)
			{
			}
			
			_Exception::_Exception(_Exception&& other)
				: _Exception(Plugin::InternalUse::Only, other.Handle)
			{
				other.Handle = 0;
			}
			
			_Exception::~_Exception()
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
			}
			
			_Exception& _Exception::operator=(const _Exception& other)
			{
				if (this->Handle)
				{
					Plugin::DereferenceManagedClass(this->Handle);
				}
				this->Handle = other.Handle;
				if (this->Handle)
				{
					Plugin::ReferenceManagedClass(this->Handle);
				}
				return *this;
			}
			
			_Exception& _Exception::operator=(decltype(nullptr))
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
					Handle = 0;
				}
				return *this;
			}
			
			_Exception& _Exception::operator=(_Exception&& other)
			{
				if (Handle)
				{
					Plugin::DereferenceManagedClass(Handle);
				}
				Handle = other.Handle;
				other.Handle = 0;
				return *this;
			}
			
			bool _Exception::operator==(const _Exception& other) const
			{
				return Handle == other.Handle;
			}
			
			bool _Exception::operator!=(const _Exception& other) const
			{
				return Handle != other.Handle;
			}
		}
	}
}

namespace UnityEngine
{
	GameObject::GameObject(decltype(nullptr))
		: UnityEngine::Object(nullptr)
	{
	}
	
	GameObject::GameObject(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	GameObject::GameObject(const GameObject& other)
		: GameObject(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	GameObject::GameObject(GameObject&& other)
		: GameObject(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	GameObject::~GameObject()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	GameObject& GameObject::operator=(const GameObject& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	GameObject& GameObject::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	GameObject& GameObject::operator=(GameObject&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool GameObject::operator==(const GameObject& other) const
	{
		return Handle == other.Handle;
	}
	
	bool GameObject::operator!=(const GameObject& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::GameObject::GameObject()
		: UnityEngine::Object(nullptr)
	{
		auto returnValue = Plugin::UnityEngineGameObjectConstructor();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
	
	template<> Native::BaseNativeScript UnityEngine::GameObject::AddComponent<Native::BaseNativeScript>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodAddComponentNativeBaseNativeScript(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return Native::BaseNativeScript(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> Native::BaseNativeEntityView UnityEngine::GameObject::AddComponent<Native::BaseNativeEntityView>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodAddComponentNativeBaseNativeEntityView(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return Native::BaseNativeEntityView(Plugin::InternalUse::Only, returnValue);
	}
	
	template<> Native::BaseNativeEntityView UnityEngine::GameObject::GetComponent<Native::BaseNativeEntityView>()
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodGetComponentNativeBaseNativeEntityView(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return Native::BaseNativeEntityView(Plugin::InternalUse::Only, returnValue);
	}
	
	UnityEngine::GameObject UnityEngine::GameObject::CreatePrimitive(UnityEngine::PrimitiveType type)
	{
		auto returnValue = Plugin::UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType(type);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::GameObject(Plugin::InternalUse::Only, returnValue);
	}
}

namespace UnityEngine
{
	Debug::Debug(decltype(nullptr))
	{
	}
	
	Debug::Debug(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Debug::Debug(const Debug& other)
		: Debug(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Debug::Debug(Debug&& other)
		: Debug(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Debug::~Debug()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Debug& Debug::operator=(const Debug& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Debug& Debug::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Debug& Debug::operator=(Debug&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Debug::operator==(const Debug& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Debug::operator!=(const Debug& other) const
	{
		return Handle != other.Handle;
	}
	
	void UnityEngine::Debug::Log(System::Object& message)
	{
		Plugin::UnityEngineDebugMethodLogSystemObject(message.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace UnityEngine
{
	Behaviour::Behaviour(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
	{
	}
	
	Behaviour::Behaviour(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Behaviour::Behaviour(const Behaviour& other)
		: Behaviour(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Behaviour::Behaviour(Behaviour&& other)
		: Behaviour(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Behaviour::~Behaviour()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Behaviour& Behaviour::operator=(const Behaviour& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Behaviour& Behaviour::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Behaviour& Behaviour::operator=(Behaviour&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Behaviour::operator==(const Behaviour& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Behaviour::operator!=(const Behaviour& other) const
	{
		return Handle != other.Handle;
	}
}

namespace UnityEngine
{
	MonoBehaviour::MonoBehaviour(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
	{
	}
	
	MonoBehaviour::MonoBehaviour(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	MonoBehaviour::MonoBehaviour(const MonoBehaviour& other)
		: MonoBehaviour(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	MonoBehaviour::MonoBehaviour(MonoBehaviour&& other)
		: MonoBehaviour(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	MonoBehaviour::~MonoBehaviour()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	MonoBehaviour& MonoBehaviour::operator=(const MonoBehaviour& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	MonoBehaviour& MonoBehaviour::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	MonoBehaviour& MonoBehaviour::operator=(MonoBehaviour&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool MonoBehaviour::operator==(const MonoBehaviour& other) const
	{
		return Handle == other.Handle;
	}
	
	bool MonoBehaviour::operator!=(const MonoBehaviour& other) const
	{
		return Handle != other.Handle;
	}
	
	UnityEngine::Transform UnityEngine::MonoBehaviour::GetTransform()
	{
		auto returnValue = Plugin::UnityEngineMonoBehaviourPropertyGetTransform(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::Transform(Plugin::InternalUse::Only, returnValue);
	}
}

namespace System
{
	Exception::Exception(decltype(nullptr))
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
	{
	}
	
	Exception::Exception(Plugin::InternalUse, int32_t handle)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Exception::Exception(const Exception& other)
		: Exception(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Exception::Exception(Exception&& other)
		: Exception(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Exception::~Exception()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Exception& Exception::operator=(const Exception& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Exception& Exception::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Exception& Exception::operator=(Exception&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Exception::operator==(const Exception& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Exception::operator!=(const Exception& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Exception::Exception(System::String& message)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
	{
		auto returnValue = Plugin::SystemExceptionConstructorSystemString(message.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
}

namespace System
{
	SystemException::SystemException(decltype(nullptr))
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
	{
	}
	
	SystemException::SystemException(Plugin::InternalUse, int32_t handle)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	SystemException::SystemException(const SystemException& other)
		: SystemException(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	SystemException::SystemException(SystemException&& other)
		: SystemException(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	SystemException::~SystemException()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	SystemException& SystemException::operator=(const SystemException& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	SystemException& SystemException::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	SystemException& SystemException::operator=(SystemException&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool SystemException::operator==(const SystemException& other) const
	{
		return Handle == other.Handle;
	}
	
	bool SystemException::operator!=(const SystemException& other) const
	{
		return Handle != other.Handle;
	}
}

namespace System
{
	NullReferenceException::NullReferenceException(decltype(nullptr))
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
		, System::SystemException(nullptr)
	{
	}
	
	NullReferenceException::NullReferenceException(Plugin::InternalUse, int32_t handle)
		: System::Runtime::InteropServices::_Exception(nullptr)
		, System::Runtime::Serialization::ISerializable(nullptr)
		, System::Exception(nullptr)
		, System::SystemException(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	NullReferenceException::NullReferenceException(const NullReferenceException& other)
		: NullReferenceException(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	NullReferenceException::NullReferenceException(NullReferenceException&& other)
		: NullReferenceException(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	NullReferenceException::~NullReferenceException()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	NullReferenceException& NullReferenceException::operator=(const NullReferenceException& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	NullReferenceException& NullReferenceException::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	NullReferenceException& NullReferenceException::operator=(NullReferenceException&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool NullReferenceException::operator==(const NullReferenceException& other) const
	{
		return Handle == other.Handle;
	}
	
	bool NullReferenceException::operator!=(const NullReferenceException& other) const
	{
		return Handle != other.Handle;
	}
}

namespace UnityEngine
{
	PrimitiveType::PrimitiveType(int32_t value)
		: Value(value)
	{
	}
	
	UnityEngine::PrimitiveType::operator int32_t() const
	{
		return Value;
	}
	
	bool UnityEngine::PrimitiveType::operator==(PrimitiveType other)
	{
		return Value == other.Value;
	}
	
	bool UnityEngine::PrimitiveType::operator!=(PrimitiveType other)
	{
		return Value != other.Value;
	}
	
	UnityEngine::PrimitiveType::operator System::Enum()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Enum(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::ValueType()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::ValueType(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::Object()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::Object(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::IComparable()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IComparable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::IConvertible()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IConvertible(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
	UnityEngine::PrimitiveType::operator System::IFormattable()
	{
		int32_t handle = Plugin::BoxPrimitiveType(*this);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
			return System::IFormattable(Plugin::InternalUse::Only, handle);
		}
		return nullptr;
	}
	
}
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Sphere(0);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Capsule(1);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Cylinder(2);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Cube(3);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Plane(4);
const UnityEngine::PrimitiveType UnityEngine::PrimitiveType::Quad(5);

namespace System
{
	System::Object::operator UnityEngine::PrimitiveType()
	{
		UnityEngine::PrimitiveType returnVal(Plugin::UnboxPrimitiveType(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace UnityEngine
{
	namespace Profiling
	{
		Profiler::Profiler(decltype(nullptr))
		{
		}
		
		Profiler::Profiler(Plugin::InternalUse, int32_t handle)
		{
			Handle = handle;
			if (handle)
			{
				Plugin::ReferenceManagedClass(handle);
			}
		}
		
		Profiler::Profiler(const Profiler& other)
			: Profiler(Plugin::InternalUse::Only, other.Handle)
		{
		}
		
		Profiler::Profiler(Profiler&& other)
			: Profiler(Plugin::InternalUse::Only, other.Handle)
		{
			other.Handle = 0;
		}
		
		Profiler::~Profiler()
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
				Handle = 0;
			}
		}
		
		Profiler& Profiler::operator=(const Profiler& other)
		{
			if (this->Handle)
			{
				Plugin::DereferenceManagedClass(this->Handle);
			}
			this->Handle = other.Handle;
			if (this->Handle)
			{
				Plugin::ReferenceManagedClass(this->Handle);
			}
			return *this;
		}
		
		Profiler& Profiler::operator=(decltype(nullptr))
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
				Handle = 0;
			}
			return *this;
		}
		
		Profiler& Profiler::operator=(Profiler&& other)
		{
			if (Handle)
			{
				Plugin::DereferenceManagedClass(Handle);
			}
			Handle = other.Handle;
			other.Handle = 0;
			return *this;
		}
		
		bool Profiler::operator==(const Profiler& other) const
		{
			return Handle == other.Handle;
		}
		
		bool Profiler::operator!=(const Profiler& other) const
		{
			return Handle != other.Handle;
		}
		
		void UnityEngine::Profiling::Profiler::BeginSample(System::String& name)
		{
			Plugin::UnityEngineProfilingProfilerMethodBeginSampleSystemString(name.Handle);
			if (Plugin::unhandledCsharpException)
			{
				System::Exception* ex = Plugin::unhandledCsharpException;
				Plugin::unhandledCsharpException = nullptr;
				ex->ThrowReferenceToThis();
				delete ex;
			}
		}
	
		void UnityEngine::Profiling::Profiler::EndSample()
		{
			Plugin::UnityEngineProfilingProfilerMethodEndSample();
			if (Plugin::unhandledCsharpException)
			{
				System::Exception* ex = Plugin::unhandledCsharpException;
				Plugin::unhandledCsharpException = nullptr;
				ex->ThrowReferenceToThis();
				delete ex;
			}
		}
	}
}

namespace UnityEngine
{
	Time::Time(decltype(nullptr))
	{
	}
	
	Time::Time(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Time::Time(const Time& other)
		: Time(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Time::Time(Time&& other)
		: Time(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Time::~Time()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Time& Time::operator=(const Time& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Time& Time::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Time& Time::operator=(Time&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Time::operator==(const Time& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Time::operator!=(const Time& other) const
	{
		return Handle != other.Handle;
	}
	
	System::Single UnityEngine::Time::GetDeltaTime()
	{
		auto returnValue = Plugin::UnityEngineTimePropertyGetDeltaTime();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
}

namespace Native
{
	EventHub::EventHub(decltype(nullptr))
	{
	}
	
	EventHub::EventHub(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	EventHub::EventHub(const EventHub& other)
		: EventHub(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	EventHub::EventHub(EventHub&& other)
		: EventHub(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	EventHub::~EventHub()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	EventHub& EventHub::operator=(const EventHub& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	EventHub& EventHub::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	EventHub& EventHub::operator=(EventHub&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool EventHub::operator==(const EventHub& other) const
	{
		return Handle == other.Handle;
	}
	
	bool EventHub::operator!=(const EventHub& other) const
	{
		return Handle != other.Handle;
	}
	
	Native::EventHub::EventHub()
	{
		auto returnValue = Plugin::NativeEventHubConstructor();
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		Handle = returnValue;
		if (returnValue)
		{
			Plugin::ReferenceManagedClass(returnValue);
		}
	}
	
	void Native::EventHub::InvokeEntityDestroyed(System::UInt32 e)
	{
		Plugin::NativeEventHubMethodInvokeEntityDestroyedSystemUInt32(Handle, e);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace Native
{
	AbstractBaseNativeScript::AbstractBaseNativeScript(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
	{
	}
	
	AbstractBaseNativeScript::AbstractBaseNativeScript(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	AbstractBaseNativeScript::AbstractBaseNativeScript(const AbstractBaseNativeScript& other)
		: AbstractBaseNativeScript(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	AbstractBaseNativeScript::AbstractBaseNativeScript(AbstractBaseNativeScript&& other)
		: AbstractBaseNativeScript(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	AbstractBaseNativeScript::~AbstractBaseNativeScript()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	AbstractBaseNativeScript& AbstractBaseNativeScript::operator=(const AbstractBaseNativeScript& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	AbstractBaseNativeScript& AbstractBaseNativeScript::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	AbstractBaseNativeScript& AbstractBaseNativeScript::operator=(AbstractBaseNativeScript&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool AbstractBaseNativeScript::operator==(const AbstractBaseNativeScript& other) const
	{
		return Handle == other.Handle;
	}
	
	bool AbstractBaseNativeScript::operator!=(const AbstractBaseNativeScript& other) const
	{
		return Handle != other.Handle;
	}
	
	Native::EventHub Native::AbstractBaseNativeScript::GetEvents()
	{
		auto returnValue = Plugin::NativeAbstractBaseNativeScriptPropertyGetEvents(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return Native::EventHub(Plugin::InternalUse::Only, returnValue);
	}
}

namespace Native
{
	Native::BaseNativeScript::BaseNativeScript()
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, Native::AbstractBaseNativeScript(nullptr)
	{
		CppHandle = Plugin::StoreBaseNativeScript(this);
		System::Int32* handle = (System::Int32*)&Handle;
		int32_t cppHandle = CppHandle;
		Plugin::BaseNativeScriptConstructor(cppHandle, &handle->Value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
		else
		{
			Plugin::RemoveBaseNativeScript(CppHandle);
			CppHandle = 0;
		}
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
	
	BaseNativeScript::BaseNativeScript(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, Native::AbstractBaseNativeScript(nullptr)
	{
		CppHandle = Plugin::StoreBaseNativeScript(this);
	}
	
	Native::BaseNativeScript::BaseNativeScript(const Native::BaseNativeScript& other)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, Native::AbstractBaseNativeScript(nullptr)
	{
		Handle = other.Handle;
		CppHandle = Plugin::StoreBaseNativeScript(this);
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
	}
	
	Native::BaseNativeScript::BaseNativeScript(Native::BaseNativeScript&& other)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, Native::AbstractBaseNativeScript(nullptr)
	{
		Handle = other.Handle;
		CppHandle = other.CppHandle;
		other.Handle = 0;
		other.CppHandle = 0;
	}
	
	Native::BaseNativeScript::BaseNativeScript(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
		, Native::AbstractBaseNativeScript(nullptr)
	{
		Handle = handle;
		CppHandle = Plugin::StoreBaseNativeScript(this);
		if (Handle)
		{
			Plugin::ReferenceManagedClass(Handle);
		}
	}
	
	Native::BaseNativeScript::~BaseNativeScript()
	{
		Plugin::RemoveWholeBaseNativeScript(this);
		Plugin::RemoveBaseNativeScript(CppHandle);
		CppHandle = 0;
		if (Handle)
		{
			int32_t handle = Handle;
			Handle = 0;
			if (Plugin::DereferenceManagedClassNoRelease(handle))
			{
				Plugin::ReleaseBaseNativeScript(handle);
				if (Plugin::unhandledCsharpException)
				{
					System::Exception* ex = Plugin::unhandledCsharpException;
					Plugin::unhandledCsharpException = nullptr;
					ex->ThrowReferenceToThis();
					delete ex;
				}
			}
		}
	}
	
	Native::BaseNativeScript& Native::BaseNativeScript::operator=(const Native::BaseNativeScript& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Native::BaseNativeScript& Native::BaseNativeScript::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			int32_t handle = Handle;
			Handle = 0;
			if (Plugin::DereferenceManagedClassNoRelease(handle))
			{
				Plugin::ReleaseBaseNativeScript(handle);
				if (Plugin::unhandledCsharpException)
				{
					System::Exception* ex = Plugin::unhandledCsharpException;
					Plugin::unhandledCsharpException = nullptr;
					ex->ThrowReferenceToThis();
					delete ex;
				}
			}
		}
		Handle = 0;
		return *this;
	}
	
	Native::BaseNativeScript& Native::BaseNativeScript::operator=(Native::BaseNativeScript&& other)
	{
		Plugin::RemoveBaseNativeScript(CppHandle);
		CppHandle = 0;
		if (Handle)
		{
			int32_t handle = Handle;
			Handle = 0;
			if (Plugin::DereferenceManagedClassNoRelease(handle))
			{
				Plugin::ReleaseBaseNativeScript(handle);
				if (Plugin::unhandledCsharpException)
				{
					System::Exception* ex = Plugin::unhandledCsharpException;
					Plugin::unhandledCsharpException = nullptr;
					ex->ThrowReferenceToThis();
					delete ex;
				}
			}
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Native::BaseNativeScript::operator==(const Native::BaseNativeScript& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Native::BaseNativeScript::operator!=(const Native::BaseNativeScript& other) const
	{
		return Handle != other.Handle;
	}
	
	DLLEXPORT int32_t NewBaseNativeScript(int32_t handle)
	{
		Native::BaseNativeScript* memory = Plugin::StoreWholeBaseNativeScript();
		Native::NativeScript* thiz = new (memory) Native::NativeScript(Plugin::InternalUse::Only, handle);
		return thiz->CppHandle;
	}

	DLLEXPORT void DestroyBaseNativeScript(int32_t cppHandle)
	{
		Native::BaseNativeScript* instance = Plugin::GetBaseNativeScript(cppHandle);
		instance->~BaseNativeScript();
	}

	void Native::BaseNativeScript::Update()
	{
	}
	
	DLLEXPORT void NativeAbstractBaseNativeScriptUpdate(int32_t cppHandle)
	{
		try
		{
			Plugin::GetBaseNativeScript(cppHandle)->Update();
		}
		catch (System::Exception ex)
		{
			Plugin::SetException(ex.Handle);
		}
		catch (...)
		{
			System::String msg = "Unhandled exception invoking Native::AbstractBaseNativeScript";
			System::Exception ex(msg);
			Plugin::SetException(ex.Handle);
		}
	}
	
	void Native::BaseNativeScript::Start()
	{
	}
	
	DLLEXPORT void NativeAbstractBaseNativeScriptStart(int32_t cppHandle)
	{
		try
		{
			Plugin::GetBaseNativeScript(cppHandle)->Start();
		}
		catch (System::Exception ex)
		{
			Plugin::SetException(ex.Handle);
		}
		catch (...)
		{
			System::String msg = "Unhandled exception invoking Native::AbstractBaseNativeScript";
			System::Exception ex(msg);
			Plugin::SetException(ex.Handle);
		}
	}
	
	void Native::BaseNativeScript::Awake()
	{
	}
	
	DLLEXPORT void NativeAbstractBaseNativeScriptAwake(int32_t cppHandle)
	{
		try
		{
			Plugin::GetBaseNativeScript(cppHandle)->Awake();
		}
		catch (System::Exception ex)
		{
			Plugin::SetException(ex.Handle);
		}
		catch (...)
		{
			System::String msg = "Unhandled exception invoking Native::AbstractBaseNativeScript";
			System::Exception ex(msg);
			Plugin::SetException(ex.Handle);
		}
	}
	
	void Native::BaseNativeScript::PassGameConfig(void* config)
	{
	}
	
	DLLEXPORT void NativeAbstractBaseNativeScriptPassGameConfig(int32_t cppHandle, void* config)
	{
		try
		{
			Plugin::GetBaseNativeScript(cppHandle)->PassGameConfig(config);
		}
		catch (System::Exception ex)
		{
			Plugin::SetException(ex.Handle);
		}
		catch (...)
		{
			System::String msg = "Unhandled exception invoking Native::AbstractBaseNativeScript";
			System::Exception ex(msg);
			Plugin::SetException(ex.Handle);
		}
	}
	
	void Native::BaseNativeScript::StartSimulation()
	{
	}
	
	DLLEXPORT void NativeAbstractBaseNativeScriptStartSimulation(int32_t cppHandle)
	{
		try
		{
			Plugin::GetBaseNativeScript(cppHandle)->StartSimulation();
		}
		catch (System::Exception ex)
		{
			Plugin::SetException(ex.Handle);
		}
		catch (...)
		{
			System::String msg = "Unhandled exception invoking Native::AbstractBaseNativeScript";
			System::Exception ex(msg);
			Plugin::SetException(ex.Handle);
		}
	}
}

namespace Native
{
	BaseNativeEntityView::BaseNativeEntityView(decltype(nullptr))
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
	{
	}
	
	BaseNativeEntityView::BaseNativeEntityView(Plugin::InternalUse, int32_t handle)
		: UnityEngine::Object(nullptr)
		, UnityEngine::Component(nullptr)
		, UnityEngine::Behaviour(nullptr)
		, UnityEngine::MonoBehaviour(nullptr)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	BaseNativeEntityView::BaseNativeEntityView(const BaseNativeEntityView& other)
		: BaseNativeEntityView(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	BaseNativeEntityView::BaseNativeEntityView(BaseNativeEntityView&& other)
		: BaseNativeEntityView(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	BaseNativeEntityView::~BaseNativeEntityView()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	BaseNativeEntityView& BaseNativeEntityView::operator=(const BaseNativeEntityView& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	BaseNativeEntityView& BaseNativeEntityView::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	BaseNativeEntityView& BaseNativeEntityView::operator=(BaseNativeEntityView&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool BaseNativeEntityView::operator==(const BaseNativeEntityView& other) const
	{
		return Handle == other.Handle;
	}
	
	bool BaseNativeEntityView::operator!=(const BaseNativeEntityView& other) const
	{
		return Handle != other.Handle;
	}
	
	System::UInt32 Native::BaseNativeEntityView::GetEntityRef()
	{
		auto returnValue = Plugin::NativeBaseNativeEntityViewPropertyGetEntityRef(Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnValue;
	}
	
	void Native::BaseNativeEntityView::SetEntityRef(System::UInt32 value)
	{
		Plugin::NativeBaseNativeEntityViewPropertySetEntityRef(Handle, value);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
	}
}

namespace UnityEngine
{
	Resources::Resources(decltype(nullptr))
	{
	}
	
	Resources::Resources(Plugin::InternalUse, int32_t handle)
	{
		Handle = handle;
		if (handle)
		{
			Plugin::ReferenceManagedClass(handle);
		}
	}
	
	Resources::Resources(const Resources& other)
		: Resources(Plugin::InternalUse::Only, other.Handle)
	{
	}
	
	Resources::Resources(Resources&& other)
		: Resources(Plugin::InternalUse::Only, other.Handle)
	{
		other.Handle = 0;
	}
	
	Resources::~Resources()
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
	}
	
	Resources& Resources::operator=(const Resources& other)
	{
		if (this->Handle)
		{
			Plugin::DereferenceManagedClass(this->Handle);
		}
		this->Handle = other.Handle;
		if (this->Handle)
		{
			Plugin::ReferenceManagedClass(this->Handle);
		}
		return *this;
	}
	
	Resources& Resources::operator=(decltype(nullptr))
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
			Handle = 0;
		}
		return *this;
	}
	
	Resources& Resources::operator=(Resources&& other)
	{
		if (Handle)
		{
			Plugin::DereferenceManagedClass(Handle);
		}
		Handle = other.Handle;
		other.Handle = 0;
		return *this;
	}
	
	bool Resources::operator==(const Resources& other) const
	{
		return Handle == other.Handle;
	}
	
	bool Resources::operator!=(const Resources& other) const
	{
		return Handle != other.Handle;
	}
	
	template<> UnityEngine::GameObject UnityEngine::Resources::Load<UnityEngine::GameObject>(System::String& path)
	{
		auto returnValue = Plugin::UnityEngineResourcesMethodLoadUnityEngineGameObjectSystemString(path.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::GameObject(Plugin::InternalUse::Only, returnValue);
	}
}

namespace Native
{
	template<> UnityEngine::GameObject Native::UnityTypeHelpers::Downcast<UnityEngine::GameObject>(UnityEngine::Object& obj)
	{
		auto returnValue = Plugin::NativeUnityTypeHelpersMethodDowncastUnityEngineGameObjectUnityEngineObject(obj.Handle);
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return UnityEngine::GameObject(Plugin::InternalUse::Only, returnValue);
	}
}

namespace System
{
	System::Object::operator System::Boolean()
	{
		System::Boolean returnVal(Plugin::UnboxBoolean(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::SByte()
	{
		System::SByte returnVal(Plugin::UnboxSByte(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Byte()
	{
		System::Byte returnVal(Plugin::UnboxByte(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Int16()
	{
		System::Int16 returnVal(Plugin::UnboxInt16(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::UInt16()
	{
		System::UInt16 returnVal(Plugin::UnboxUInt16(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Int32()
	{
		System::Int32 returnVal(Plugin::UnboxInt32(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::UInt32()
	{
		System::UInt32 returnVal(Plugin::UnboxUInt32(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Int64()
	{
		System::Int64 returnVal(Plugin::UnboxInt64(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::UInt64()
	{
		System::UInt64 returnVal(Plugin::UnboxUInt64(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Char()
	{
		System::Char returnVal(Plugin::UnboxChar(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Single()
	{
		System::Single returnVal(Plugin::UnboxSingle(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	System::Object::operator System::Double()
	{
		System::Double returnVal(Plugin::UnboxDouble(Handle));
		if (Plugin::unhandledCsharpException)
		{
			System::Exception* ex = Plugin::unhandledCsharpException;
			Plugin::unhandledCsharpException = nullptr;
			ex->ThrowReferenceToThis();
			delete ex;
		}
		return returnVal;
	}
}

namespace System
{
	struct NullReferenceExceptionThrower : System::NullReferenceException
	{
		NullReferenceExceptionThrower(int32_t handle)
			: System::Runtime::InteropServices::_Exception(nullptr)
			, System::Runtime::Serialization::ISerializable(nullptr)
			, System::Exception(nullptr)
			, System::SystemException(nullptr)
			, System::NullReferenceException(Plugin::InternalUse::Only, handle)
		{
		}
	
		virtual void ThrowReferenceToThis()
		{
			throw *this;
		}
	};
}

DLLEXPORT void SetCsharpExceptionSystemNullReferenceException(int32_t handle)
{
	delete Plugin::unhandledCsharpException;
	Plugin::unhandledCsharpException = new System::NullReferenceExceptionThrower(handle);
}
/*END METHOD DEFINITIONS*/

////////////////////////////////////////////////////////////////
// App-specific functions for this file to call
////////////////////////////////////////////////////////////////

// Called when the plugin is initialized
extern void PluginMain(
	void* memory,
	int32_t memorySize,
	bool isFirstBoot);

////////////////////////////////////////////////////////////////
// C++ functions for C# to call
////////////////////////////////////////////////////////////////

enum class InitMode : uint8_t
{
	FirstBoot,
	Reload
};

// Init the plugin
DLLEXPORT void Init(
	uint8_t* memory,
	int32_t memorySize,
	InitMode initMode)
{
	uint8_t* curMemory = memory;
	
	// Read fixed parameters
	Plugin::ReleaseObject = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseObject);
	Plugin::StringNew = *(int32_t (**)(const char*))curMemory;
	curMemory += sizeof(Plugin::StringNew);
	Plugin::SetException = *(void (**)(int32_t))curMemory;
	curMemory += sizeof(Plugin::SetException);
	Plugin::ArrayGetLength = *(int32_t (**)(int32_t))curMemory;
	curMemory += sizeof(Plugin::ArrayGetLength);
	Plugin::EnumerableGetEnumerator = *(int32_t (**)(int32_t))curMemory;
	curMemory += sizeof(Plugin::EnumerableGetEnumerator);
	
	// Read generated parameters
	int32_t maxManagedObjects = *(int32_t*)curMemory;
	curMemory += sizeof(int32_t);
	/*BEGIN INIT BODY PARAMETER READS*/
	Plugin::ReleaseSystemDecimal = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseSystemDecimal);
	Plugin::SystemDecimalConstructorSystemDouble = *(int32_t (**)(double value))curMemory;
	curMemory += sizeof(Plugin::SystemDecimalConstructorSystemDouble);
	Plugin::SystemDecimalConstructorSystemUInt64 = *(int32_t (**)(uint64_t value))curMemory;
	curMemory += sizeof(Plugin::SystemDecimalConstructorSystemUInt64);
	Plugin::BoxDecimal = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::BoxDecimal);
	Plugin::UnboxDecimal = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxDecimal);
	Plugin::UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle = *(UnityEngine::Vector3 (**)(float x, float y, float z))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3ConstructorSystemSingle_SystemSingle_SystemSingle);
	Plugin::UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3 = *(UnityEngine::Vector3 (**)(UnityEngine::Vector3& a, UnityEngine::Vector3& b))curMemory;
	curMemory += sizeof(Plugin::UnityEngineVector3Methodop_AdditionUnityEngineVector3_UnityEngineVector3);
	Plugin::BoxVector3 = *(int32_t (**)(UnityEngine::Vector3& val))curMemory;
	curMemory += sizeof(Plugin::BoxVector3);
	Plugin::UnboxVector3 = *(UnityEngine::Vector3 (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxVector3);
	Plugin::UnityEngineObjectPropertyGetName = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineObjectPropertyGetName);
	Plugin::UnityEngineObjectPropertySetName = *(void (**)(int32_t thisHandle, int32_t valueHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineObjectPropertySetName);
	Plugin::UnityEngineObjectMethodInstantiateUnityEngineObject = *(int32_t (**)(int32_t originalHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineObjectMethodInstantiateUnityEngineObject);
	Plugin::UnityEngineComponentPropertyGetTransform = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineComponentPropertyGetTransform);
	Plugin::UnityEngineTransformPropertyGetPosition = *(UnityEngine::Vector3 (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineTransformPropertyGetPosition);
	Plugin::UnityEngineTransformPropertySetPosition = *(void (**)(int32_t thisHandle, UnityEngine::Vector3& value))curMemory;
	curMemory += sizeof(Plugin::UnityEngineTransformPropertySetPosition);
	Plugin::SystemCollectionsIEnumeratorPropertyGetCurrent = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::SystemCollectionsIEnumeratorPropertyGetCurrent);
	Plugin::SystemCollectionsIEnumeratorMethodMoveNext = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::SystemCollectionsIEnumeratorMethodMoveNext);
	Plugin::UnityEngineGameObjectConstructor = *(int32_t (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectConstructor);
	Plugin::UnityEngineGameObjectMethodAddComponentNativeBaseNativeScript = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodAddComponentNativeBaseNativeScript);
	Plugin::UnityEngineGameObjectMethodAddComponentNativeBaseNativeEntityView = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodAddComponentNativeBaseNativeEntityView);
	Plugin::UnityEngineGameObjectMethodGetComponentNativeBaseNativeEntityView = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodGetComponentNativeBaseNativeEntityView);
	Plugin::UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType = *(int32_t (**)(UnityEngine::PrimitiveType type))curMemory;
	curMemory += sizeof(Plugin::UnityEngineGameObjectMethodCreatePrimitiveUnityEnginePrimitiveType);
	Plugin::UnityEngineDebugMethodLogSystemObject = *(void (**)(int32_t messageHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineDebugMethodLogSystemObject);
	Plugin::UnityEngineMonoBehaviourPropertyGetTransform = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineMonoBehaviourPropertyGetTransform);
	Plugin::SystemExceptionConstructorSystemString = *(int32_t (**)(int32_t messageHandle))curMemory;
	curMemory += sizeof(Plugin::SystemExceptionConstructorSystemString);
	Plugin::BoxPrimitiveType = *(int32_t (**)(UnityEngine::PrimitiveType val))curMemory;
	curMemory += sizeof(Plugin::BoxPrimitiveType);
	Plugin::UnboxPrimitiveType = *(UnityEngine::PrimitiveType (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxPrimitiveType);
	Plugin::UnityEngineProfilingProfilerMethodBeginSampleSystemString = *(void (**)(int32_t nameHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineProfilingProfilerMethodBeginSampleSystemString);
	Plugin::UnityEngineProfilingProfilerMethodEndSample = *(void (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineProfilingProfilerMethodEndSample);
	Plugin::UnityEngineTimePropertyGetDeltaTime = *(float (**)())curMemory;
	curMemory += sizeof(Plugin::UnityEngineTimePropertyGetDeltaTime);
	Plugin::NativeEventHubConstructor = *(int32_t (**)())curMemory;
	curMemory += sizeof(Plugin::NativeEventHubConstructor);
	Plugin::NativeEventHubMethodInvokeEntityDestroyedSystemUInt32 = *(void (**)(int32_t thisHandle, uint32_t e))curMemory;
	curMemory += sizeof(Plugin::NativeEventHubMethodInvokeEntityDestroyedSystemUInt32);
	Plugin::NativeAbstractBaseNativeScriptPropertyGetEvents = *(int32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::NativeAbstractBaseNativeScriptPropertyGetEvents);
	Plugin::ReleaseBaseNativeScript = *(void (**)(int32_t handle))curMemory;
	curMemory += sizeof(Plugin::ReleaseBaseNativeScript);
	Plugin::BaseNativeScriptConstructor = *(void (**)(int32_t cppHandle, int32_t* handle))curMemory;
	curMemory += sizeof(Plugin::BaseNativeScriptConstructor);
	Plugin::NativeBaseNativeEntityViewPropertyGetEntityRef = *(uint32_t (**)(int32_t thisHandle))curMemory;
	curMemory += sizeof(Plugin::NativeBaseNativeEntityViewPropertyGetEntityRef);
	Plugin::NativeBaseNativeEntityViewPropertySetEntityRef = *(void (**)(int32_t thisHandle, uint32_t value))curMemory;
	curMemory += sizeof(Plugin::NativeBaseNativeEntityViewPropertySetEntityRef);
	Plugin::UnityEngineResourcesMethodLoadUnityEngineGameObjectSystemString = *(int32_t (**)(int32_t pathHandle))curMemory;
	curMemory += sizeof(Plugin::UnityEngineResourcesMethodLoadUnityEngineGameObjectSystemString);
	Plugin::NativeUnityTypeHelpersMethodDowncastUnityEngineGameObjectUnityEngineObject = *(int32_t (**)(int32_t objHandle))curMemory;
	curMemory += sizeof(Plugin::NativeUnityTypeHelpersMethodDowncastUnityEngineGameObjectUnityEngineObject);
	Plugin::BoxBoolean = *(int32_t (**)(uint32_t val))curMemory;
	curMemory += sizeof(Plugin::BoxBoolean);
	Plugin::UnboxBoolean = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxBoolean);
	Plugin::BoxSByte = *(int32_t (**)(int8_t val))curMemory;
	curMemory += sizeof(Plugin::BoxSByte);
	Plugin::UnboxSByte = *(int8_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxSByte);
	Plugin::BoxByte = *(int32_t (**)(uint8_t val))curMemory;
	curMemory += sizeof(Plugin::BoxByte);
	Plugin::UnboxByte = *(uint8_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxByte);
	Plugin::BoxInt16 = *(int32_t (**)(int16_t val))curMemory;
	curMemory += sizeof(Plugin::BoxInt16);
	Plugin::UnboxInt16 = *(int16_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxInt16);
	Plugin::BoxUInt16 = *(int32_t (**)(uint16_t val))curMemory;
	curMemory += sizeof(Plugin::BoxUInt16);
	Plugin::UnboxUInt16 = *(uint16_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxUInt16);
	Plugin::BoxInt32 = *(int32_t (**)(int32_t val))curMemory;
	curMemory += sizeof(Plugin::BoxInt32);
	Plugin::UnboxInt32 = *(int32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxInt32);
	Plugin::BoxUInt32 = *(int32_t (**)(uint32_t val))curMemory;
	curMemory += sizeof(Plugin::BoxUInt32);
	Plugin::UnboxUInt32 = *(uint32_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxUInt32);
	Plugin::BoxInt64 = *(int32_t (**)(int64_t val))curMemory;
	curMemory += sizeof(Plugin::BoxInt64);
	Plugin::UnboxInt64 = *(int64_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxInt64);
	Plugin::BoxUInt64 = *(int32_t (**)(uint64_t val))curMemory;
	curMemory += sizeof(Plugin::BoxUInt64);
	Plugin::UnboxUInt64 = *(uint64_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxUInt64);
	Plugin::BoxChar = *(int32_t (**)(uint16_t val))curMemory;
	curMemory += sizeof(Plugin::BoxChar);
	Plugin::UnboxChar = *(int16_t (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxChar);
	Plugin::BoxSingle = *(int32_t (**)(float val))curMemory;
	curMemory += sizeof(Plugin::BoxSingle);
	Plugin::UnboxSingle = *(float (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxSingle);
	Plugin::BoxDouble = *(int32_t (**)(double val))curMemory;
	curMemory += sizeof(Plugin::BoxDouble);
	Plugin::UnboxDouble = *(double (**)(int32_t valHandle))curMemory;
	curMemory += sizeof(Plugin::UnboxDouble);
	/*END INIT BODY PARAMETER READS*/
	
	// Init managed object ref counting
	Plugin::RefCountsLenClass = maxManagedObjects;
	Plugin::RefCountsClass = (int32_t*)curMemory;
	curMemory += maxManagedObjects * sizeof(int32_t);
	
	/*BEGIN INIT BODY ARRAYS*/
	Plugin::RefCountsSystemDecimal = (int32_t*)curMemory;
	curMemory += 1000 * sizeof(int32_t);
	Plugin::RefCountsLenSystemDecimal = 1000;
	
	Plugin::BaseNativeScriptFreeListSize = 1000;
	Plugin::BaseNativeScriptFreeList = (Native::BaseNativeScript**)curMemory;
	curMemory += 1000 * sizeof(Native::BaseNativeScript*);
	
	Plugin::BaseNativeScriptFreeWholeListSize = 1000;
	Plugin::BaseNativeScriptFreeWholeList = (Plugin::BaseNativeScriptFreeWholeListEntry*)curMemory;
	curMemory += 1000 * sizeof(Plugin::BaseNativeScriptFreeWholeListEntry);
	/*END INIT BODY ARRAYS*/
	
	// Make sure there was enough memory
	int32_t usedMemory = (int32_t)(curMemory - (uint8_t*)memory);
	if (usedMemory > memorySize)
	{
		System::String msg = "Plugin memory size is too low";
		System::Exception ex(msg);
		Plugin::SetException(ex.Handle);
		return;
	}
	
	if (initMode == InitMode::FirstBoot)
	{
		// Clear memory
		memset(memory, 0, memorySize);
		
		/*BEGIN INIT BODY FIRST BOOT*/
		for (int32_t i = 0, end = Plugin::BaseNativeScriptFreeListSize - 1; i < end; ++i)
		{
			Plugin::BaseNativeScriptFreeList[i] = (Native::BaseNativeScript*)(Plugin::BaseNativeScriptFreeList + i + 1);
		}
		Plugin::BaseNativeScriptFreeList[Plugin::BaseNativeScriptFreeListSize - 1] = nullptr;
		Plugin::NextFreeBaseNativeScript = Plugin::BaseNativeScriptFreeList + 1;
		
		for (int32_t i = 0, end = Plugin::BaseNativeScriptFreeWholeListSize - 1; i < end; ++i)
		{
			Plugin::BaseNativeScriptFreeWholeList[i].Next = Plugin::BaseNativeScriptFreeWholeList + i + 1;
		}
		Plugin::BaseNativeScriptFreeWholeList[Plugin::BaseNativeScriptFreeWholeListSize - 1].Next = nullptr;
		Plugin::NextFreeWholeBaseNativeScript = Plugin::BaseNativeScriptFreeWholeList + 1;
		/*END INIT BODY FIRST BOOT*/
	}
	
	try
	{
		PluginMain(
			curMemory,
			(int32_t)(memorySize - usedMemory),
			initMode == InitMode::FirstBoot);
	}
	catch (System::Exception ex)
	{
		Plugin::SetException(ex.Handle);
	}
	catch (...)
	{
		System::String msg = "Unhandled exception in PluginMain";
		System::Exception ex(msg);
		Plugin::SetException(ex.Handle);
	}
}

// Receive an unhandled exception from C#
DLLEXPORT void SetCsharpException(int32_t handle)
{
	Plugin::unhandledCsharpException = new System::Exception(
		Plugin::InternalUse::Only,
		handle);
}


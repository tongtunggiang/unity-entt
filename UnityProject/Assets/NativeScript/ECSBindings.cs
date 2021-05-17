using NativeScript;
using System;
using System.Runtime.InteropServices;
using UnityEngine;

/// <summary>
/// Workaround for one-value components, which cannot be directly casted into
/// int or float values
/// </summary>
/// <typeparam name="T"></typeparam>
struct Value<T> 
{
    public T value;

    public Value(T value) { this.value = value; }

    public static implicit operator T(Value<T> a) => a.value;
    public static explicit operator Value<T>(T a) => new Value<T>(a);
}


/*BEGIN TYPE DEFINITION*/
public struct CBodySize
{
	public float radius;
}
public struct CCollisionLayer
{
	public System.Byte value;
}
public struct CCooldown
{
	public float remaining, max;
}
public struct CCurrentWave
{
	public int nextWaveIndex;
	public float lastSpawnInWave;
	public int numSpawnedInWave;
}
public struct CDamage
{
	public float value;
}
public struct CDestination
{
	public Vector3 value;
}
public struct CElapsedTime
{
	public float value;
}
public struct CHealth
{
	public float current;
	public float max;
}
public struct CLifeTime
{
	public float value;
}
public struct CMoveSpeed
{
	public float value;
}
public struct COrientation
{
	public Vector3 value;
}
public struct CPosition
{
	public Vector3 value;
}
public struct CRangeDetection
{
	public float range;
}
public struct CWaypointIndex
{
	public int value;
}
/*END TYPE DEFINITION*/


class ECSBindings
{
    /*BEGIN DELEGATE DECLARATION*/
	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CBodySize GetBodySizeType(UInt32 entity);
	public static GetBodySizeType GetBodySize;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CCollisionLayer GetCollisionLayerType(UInt32 entity);
	public static GetCollisionLayerType GetCollisionLayer;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CCooldown GetCooldownType(UInt32 entity);
	public static GetCooldownType GetCooldown;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CCurrentWave GetStateCurrentWaveType();
	public static GetStateCurrentWaveType GetStateCurrentWave;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CDamage GetDamageType(UInt32 entity);
	public static GetDamageType GetDamage;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CDestination GetDestinationType(UInt32 entity);
	public static GetDestinationType GetDestination;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CElapsedTime GetStateElapsedTimeType();
	public static GetStateElapsedTimeType GetStateElapsedTime;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CHealth GetHealthType(UInt32 entity);
	public static GetHealthType GetHealth;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CLifeTime GetLifeTimeType(UInt32 entity);
	public static GetLifeTimeType GetLifeTime;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CMoveSpeed GetMoveSpeedType(UInt32 entity);
	public static GetMoveSpeedType GetMoveSpeed;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate COrientation GetOrientationType(UInt32 entity);
	public static GetOrientationType GetOrientation;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CPosition GetPositionType(UInt32 entity);
	public static GetPositionType GetPosition;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CRangeDetection GetRangeDetectionType(UInt32 entity);
	public static GetRangeDetectionType GetRangeDetection;

	[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
	public delegate CWaypointIndex GetWaypointIndexType(UInt32 entity);
	public static GetWaypointIndexType GetWaypointIndex;

	/*END DELEGATE DECLARATION*/

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void SpawnTowerType(float x, float y);
    public static SpawnTowerType SpawnTower;

    public static void Load(IntPtr libraryHandle)
    {
        /*BEGIN DELEGATE ASSIGN*/
		GetBodySize = Bindings.GetDelegate<GetBodySizeType>(libraryHandle, "GetBodySize");
		GetCollisionLayer = Bindings.GetDelegate<GetCollisionLayerType>(libraryHandle, "GetCollisionLayer");
		GetCooldown = Bindings.GetDelegate<GetCooldownType>(libraryHandle, "GetCooldown");
		GetStateCurrentWave = Bindings.GetDelegate<GetStateCurrentWaveType>(libraryHandle, "GetStateCurrentWave");
		GetDamage = Bindings.GetDelegate<GetDamageType>(libraryHandle, "GetDamage");
		GetDestination = Bindings.GetDelegate<GetDestinationType>(libraryHandle, "GetDestination");
		GetStateElapsedTime = Bindings.GetDelegate<GetStateElapsedTimeType>(libraryHandle, "GetStateElapsedTime");
		GetHealth = Bindings.GetDelegate<GetHealthType>(libraryHandle, "GetHealth");
		GetLifeTime = Bindings.GetDelegate<GetLifeTimeType>(libraryHandle, "GetLifeTime");
		GetMoveSpeed = Bindings.GetDelegate<GetMoveSpeedType>(libraryHandle, "GetMoveSpeed");
		GetOrientation = Bindings.GetDelegate<GetOrientationType>(libraryHandle, "GetOrientation");
		GetPosition = Bindings.GetDelegate<GetPositionType>(libraryHandle, "GetPosition");
		GetRangeDetection = Bindings.GetDelegate<GetRangeDetectionType>(libraryHandle, "GetRangeDetection");
		GetWaypointIndex = Bindings.GetDelegate<GetWaypointIndexType>(libraryHandle, "GetWaypointIndex");
		/*END DELEGATE ASSIGN*/

        // Spawn functions
        SpawnTower = Bindings.GetDelegate<SpawnTowerType>(libraryHandle, "SpawnTower");
    }
}

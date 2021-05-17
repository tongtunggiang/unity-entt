using System.Collections;
using System.Collections.Generic;
using UnityEngine;

#if UNITY_EDITOR
using UnityEditor;
#endif

[ExecuteInEditMode]
public class GeometryBasicGenerator : MonoBehaviour
{
    [SerializeField]
    GameObject m_TileToSpawn;

    [SerializeField]
    float m_SpawnScale;

    [SerializeField]
    Vector2 m_RangeX;

    [SerializeField]
    Vector2 m_RangeY;

    public void Clear()
    {
        int last = transform.childCount - 1;
        int first = 0;
        for (int i = last; i >= first; i--)
        {
            DestroyImmediate(transform.GetChild(i).gameObject);
        }
    }

    public void GenerateGeometry()
    {
        Clear();

        for (int x = (int)m_RangeX.x; x <= (int)m_RangeX.y; x++)
        {
            for (int z = (int)m_RangeY.x; z <= (int)m_RangeY.y; z++)
            {
                GameObject tile = Instantiate(m_TileToSpawn);
                tile.transform.SetParent(transform);
                tile.transform.localScale = new Vector3(m_SpawnScale, 1, m_SpawnScale);
                tile.transform.localPosition = new Vector3(x, 0, z);
                tile.isStatic = true;
            }
        }
    }
}

#if UNITY_EDITOR
[CustomEditor(typeof(GeometryBasicGenerator))]
public class GeometryBasicGeneratorInspector : Editor
{
    public override void OnInspectorGUI()
    {
        DrawDefaultInspector();

        serializedObject.Update();

        if (GUILayout.Button("Generate"))
            ((GeometryBasicGenerator)serializedObject.targetObject).GenerateGeometry();

        if (GUILayout.Button("Clear"))
            ((GeometryBasicGenerator)serializedObject.targetObject).Clear();
    }
}
#endif

using UnityEngine;

[RequireComponent(typeof(Native.BaseNativeEntityView))]
public class EntityPositionView : MonoBehaviour
{
    [SerializeField] bool m_UpdateOnce;
    [SerializeField] bool m_ViewPosition;
    [SerializeField] bool m_ViewOrientation;

    Native.BaseNativeEntityView m_View;

    void Start()
    {
        m_View = GetComponent<Native.BaseNativeEntityView>();
    }

    void Update()
    {
        if (m_ViewPosition)
        {
            Vector3 pos = ECSBindings.GetPosition(m_View.EntityRef).value;
            transform.position = new Vector3(pos.x, pos.y, pos.z);
        }

        if (m_ViewOrientation)
        {
            Vector3 orientation = ECSBindings.GetOrientation(m_View.EntityRef).value;
            transform.forward = new Vector3(orientation.x, orientation.y, orientation.z);
        }

        if (m_UpdateOnce)
        {
            enabled = false;
        }
    }
}

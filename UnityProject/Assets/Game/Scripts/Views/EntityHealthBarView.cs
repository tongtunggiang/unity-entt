using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(Native.BaseNativeEntityView))]
public class EntityHealthBarView : MonoBehaviour
{
    [SerializeField] private Image m_Foreground;

    Native.BaseNativeEntityView m_View;

    void Start()
    {
        m_View = GetComponent<Native.BaseNativeEntityView>();

        if (transform.parent != GUI.Instance.hudRoot.transform)
        {
            ((RectTransform)transform).SetParent(GUI.Instance.hudRoot.transform, false);
            transform.localScale.Set(1, 1, 1);
        }
    }

    void Update()
    {
        Vector3 pos = ECSBindings.GetPosition(m_View.EntityRef).value;
        pos.y = 0.5f;

        transform.position = GUI.Instance.MainCamera.WorldToScreenPoint(pos);

        var health = ECSBindings.GetHealth(m_View.EntityRef);
        if (health.max > 0)
            m_Foreground.fillAmount = health.current / health.max;
    }
}

using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(Native.BaseNativeEntityView))]
public class EntityCooldownView : MonoBehaviour
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

        var cooldown = ECSBindings.GetCooldown(m_View.EntityRef);
        if (cooldown.remaining <= 0)
        {
            Destroy(gameObject);
            return;
        }
        
        m_Foreground.fillAmount = cooldown.remaining / cooldown.max;
    }
}

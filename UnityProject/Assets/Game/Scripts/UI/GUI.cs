using UnityEngine;

public class GUI : Singleton<GUI>
{

    public GameObject hudRoot;
    public GameObject popupRoot;

    public Camera MainCamera
    {
        get
        {
            if (m_MainCamera == null)
            {
                m_MainCamera = Camera.main;
            }
            return m_MainCamera;
        }
    }
    private Camera m_MainCamera;

}

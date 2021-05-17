using UnityEngine;

public class InputManager : MonoBehaviour
{
    [SerializeField] GameObject m_HighlightedTilePrefab;
    [SerializeField] LayerMask m_Selectable;

    [SerializeField] float m_CameraScrollSpeed;
    [SerializeField] Vector2 m_CameraScrollSize;

    [SerializeField] float m_CameraMoveSpeed;

    private GameObject m_HighlightedTile;
    private Camera m_MainCamera;

    private void Start()
    {
        m_HighlightedTile = Instantiate(m_HighlightedTilePrefab);
        m_MainCamera = Camera.main;
    }

    private void Update()
    {
        UpdateCameraMovement();
        UpdateZoom();
        UpdateSelection();
        UpdateMouseClick();
    }

    private void UpdateSelection()
    {
        Ray ray = m_MainCamera.ScreenPointToRay(Input.mousePosition);
        RaycastHit hitData;

        if (Physics.Raycast(ray, out hitData, 1000, m_Selectable))
        {
            Vector3 hitPoint = hitData.point;
            hitPoint.x = Mathf.Floor(hitPoint.x);
            hitPoint.z = Mathf.Floor(hitPoint.z);
            hitPoint.y = -0.19f;
            m_HighlightedTile.transform.position = hitPoint;
        }
    }

    private void UpdateZoom()
    {
        m_MainCamera.orthographicSize += (-Input.mouseScrollDelta.y) * Time.deltaTime * m_CameraScrollSpeed;
        m_MainCamera.orthographicSize = Mathf.Clamp(m_MainCamera.orthographicSize, m_CameraScrollSize.x, m_CameraScrollSize.y);
    }

    private void UpdateCameraMovement()
    {
        Vector3 movement = new Vector3(
            Input.GetAxis("Horizontal"),
            0,
            Input.GetAxis("Vertical")
        );
        movement = Quaternion.Euler(0, m_MainCamera.transform.eulerAngles.y, 0) * movement;
        m_MainCamera.transform.position += movement.normalized * m_CameraMoveSpeed * Time.deltaTime;
    }

    private void UpdateMouseClick()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ECSBindings.SpawnTower(m_HighlightedTile.transform.position.x, m_HighlightedTile.transform.position.z);
        }
    }
}


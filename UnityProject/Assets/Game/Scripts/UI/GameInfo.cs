using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class GameInfo : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI m_Money;
    [SerializeField] private Image m_Time;
    [SerializeField] private GameObject m_SpawnMilestonePrefab;

    private float m_ExpectedMaxTime;

    private void Start()
    {
        GameSettings gameSettings = FindObjectOfType<GameSettings>();
        
        {
            var lastWave = gameSettings.SpawnConfigurations[gameSettings.SpawnConfigurations.Length - 1];
            m_ExpectedMaxTime = lastWave.time + 3.0f;
        }

        {
            m_SpawnMilestonePrefab.SetActive(true);

            
            foreach (var config in gameSettings.SpawnConfigurations)
            {
                float timePercent = config.time / m_ExpectedMaxTime;
                float widthPercent = timePercent * m_Time.rectTransform.rect.width;

                Vector3 spawnPos = m_SpawnMilestonePrefab.transform.localPosition;
                spawnPos.x = m_Time.rectTransform.rect.x + widthPercent;
                GameObject milestone = Instantiate(m_SpawnMilestonePrefab, m_SpawnMilestonePrefab.transform.parent, false);
                milestone.transform.localPosition = spawnPos;
            }

            m_SpawnMilestonePrefab.SetActive(false);
        }
    }
    private void Update()
    {
        float elapsed = ECSBindings.GetStateElapsedTime().value;
        m_Time.fillAmount = elapsed / m_ExpectedMaxTime;
    }
}

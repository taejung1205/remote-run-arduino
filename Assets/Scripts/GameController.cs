using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class GameController : MonoBehaviour
{
    public bool canStart = true;
    public bool isGameRunning = false;

    public bool isUsingArduino = false;

    public TMP_Text CountdownText;
    public TMP_Text GameOverText;

    public GameObject SettingButton;
    public GameObject Player;

    public GameObject SettingScreen;
    public GameObject StartScreen;

    // Start is called before the first frame update
    void Start()
    {
        StartingInterface();  
    }

    // Update is called once per frame
    void Update()
    {
    }

    void StartingInterface()
    {
        SettingScreen.SetActive(false);
        StartScreen.SetActive(true);
        CountdownText.text = "";
        GameOverText.text = "";
        Player.transform.position = new Vector3(0, 0.6f, 0);
    }

    public void StartGame()
    {
        StartScreen.SetActive(false);
        StartCoroutine(StartCountdown());
    }

    public void GameOver()
    {
        StartCoroutine(GameOverProcess());
    }

    public void GameClear()
    {
        StartCoroutine(GameClearProcess());
    }

    public void OpenSetting()
    {
        canStart = false;
        StartScreen.SetActive(false);
        SettingScreen.SetActive(true);
    }

    public void CloseSetting()
    {
        canStart = true;
        StartScreen.SetActive(true);
        SettingScreen.SetActive(false);
    }

    IEnumerator StartCountdown()
    {
        canStart = false;
        CountdownText.text = "3";
        yield return new WaitForSeconds(1);
        CountdownText.text = "2";
        yield return new WaitForSeconds(1);
        CountdownText.text = "1";
        yield return new WaitForSeconds(1);
        CountdownText.text = "";
        isGameRunning = true;
    }

    IEnumerator GameOverProcess()
    {
        isGameRunning = false;
        GameOverText.text = "Game Over...";
        GameOverText.color = Color.grey;
        yield return new WaitForSeconds(2);
        StartingInterface();
        yield return new WaitForSeconds(1);
        canStart = true;
    }

    IEnumerator GameClearProcess()
    {
        isGameRunning = false;
        GameOverText.text = "Game Clear!!";
        GameOverText.color = Color.cyan;
        yield return new WaitForSeconds(4);
        StartingInterface();
        yield return new WaitForSeconds(1);
        canStart = true;
    }
}

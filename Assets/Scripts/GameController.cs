using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class GameController : MonoBehaviour
{
    public bool isGameRunning = false;

    public bool isUsingArduino = false;

    public TMP_Text countdown;

    public GameObject startButton;

    // Start is called before the first frame update
    void Start()
    {
        countdown.text = "";
    }

    // Update is called once per frame
    void Update()
    {
    }

    public void StartGame()
    {
        startButton.SetActive(false);
        StartCoroutine(StartCountdown());
    }

    IEnumerator StartCountdown()
    {
        countdown.text = "3";
        yield return new WaitForSeconds(1);
        countdown.text = "2";
        yield return new WaitForSeconds(1);
        countdown.text = "1";
        yield return new WaitForSeconds(1);
        countdown.text = "";
        isGameRunning = true;
    }
}

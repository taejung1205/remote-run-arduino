using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class GameController : MonoBehaviour
{
    public bool isGameRunning = false;
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
        print("hello");
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

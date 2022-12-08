using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoListener : MonoBehaviour
{

    public PlayerController MyPlayerController;

    public GameController MyGameController;


    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
    }

    // Invoked when a line of data is received from the serial device.

    void OnMessageArrived(string msg)
    {
        Debug.Log(msg);
        string[] distances = msg.Split(' ');
        float left = float.Parse(distances[0]);
        float right = float.Parse(distances[1]);
        float result = right - left;
        if(right < 50 && left < 50)
        {
            MyPlayerController.direction = left - right;
        }

        if(MyGameController.canStart && right < 5 && left < 5)
        {
            MyGameController.StartGame();
        }
    }

    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");
    }
}

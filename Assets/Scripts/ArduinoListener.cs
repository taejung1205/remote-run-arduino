using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoListener : MonoBehaviour
{
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
        string[] distances = msg.Split(' ');
        int left = Int32.Parse(distances[0]);
        int right = Int32.Parse(distances[1]);
        Debug.Log("Left: " + left + " Right: " + right);
    }

    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");
    }
}

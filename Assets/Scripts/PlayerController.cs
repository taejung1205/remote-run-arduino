using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{

    private Transform PlayerTransform;

    public GameController MyGameController;

    public float direction = 0;
    public float sensitivity = 0.2f;

    // Start is called before the first frame update
    void Start()
    {
        PlayerTransform = transform;
    }

    // Update is called once per frame
    void Update()
    {
        if (MyGameController.isGameRunning)
        {
            PlayerTransform.position +=
                new Vector3(6.5f, 0, 0) * Time.deltaTime;

            if (!MyGameController.isUsingArduino)
            {
                if (Input.GetKey(KeyCode.A))
                {
                    PlayerTransform.position +=
                        new Vector3(0, 0, 2f) * Time.deltaTime;
                }
                else if (Input.GetKey(KeyCode.D))
                {
                    PlayerTransform.position +=
                        new Vector3(0, 0, -2f) * Time.deltaTime;
                }
            } else
            {
                PlayerTransform.position +=
                        new Vector3(0, 0, direction * sensitivity) * Time.deltaTime;
            }

            if(PlayerTransform.position.x >= 325)
            {
                MyGameController.GameClear();
            }
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        
        if (MyGameController.isGameRunning)
        {
            Debug.Log("Collision Occured");
            MyGameController.GameOver();
        }
    }

    public void SetSensitivity(string str)
    {
        try
        {
            float sen = float.Parse(str);
            sensitivity = sen;
        } catch
        {

        }
    }
}


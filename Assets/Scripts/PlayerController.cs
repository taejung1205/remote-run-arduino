using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public GameObject gameController;
    private Transform playerTransform;

    // Start is called before the first frame update
    void Start()
    {
        playerTransform = transform;
    }

    // Update is called once per frame
    void Update()
    {
        if (gameController.GetComponent<GameController>().isGameRunning)
        {
            playerTransform.position += new Vector3(6.5f, 0, 0) * Time.deltaTime;
            if (Input.GetKey(KeyCode.A))
            {
                playerTransform.position += new Vector3(0, 0, 2f) * Time.deltaTime;
            } else if (Input.GetKey(KeyCode.D))
            {
                playerTransform.position += new Vector3(0, 0, -2f) * Time.deltaTime;
            }
        }
    }
}

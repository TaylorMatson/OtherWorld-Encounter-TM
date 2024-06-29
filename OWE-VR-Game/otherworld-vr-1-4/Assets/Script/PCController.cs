using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PCController : MonoBehaviour

{
    float playerYaw;

    public float speedH = 10.0f;
    public float fbSpeed = 30.0f;

    void Start()
    {

    }

    void Update()
    {
        if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow))
        {
            transform.position += transform.forward * fbSpeed * Time.deltaTime;
        }
        if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
        {
            transform.position -= transform.forward * fbSpeed * Time.deltaTime;
        }

        playerYaw += speedH * Input.GetAxis("Mouse X");

        transform.eulerAngles = new Vector3(0.0f, playerYaw, 0.0f);
    }
}
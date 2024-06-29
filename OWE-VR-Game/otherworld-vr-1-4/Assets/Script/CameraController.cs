using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {

    public float speedV = 2.0f;
    public float clamp = 30.0f;

    private float pitch;

    public GameObject Parent;



    // Update is called once per frame
    void Update()
    {
        pitch += -speedV * Input.GetAxis("Mouse Y");

        pitch = Mathf.Clamp(pitch, -clamp, clamp);

        transform.localEulerAngles = new Vector3(pitch, 0.0f, 0.0f);
    }
}
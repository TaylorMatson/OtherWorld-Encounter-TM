using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotateAround : MonoBehaviour {

    public GameObject objectToOrbit;

	// Use this for initialization
	void Start () {
		
	}

    // Update is called once per frame
    void Update()
    {
        // Spin the object around the world origin at 20 degrees/second.
        transform.RotateAround(objectToOrbit.transform.position, Vector3.up, 20 * Time.deltaTime);
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// (fps 카메라) 

public class FirstPersonCamera : MonoBehaviour
{

	void Awake()
	{
		Camera.main.transform.eulerAngles = new Vector3(0, 0, 0);
		Input.mousePosition.Set(0, 0, 0);
		//Screen.height
	}

	// Start is called before the first frame update
	void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		float fSpeed = 50;
		float x = Input.GetAxis("Mouse X");
		float y = -Input.GetAxis("Mouse Y");

		Vector3 tmp = transform.eulerAngles;
		tmp.x += y * Time.deltaTime * fSpeed;
		tmp.y += x * Time.deltaTime * fSpeed;
		transform.eulerAngles = tmp;

		float mz = Input.GetAxis("Vertical");
		float mx = Input.GetAxis("Horizontal");
		float my = transform.position.y;
		Vector3 deltaz = Vector3.zero;

		if(mz != 0)
		{
			deltaz = transform.forward * mz * 0.1f;
			Debug.Log(transform.forward);
			transform.Translate(deltaz);
		}

		Vector3 deltax = Vector3.zero;
		if (mx != 0)
		{
			deltax = transform.right * mx * 0.1f;
			transform.Translate(deltax);
		}

		if (my != transform.position.y)
			transform.position = new Vector3(transform.position.x
										, my
										, transform.position.z);
	}
}

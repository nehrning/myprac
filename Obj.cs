using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Obj : MonoBehaviour
{
	Rigidbody rb;
    // Start is called before the first frame update
    void Start()
    {
		rb = GetComponent<Rigidbody>();
    }

	//충돌시작
	void OnCollisionEnter(Collision collision)
	{
		Debug.Log("충돌 오브젝트 : " + collision.gameObject.name);
	}

	//충돌 진행
	void OnCollisionStay(Collision collision)
	{
		
	}

	//충돌 종료
	void OnCollisionExit(Collision collision)
	{
		
	}

	private void OnTriggerEnter(Collider other)
	{
		Debug.Log("트리거 충돌 : " + other);
		if (other.name == "Obj_2")
			other.gameObject.SetActive(false);
		//if(other.gameObject.CompareTag("태그이름"))
	}

	void FixedUpdate()
	{
		if (Input.GetMouseButtonDown(0))
		{
			//rb.AddForce(new Vector3(1, 10, 1), ForceMode.Impulse);
			rb.velocity = new Vector3(0, 10, 0);
		}
		rb.MovePosition(rb.position +
				transform.right * Time.fixedDeltaTime); //물리 이동
	}
	// Update is called once per frame
	void Update()
    {
        
    }
}

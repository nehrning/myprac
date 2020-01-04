using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
	public float speed = 50f;
	bool bfire = false;
	Transform trPos;
	Vector3 dir = Vector3.zero;
    // Start is called before the first frame update
    void Start()
    {
		//Destroy(this.gameObject, 1f);
    }

	void OffBullet()
	{
		this.gameObject.SetActive(false);
	}

	// Update is called once per frame
	void Update()
    {
		if (bfire)
		{
			//transform.Translate(dir * Time.deltaTime * speed);
			Vector3 tmp = transform.position;
			tmp.x = tmp.x + dir.x * Time.deltaTime * speed;
			tmp.y = tmp.y + dir.y * Time.deltaTime * speed;
			tmp.z = tmp.z + dir.z * Time.deltaTime * speed;
			transform.position = tmp;
		}
    }

	public void SetFirePosition(Transform _pos)
	{
		Invoke("OffBullet", 3f);
		trPos = _pos;
		bfire = true;
		transform.position = trPos.position;
		dir = trPos.forward;
	}
}

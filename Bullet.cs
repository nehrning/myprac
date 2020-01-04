using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
	public float speed = 10f;
	bool bfire = false;
	Transform trPos;
	Vector3 dir = Vector3.zero;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		if(bfire){
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
		trPos = _pos;
		bfire = true;
		//transformPoint 지역좌표를 월드좌표로 변환
		transform.position = trPos.position;
		dir = trPos.forward;
	}
}

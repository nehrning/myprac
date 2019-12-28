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
		if(bfire)
			transform.Translate(dir * Time.deltaTime * speed);
    }

	public void SetFirePosition(Transform _pos)
	{
		trPos = _pos;
		bfire = true;
		//transformPoint 지역좌표를 월드좌표로 변환
		transform.position = trPos.TransformPoint(trPos.localPosition);
		dir = trPos.forward;
	}
}

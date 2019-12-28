using UnityEngine;

public class Gun : MonoBehaviour
{

	public int MAX_BULLET = 10;
	public Transform BulletPos;
	/*
	 * public 변수는 inspector에 공개됨
	 * 
	 * 게임오브젝트에 추가되어 있는 컴포넌트를 가져오는 함수
	 *  GameObject.GetComponent<컴포넌트>();
	 * ex) MeshRenderer ren = GetComponent<MeshRenderer>();
	 * 
	 * 게임오브젝트에 컴포넌트를 추가하는 함수
	 * AddComponent<컴포넌트>();
	 * 
	 * 컴포넌트.enable = true, false / 활성화, 비활성화
	 * 
	 * 프리팹 prefeb
	 * 게임오브젝트를 재사용하기 위한 게임오브젝트의 일종
	 * 3d일 경우 원본리소스는 확장자 .fbx이다
	 * 게임에서는 원본을 사용하는 것이 아니라 프리팹을 사용한다.
	 * 
	 * 리소스를 실시간으로 로드하는 방법
	 * 1. Resources 폴더를 생성 ( 폴더이름은 변경 불가 )
	 * 하위에 리소스를 배치
	 * 2. Asset Bundle을 사용
	 *  Resources폴더에 국한하지 않고 실시간으로 리소스를 불러올 수 있는
	 *  방법으로  게임 패치에서 주로 사용된다.
	 *  
	 *  Resources폴더는 빌드시에 포함되므로 폴더에 포함된 내용은 패치로
	 *  변경하라 수 없다.
	 *  따라서 제작하고자 하는 게임이 패치되어야하는 내용을 포함한다면 assetbundle로
	 *  리소스를 제작하고 패치시스템을 구현해야한다.
	 *  
	 *  리소스 로드
	 *  Resources.Load("Asset_name");
	 *  ex) GameObject obj = Resources.Load("Bullet") as GameObject;
	 *  
	 *  리소스 출럭
	 *  Instantiate(메모리에 적제된 게임오브젝트)
	 *  ex) GameObject tmp = Instantiate(obj);
	 *  
	 */
	GameObject _bullet;
	void Awake()
	{
		_bullet = Resources.Load("Bullet") as GameObject;

	}
	// Start is called before the first frame update
	void Start()
    {

	}

    // Update is called once per frame
    void Update()
    {
		if (Input.GetKeyDown(KeyCode.Space))
		{
			GameObject tmp = Instantiate(_bullet);
			Bullet bulletScript = tmp.AddComponent<Bullet>();
			bulletScript.SetFirePosition(BulletPos);
			//tmp.AddComponent<Bullet>();
			//tmp.transform.position = BulletPos.position;
		}
    }
}

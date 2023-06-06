# miniRT 뿌수기 !
## 구조체 설명
> 맵파싱 부분에서 받을 구조체들입니다.
```c
typedef struct s_data
{
	struct s_light	a_light;	// 주변광
	struct s_camera	camera;		// 카메라
	struct s_light	*lights;	// 빛
	struct s_object	*objects;	// 도형
}	t_data;
```
- `enum e_shape`
	```c
	typedef enum e_shape
	{
		sphere = 0,		// 구체(원)
		plane,			// 평면
		cylinder,		// 원기둥
		con,			// 원뿔
		hyperboloid,	// 쌍곡선
		paraboloid		// 포물선
	}   t_shape;
	```
- `struct s_point`
	```c
	typedef struct s_point
	{
		int x;	// x 좌표
		int y;	// y 좌표
		int z;	// z 좌표
	}   t_point;
	```
- `struct s_light`
	```c
	typedef struct s_light
	{
		struct s_point	point;			// 위치
		int				light_ratio;	// 빛세기
		int				color;			// 색상
	}   t_light;
	```
- `struct s_camera`
	```c
	typedef struct s_camera
	{
		t_point	point;		// 위치
		t_point	n_vector;	// 방향(기울기)
		int		fov;		// 시야폭
	}	t_camera;
	```
- `struct s_object`
	```c
	typedef struct s_object
	{
		t_shape	shape;		// 모양
		t_point	point;		// 위치
		t_point	n_vector;	// 방향(기울기)
		int		diameter;	// 지름
		size_t	height;		// 높이
		int		color;		// 색상
	}   t_object;
	```
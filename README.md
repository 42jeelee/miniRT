# miniRT 뿌수기 !
## 구조체 설명
- 해상도 설정
	```c
	#define WINDOW_X 1920;		// 가로
	#define WINDOW_Y 1080;		// 세로
	```
- 맵파싱 부분에서 받을 구조체들입니다.
	```c
	typedef struct s_data
	{
		struct s_light	a_light;	// 주변광
		struct s_camera	camera;		// 카메라
		struct s_mlx	params;		// mlx
		struct s_light	**lights;	// 빛
		struct s_object	**objects;	// 도형
	}	t_data;
	```
	+ `enum e_shape`
		```c
		typedef enum e_shape
		{
			amb = 1,		// 주변광
			camera,			// 카메라
			light,			// 빛
			sphere,			// 구체(원)
			plane,			// 평면
			cylinder,		// 원기둥
			cone,			// 원뿔
			hyperboloid,		// 쌍곡선
			paraboloid,		// 포물선
			circle			// 원기둥, 원뿔의 cap
		}	t_shape;
		```
	+ `struct s_point`
		```c
		typedef struct s_point
		{
			double	x;	// x 좌표
			double	y;	// y 좌표
			double	z;	// z 좌표
		}	t_point;
		```
	+ `struct s_color`
		```c
		typedef struct s_color
		{
			int	r;	// R
			int	g;	// G
			int	b;	// B
		}	t_color;
		```
	+ `struct s_light`
		```c
		typedef struct s_light
		{
			struct s_point	point;		// 위치
			double		light_ratio;	// 빛세기
			t_color		color;		// 색상
		}	t_light;
		```
	+ `struct s_camera`
		```c
		typedef struct s_camera
		{
			t_point	point;		// 위치
			t_point	n_vector;	// 방향(기울기)
			int		fov;		// 시야폭
		}	t_camera;
		```
	+ `struct s_object`
		```c
		typedef struct s_object
		{
			t_shape		shape;		// 모양
			t_point		point;		// 위치
			t_point		n_vector;	// 방향(기울기)
			double		diameter;	// 지름
			double		height;		// 높이
			t_color		color;		// 색상
		}	t_object;
		```


#define TRUE true
#define FALSE false
typedef bool color_t;
typedef unsigned int coord_t;
typedef unsigned int powermode_t;
typedef unsigned int orientation_t;

typedef struct GDISPControl {
		coord_t					Width;
		coord_t					Height;
		orientation_t			Orientation;
		powermode_t				Powermode;
		uint8_t					Backlight;
		uint8_t					Contrast;
	}GDISPControl_t;
enum powermode{powerOff};

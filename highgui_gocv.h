#include "mvsc.h"

#ifndef _OPENCV3_HIGHGUI_H_
#define _OPENCV3_HIGHGUI_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

typedef void(*mouse_callback) (int event, int x, int y, int flags, void *userdata);

/* typedef struct mouse_callback_userdata {
    char* winname;
    void* userdata;
} mouse_callback_userdata; */
DLL_EXPORT void Window_SetMouseCallback(char* winname, mouse_callback on_mouse);

// Window
DLL_EXPORT void Window_New(const char* winname, int flags);
DLL_EXPORT void Window_Close(const char* winname);
DLL_EXPORT void Window_IMShow(const char* winname, Mat mat);
DLL_EXPORT double Window_GetProperty(const char* winname, int flag);
DLL_EXPORT void Window_SetProperty(const char* winname, int flag, double value);
DLL_EXPORT void Window_SetTitle(const char* winname, const char* title);
DLL_EXPORT int Window_WaitKey(int);
DLL_EXPORT int Window_WaitKeyEx(int);
DLL_EXPORT int Window_PollKey(void);
DLL_EXPORT void Window_Move(const char* winname, int x, int y);
DLL_EXPORT void Window_Resize(const char* winname, int width, int height);
DLL_EXPORT struct Rect Window_SelectROI(const char* winname, Mat img);
DLL_EXPORT struct Rects Window_SelectROIs(const char* winname, Mat img);

// Trackbar
DLL_EXPORT void Trackbar_Create(const char* winname, const char* trackname, int max);
DLL_EXPORT void Trackbar_CreateWithValue(const char* winname, const char* trackname, int* value, int max);
DLL_EXPORT int Trackbar_GetPos(const char* winname, const char* trackname);
DLL_EXPORT void Trackbar_SetPos(const char* winname, const char* trackname, int pos);
DLL_EXPORT void Trackbar_SetMin(const char* winname, const char* trackname, int pos);
DLL_EXPORT void Trackbar_SetMax(const char* winname, const char* trackname, int pos);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_HIGHGUI_H_

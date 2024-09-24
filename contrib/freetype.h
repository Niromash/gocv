#include "../mvsc.h"

#ifndef _OPENCV3_FREETYPE2_H_
#define _OPENCV3_FREETYPE2_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>
extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::freetype::FreeType2>* FreeType2;
#else
typedef void* FreeType2;
#endif
DLL_EXPORT FreeType2 FreeType2_CreateFreeType2();
DLL_EXPORT void FreeType2_Close(FreeType2 f);
DLL_EXPORT void FreeType2_LoadFontData(FreeType2 f, const char* fontFileName, int id);
DLL_EXPORT void FreeType2_SetSplitNumber(FreeType2 f, int num);
DLL_EXPORT void FreeType2_PutText(FreeType2 f, Mat img, const char* text, Point org,
        int fontHeight, Scalar color,
        int thickness, int line_type, bool bottomLeftOrigin
    );
DLL_EXPORT Size FreeType2_GetTextSize(FreeType2 f, const char* text,
                                int fontHeight, int thickness, int* baseLine);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_FREETYPE2_H_

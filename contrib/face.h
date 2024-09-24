#include "../mvsc.h"

#ifndef _OPENCV3_FACE_H_
#define _OPENCV3_FACE_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::face::FaceRecognizer>* FaceRecognizer;
typedef cv::Ptr<cv::face::BasicFaceRecognizer>* BasicFaceRecognizer;
typedef cv::Ptr<cv::face::LBPHFaceRecognizer>* LBPHFaceRecognizer;
typedef cv::Ptr<cv::face::EigenFaceRecognizer>* EigenFaceRecognizer;
typedef cv::Ptr<cv::face::FisherFaceRecognizer>* FisherFaceRecognizer;
#else
typedef void* FaceRecognizer;
typedef void* BasicFaceRecognizer;
typedef void* LBPHFaceRecognizer;
typedef void* EigenFaceRecognizer;
typedef void* FisherFaceRecognizer;
#endif

struct PredictResponse {
    int label;
    double confidence;
};
DLL_EXPORT bool FaceRecognizer_Empty(FaceRecognizer fr);
DLL_EXPORT void FaceRecognizer_Train(FaceRecognizer fr, Mats images, IntVector labels);
DLL_EXPORT void FaceRecognizer_Update(FaceRecognizer fr, Mats images, IntVector labels);
DLL_EXPORT int FaceRecognizer_Predict(FaceRecognizer fr, Mat sample);
DLL_EXPORT struct PredictResponse FaceRecognizer_PredictExtended(FaceRecognizer fr, Mat sample);
DLL_EXPORT double FaceRecognizer_GetThreshold(FaceRecognizer fr);
DLL_EXPORT void FaceRecognizer_SetThreshold(FaceRecognizer fr, double threshold);
DLL_EXPORT void FaceRecognizer_SaveFile(FaceRecognizer fr, const char*  filename);
DLL_EXPORT void FaceRecognizer_LoadFile(FaceRecognizer fr, const char*  filename);
DLL_EXPORT void BasicFaceRecognizer_Train(BasicFaceRecognizer fr, Mats images, IntVector labels);
DLL_EXPORT void BasicFaceRecognizer_Update(BasicFaceRecognizer fr, Mats images, IntVector labels);
DLL_EXPORT Mat BasicFaceRecognizer_getEigenValues(BasicFaceRecognizer fr);
DLL_EXPORT Mat BasicFaceRecognizer_getEigenVectors(BasicFaceRecognizer fr);
DLL_EXPORT Mat BasicFaceRecognizer_getLabels(BasicFaceRecognizer fr);
DLL_EXPORT Mat BasicFaceRecognizer_getMean(BasicFaceRecognizer fr);
DLL_EXPORT int BasicFaceRecognizer_getNumComponents(BasicFaceRecognizer fr);
DLL_EXPORT Mats BasicFaceRecognizer_getProjections(BasicFaceRecognizer fr);
DLL_EXPORT void BasicFaceRecognizer_setNumComponents(BasicFaceRecognizer fr, int val);	
DLL_EXPORT void BasicFaceRecognizer_SaveFile(BasicFaceRecognizer fr, const char*  filename);
DLL_EXPORT void BasicFaceRecognizer_LoadFile(BasicFaceRecognizer fr, const char*  filename);
DLL_EXPORT LBPHFaceRecognizer CreateLBPHFaceRecognizer(void);
DLL_EXPORT void LBPHFaceRecognizer_SetRadius(LBPHFaceRecognizer fr, int radius);
DLL_EXPORT void LBPHFaceRecognizer_SetNeighbors(LBPHFaceRecognizer fr, int neighbors);
DLL_EXPORT int LBPHFaceRecognizer_GetNeighbors(LBPHFaceRecognizer fr);
DLL_EXPORT void LBPHFaceRecognizer_SetGridX(LBPHFaceRecognizer fr, int x);
DLL_EXPORT void LBPHFaceRecognizer_SetGridY(LBPHFaceRecognizer fr, int y);
DLL_EXPORT int LBPHFaceRecognizer_GetGridX(LBPHFaceRecognizer fr);
DLL_EXPORT int LBPHFaceRecognizer_GetGridY(LBPHFaceRecognizer fr);
DLL_EXPORT void LBPHFaceRecognizer_Close(LBPHFaceRecognizer fr);
DLL_EXPORT FisherFaceRecognizer FisherFaceRecognizer_Create(void);
DLL_EXPORT FisherFaceRecognizer FisherFaceRecognizer_CreateWithParams(int num_components, float threshold);
DLL_EXPORT void FisherFaceRecognizer_Close(FisherFaceRecognizer fr);
DLL_EXPORT EigenFaceRecognizer EigenFaceRecognizer_Create(void);
DLL_EXPORT EigenFaceRecognizer EigenFaceRecognizer_CreateWithParams(int num_components, float threshold);
DLL_EXPORT void EigenFaceRecognizer_Close(EigenFaceRecognizer fr);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_FACE_H_

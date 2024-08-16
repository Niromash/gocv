#ifndef _OPENCV3_ARUCO_H_
#define _OPENCV3_ARUCO_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::aruco::Dictionary* ArucoDictionary;
typedef cv::aruco::DetectorParameters* ArucoDetectorParameters; 
typedef cv::aruco::ArucoDetector* ArucoDetector;
#else
typedef void *ArucoDictionary;
typedef void *ArucoDetectorParameters;
typedef void *ArucoDetector;
#endif
DLL_EXPORT ArucoDetectorParameters ArucoDetectorParameters_Create();
DLL_EXPORT void ArucoDetectorParameters_SetAdaptiveThreshWinSizeMin(ArucoDetectorParameters ap, int adaptiveThreshWinSizeMin);
DLL_EXPORT int ArucoDetectorParameters_GetAdaptiveThreshWinSizeMin(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAdaptiveThreshWinSizeMax(ArucoDetectorParameters ap, int adaptiveThreshWinSizeMax);
DLL_EXPORT int ArucoDetectorParameters_GetAdaptiveThreshWinSizeMax(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAdaptiveThreshWinSizeStep(ArucoDetectorParameters ap, int adaptiveThreshWinSizeStep);
DLL_EXPORT int ArucoDetectorParameters_GetAdaptiveThreshWinSizeStep(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAdaptiveThreshConstant(ArucoDetectorParameters ap, double adaptiveThreshConstant);
DLL_EXPORT double ArucoDetectorParameters_GetAdaptiveThreshConstant(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMinMarkerPerimeterRate(ArucoDetectorParameters ap, double minMarkerPerimeterRate);
DLL_EXPORT double ArucoDetectorParameters_GetMinMarkerPerimeterRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMaxMarkerPerimeterRate(ArucoDetectorParameters ap, double maxMarkerPerimeterRate);
DLL_EXPORT double ArucoDetectorParameters_GetMaxMarkerPerimeterRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetPolygonalApproxAccuracyRate(ArucoDetectorParameters ap, double polygonalApproxAccuracyRate);
DLL_EXPORT double ArucoDetectorParameters_GetPolygonalApproxAccuracyRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMinCornerDistanceRate(ArucoDetectorParameters ap, double minCornerDistanceRate);
DLL_EXPORT double ArucoDetectorParameters_GetMinCornerDistanceRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMinDistanceToBorder(ArucoDetectorParameters ap, int minDistanceToBorder);
DLL_EXPORT int ArucoDetectorParameters_GetMinDistanceToBorder(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMinMarkerDistanceRate(ArucoDetectorParameters ap, double minMarkerDistanceRate);
DLL_EXPORT double ArucoDetectorParameters_GetMinMarkerDistanceRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetCornerRefinementMethod(ArucoDetectorParameters ap, int cornerRefinementMethod);
DLL_EXPORT int ArucoDetectorParameters_GetCornerRefinementMethod(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetCornerRefinementWinSize(ArucoDetectorParameters ap, int cornerRefinementWinSize);
DLL_EXPORT int ArucoDetectorParameters_GetCornerRefinementWinSize(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetCornerRefinementMaxIterations(ArucoDetectorParameters ap, int cornerRefinementMaxIterations);
DLL_EXPORT int ArucoDetectorParameters_GetCornerRefinementMaxIterations(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetCornerRefinementMinAccuracy(ArucoDetectorParameters ap, double cornerRefinementMinAccuracy);
DLL_EXPORT double ArucoDetectorParameters_GetCornerRefinementMinAccuracy(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMarkerBorderBits(ArucoDetectorParameters ap, int markerBorderBits);
DLL_EXPORT int ArucoDetectorParameters_GetMarkerBorderBits(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetPerspectiveRemovePixelPerCell(ArucoDetectorParameters ap, int perspectiveRemovePixelPerCell);
DLL_EXPORT int ArucoDetectorParameters_GetPerspectiveRemovePixelPerCell(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetPerspectiveRemoveIgnoredMarginPerCell(ArucoDetectorParameters ap, double perspectiveRemoveIgnoredMarginPerCell);
DLL_EXPORT double ArucoDetectorParameters_GetPerspectiveRemoveIgnoredMarginPerCell(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMaxErroneousBitsInBorderRate(ArucoDetectorParameters ap, double maxErroneousBitsInBorderRate);
DLL_EXPORT double ArucoDetectorParameters_GetMaxErroneousBitsInBorderRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetMinOtsuStdDev(ArucoDetectorParameters ap, double minOtsuStdDev);
DLL_EXPORT double ArucoDetectorParameters_GetMinOtsuStdDev(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetErrorCorrectionRate(ArucoDetectorParameters ap, double errorCorrectionRate);
DLL_EXPORT double ArucoDetectorParameters_GetErrorCorrectionRate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagQuadDecimate(ArucoDetectorParameters ap, float aprilTagQuadDecimate);
DLL_EXPORT float ArucoDetectorParameters_GetAprilTagQuadDecimate(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagQuadSigma(ArucoDetectorParameters ap, float aprilTagQuadSigma);
DLL_EXPORT float ArucoDetectorParameters_GetAprilTagQuadSigma(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagMinClusterPixels(ArucoDetectorParameters ap, int aprilTagMinClusterPixels);
DLL_EXPORT int ArucoDetectorParameters_GetAprilTagMinClusterPixels(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagMaxNmaxima(ArucoDetectorParameters ap, int aprilTagMaxNmaxima);
DLL_EXPORT int ArucoDetectorParameters_GetAprilTagMaxNmaxima(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagCriticalRad(ArucoDetectorParameters ap, float aprilTagCriticalRad);
DLL_EXPORT float ArucoDetectorParameters_GetAprilTagCriticalRad(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagMaxLineFitMse(ArucoDetectorParameters ap, float aprilTagMaxLineFitMse);
DLL_EXPORT float ArucoDetectorParameters_GetAprilTagMaxLineFitMse(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagMinWhiteBlackDiff(ArucoDetectorParameters ap, int aprilTagMinWhiteBlackDiff);
DLL_EXPORT int ArucoDetectorParameters_GetAprilTagMinWhiteBlackDiff(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetAprilTagDeglitch(ArucoDetectorParameters ap, int aprilTagDeglitch);
DLL_EXPORT int ArucoDetectorParameters_GetAprilTagDeglitch(ArucoDetectorParameters ap);
DLL_EXPORT void ArucoDetectorParameters_SetDetectInvertedMarker(ArucoDetectorParameters ap, bool detectInvertedMarker);
DLL_EXPORT bool ArucoDetectorParameters_GetDetectInvertedMarker(ArucoDetectorParameters ap);
DLL_EXPORT ArucoDictionary getPredefinedDictionary(int dictionaryId);
DLL_EXPORT ArucoDetector ArucoDetector_New();
DLL_EXPORT ArucoDetector ArucoDetector_NewWithParams(ArucoDictionary dictionary, ArucoDetectorParameters params);
DLL_EXPORT void ArucoDetector_Close(ArucoDetector ad);
DLL_EXPORT void ArucoDetector_DetectMarkers(ArucoDetector ad, Mat inputArr, Points2fVector markerCorners, IntVector *markerIds, Points2fVector rejectedCandidates);
DLL_EXPORT void ArucoDrawDetectedMarkers(Mat image, Points2fVector markerCorners, IntVector markerIds, Scalar borderColor);
DLL_EXPORT void ArucoGenerateImageMarker(int dictionaryId, int id, int sidePixels, Mat img, int borderBits);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_ARUCO_H_

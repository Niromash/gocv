#include "mvsc.h"

#ifndef _OPENCV3_OBJDETECT_H_
#define _OPENCV3_OBJDETECT_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::FileStorage* FileStorage;
typedef cv::FileNode* FileNode;
#else
typedef void* FileStorage;
typedef void* FileNode;
#endif

// FileStorage
DLL_EXPORT FileStorage FileStorage_Create(void);
DLL_EXPORT FileStorage FileStorage_CreateWithParams(const char* filename, int flags, const char* encoding);
DLL_EXPORT void FileStorage_Close(FileStorage fs);
DLL_EXPORT const char *FileStorage_ElName(FileStorage fs);
DLL_EXPORT int FileStorage_State(FileStorage fs);
DLL_EXPORT void FileStorage_EndWriteStruct(FileStorage fs);
DLL_EXPORT int FileStorage_GetFormat(FileStorage fs);
DLL_EXPORT bool FileStorage_IsOpened(FileStorage fs);
DLL_EXPORT bool FileStorage_Open(FileStorage fs, const char* filename, int flags, const char* encoding);
DLL_EXPORT void FileStorage_Release(FileStorage fs);
DLL_EXPORT const char* FileStorage_ReleaseAndGetString(FileStorage fs);
DLL_EXPORT void FileStorage_StartWriteStruct(FileStorage fs, const char* name, int flags, const char* typeName);
DLL_EXPORT void FileStorage_WriteMat(FileStorage fs, const char* name, Mat val);
DLL_EXPORT void FileStorage_WriteString(FileStorage fs, const char* name, const char* val);
DLL_EXPORT void FileStorage_WriteStringArray(FileStorage fs, const char* name, const char** val, size_t len);
DLL_EXPORT void FileStorage_WriteDouble(FileStorage fs, const char* name, double val);
DLL_EXPORT void FileStorage_WriteInt(FileStorage fs, const char* name, int val);
DLL_EXPORT void FileStorage_WriteComment(FileStorage fs, const char* comment, bool append);
DLL_EXPORT void FileStorage_WriteRaw(FileStorage fs, const char* fmt, const void* vec, size_t len);
DLL_EXPORT FileNode FileStorage_GetFirstTopLevelNode(FileStorage fs);
DLL_EXPORT FileNode FileStorage_GetNode(FileStorage fs, const char* nodename);
DLL_EXPORT FileNode FileStorage_Root(FileStorage fs, int streamidx);
DLL_EXPORT bool FileNode_Empty(FileNode fn);
DLL_EXPORT bool FileNode_IsInt(FileNode fn);
DLL_EXPORT bool FileNode_IsMap(FileNode fn);
DLL_EXPORT bool FileNode_IsNamed(FileNode fn);
DLL_EXPORT bool FileNode_IsNone(FileNode fn);
DLL_EXPORT bool FileNode_IsReal(FileNode fn);
DLL_EXPORT bool FileNode_IsSeq(FileNode fn);
DLL_EXPORT bool FileNode_IsString(FileNode fn);
DLL_EXPORT char** FileNode_Keys(FileNode fn);
DLL_EXPORT size_t FileNode_KeysCount(FileNode fn);
DLL_EXPORT void FileNode_KeysFree(char** keys, size_t len);
DLL_EXPORT Mat FileNode_Mat(FileNode fn);
DLL_EXPORT const char* FileNode_Name(FileNode fn);
DLL_EXPORT float FileNode_Float(FileNode fn);
DLL_EXPORT const char* FileNode_String(FileNode fn);
DLL_EXPORT FileNode FileNode_Get(FileNode fn, int i); //FileNode operator[] (int i) const
DLL_EXPORT FileNode FileNode_GetByName(FileNode fn, const char* nodename); //FileNode operator[] (const char *nodename) const
DLL_EXPORT size_t FileNode_RawSize(FileNode fn);
DLL_EXPORT void FileNode_ReadRaw(FileNode fn, const char* fmt, void *vec, size_t len);
DLL_EXPORT void FileNode_SetValue(FileNode fn, int type, const void *value, int len);
DLL_EXPORT size_t FileNode_Size(FileNode fn);
DLL_EXPORT int FileNode_Type(FileNode fn);
DLL_EXPORT void FileNode_Close(FileNode fn);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_OBJDETECT_H_

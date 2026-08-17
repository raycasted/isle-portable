#pragma once

#include "structs.h"

#include <SDL3/SDL.h>
#include <stdint.h>
#include <vector>

// We don't want to transitively include windows.h, but we need GLuint
typedef unsigned int GLuint;
struct IDirect3DRMTexture;
struct MeshGroup;

typedef float Matrix4x4[4][4];

struct PBGL_BridgeVector {
	float x, y, z;
};

struct PBGL_BridgeTexCoord {
	float u, v;
};

struct PBGL_BridgeSceneLight {
	FColor color;
	PBGL_BridgeVector position;
	float positional;
	PBGL_BridgeVector direction;
	float directional;
};

struct PBGL_BridgeSceneVertex {
	PBGL_BridgeVector position;
	PBGL_BridgeVector normal;
	float tu, tv;
};

struct GLTextureCacheEntry {
	IDirect3DRMTexture* texture;
	Uint32 version;
	GLuint glTextureId;
	float width;
	float height;
};

struct GLMeshCacheEntry {
	const MeshGroup* meshGroup;
	int version;
	bool flat;

	// non-VBO cache
	std::vector<PBGL_BridgeVector> positions;
	std::vector<PBGL_BridgeVector> normals;
	std::vector<PBGL_BridgeTexCoord> texcoords;
	std::vector<uint16_t> indices;

	// VBO cache
	GLuint vboPositions;
	GLuint vboNormals;
	GLuint vboTexcoords;
	GLuint ibo;
};

void PBGL_InitState();
void PBGL_LoadExtensions();
void PBGL_DestroyTexture(GLuint texId);
int PBGL_GetMaxTextureSize();
GLuint PBGL_UploadTextureData(void* pixels, int width, int height, bool isUI, float scaleX, float scaleY);
void PBGL_UploadMesh(GLMeshCacheEntry& cache, bool hasTexture);
void PBGL_DestroyMesh(GLMeshCacheEntry& cache);
void PBGL_BeginFrame(const Matrix4x4* projection);
void PBGL_UploadLight(int lightIdx, PBGL_BridgeSceneLight* l);
void PBGL_EnableTransparency();
void PBGL_SubmitDraw(
	GLMeshCacheEntry& mesh,
	const Matrix4x4& modelViewMatrix,
	const Appearance& appearance,
	GLuint texId
);
void PBGL_Resize(int width, int height);
void PBGL_Clear(float r, float g, float b);
void PBGL_Draw2DImage(
	const GLTextureCacheEntry* cache,
	const SDL_Rect& srcRect,
	const SDL_Rect& dstRect,
	const FColor& color,
	float left,
	float right,
	float bottom,
	float top
);
void PBGL_SetDither(bool dither);
void PBGL_Download(SDL_Surface* target);

#pragma once

#include <assimp/scene.h>
#include<vector>
#include <GL/glew.h>
#include <iostream>
#include "texture.hpp"

class Mesh {

private:
	unsigned mVAO_flat;
	unsigned mVBO_flat;
	std::vector<float> mVertices_flat;
	unsigned mEBO_flat;

	unsigned normal_lines_vao;
	unsigned normal_lines_vbo;
	std::vector<float> normal_line_vertices;

	unsigned averaged_normal_lines_vao;
	unsigned averaged_normal_lines_vbo;
	std::vector<float> averaged_normal_vertices;

	unsigned mVAO_smooth;
	unsigned mVBO_smooth;
	std::vector<float> mVertices_smooth;
	unsigned mEBO_smooth;

	unsigned mVertexCount;
	unsigned mIndexCount;
	unsigned mDiffuseTexture;
	unsigned mSpecularTexture;
	std::vector<unsigned> mIndices;

	unsigned loadMeshTexture(const aiMaterial* material, const std::string& resPath, aiTextureType type);

	void processVertices(const aiMesh* mesh, aiVector3D Zero3D);
	void processIndices(const aiMesh* mesh);
	void processTextures(const aiMaterial* material, const std::string& resPath);
	void flatSetup();
	void normalLinesSetup();
	void averagedNormalsSetup(int meshNumber, std::string& file_start, std::string& numStr, std::string& file_end,
	                          std::string& filename);
	void smoothSetup(std::string& file_start, std::string numStr, std::string file_end, std::string& filename);
	void processMesh(const aiMesh* mesh, const aiMaterial* material, const std::string& resPath,const int meshNumber);

public:
	Mesh(const aiMesh* mesh, const aiMaterial* material, const std::string& resPath,const int meshNumber);
	void RenderFlat() const;
	void RenderSmooth() const;
	void RenderVertices() const;
	void RenderTriangles() const;
	void RenderFilledTriangles() const;
	void RenderNormals() const;
	void RenderAveragedNormals() const;
};

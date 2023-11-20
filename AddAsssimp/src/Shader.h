#pragma once
#include<string>
#include<unordered_map>

#include "glm/glm.hpp"
struct  ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;

};

class Shader
{
private:
	std::string m_FilePath;
	//unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& filePath);
	~Shader();
	unsigned int m_RendererID;

	void Bind()const;
	void Unbind()const;

	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform4f(const std::string& name, glm::vec4& value);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniform3f(const std::string& name, glm::vec3&value);

	void SetUniform3f(const std::string& name, float* value);

	unsigned int GetId() {
		return m_RendererID;
	}
private:

	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreatShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);
};

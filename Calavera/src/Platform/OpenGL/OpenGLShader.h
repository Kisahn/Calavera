#ifndef OPENGLSHADER_H
#define OPENGLSHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Calavera/Renderer/Shader.h"

// TODO: REMOVE!
typedef unsigned int GLenum;

namespace Calavera {

	class OpenGLShader : public Shader
	{
		public:
			OpenGLShader(const std::string& filepath);
			OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
			virtual ~OpenGLShader();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			void UploadUniformInt(const std::string& name, int value);

			void UploadUniformFloat(const std::string& name, float value);
			void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
			void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
			void UploadUniformFloat4(const std::string& name, const glm::vec4& values);

			void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
			void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

		private:
			std::string Readfile(const std::string& filepath);
			std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
			void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);
			uint32_t m_RendererID;

	};

}

#endif // !OPENGLSHADER_H
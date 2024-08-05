#ifndef SHADER_H
#define SHADER_H

#include <string>

#include "Calavera/Log.h"

namespace Calavera {

	class Shader {
		
		public:
			virtual ~Shader() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);

	};

}

#endif // !SHADER_H

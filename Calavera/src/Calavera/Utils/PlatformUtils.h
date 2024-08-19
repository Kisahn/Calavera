#ifndef PLATFORMUTILS_H
#define PLATFORMUTILS_H

#include <string>

namespace Calavera {

	class FileDialogs
	{

		public:
			// These return empty strings if cancelled
			static std::string OpenFile(const char* filter);
			static std::string SaveFile(const char* filter);

	};

}

#endif // !PLATFORMUTILS_H

#pragma once

#include "Table/Core/Buffer.h"

namespace Table {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}